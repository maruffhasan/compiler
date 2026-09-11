#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include "antlr4-runtime.h"
#include "CSubsetBaseVisitor.h"
#include "SymbolTable.h"

using namespace std;

class BuildCodeVisitor : public CSubsetBaseVisitor {
private:
    ofstream asmFile;
    string unoptimizedFileName;
    string optimizedFileName;
    SymbolTable* symbolTable;

    int currentLocalOffset = 0;
    int currentParamOffset = 8;
    int labelCount = 0;
    bool isGlobalScope = true;

    string currentFunctionExitLabel = "main_exit";


    string newLabel(const string& prefix) { // creating new unique label
        return prefix + "_" + to_string(labelCount++);
    }

    void annotateLine(antlr4::ParserRuleContext* ctx) { // printing line number
        if (ctx && ctx->getStart()) {
            size_t line = ctx->getStart()->getLine();
            emit("; -- line " + to_string(line) + " --");
        }
    }

    string addrOf(SymbolInfo* sym) { // returns address of variable  
        if (!sym) return "";
        if (sym->isGlobal) return "[" + sym->name + "]";
        return "[EBP" + (sym->offset >= 0 ? "+" + to_string(sym->offset) : to_string(sym->offset)) + "]";
    }


    string computeArrayAddress(CSubsetParser::VarArrayContext* ctx) {  // address of array element
        string varName = ctx->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        visit(ctx->expression());     
        emit("IMUL EAX, 4");          

        if (sym && sym->isGlobal) {   // [arr + EBX]
            emit("MOV EBX, EAX");
            return "[" + varName + " + EBX]";
        } else {
            emit("MOV ESI, " + to_string(sym->offset));  // [EBP - base_offset - index * 4] 
            emit("SUB ESI, EAX");
            return "[EBP + ESI]";
        }
    }

    string resolveVariableAddress(CSubsetParser::VariableContext* vctx) {  // compute address of variable and array
        if (auto* v = static_cast<CSubsetParser::VarSimpleContext*>(vctx)) {
            SymbolInfo* sym = symbolTable->LookUp(v->ID()->getText());
            return addrOf(sym);
        } else if (auto* v = static_cast<CSubsetParser::VarArrayContext*>(vctx)) {
            return computeArrayAddress(v);
        }
        return "";
    }

    void processVariableDeclaration(const string& varName, bool isArray, int arraySize) {
        SymbolInfo si(varName, isArray ? "ARRAY" : "VAR", "INT");
        if (isGlobalScope) {
            si.isGlobal = true;
            symbolTable->Insert(si);

            asmFile << "segment readable writeable\n";
            asmFile << varName << " dd " << arraySize << " dup (0)\n";
        } else {
            si.isGlobal = false;
            int size = 4 * arraySize;
            currentLocalOffset -= size;
            si.offset = currentLocalOffset;
            symbolTable->Insert(si);
            emit("SUB ESP, " + to_string(size));
        }
    }

    // Parameter list helpers

    int countParams(CSubsetParser::Parameter_listContext* ctx) { // count number of parameters (need for function return : RET N)
        if (!ctx) return 0;
        if (auto* c = static_cast<CSubsetParser::ParamListMultiNamedContext*>(ctx)) {
            return 1 + countParams(c->parameter_list());
        } else if (auto* c = static_cast<CSubsetParser::ParamListMultiUnnamedContext*>(ctx)) {
            return 1 + countParams(c->parameter_list());
        } else if (static_cast<CSubsetParser::ParamListSingleNamedContext*>(ctx)) {
            return 1;
        } else if (static_cast<CSubsetParser::ParamListSingleUnnamedContext*>(ctx)) {
            return 1;
        }
        return 0;
    }

    void addParamSymbol(const string& name) {  // add parameter to symbol table 
        SymbolInfo si(name, "VAR", "INT");
        si.isGlobal = false;
        si.offset = currentParamOffset;
        symbolTable->Insert(si);
        currentParamOffset += 4;
    }


