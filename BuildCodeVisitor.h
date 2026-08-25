#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include "antlr4-runtime.h"
#include "CSubsetBaseVisitor.h"
#include "SymbolTable.h"

class BuildCodeVisitor : public CSubsetBaseVisitor {
private:
    std::ofstream asmFile;
    SymbolTable* symbolTable;
    
    int currentLocalOffset = -4;
    int labelCount = 0;
    bool isGlobalScope = true;

    std::string newLabel(const std::string& prefix) {
        return prefix + "_" + std::to_string(labelCount++);
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

    void handleFuncDefinition(const std::string& funcName, CSubsetParser::Parameter_listContext* paramCtx, CSubsetParser::Compound_statementContext* bodyCtx) {
        isGlobalScope = false;
        currentLocalOffset = -4;

        asmFile << "\nsegment readable executable\n";
        emitLabel(funcName);
        
        // Function Prologue
        emit("PUSH EBP");
        emit("MOV EBP, ESP");
        emit("SUB ESP, 128");

        symbolTable->EnterScope();

        if (paramCtx) {
            int paramOffset = 8;
            auto currParam = paramCtx;
            std::vector<std::string> paramNames;

            // Extract parameter names traversing left-recursive tree
            std::function<void(antlr4::ParserRuleContext*)> collectParams = [&](antlr4::ParserRuleContext* ctx) {
                if (!ctx) return;
                for (auto* child : ctx->children) {
                    if (auto* p = dynamic_cast<CSubsetParser::Parameter_listContext*>(child)) {
                        collectParams(p);
                    }
                }
                auto terminal = dynamic_cast<antlr4::tree::TerminalNode*>(ctx->children.back());
                if (ctx->children.size() >= 2 && terminal && terminal->getSymbol()->getType() == CSubsetParser::ID) {
                    paramNames.push_back(terminal->getText());
                }
            };
            collectParams(currParam);

            for (const auto& name : paramNames) {
                SymbolInfo si(name, "VAR", "INT");
                si.isGlobal = false;
                si.offset = paramOffset;
                symbolTable->Insert(si);
                paramOffset += 4;
            }
        }

        if (bodyCtx) {
            visit(bodyCtx);
        }

        symbolTable->ExitScope();

        // Function Epilogue
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
    BuildCodeVisitor(const std::string& filename, std::ofstream& logout) {
        asmFile.open(filename);
        symbolTable = new SymbolTable(11, logout);
        
        // FASM Executable Header
        asmFile << "format ELF executable 3\nentry main\n\n";
    }

    ~BuildCodeVisitor() {
        if (asmFile.is_open()) {
            emitOutdecProcedure();
            asmFile.close();
        }
        delete symbolTable;
    }

    void emit(const std::string& code) { asmFile << "\t" << code << "\n"; }
    void emitLabel(const std::string& label) { asmFile << label << ":\n"; }

    // --- Declarations ---

    virtual std::any visitDeclListSingleId(CSubsetParser::DeclListSingleIdContext *ctx) override {
        processVariableDeclaration(ctx->ID()->getText(), false, 1);
        return 0;
    }

    virtual std::any visitDeclListSingleArray(CSubsetParser::DeclListSingleArrayContext *ctx) override {
        int size = std::stoi(ctx->CONST_INT()->getText());
        processVariableDeclaration(ctx->ID()->getText(), true, size);
        return 0;
    }

    virtual std::any visitDeclListCommaId(CSubsetParser::DeclListCommaIdContext *ctx) override {
        visit(ctx->declaration_list());
        processVariableDeclaration(ctx->ID()->getText(), false, 1);
        return 0;
    }

    virtual std::any visitDeclListCommaArray(CSubsetParser::DeclListCommaArrayContext *ctx) override {
        visit(ctx->declaration_list());
        int size = std::stoi(ctx->CONST_INT()->getText());
        processVariableDeclaration(ctx->ID()->getText(), true, size);
        return 0;
    }

    // --- Function Definitions ---

    virtual std::any visitFuncDefWithParams(CSubsetParser::FuncDefWithParamsContext *ctx) override {
        handleFuncDefinition(ctx->ID()->getText(), ctx->parameter_list(), ctx->compound_statement());
        return 0;
    }

    virtual std::any visitFuncDefNoParams(CSubsetParser::FuncDefNoParamsContext *ctx) override {
        handleFuncDefinition(ctx->ID()->getText(), nullptr, ctx->compound_statement());
        return 0;
    }

    // --- Statements ---

    virtual std::any visitStmtPrintln(CSubsetParser::StmtPrintlnContext *ctx) override {
        std::string varName = ctx->ID()->getText();
        SymbolInfo* sym = symbolTable->LookUp(varName);

        if (sym) {
            if (sym->isGlobal) {
                emit("MOV EAX, [" + sym->name + "]");
            } else {
                emit("MOV EAX, [EBP" + (sym->offset >= 0 ? "+" + std::to_string(sym->offset) : std::to_string(sym->offset)) + "]");
            }
        } else {
            emit("MOV EAX, [EBP-4]");
        }
        emit("CALL OUTDEC");
        return 0;
    }

    virtual std::any visitStmtReturn(CSubsetParser::StmtReturnContext *ctx) override {
        if (ctx->expression()) {
            visit(ctx->expression());
        }
        emit("JMP main_exit");
        return 0;
    }

    virtual std::any visitStmtIf(CSubsetParser::StmtIfContext *ctx) override {
        std::string endLabel = newLabel("L_endif");

        visit(ctx->expression());
        emit("CMP EAX, 0");
        emit("JE " + endLabel);

        visit(ctx->statement());
        emitLabel(endLabel);
        return 0;
    }

    virtual std::any visitStmtIfElse(CSubsetParser::StmtIfElseContext *ctx) override {
        std::string elseLabel = newLabel("L_else");
        std::string endLabel = newLabel("L_endif");

        visit(ctx->expression());
        emit("CMP EAX, 0");
        emit("JE " + elseLabel);

        visit(ctx->statement(0));
        emit("JMP " + endLabel);

        emitLabel(elseLabel);
        visit(ctx->statement(1));

        emitLabel(endLabel);
        return 0;
    }

    virtual std::any visitStmtWhile(CSubsetParser::StmtWhileContext *ctx) override {
        std::string startLabel = newLabel("L_while_start");
        std::string endLabel = newLabel("L_while_end");

        emitLabel(startLabel);
        visit(ctx->expression());
        emit("CMP EAX, 0");
        emit("JE " + endLabel);

        visit(ctx->statement());
        emit("JMP " + startLabel);

        emitLabel(endLabel);
        return 0;
    }

    virtual std::any visitStmtFor(CSubsetParser::StmtForContext *ctx) override {
        std::string startLabel = newLabel("L_for_start");
        std::string endLabel = newLabel("L_for_end");

        if (ctx->expression_statement(0)) {
            visit(ctx->expression_statement(0));
        }

        emitLabel(startLabel);

        if (ctx->expression_statement(1)) {
            visit(ctx->expression_statement(1));
            emit("CMP EAX, 0");
            emit("JE " + endLabel);
        }

        visit(ctx->statement());

        if (ctx->expression()) {
            visit(ctx->expression());
        }

        emit("JMP " + startLabel);
        emitLabel(endLabel);
        return 0;
    }

    // --- Expressions & Assignments ---

    virtual std::any visitExprAssign(CSubsetParser::ExprAssignContext *ctx) override {
        visit(ctx->logic_expression());
        emit("PUSH EAX");

        if (auto* varSimple = dynamic_cast<CSubsetParser::VarSimpleContext*>(ctx->variable())) {
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
        } else if (auto* varArray = dynamic_cast<CSubsetParser::VarArrayContext*>(ctx->variable())) {
            std::string varName = varArray->ID()->getText();
            SymbolInfo* sym = symbolTable->LookUp(varName);

            visit(varArray->expression());
            emit("MOV EDX, EAX");
            emit("POP EAX");

            if (sym && sym->isGlobal) {
                emit("MOV [" + sym->name + " + EDX*4], EAX");
            } else if (sym) {
                emit("NEG EDX");
                emit("LEA ECX, [EBP" + std::to_string(sym->offset) + "]");
                emit("MOV [ECX + EDX*4], EAX");
            }
        }
        return 0;
    }

    // --- Arithmetic & Logical Operations ---

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

    virtual std::any visitLogicOp(CSubsetParser::LogicOpContext *ctx) override {
        visit(ctx->rel_expression(0)); // LHS in EAX
        emit("CMP EAX, 0");
        emit("SETNE AL");             // AL = 1 if EAX != 0, else 0
        emit("MOVZX EAX, AL");
        emit("PUSH EAX");

        visit(ctx->rel_expression(1)); // RHS in EAX
        emit("CMP EAX, 0");
        emit("SETNE AL");             // AL = 1 if EAX != 0, else 0
        emit("MOVZX EAX, AL");
        emit("POP EBX");              // LHS in EBX

        std::string op = ctx->LOGICOP()->getText();
        if (op == "&&") {
            emit("AND EAX, EBX");      // Both must be 1
        } else if (op == "||") {
            emit("OR EAX, EBX");       // Either can be 1
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

    // --- Factors ---

    virtual std::any visitFactorConstInt(CSubsetParser::FactorConstIntContext *ctx) override {
        emit("MOV EAX, " + ctx->CONST_INT()->getText());
        return 0;
    }

    virtual std::any visitFactorVar(CSubsetParser::FactorVarContext *ctx) override {
        if (auto* varSimple = dynamic_cast<CSubsetParser::VarSimpleContext*>(ctx->variable())) {
            std::string varName = varSimple->ID()->getText();
            SymbolInfo* sym = symbolTable->LookUp(varName);

            if (sym) {
                if (sym->isGlobal) {
                    emit("MOV EAX, [" + sym->name + "]");
                } else {
                    emit("MOV EAX, [EBP" + (sym->offset >= 0 ? "+" + std::to_string(sym->offset) : std::to_string(sym->offset)) + "]");
                }
            }
        } else if (auto* varArray = dynamic_cast<CSubsetParser::VarArrayContext*>(ctx->variable())) {
            std::string varName = varArray->ID()->getText();
            SymbolInfo* sym = symbolTable->LookUp(varName);

            visit(varArray->expression());
            if (sym && sym->isGlobal) {
                emit("MOV EAX, [" + sym->name + " + EAX*4]");
            } else if (sym) {
                emit("NEG EAX");
                emit("LEA ECX, [EBP" + std::to_string(sym->offset) + "]");
                emit("MOV EAX, [ECX + EAX*4]");
            }
        }
        return 0;
    }

    virtual std::any visitFactorIncop(CSubsetParser::FactorIncopContext *ctx) override {
        if (auto* varSimple = dynamic_cast<CSubsetParser::VarSimpleContext*>(ctx->variable())) {
            std::string varName = varSimple->ID()->getText();
            SymbolInfo* sym = symbolTable->LookUp(varName);

            if (sym) {
                std::string varRef = sym->isGlobal ? "[" + sym->name + "]" : "[EBP" + (sym->offset >= 0 ? "+" + std::to_string(sym->offset) : std::to_string(sym->offset)) + "]";
                emit("MOV EAX, " + varRef);
                emit("INC dword " + varRef);
            }
        }
        return 0;
    }

    virtual std::any visitFactorDecop(CSubsetParser::FactorDecopContext *ctx) override {
        if (auto* varSimple = dynamic_cast<CSubsetParser::VarSimpleContext*>(ctx->variable())) {
            std::string varName = varSimple->ID()->getText();
            SymbolInfo* sym = symbolTable->LookUp(varName);

            if (sym) {
                std::string varRef = sym->isGlobal ? "[" + sym->name + "]" : "[EBP" + (sym->offset >= 0 ? "+" + std::to_string(sym->offset) : std::to_string(sym->offset)) + "]";
                emit("MOV EAX, " + varRef);
                emit("DEC dword " + varRef);
            }
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
};