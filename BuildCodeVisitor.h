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

class BuildCodeVisitor : public CSubsetBaseVisitor {
private:
    std::ofstream asmFile;
    std::string unoptimizedFileName;
    std::string optimizedFileName;
    SymbolTable* symbolTable;
    
    int currentLocalOffset = -4;
    int labelCount = 0;
    bool isGlobalScope = true;

    std::string newLabel(const std::string& prefix) {
        return prefix + "_" + std::to_string(labelCount++);
    }

    void annotateLine(antlr4::ParserRuleContext* ctx) {
        if (ctx && ctx->getStart()) {
            size_t line = ctx->getStart()->getLine();
            emit("; -- line " + std::to_string(line) + " --");
        }
    }

    void processVariableDeclaration(const std::string& varName, bool isArray, int arraySize) {
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

    void handleFuncDefinition(const std::string& funcName, CSubsetParser::Compound_statementContext* bodyCtx) {
        isGlobalScope = false;
        currentLocalOffset = -4;

        asmFile << "\nsegment readable executable\n";
        emitLabel(funcName);
        
        // Function Prologue
        emit("PUSH EBP");
        emit("MOV EBP, ESP");
        emit("SUB ESP, 128");

        symbolTable->EnterScope();

        if (bodyCtx) {
            visit(bodyCtx);
        }

        symbolTable->ExitScope();

        // Function Epilogue[cite: 2]
        std::string exitLabel = funcName + "_exit";
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
    BuildCodeVisitor(const std::string& codeAsmPath, const std::string& optAsmPath, std::ofstream& logout)
        : unoptimizedFileName(codeAsmPath), optimizedFileName(optAsmPath) {
        asmFile.open(unoptimizedFileName);
        symbolTable = new SymbolTable(11, logout);
        
        // FASM Linux Executable Header[cite: 2]
        asmFile << "format ELF executable 3\nentry main\n\n";
    }

    ~BuildCodeVisitor() {
        if (asmFile.is_open()) {
            emitOutdecProcedure();
            asmFile.close();
        }
        delete symbolTable;

        // Perform Peephole Optimization Pass[cite: 2]
        performOptimization();
    }

    void emit(const std::string& code) { asmFile << "\t" << code << "\n"; }
    void emitLabel(const std::string& label) { asmFile << label << ":\n"; }

    // --- Declarations ---

    virtual std::any visitDeclListSingleId(CSubsetParser::DeclListSingleIdContext *ctx) override {
        processVariableDeclaration(ctx->ID()->getText(), false, 1);
        return 0;
    }

    virtual std::any visitDeclListCommaId(CSubsetParser::DeclListCommaIdContext *ctx) override {
        visit(ctx->declaration_list());
        processVariableDeclaration(ctx->ID()->getText(), false, 1);
        return 0;
    }

    // --- Function Definitions ---

    virtual std::any visitFuncDefNoParams(CSubsetParser::FuncDefNoParamsContext *ctx) override {
        handleFuncDefinition(ctx->ID()->getText(), ctx->compound_statement());
        return 0;
    }

    // --- Statements ---

    virtual std::any visitStmtPrintln(CSubsetParser::StmtPrintlnContext *ctx) override {
        annotateLine(ctx);
        std::string varName = ctx->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        if (sym) {
            if (sym->isGlobal) {
                emit("MOV EAX, [" + sym->name + "]");
            } else {
                emit("MOV EAX, [EBP" + (sym->offset >= 0 ? "+" + std::to_string(sym->offset) : std::to_string(sym->offset)) + "]");
            }
        }
        emit("CALL OUTDEC");
        return 0;
    }

    virtual std::any visitStmtReturn(CSubsetParser::StmtReturnContext *ctx) override {
        annotateLine(ctx);
        if (ctx->expression()) {
            visit(ctx->expression());
        }
        emit("JMP main_exit");
        return 0;
    }

    // --- Expressions & Assignments ---

    virtual std::any visitExprAssign(CSubsetParser::ExprAssignContext *ctx) override {
        annotateLine(ctx);
        visit(ctx->logic_expression());
        emit("PUSH EAX");

        auto* varSimple = dynamic_cast<CSubsetParser::VarSimpleContext*>(ctx->variable());
        std::string varName = varSimple->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        emit("POP EAX");
        if (sym) {
            if (sym->isGlobal) {
                emit("MOV [" + sym->name + "], EAX");
            } else {
                emit("MOV [EBP" + (sym->offset >= 0 ? "+" + std::to_string(sym->offset) : std::to_string(sym->offset)) + "], EAX");
            }
        }
        return 0;
    }

    // Short-Circuit Implementation for Boolean Logical Expressions[cite: 2]
    virtual std::any visitLogicOp(CSubsetParser::LogicOpContext *ctx) override {
        std::string op = ctx->LOGICOP()->getText();
        std::string trueLabel = newLabel("L_bool_true");
        std::string falseLabel = newLabel("L_bool_false");
        std::string endLabel = newLabel("L_bool_end");

        if (op == "&&") {
            visit(ctx->rel_expression(0));
            emit("CMP EAX, 0");
            emit("JE " + falseLabel); // Short-circuit directly to false

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
            emit("JNE " + trueLabel); // Short-circuit directly to true

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

    virtual std::any visitRelOp(CSubsetParser::RelOpContext *ctx) override {
        visit(ctx->simple_expression(0));
        emit("PUSH EAX");
        visit(ctx->simple_expression(1));
        emit("POP EBX");

        emit("CMP EBX, EAX");
        std::string trueLabel = newLabel("L_rel_true");
        std::string endLabel = newLabel("L_rel_end");

        std::string relOp = ctx->RELOP()->getText();
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

    virtual std::any visitSimpleAddOp(CSubsetParser::SimpleAddOpContext *ctx) override {
        visit(ctx->term());
        emit("PUSH EAX");
        visit(ctx->simple_expression());
        emit("POP EBX");

        std::string op = ctx->ADDOP()->getText();
        if (op == "+") {
            emit("ADD EAX, EBX");
        } else if (op == "-") {
            emit("SUB EAX, EBX");
        }
        return 0;
    }

    virtual std::any visitTermMulOp(CSubsetParser::TermMulOpContext *ctx) override {
        visit(ctx->unary_expression());
        emit("PUSH EAX");
        visit(ctx->term());
        emit("POP EBX");

        std::string op = ctx->MULOP()->getText();
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

    // --- Unary Expressions ---

    virtual std::any visitUnaryAddOp(CSubsetParser::UnaryAddOpContext *ctx) override {
        visit(ctx->unary_expression());
        std::string op = ctx->ADDOP()->getText();
        if (op == "-") {
            emit("NEG EAX");
        }
        return 0;
    }

    virtual std::any visitUnaryNot(CSubsetParser::UnaryNotContext *ctx) override {
        visit(ctx->unary_expression());
        emit("CMP EAX, 0");
        emit("SETE AL");
        emit("MOVZX EAX, AL");
        return 0;
    }

    // --- Factors ---

    virtual std::any visitFactorConstInt(CSubsetParser::FactorConstIntContext *ctx) override {
        emit("MOV EAX, " + ctx->CONST_INT()->getText());
        return 0;
    }

    virtual std::any visitFactorVar(CSubsetParser::FactorVarContext *ctx) override {
        auto* varSimple = dynamic_cast<CSubsetParser::VarSimpleContext*>(ctx->variable());
        std::string varName = varSimple->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        if (sym) {
            if (sym->isGlobal) {
                emit("MOV EAX, [" + sym->name + "]");
            } else {
                emit("MOV EAX, [EBP" + (sym->offset >= 0 ? "+" + std::to_string(sym->offset) : std::to_string(sym->offset)) + "]");
            }
        }
        return 0;
    }

    virtual std::any visitFactorIncop(CSubsetParser::FactorIncopContext *ctx) override {
        auto* varSimple = dynamic_cast<CSubsetParser::VarSimpleContext*>(ctx->variable());
        std::string varName = varSimple->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        if (sym) {
            std::string varRef = sym->isGlobal ? "[" + sym->name + "]" : "[EBP" + (sym->offset >= 0 ? "+" + std::to_string(sym->offset) : std::to_string(sym->offset)) + "]";
            emit("MOV EAX, " + varRef);
            emit("INC dword " + varRef);
        }
        return 0;
    }

    virtual std::any visitFactorDecop(CSubsetParser::FactorDecopContext *ctx) override {
        auto* varSimple = dynamic_cast<CSubsetParser::VarSimpleContext*>(ctx->variable());
        std::string varName = varSimple->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        if (sym) {
            std::string varRef = sym->isGlobal ? "[" + sym->name + "]" : "[EBP" + (sym->offset >= 0 ? "+" + std::to_string(sym->offset) : std::to_string(sym->offset)) + "]";
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

    // Peephole Optimizer Implementation[cite: 2]
    void performOptimization() {
        std::ifstream inFile(unoptimizedFileName);
        if (!inFile.is_open()) return;

        std::vector<std::string> lines;
        std::string line;
        while (std::getline(inFile, line)) {
            lines.push_back(line);
        }
        inFile.close();

        std::vector<std::string> optimized;
        size_t n = lines.size();

        for (size_t i = 0; i < n; ++i) {
            std::string cur = lines[i];

            // Clean leading/trailing whitespaces for pattern checks
            std::string trimmed = std::regex_replace(cur, std::regex("^\\s+|\\s+$"), "");

            // 1. Remove redundant operations (e.g., ADD EAX, 0 or IMUL EAX, 1)[cite: 2]
            if (trimmed == "ADD EAX, 0" || trimmed == "SUB EAX, 0" || trimmed == "IMUL EAX, 1") {
                continue; // Redundant operation, skip line
            }

            // Lookahead check for instruction pairs
            if (i + 1 < n) {
                std::string nextLine = lines[i + 1];
                std::string trimmedNext = std::regex_replace(nextLine, std::regex("^\\s+|\\s+$"), "");

                // 2. Remove redundant MOV AX, a / MOV a, AX pairs[cite: 2]
                std::smatch m1, m2;
                std::regex movRegex("^MOV\\s+([^,]+),\\s*(.+)$");
                if (std::regex_match(trimmed, m1, movRegex) && std::regex_match(trimmedNext, m2, movRegex)) {
                    if (m1[1].str() == m2[2].str() && m1[2].str() == m2[1].str()) {
                        optimized.push_back(cur);
                        i++; // Skip redundant inverse MOV instruction
                        continue;
                    }
                }

                // 3. Remove redundant PUSH reg / POP reg pairs[cite: 2]
                std::regex pushRegex("^PUSH\\s+(.+)$");
                std::regex popRegex("^POP\\s+(.+)$");
                if (std::regex_match(trimmed, m1, pushRegex) && std::regex_match(trimmedNext, m2, popRegex)) {
                    if (m1[1].str() == m2[1].str()) {
                        i++; // Skip both PUSH and POP
                        continue;
                    }
                }

                // 4. Remove redundant labels[cite: 2]
                if (!trimmed.empty() && trimmed.back() == ':' && !trimmedNext.empty() && trimmedNext.back() == ':') {
                    // Two consecutive labels found, combine/skip first label
                    continue;
                }
            }

            optimized.push_back(cur);
        }

        std::ofstream outFile(optimizedFileName);
        for (const auto& optLine : optimized) {
            outFile << optLine << "\n";
        }
        outFile.close();
    }
};