    void registerParams(CSubsetParser::Parameter_listContext* ctx) { // add parameter to function's scope in symbol table 
        if (!ctx) return;
        if (auto* c = static_cast<CSubsetParser::ParamListMultiNamedContext*>(ctx)) {
            registerParams(c->parameter_list());
            addParamSymbol(c->ID()->getText());
        } else if (auto* c = static_cast<CSubsetParser::ParamListMultiUnnamedContext*>(ctx)) {
            registerParams(c->parameter_list());
            currentParamOffset += 4; // unnamed param still occupies a slot
        } else if (auto* c = static_cast<CSubsetParser::ParamListSingleNamedContext*>(ctx)) {
            addParamSymbol(c->ID()->getText());
        } else if (static_cast<CSubsetParser::ParamListSingleUnnamedContext*>(ctx)) {
            currentParamOffset += 4;
        }
    }

    // Function call argument helpers 

    void pushArgumentsRec(CSubsetParser::ArgumentsContext* ctx) {
        if (!ctx) return;
        if (auto* c = static_cast<CSubsetParser::ArgumentsMultiContext*>(ctx)) { // push right to left
            visit(c->logic_expression());
            emit("PUSH EAX");
            pushArgumentsRec(c->arguments());
        } else if (auto* c = static_cast<CSubsetParser::ArgumentsSingleContext*>(ctx)) {
            visit(c->logic_expression());
            emit("PUSH EAX");
        }
    }

    void pushArguments(CSubsetParser::Argument_listContext* ctx) {
        if (!ctx) return;
        if (auto* c = static_cast<CSubsetParser::ArgListNonEmptyContext*>(ctx)) {
            pushArgumentsRec(c->arguments());
        }
    }

    // Function definition 

    void handleFuncDefinition(const string& funcName,
                               CSubsetParser::Parameter_listContext* paramCtx,
                               CSubsetParser::Compound_statementContext* bodyCtx) {
        isGlobalScope = false;
        currentLocalOffset = 0;
        currentParamOffset = 8;
        currentFunctionExitLabel = funcName + "_exit";

        asmFile << "\nsegment readable executable\n";
        emitLabel(funcName);

        emit("PUSH EBP");
        emit("MOV EBP, ESP");

        symbolTable->EnterScope();

        int paramCount = 0;
        if (paramCtx) {
            paramCount = countParams(paramCtx);
            registerParams(paramCtx);
        }

        if (bodyCtx) {
            visit(bodyCtx);
        }

        symbolTable->ExitScope();

        emitLabel(currentFunctionExitLabel);
        emit("MOV ESP, EBP");
        emit("POP EBP");

        if (funcName == "main") {
            emit("MOV EAX, 1");
            emit("XOR EBX, EBX");
            emit("INT 0x80");
        } else {
            int bytesToClean = paramCount * 4;
            if (bytesToClean > 0) emit("RET " + to_string(bytesToClean));
            else emit("RET");
        }

        isGlobalScope = true;
    }

public:
    BuildCodeVisitor(const string& codeAsmPath, const string& optAsmPath, ofstream& logout)
        : unoptimizedFileName(codeAsmPath), optimizedFileName(optAsmPath) {
        asmFile.open(unoptimizedFileName);
        symbolTable = new SymbolTable(11, logout);

        asmFile << "format ELF executable 3\nentry main\n\n";
    }

    ~BuildCodeVisitor() {
        if (asmFile.is_open()) {
            emitOutdecProcedure();
            asmFile.close();
        }
        delete symbolTable;

        // Peephole Optimization
        performOptimization();
    }

    void emit(const string& code) { asmFile << "\t" << code << "\n"; }
    void emitLabel(const string& label) { asmFile << label << ":\n"; }


    virtual any visitFuncDefNoParams(CSubsetParser::FuncDefNoParamsContext *ctx) override {
        handleFuncDefinition(ctx->ID()->getText(), nullptr, ctx->compound_statement());
        return 0;
    }

