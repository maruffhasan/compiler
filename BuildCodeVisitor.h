#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
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

    int currentLocalOffset = -4;     // next local variable slot (grows downward)
    int currentParamOffset = 8;      // next parameter slot (grows upward), reset per function
    int labelCount = 0;
    bool isGlobalScope = true;

    string currentFunctionName;
    string currentFunctionExitLabel = "main_exit";

    // Function name -> declared parameter count (used for callee RET-N cleanup bookkeeping)
    unordered_map<string, int> funcParamCount;

    string newLabel(const string& prefix) {
        return prefix + "_" + to_string(labelCount++);
    }

    void annotateLine(antlr4::ParserRuleContext* ctx) {
        if (ctx && ctx->getStart()) {
            size_t line = ctx->getStart()->getLine();
            emit("; -- line " + to_string(line) + " --");
        }
    }

    // ---------------------------------------------------------------
    // Symbol helpers
    // ---------------------------------------------------------------

    // Returns the addressing-mode string for a simple (non-array) symbol,
    // e.g. "[x]" for a global or "[EBP-4]" / "[EBP+8]" for a local/param.
    string addrOf(SymbolInfo* sym) {
        if (!sym) return "";
        if (sym->isGlobal) return "[" + sym->name + "]";
        return "[EBP" + (sym->offset >= 0 ? "+" + to_string(sym->offset) : to_string(sym->offset)) + "]";
    }

    // Computes the effective address of an array element access (arr[expr]).
    // Leaves the byte offset in EBX (global) or the EBP displacement in ESI
    // (local), and returns the memory operand string to use in a MOV/etc.
    // Clobbers EAX (and EBX or ESI) — call this BEFORE you need EAX for
    // anything else at the current step.
    string computeArrayAddress(CSubsetParser::VarArrayContext* ctx) {
        string varName = ctx->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        visit(ctx->expression());     // index value -> EAX
        emit("IMUL EAX, 4");          // EAX = index * 4 (byte offset)

        if (sym && sym->isGlobal) {
            emit("MOV EBX, EAX");
            return "[" + varName + " + EBX]";
        } else {
            // local array: element address = EBP + (sym->offset - byteOffset)
            emit("MOV ESI, " + to_string(sym ? sym->offset : 0));
            emit("SUB ESI, EAX");
            return "[EBP + ESI]";
        }
    }

    // Dispatches on VarSimple vs VarArray and returns the memory operand
    // string for that variable / array element.
    string resolveVariableAddress(CSubsetParser::VariableContext* vctx) {
        if (auto* v = dynamic_cast<CSubsetParser::VarSimpleContext*>(vctx)) {
            SymbolInfo* sym = symbolTable->LookUp(v->ID()->getText());
            return addrOf(sym);
        } else if (auto* v = dynamic_cast<CSubsetParser::VarArrayContext*>(vctx)) {
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
            si.offset = currentLocalOffset;
            symbolTable->Insert(si);

            currentLocalOffset -= (4 * arraySize);
        }
    }

    // ---------------------------------------------------------------
    // Parameter list helpers
    // ---------------------------------------------------------------

    int countParams(CSubsetParser::Parameter_listContext* ctx) {
        if (!ctx) return 0;
        if (auto* c = dynamic_cast<CSubsetParser::ParamListMultiNamedContext*>(ctx)) {
            return 1 + countParams(c->parameter_list());
        } else if (auto* c = dynamic_cast<CSubsetParser::ParamListMultiUnnamedContext*>(ctx)) {
            return 1 + countParams(c->parameter_list());
        } else if (dynamic_cast<CSubsetParser::ParamListSingleNamedContext*>(ctx)) {
            return 1;
        } else if (dynamic_cast<CSubsetParser::ParamListSingleUnnamedContext*>(ctx)) {
            return 1;
        }
        return 0;
    }

    void addParamSymbol(const string& name) {
        SymbolInfo si(name, "VAR", "INT");
        si.isGlobal = false;
        si.offset = currentParamOffset;
        symbolTable->Insert(si);
        currentParamOffset += 4;
    }

    // Registers parameters into the symbol table left-to-right so the
    // first declared parameter ends up at EBP+8, the next at EBP+12, etc.
    void registerParams(CSubsetParser::Parameter_listContext* ctx) {
        if (!ctx) return;
        if (auto* c = dynamic_cast<CSubsetParser::ParamListMultiNamedContext*>(ctx)) {
            registerParams(c->parameter_list());
            addParamSymbol(c->ID()->getText());
        } else if (auto* c = dynamic_cast<CSubsetParser::ParamListMultiUnnamedContext*>(ctx)) {
            registerParams(c->parameter_list());
            currentParamOffset += 4; // unnamed param still occupies a slot
        } else if (auto* c = dynamic_cast<CSubsetParser::ParamListSingleNamedContext*>(ctx)) {
            addParamSymbol(c->ID()->getText());
        } else if (dynamic_cast<CSubsetParser::ParamListSingleUnnamedContext*>(ctx)) {
            currentParamOffset += 4;
        }
    }

    // ---------------------------------------------------------------
    // Function call argument helpers (push right-to-left)
    // ---------------------------------------------------------------

    void pushArgumentsRec(CSubsetParser::ArgumentsContext* ctx) {
        if (!ctx) return;
        if (auto* c = dynamic_cast<CSubsetParser::ArgumentsMultiContext*>(ctx)) {
            // Evaluate/push the rightmost argument at this level first,
            // then recurse into the remaining left part, so the FIRST
            // (leftmost) argument ends up pushed LAST -> closest to EBP+8.
            visit(c->logic_expression());
            emit("PUSH EAX");
            pushArgumentsRec(c->arguments());
        } else if (auto* c = dynamic_cast<CSubsetParser::ArgumentsSingleContext*>(ctx)) {
            visit(c->logic_expression());
            emit("PUSH EAX");
        }
    }

    void pushArguments(CSubsetParser::Argument_listContext* ctx) {
        if (!ctx) return;
        if (auto* c = dynamic_cast<CSubsetParser::ArgListNonEmptyContext*>(ctx)) {
            pushArgumentsRec(c->arguments());
        }
        // ArgListEmptyContext: nothing to push
    }

    // ---------------------------------------------------------------
    // Function signature pre-pass (so calls work regardless of source order)
    // ---------------------------------------------------------------

    void collectUnitSignature(CSubsetParser::UnitContext* uctx) {
        if (!uctx) return;
        if (auto* c = dynamic_cast<CSubsetParser::UnitFuncDeclContext*>(uctx)) {
            auto* fd = c->func_declaration();
            if (auto* f1 = dynamic_cast<CSubsetParser::FuncDeclWithParamsContext*>(fd)) {
                funcParamCount[f1->ID()->getText()] = countParams(f1->parameter_list());
            } else if (auto* f2 = dynamic_cast<CSubsetParser::FuncDeclNoParamsContext*>(fd)) {
                funcParamCount[f2->ID()->getText()] = 0;
            }
        } else if (auto* c = dynamic_cast<CSubsetParser::UnitFuncDefContext*>(uctx)) {
            auto* fd = c->func_definition();
            if (auto* f1 = dynamic_cast<CSubsetParser::FuncDefWithParamsContext*>(fd)) {
                funcParamCount[f1->ID()->getText()] = countParams(f1->parameter_list());
            } else if (auto* f2 = dynamic_cast<CSubsetParser::FuncDefNoParamsContext*>(fd)) {
                funcParamCount[f2->ID()->getText()] = 0;
            }
        }
    }

    void collectSignatures(CSubsetParser::ProgramContext* ctx) {
        if (!ctx) return;
        if (auto* c = dynamic_cast<CSubsetParser::ProgramUnitContext*>(ctx)) {
            collectSignatures(c->program());
            collectUnitSignature(c->unit());
        } else if (auto* c = dynamic_cast<CSubsetParser::ProgramSingleUnitContext*>(ctx)) {
            collectUnitSignature(c->unit());
        }
    }

    // ---------------------------------------------------------------
    // Function definition codegen
    // ---------------------------------------------------------------

    void handleFuncDefinition(const string& funcName,
                               CSubsetParser::Parameter_listContext* paramCtx,
                               CSubsetParser::Compound_statementContext* bodyCtx) {
        isGlobalScope = false;
        currentLocalOffset = -4;
        currentParamOffset = 8;
        currentFunctionName = funcName;
        currentFunctionExitLabel = funcName + "_exit";

        asmFile << "\nsegment readable executable\n";
        emitLabel(funcName);

        emit("PUSH EBP");
        emit("MOV EBP, ESP");
        emit("SUB ESP, 128");

        symbolTable->EnterScope();

        int paramCount = 0;
        if (paramCtx) {
            paramCount = countParams(paramCtx);
            registerParams(paramCtx);
        }
        funcParamCount[funcName] = paramCount;

        if (bodyCtx) {
            visit(bodyCtx);
        }

        symbolTable->ExitScope();

        emitLabel(currentFunctionExitLabel);
        emit("ADD ESP, 128");
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

    // -----------------------------------------------------------
    // Entry point — collect function signatures first so calls to
    // functions defined later in the file still work.
    // -----------------------------------------------------------

    virtual any visitStart(CSubsetParser::StartContext *ctx) override {
        collectSignatures(ctx->program());
        return visitChildren(ctx);
    }

    // -----------------------------------------------------------
    // Function declarations (prototypes) — no code, just bookkeeping
    // -----------------------------------------------------------

    virtual any visitFuncDeclWithParams(CSubsetParser::FuncDeclWithParamsContext *ctx) override {
        funcParamCount[ctx->ID()->getText()] = countParams(ctx->parameter_list());
        return 0;
    }

    virtual any visitFuncDeclNoParams(CSubsetParser::FuncDeclNoParamsContext *ctx) override {
        funcParamCount[ctx->ID()->getText()] = 0;
        return 0;
    }

    // -----------------------------------------------------------
    // Function definitions
    // -----------------------------------------------------------

    virtual any visitFuncDefNoParams(CSubsetParser::FuncDefNoParamsContext *ctx) override {
        handleFuncDefinition(ctx->ID()->getText(), nullptr, ctx->compound_statement());
        return 0;
    }

    virtual any visitFuncDefWithParams(CSubsetParser::FuncDefWithParamsContext *ctx) override {
        handleFuncDefinition(ctx->ID()->getText(), ctx->parameter_list(), ctx->compound_statement());
        return 0;
    }

    // -----------------------------------------------------------
    // Compound statement -> its own scope (so nested blocks in
    // if/while/for bodies get properly scoped locals)
    // -----------------------------------------------------------

    virtual any visitCompoundWithStmts(CSubsetParser::CompoundWithStmtsContext *ctx) override {
        symbolTable->EnterScope();
        visit(ctx->statements());
        symbolTable->ExitScope();
        return 0;
    }

    virtual any visitCompoundEmpty(CSubsetParser::CompoundEmptyContext *ctx) override {
        return 0;
    }

    // -----------------------------------------------------------
    // Declarations
    // -----------------------------------------------------------

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

    // -----------------------------------------------------------
    // Statements
    // -----------------------------------------------------------

    virtual any visitStmtPrintln(CSubsetParser::StmtPrintlnContext *ctx) override {
        annotateLine(ctx);
        string varName = ctx->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        emit("MOV EAX, " + addrOf(sym));
        emit("CALL OUTDEC");
        return 0;
    }

    virtual any visitStmtReturn(CSubsetParser::StmtReturnContext *ctx) override {
        annotateLine(ctx);
        if (ctx->expression()) {
            visit(ctx->expression());
        }
        emit("JMP " + currentFunctionExitLabel);
        return 0;
    }

    virtual any visitStmtIf(CSubsetParser::StmtIfContext *ctx) override {
        annotateLine(ctx);
        visit(ctx->expression());
        string endLabel = newLabel("L_if_end");
        emit("CMP EAX, 0");
        emit("JE " + endLabel);
        visit(ctx->statement());
        emitLabel(endLabel);
        return 0;
    }

    virtual any visitStmtIfElse(CSubsetParser::StmtIfElseContext *ctx) override {
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

    virtual any visitStmtWhile(CSubsetParser::StmtWhileContext *ctx) override {
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

    virtual any visitStmtFor(CSubsetParser::StmtForContext *ctx) override {
        annotateLine(ctx);
        visit(ctx->expression_statement(0)); // init

        string startLabel = newLabel("L_for_start");
        string endLabel = newLabel("L_for_end");
        emitLabel(startLabel);

        visit(ctx->expression_statement(1)); // condition -> EAX (1 if empty)
        emit("CMP EAX, 0");
        emit("JE " + endLabel);

        visit(ctx->statement());   // body
        visit(ctx->expression());  // increment, result discarded

        emit("JMP " + startLabel);
        emitLabel(endLabel);
        return 0;
    }

    virtual any visitExprStmtEmpty(CSubsetParser::ExprStmtEmptyContext *ctx) override {
        // An empty for-condition means "always true"
        emit("MOV EAX, 1");
        return 0;
    }

    virtual any visitExprStmtExpr(CSubsetParser::ExprStmtExprContext *ctx) override {
        visit(ctx->expression());
        return 0;
    }

    // -----------------------------------------------------------
    // Expressions & Assignments
    // -----------------------------------------------------------

    virtual any visitExprAssign(CSubsetParser::ExprAssignContext *ctx) override {
        annotateLine(ctx);
        visit(ctx->logic_expression());
        emit("PUSH EAX");

        string addr = resolveVariableAddress(ctx->variable());

        emit("POP EAX");
        emit("MOV " + addr + ", EAX");
        return 0;
    }

    virtual any visitLogicOp(CSubsetParser::LogicOpContext *ctx) override {
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

    virtual any visitRelOp(CSubsetParser::RelOpContext *ctx) override {
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

    virtual any visitSimpleAddOp(CSubsetParser::SimpleAddOpContext *ctx) override {
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

    virtual any visitTermMulOp(CSubsetParser::TermMulOpContext *ctx) override {
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

    // -----------------------------------------------------------
    // Unary Expressions
    // -----------------------------------------------------------

    virtual any visitUnaryAddOp(CSubsetParser::UnaryAddOpContext *ctx) override {
        visit(ctx->unary_expression());
        string op = ctx->ADDOP()->getText();
        if (op == "-") {
            emit("NEG EAX");
        }
        return 0;
    }

    virtual any visitUnaryNot(CSubsetParser::UnaryNotContext *ctx) override {
        visit(ctx->unary_expression());
        emit("CMP EAX, 0");
        emit("SETE AL");
        emit("MOVZX EAX, AL");
        return 0;
    }

    // -----------------------------------------------------------
    // Factors
    // -----------------------------------------------------------

    virtual any visitFactorConstInt(CSubsetParser::FactorConstIntContext *ctx) override {
        emit("MOV EAX, " + ctx->CONST_INT()->getText());
        return 0;
    }

    virtual any visitFactorConstFloat(CSubsetParser::FactorConstFloatContext *ctx) override {
        // Floating point is out of scope for this assignment.
        emit("; float literal ignored (unsupported): " + ctx->CONST_FLOAT()->getText());
        emit("MOV EAX, 0");
        return 0;
    }

    virtual any visitFactorVar(CSubsetParser::FactorVarContext *ctx) override {
        string addr = resolveVariableAddress(ctx->variable());
        emit("MOV EAX, " + addr);
        return 0;
    }

    virtual any visitFactorFuncCall(CSubsetParser::FactorFuncCallContext *ctx) override {
        pushArguments(ctx->argument_list());
        emit("CALL " + ctx->ID()->getText());
        // callee cleans up its own arguments (callee-cleanup convention);
        // return value is already in EAX
        return 0;
    }

    virtual any visitFactorIncop(CSubsetParser::FactorIncopContext *ctx) override {
        string addr = resolveVariableAddress(ctx->variable());
        emit("MOV EAX, " + addr);
        emit("INC dword " + addr);
        return 0;
    }

    virtual any visitFactorDecop(CSubsetParser::FactorDecopContext *ctx) override {
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

    // -----------------------------------------------------------
    // Peephole Optimizer Implementation
    // -----------------------------------------------------------

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

                if (!trimmed.empty() && trimmed.back() == ':' && !trimmedNext.empty() && trimmedNext.back() == ':') {
                    continue;
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