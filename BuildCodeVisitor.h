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
    
    int currentLocalOffset = -4;
    int labelCount = 0;
    bool isGlobalScope = true;

    string newLabel(const string& prefix) {
        return prefix + "_" + to_string(labelCount++);
    }

    void annotateLine(antlr4::ParserRuleContext* ctx) {
        if (ctx && ctx->getStart()) {
            size_t line = ctx->getStart()->getLine();
            emit("; -- line " + to_string(line) + " --");
        }
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

    void handleFuncDefinition(const string& funcName, CSubsetParser::Compound_statementContext* bodyCtx) {
        isGlobalScope = false;
        currentLocalOffset = -4;

        asmFile << "\nsegment readable executable\n";
        emitLabel(funcName);
        
        emit("PUSH EBP");
        emit("MOV EBP, ESP");
        emit("SUB ESP, 128");

        symbolTable->EnterScope();

        if (bodyCtx) {
            visit(bodyCtx);
        }

        symbolTable->ExitScope();

        string exitLabel = funcName + "_exit";
        emitLabel(exitLabel);

        if (funcName == "main") {
            emit("ADD ESP, 128");
            emit("POP EBP");
            emit("MOV EAX, 1");
            emit("XOR EBX, EBX");
            emit("INT 0x80");
        } else {
            emit("ADD ESP, 128");
            emit("POP EBP");
            emit("RET");
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
    
    //  Function Definitions 

    virtual any visitFuncDefNoParams(CSubsetParser::FuncDefNoParamsContext *ctx) override {
        handleFuncDefinition(ctx->ID()->getText(), ctx->compound_statement());
        return 0;
    }


    //  Declarations 

    virtual any visitDeclListCommaId(CSubsetParser::DeclListCommaIdContext *ctx) override {
        visit(ctx->declaration_list());
        processVariableDeclaration(ctx->ID()->getText(), false, 1);
        return 0;
    }

    virtual any visitDeclListSingleId(CSubsetParser::DeclListSingleIdContext *ctx) override {
        processVariableDeclaration(ctx->ID()->getText(), false, 1);
        return 0;
    }

    //  Statements 

    virtual any visitStmtPrintln(CSubsetParser::StmtPrintlnContext *ctx) override {
        annotateLine(ctx);
        string varName = ctx->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        if (sym) {
            if (sym->isGlobal) {
                emit("MOV EAX, [" + sym->name + "]");
            } else {
                emit("MOV EAX, [EBP" + (sym->offset >= 0 ? "+" + to_string(sym->offset) : to_string(sym->offset)) + "]");
            }
        }
        emit("CALL OUTDEC");
        return 0;
    }

    virtual any visitStmtReturn(CSubsetParser::StmtReturnContext *ctx) override {
        annotateLine(ctx);
        if (ctx->expression()) {
            visit(ctx->expression());
        }
        emit("JMP main_exit");
        return 0;
    }

    //  Expressions & Assignments 

    virtual any visitExprAssign(CSubsetParser::ExprAssignContext *ctx) override {
        annotateLine(ctx);
        visit(ctx->logic_expression());
        emit("PUSH EAX");

        auto* varSimple = dynamic_cast<CSubsetParser::VarSimpleContext*>(ctx->variable());
        string varName = varSimple->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        emit("POP EAX");
        if (sym) {
            if (sym->isGlobal) {
                emit("MOV [" + sym->name + "], EAX");
            } else {
                emit("MOV [EBP" + (sym->offset >= 0 ? "+" + to_string(sym->offset) : to_string(sym->offset)) + "], EAX");
            }
        }
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

    // Unary Expressions 

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

    // Factors 

    virtual any visitFactorConstInt(CSubsetParser::FactorConstIntContext *ctx) override {
        emit("MOV EAX, " + ctx->CONST_INT()->getText());
        return 0;
    }

    virtual any visitFactorVar(CSubsetParser::FactorVarContext *ctx) override {
        auto* varSimple = dynamic_cast<CSubsetParser::VarSimpleContext*>(ctx->variable());
        string varName = varSimple->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        if (sym) {
            if (sym->isGlobal) {
                emit("MOV EAX, [" + sym->name + "]");
            } else {
                emit("MOV EAX, [EBP" + (sym->offset >= 0 ? "+" + to_string(sym->offset) : to_string(sym->offset)) + "]");
            }
        }
        return 0;
    }

    virtual any visitFactorIncop(CSubsetParser::FactorIncopContext *ctx) override {
        auto* varSimple = dynamic_cast<CSubsetParser::VarSimpleContext*>(ctx->variable());
        string varName = varSimple->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        if (sym) {
            string varRef = sym->isGlobal ? "[" + sym->name + "]" : "[EBP" + (sym->offset >= 0 ? "+" + to_string(sym->offset) : to_string(sym->offset)) + "]";
            emit("MOV EAX, " + varRef);
            emit("INC dword " + varRef);
        }
        return 0;
    }

    virtual any visitFactorDecop(CSubsetParser::FactorDecopContext *ctx) override {
        auto* varSimple = dynamic_cast<CSubsetParser::VarSimpleContext*>(ctx->variable());
        string varName = varSimple->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        if (sym) {
            string varRef = sym->isGlobal ? "[" + sym->name + "]" : "[EBP" + (sym->offset >= 0 ? "+" + to_string(sym->offset) : to_string(sym->offset)) + "]";
            emit("MOV EAX, " + varRef);
            emit("DEC dword " + varRef);
        }
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