    virtual any visitFuncDefWithParams(CSubsetParser::FuncDefWithParamsContext *ctx) override {
        handleFuncDefinition(ctx->ID()->getText(), ctx->parameter_list(), ctx->compound_statement());
        return 0;
    }

    virtual any visitCompoundWithStmts(CSubsetParser::CompoundWithStmtsContext *ctx) override {
        symbolTable->EnterScope();
        visit(ctx->statements());
        symbolTable->ExitScope();
        return 0;
    }

    // Declarations

    virtual any visitDeclListCommaId(CSubsetParser::DeclListCommaIdContext *ctx) override {
        visit(ctx->declaration_list());
        processVariableDeclaration(ctx->ID()->getText(), false, 1);
        return 0;
    }

    virtual any visitDeclListSingleId(CSubsetParser::DeclListSingleIdContext *ctx) override {
        processVariableDeclaration(ctx->ID()->getText(), false, 1);
        return 0;
    }

    virtual any visitDeclListCommaIdArray(CSubsetParser::DeclListCommaIdArrayContext *ctx) override {
        visit(ctx->declaration_list());
        int size = stoi(ctx->CONST_INT()->getText());
        processVariableDeclaration(ctx->ID()->getText(), true, size);
        return 0;
    }

    virtual any visitDeclListSingleIdArray(CSubsetParser::DeclListSingleIdArrayContext *ctx) override {
        int size = stoi(ctx->CONST_INT()->getText());
        processVariableDeclaration(ctx->ID()->getText(), true, size);
        return 0;
    }

    // Statements

    virtual any visitStmtPrintln(CSubsetParser::StmtPrintlnContext *ctx) override { // printing identifier 
        annotateLine(ctx);
        string varName = ctx->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        emit("MOV EAX, " + addrOf(sym));
        emit("CALL OUTDEC");
        return 0;
    }

    virtual any visitStmtReturn(CSubsetParser::StmtReturnContext *ctx) override { // return statement
        annotateLine(ctx);
        visit(ctx->expression());

        emit("JMP " + currentFunctionExitLabel);
        return 0;
    }

    virtual any visitStmtIf(CSubsetParser::StmtIfContext *ctx) override { // if condition without else block 
        annotateLine(ctx);
        visit(ctx->expression());
        string endLabel = newLabel("L_if_end");
        emit("CMP EAX, 0");
        emit("JE " + endLabel);
        visit(ctx->statement());
        emitLabel(endLabel);
        return 0;
    }

    virtual any visitStmtIfElse(CSubsetParser::StmtIfElseContext *ctx) override { // if else condition
        annotateLine(ctx);
        visit(ctx->expression());
        string elseLabel = newLabel("L_else");
        string endLabel = newLabel("L_if_end");
        emit("CMP EAX, 0");
        emit("JE " + elseLabel);
        visit(ctx->statement(0));
        emit("JMP " + endLabel);
        emitLabel(elseLabel);
        visit(ctx->statement(1));
        emitLabel(endLabel);
        return 0;
    }

    virtual any visitStmtWhile(CSubsetParser::StmtWhileContext *ctx) override {  // while loop
        annotateLine(ctx);
        string startLabel = newLabel("L_while_start");
        string endLabel = newLabel("L_while_end");
        emitLabel(startLabel);
        visit(ctx->expression());
        emit("CMP EAX, 0");
        emit("JE " + endLabel);
        visit(ctx->statement());
        emit("JMP " + startLabel);
        emitLabel(endLabel);
        return 0;
    }

    virtual any visitStmtFor(CSubsetParser::StmtForContext *ctx) override { // for loop
        annotateLine(ctx);
        visit(ctx->expression_statement(0)); // init

        string startLabel = newLabel("L_for_start");
        string endLabel = newLabel("L_for_end");
        emitLabel(startLabel);

        visit(ctx->expression_statement(1)); // condition -> EAX (1 if empty)
        emit("CMP EAX, 0");
        emit("JE " + endLabel);

        visit(ctx->statement());   // body
        visit(ctx->expression());  // increment

        emit("JMP " + startLabel);
        emitLabel(endLabel);
        return 0;
    }

    virtual any visitExprStmtEmpty(CSubsetParser::ExprStmtEmptyContext *ctx) override { // explicitly for "for loop"
        emit("MOV EAX, 1"); // An empty for condition means "always true"
        return 0;
    }

    // Expressions & Assignments

    virtual any visitExprAssign(CSubsetParser::ExprAssignContext *ctx) override {  // assignment : x = y * 4
        annotateLine(ctx);
        visit(ctx->logic_expression());
        emit("PUSH EAX");

        string addr = resolveVariableAddress(ctx->variable());

        emit("POP EAX");
        emit("MOV " + addr + ", EAX");
        return 0;
    }

    virtual any visitLogicOp(CSubsetParser::LogicOpContext *ctx) override {  // logical operators : x || y
        string op = ctx->LOGICOP()->getText();
        string trueLabel = newLabel("L_bool_true");
        string falseLabel = newLabel("L_bool_false");
        string endLabel = newLabel("L_bool_end");

        if (op == "&&") {
            visit(ctx->rel_expression(0));
            emit("CMP EAX, 0");
            emit("JE " + falseLabel); // Short circuit directly to false

            visit(ctx->rel_expression(1));
            emit("CMP EAX, 0");
            emit("JE " + falseLabel);

            emitLabel(trueLabel);
            emit("MOV EAX, 1");
            emit("JMP " + endLabel);

            emitLabel(falseLabel);
            emit("MOV EAX, 0");
            emitLabel(endLabel);
        } else if (op == "||") {
            visit(ctx->rel_expression(0));
            emit("CMP EAX, 0");
            emit("JNE " + trueLabel); // Short circuit directly to true

            visit(ctx->rel_expression(1));
            emit("CMP EAX, 0");
            emit("JNE " + trueLabel);

            emitLabel(falseLabel);
            emit("MOV EAX, 0");
            emit("JMP " + endLabel);

            emitLabel(trueLabel);
            emit("MOV EAX, 1");
            emitLabel(endLabel);
        }
        return 0;
    }

    virtual any visitRelOp(CSubsetParser::RelOpContext *ctx) override {  // relational operator : x >= y
        visit(ctx->simple_expression(0));
        emit("PUSH EAX");
        visit(ctx->simple_expression(1));
        emit("POP EBX");

        emit("CMP EBX, EAX");
        string trueLabel = newLabel("L_rel_true");
        string endLabel = newLabel("L_rel_end");

        string relOp = ctx->RELOP()->getText();
        if (relOp == "<")       emit("JL " + trueLabel);
        else if (relOp == "<=") emit("JLE " + trueLabel);
        else if (relOp == ">")  emit("JG " + trueLabel);
        else if (relOp == ">=") emit("JGE " + trueLabel);
        else if (relOp == "==") emit("JE " + trueLabel);
        else if (relOp == "!=") emit("JNE " + trueLabel);

        emit("MOV EAX, 0");
        emit("JMP " + endLabel);
        emitLabel(trueLabel);
        emit("MOV EAX, 1");
        emitLabel(endLabel);
        return 0;
    }

    virtual any visitSimpleAddOp(CSubsetParser::SimpleAddOpContext *ctx) override {  // x +- y
        visit(ctx->term());
        emit("PUSH EAX");
        visit(ctx->simple_expression());
        emit("POP EBX");

        string op = ctx->ADDOP()->getText();
        if (op == "+") {
            emit("ADD EAX, EBX");
        } else if (op == "-") {
            emit("SUB EAX, EBX");
        }
        return 0;
    }

    virtual any visitTermMulOp(CSubsetParser::TermMulOpContext *ctx) override {  // x */% y
        visit(ctx->unary_expression());
        emit("PUSH EAX");
        visit(ctx->term());
        emit("POP EBX");

        string op = ctx->MULOP()->getText();
        if (op == "*") {
            emit("IMUL EAX, EBX");
        } else if (op == "/") {
            emit("XOR EDX, EDX");
            emit("IDIV EBX");
        } else if (op == "%") {
            emit("XOR EDX, EDX");
            emit("IDIV EBX");
            emit("MOV EAX, EDX");
        }
        return 0;
    }

    // Unary Expressions

    virtual any visitUnaryAddOp(CSubsetParser::UnaryAddOpContext *ctx) override { // +-x
        visit(ctx->unary_expression());
        string op = ctx->ADDOP()->getText();
        if (op == "-") {
            emit("NEG EAX");
        }
        return 0;
    }

    virtual any visitUnaryNot(CSubsetParser::UnaryNotContext *ctx) override { // !x
        visit(ctx->unary_expression());
        emit("CMP EAX, 0");
        emit("SETE AL");
        emit("MOVZX EAX, AL");
        return 0;
    }

    // Factors

    virtual any visitFactorConstInt(CSubsetParser::FactorConstIntContext *ctx) override {  // integer
        emit("MOV EAX, " + ctx->CONST_INT()->getText());
        return 0;
    }

    virtual any visitFactorVar(CSubsetParser::FactorVarContext *ctx) override { // variable
        string addr = resolveVariableAddress(ctx->variable());
        emit("MOV EAX, " + addr);
        return 0;
    }

    virtual any visitFactorFuncCall(CSubsetParser::FactorFuncCallContext *ctx) override {  // function call
        pushArguments(ctx->argument_list());
        emit("CALL " + ctx->ID()->getText());  // callee-cleanup convention, return value is in EAX
        return 0;
    }

    virtual any visitFactorIncop(CSubsetParser::FactorIncopContext *ctx) override { // post increment : x++
        string addr = resolveVariableAddress(ctx->variable());
        emit("MOV EAX, " + addr);
        emit("INC dword " + addr);
        return 0;
    }

    virtual any visitFactorDecop(CSubsetParser::FactorDecopContext *ctx) override { // post decrement : x--
        string addr = resolveVariableAddress(ctx->variable());
        emit("MOV EAX, " + addr);
        emit("DEC dword " + addr);
        return 0;
    }

private:
    void emitOutdecProcedure() {
        asmFile << "\nOUTDEC:\n"
                << "\tPUSH EBX\n"
                << "\tPUSH ECX\n"
                << "\tPUSH EDX\n"
                << "\tPUSH ESI\n"
                << "\tOR EAX, EAX\n"
                << "\tJGE OUTDEC_POSITIVE\n"
                << "\tNEG EAX\n"
                << "\tPUSH EAX\n"
                << "\tSUB ESP, 4\n"
                << "\tMOV byte [ESP], '-'\n"
                << "\tMOV EAX, 4\n"
                << "\tMOV EBX, 1\n"
                << "\tMOV ECX, ESP\n"
                << "\tMOV EDX, 1\n"
                << "\tINT 0x80\n"
                << "\tADD ESP, 4\n"
                << "\tPOP EAX\n"
                << "OUTDEC_POSITIVE:\n"
                << "\tXOR ECX, ECX\n"
                << "\tMOV EBX, 10\n"
                << "OUTDEC_DIGIT_LOOP:\n"
                << "\tXOR EDX, EDX\n"
                << "\tDIV EBX\n"
                << "\tADD DL, 30h\n"
                << "\tPUSH EDX\n"
                << "\tINC ECX\n"
                << "\tTEST EAX, EAX\n"
                << "\tJNZ OUTDEC_DIGIT_LOOP\n"
                << "OUTDEC_PRINT_LOOP:\n"
                << "\tTEST ECX, ECX\n"
                << "\tJZ OUTDEC_NEWLINE\n"
                << "\tPUSH ECX\n"
                << "\tMOV EAX, 4\n"
                << "\tMOV EBX, 1\n"
                << "\tLEA ECX, [ESP+4]\n"
                << "\tMOV EDX, 1\n"
                << "\tINT 0x80\n"
                << "\tPOP ECX\n"
                << "\tADD ESP, 4\n"
                << "\tDEC ECX\n"
                << "\tJMP OUTDEC_PRINT_LOOP\n"
                << "OUTDEC_NEWLINE:\n"
                << "\tSUB ESP, 4\n"
                << "\tMOV byte [ESP], 10\n"
                << "\tMOV EAX, 4\n"
                << "\tMOV EBX, 1\n"
                << "\tMOV ECX, ESP\n"
                << "\tMOV EDX, 1\n"
                << "\tINT 0x80\n"
                << "\tADD ESP, 4\n"
                << "\tPOP ESI\n"
                << "\tPOP EDX\n"
                << "\tPOP ECX\n"
                << "\tPOP EBX\n"
                << "\tRET\n";
    }

    // Peephole Optimizer Implementation

    void performOptimization() {
        ifstream inFile(unoptimizedFileName);
        if (!inFile.is_open()) return;

        vector<string> lines;
        string line;
        while (getline(inFile, line)) {
            lines.push_back(line);
        }
        inFile.close();

        vector<string> optimized;
        size_t n = lines.size();

        for (size_t i = 0; i < n; ++i) {
            string cur = lines[i];

            string trimmed = regex_replace(cur, regex("^\\s+|\\s+$"), "");

            if (trimmed == "ADD EAX, 0" || trimmed == "SUB EAX, 0" || trimmed == "IMUL EAX, 1") {
                continue;
            }

            // Lookahead
            if (i + 1 < n) {
                string nextLine = lines[i + 1];
                string trimmedNext = regex_replace(nextLine, regex("^\\s+|\\s+$"), "");

                auto parseInst = [](const string& line, string& op, string& arg1, string& arg2) {
                    op = arg1 = arg2 = "";
                    size_t spacePos = line.find_first_of(" \t");
                    if (spacePos == string::npos) {
                        op = line;
                        return;
                    }
                    op = line.substr(0, spacePos);

                    size_t firstChar = line.find_first_not_of(" \t", spacePos);
                    if (firstChar == string::npos) return;
                    string args = line.substr(firstChar);

                    size_t commaPos = args.find(',');
                    if (commaPos != string::npos) {
                        arg1 = args.substr(0, commaPos);
                        size_t end1 = arg1.find_last_not_of(" \t");
                        if (end1 != string::npos) arg1 = arg1.substr(0, end1 + 1);

                        size_t start2 = args.find_first_not_of(" \t", commaPos + 1);
                        if (start2 != string::npos) arg2 = args.substr(start2);
                    } else {
                        arg1 = args;
                        size_t end1 = arg1.find_last_not_of(" \t");
                        if (end1 != string::npos) arg1 = arg1.substr(0, end1 + 1);
                    }
                };

                string op1, a1_1, a1_2;
                string op2, a2_1, a2_2;
                parseInst(trimmed, op1, a1_1, a1_2);
                parseInst(trimmedNext, op2, a2_1, a2_2);

                if (op1 == "MOV" && op2 == "MOV") {
                    if (!a1_1.empty() && !a1_2.empty() && a1_1 == a2_2 && a1_2 == a2_1) {
                        optimized.push_back(cur);
                        i++;
                        continue;
                    }
                }

                if (op1 == "PUSH" && op2 == "POP") {
                    if (!a1_1.empty() && a1_1 == a2_1) {
                        i++;
                        continue;
                    }
                }
            }

            optimized.push_back(cur);
        }

        ofstream outFile(optimizedFileName);
        for (const auto& optLine : optimized) {
            outFile << optLine << "\n";
        }
        outFile.close();
    }
};