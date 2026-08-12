#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "CSubsetBaseVisitor.h"
#include "SymbolTable.h"

using namespace std;

extern ofstream lexLogFile;

int bucket_size = 30;
SymbolTable sym_tab(bucket_size, lexLogFile);

struct ExprAttr {
    string type = "INT";
    bool isArray = false;
    bool valid = true;
    string value;
};

struct Param {
    string type;
    string name;
    int line = 0;
};

class ASTVisitor : public CSubsetBaseVisitor {
private:
    ofstream &logFile;
    ofstream &errorFile;
    int errorCount = 0;

    string currentDeclType_;

    void logError(int line, const string &message) {
        errorCount++;
        string full = "Error at line " + to_string(line) + ": " + message;
        errorFile << full << "\n\n";
        logFile << full << "\n\n";
    }

    void log(int line, const string &ruleLHS, const string &ruleRHS, const string &text) {
        logFile << "Line " << to_string(line) << ": " << ruleLHS << " : " << ruleRHS << "\n\n";
        logFile << text << "\n\n\n";
    }

    vector<Param> collectParams(CSubsetParser::Parameter_listContext *ctx) {
        vector<Param> result;
        if (!ctx) return result;
        if (ctx->parameter_list()) 
            result = collectParams(ctx->parameter_list());
        
        Param p;
        p.type = any_cast<string>(visit(ctx->type_specifier()));
        p.name = ctx->ID() ? ctx->ID()->getText() : "";
        p.line = ctx->getStart()->getLine();
        result.push_back(p);
        return result;
    }

    void collectArgs(CSubsetParser::ArgumentsContext *ctx, vector<ExprAttr> &out) {
        if (!ctx) return;
        if (ctx->arguments()) collectArgs(ctx->arguments(), out);
        ExprAttr a = any_cast<ExprAttr>(visit(ctx->logic_expression()));
        out.push_back(a);
    }

public:
    ASTVisitor(ofstream &log, ofstream &err) 
        : logFile(log), errorFile(err) {}

    int getErrorCount() const { return errorCount; }

    // --- Root Node ---

    any visitStart(CSubsetParser::StartContext *ctx) override {
        visitChildren(ctx);
        int totalLines = ctx->getStop()->getLine();

        log(1, "start", "program", ctx->getText());

        sym_tab.PrintAllScopes();

        logFile << "Total lines: " << totalLines << "\n";
        logFile << "Total errors: " << errorCount << "\n";

        return nullptr;
    }

    any visitProgram(CSubsetParser::ProgramContext *ctx) override {
        int line = ctx->getStart()->getLine();
        if (ctx->program()) {
            visit(ctx->program());
            visit(ctx->unit());
            log(line, "program", "program unit", ctx->getText());
        } else {
            visit(ctx->unit());
            log(line, "program", "unit", ctx->getText());
        }
        return nullptr;
    }

    any visitUnit(CSubsetParser::UnitContext *ctx) override {
        int line = ctx->getStart()->getLine();
        visitChildren(ctx);
        if (ctx->var_declaration()) {
            log(line, "unit", "var_declaration", ctx->getText());
        } else if (ctx->func_declaration()) {
            log(line, "unit", "func_declaration", ctx->getText());
        } else if (ctx->func_definition()) {
            log(line, "unit", "func_definition", ctx->getText());
        }
        return nullptr;
    }

    // --- Declarations & Types ---

    any visitType_specifier(CSubsetParser::Type_specifierContext *ctx) override {
        int line = ctx->getStart()->getLine();
        string type;
        if (ctx->INT()) type = "INT";
        else if (ctx->FLOAT()) type = "FLOAT";
        else if (ctx->VOID()) type = "VOID";
        log(line, "type_specifier", type, ctx->getText());
        return type;
    }

    any visitDeclaration_list(CSubsetParser::Declaration_listContext *ctx) override {
        int line = ctx->getStart()->getLine();
        string id = ctx->ID() ? ctx->ID()->getText() : "";

        if (ctx->declaration_list()) {
            visit(ctx->declaration_list());
            if (ctx->LTHIRD()) {
                log(line, "declaration_list", "declaration_list COMMA ID LTHIRD CONST_INT RTHIRD", ctx->getText());
            } else {
                log(line, "declaration_list", "declaration_list COMMA ID", ctx->getText());
            }
        } else {
            if (ctx->LTHIRD()) {
                log(line, "declaration_list", "ID LTHIRD CONST_INT RTHIRD", ctx->getText());
            } else {
                log(line, "declaration_list", "ID", ctx->getText());
            }
        }

        if (ctx->ADDOP()) {
            logError(line, "syntax error, unexpected token(s) '" + ctx->ADDOP()->getText() + id + "' in declaration list");
            return nullptr;
        }

        SymbolInfo si(id, "ID", currentDeclType_);
        if (ctx->LTHIRD()) si.array = true; 
        if (ctx->CONST_FLOAT()) {
            logError(line, "Expression inside third brackets not an integer");
        }             
        
        if (!sym_tab.Insert(si)) {
            logError(line, "Multiple declaration of " + id);
        }

        return nullptr;
    }

    any visitVar_declaration(CSubsetParser::Var_declarationContext *ctx) override {
        int line = ctx->getStart()->getLine();
        currentDeclType_ = any_cast<string>(visit(ctx->type_specifier()));
        visit(ctx->declaration_list());

        if (currentDeclType_ == "VOID") {
            logError(line, "Variable type cannot be void");
        }

        log(line, "var_declaration", "type_specifier declaration_list SEMICOLON", ctx->getText());
        return nullptr;
    }

    // --- Functions ---

    any visitFunc_declaration(CSubsetParser::Func_declarationContext *ctx) override {
        string retType = any_cast<string>(visit(ctx->type_specifier()));
        string name = ctx->ID()->getText();
        int line = ctx->getStart()->getLine();
 
        SymbolInfo *existing = sym_tab.LookUp(name);
        if (existing) {
            if (existing->type != "FUNCTION") {
                logError(line, "Multiple declaration of " + name);
            }
            return nullptr;
        }

        vector<Param> params = collectParams(ctx->parameter_list());
        vector<string> paramTypes;
        for (auto &p : params) paramTypes.push_back(p.type);
 
        SymbolInfo si(name, "FUNCTION", retType);
        vector<string> extraTypes;
        extraTypes.push_back(retType);
        for (auto &t : paramTypes) extraTypes.push_back(t);
        si.set_extra(nullptr, extraTypes.data(), extraTypes.size());
        sym_tab.Insert(si);

        if (ctx->parameter_list()) {
            log(line, "func_declaration", "type_specifier ID LPAREN parameter_list RPAREN SEMICOLON", ctx->getText());
        } else {
            log(line, "func_declaration", "type_specifier ID LPAREN RPAREN SEMICOLON", ctx->getText());
        }
 
        return nullptr;
    }

    any visitFunc_definition(CSubsetParser::Func_definitionContext *ctx) override {
        string retType = any_cast<string>(visit(ctx->type_specifier()));
        string name = ctx->ID()->getText();
        int line = ctx->getStart()->getLine();
 
        vector<Param> params = collectParams(ctx->parameter_list());

        auto x = ctx->parameter_list();
        while (x) {
            if (x->ADDOP()) {
                logError(line, "syntax error, unexpected token(s) '" + x->ADDOP()->getText() + "'");    
            }
            x = x->parameter_list();
        }
 
        set<string> seen;
        vector<Param> finalParams;
        vector<string> paramTypes;
        int idx = 0;
        for (auto &p : params) {
            idx++;
            paramTypes.push_back(p.type);
            if (!p.name.empty()) {
                if (seen.count(p.name)) {
                    logError(line, "Multiple declaration of " + p.name + " in parameter");
                } else {
                    seen.insert(p.name);
                    finalParams.push_back(p);
                }
            } else {
                logError(line, to_string(idx) + "th parameter's name not given in function definition of " + name);
            }
        }
 
        SymbolInfo *existing = sym_tab.LookUp(name);
        bool doInsert = true;
 
        if (existing) {
            if (existing->type == "FUNCTION") {
                doInsert = false;
                if (existing->var_type != retType) {
                    logError(line, "Return type mismatch with function declaration in function " + name);
                }
                int expectedCount = existing->extra_count - 1;
                if (expectedCount != (int)paramTypes.size()) {
                    logError(line, "Total number of arguments mismatch with declaration in function " + name);
                }
            }
        }
 
        if (doInsert) {
            SymbolInfo si(name, "FUNCTION", retType);
            vector<string> extraTypes;
            extraTypes.push_back(retType);
            for (auto &t : paramTypes) extraTypes.push_back(t);
            si.set_extra(nullptr, extraTypes.data(), extraTypes.size());
            if (!sym_tab.Insert(si)) {
                logError(line, "Multiple declaration of " + name);
            }
        }
 
        sym_tab.EnterScope();
        for (auto &p : finalParams) {
            SymbolInfo psi(p.name, "ID", p.type);
            sym_tab.Insert(psi);
        }
 
        if (ctx->compound_statement()) {
            visit(ctx->compound_statement());
        }
        
        sym_tab.PrintAllScopes();
        sym_tab.ExitScope();

        if (ctx->parameter_list()) {
            log(line, "func_definition", "type_specifier ID LPAREN parameter_list RPAREN compound_statement", ctx->getText());
        } else {
            log(line, "func_definition", "type_specifier ID LPAREN RPAREN compound_statement", ctx->getText());
        }
 
        return nullptr;
    }

    // --- Compound Statements & Statements ---

    any visitCompound_statement(CSubsetParser::Compound_statementContext *ctx) override {
        int line = ctx->getStart()->getLine();
        sym_tab.EnterScope();

        if (ctx->statements()) {
            visit(ctx->statements());
            log(line, "compound_statement", "LCURL statements RCURL", ctx->getText());
        } else {
            log(line, "compound_statement", "LCURL RCURL", ctx->getText());
        }

        sym_tab.PrintAllScopes();
        sym_tab.ExitScope();
        return nullptr;
    }

    any visitStatements(CSubsetParser::StatementsContext *ctx) override {
        int line = ctx->getStart()->getLine();
        if (ctx->statements()) {
            visit(ctx->statements());
            visit(ctx->statement());
            log(line, "statements", "statements statement", ctx->getText());
        } else {
            visit(ctx->statement());
            log(line, "statements", "statement", ctx->getText());
        }
        return nullptr;
    }

    any visitStatement(CSubsetParser::StatementContext *ctx) override {
        int line = ctx->getStart()->getLine();
        if (ctx->PRINTLN()) {
            string name = ctx->ID()->getText();
            if (!sym_tab.LookUp(name)) {
                logError(line, "Undeclared variable " + name);
            }
            log(line, "statement", "PRINTLN LPAREN ID RPAREN SEMICOLON", ctx->getText());
            return nullptr;
        } else if (ctx->RETURN()) {
            visit(ctx->expression());
            log(line, "statement", "RETURN expression SEMICOLON", ctx->getText());
            return nullptr;
        } else if (ctx->var_declaration()) {
            visit(ctx->var_declaration());
            log(line, "statement", "var_declaration", ctx->getText());
            return nullptr;
        } else if (!ctx->expression_statement().empty()) {
            visit(ctx->expression_statement(0));
            log(line, "statement", "expression_statement", ctx->getText());
            return nullptr;
        } else if (ctx->compound_statement()) {
            visit(ctx->compound_statement());
            log(line, "statement", "compound_statement", ctx->getText());
            return nullptr;
        }
        return visitChildren(ctx);
    }

    any visitExpression_statement(CSubsetParser::Expression_statementContext *ctx) override {
        int line = ctx->getStart()->getLine();

        if (!ctx->SEMICOLON()) {
            string expr = ctx->expression() ? ctx->expression()->getText() : "";
            if (expr.length() > 1 && expr[expr.length() - 1] == '=') {
                expr = expr.substr(0, expr.length() - 2);
            }
            logError(line, "syntax error, missing ';' after expression '" + expr + "'");
            log(line, "expression_statement", "expression (missing SEMICOLON)", ctx->getText());
        } else if (ctx->expression()) {
            visit(ctx->expression());
            log(line, "expression_statement", "expression SEMICOLON", ctx->getText());
        } else {
            log(line, "expression_statement", "SEMICOLON", ctx->getText());
        }

        return nullptr;
    }

    // --- Expressions & Precedence ---

    any visitExpression(CSubsetParser::ExpressionContext *ctx) override {
        int line = ctx->getStart()->getLine();
        if (!ctx->ASSIGNOP()) {
            ExprAttr res = any_cast<ExprAttr>(visit(ctx->logic_expression()));
            log(line, "expression", "logic expression", ctx->getText());
            return res;
        }

        ExprAttr lhs = any_cast<ExprAttr>(visit(ctx->variable()));
        ExprAttr rhs = any_cast<ExprAttr>(visit(ctx->logic_expression()));

        if (lhs.valid && rhs.valid) {
            if (rhs.type == "VOID") {
                logError(line, "Void function used in expression");
            } else if (lhs.type == "INT" && rhs.type == "FLOAT") {
                logError(line, "Type Mismatch");   
            }
        }

        log(line, "expression", "variable ASSIGNOP logic_expression", ctx->getText());
        return lhs;
    }

    any visitVariable(CSubsetParser::VariableContext *ctx) override {
        string name = ctx->ID()->getText();
        int line = ctx->getStart()->getLine();
        auto sym = sym_tab.LookUp(name); 

        if (!sym) {
            logError(line, "Undeclared variable " + name);
            return ExprAttr{ .valid = false };
        }

        ExprAttr expAttr{ .type = sym->var_type, .valid = true };

        if (ctx->LTHIRD()) {
            expAttr.isArray = true;
            if (!sym->array) {
                logError(line, name + " is not an array");
                expAttr.valid = false;
            }

            ExprAttr idx = any_cast<ExprAttr>(visit(ctx->expression()));
            if (idx.type != "INT") {
                logError(line, "Expression inside third brackets not an integer");
                expAttr.valid = false;
            }
            log(line, "variable", "ID LTHIRD expression RTHIRD", ctx->getText());
        } else {
            if (sym->array) {
                logError(line, "Type mismatch, " + name + " is an array");
                expAttr.valid = false;
            }
            log(line, "variable", "ID", ctx->getText());
        }   

        return expAttr;
    }

    any visitLogic_expression(CSubsetParser::Logic_expressionContext *ctx) override {
        int line = ctx->getStart()->getLine();
        auto rels = ctx->rel_expression();
        if (rels.size() == 1) {
            ExprAttr res = any_cast<ExprAttr>(visit(rels[0]));
            log(line, "logic_expression", "rel_expression", ctx->getText());
            return res;
        }

        visit(rels[0]);
        visit(rels[1]);
        log(line, "logic_expression", "rel_expression LOGICOP rel_expression", ctx->getText());
        return ExprAttr{ .type = "INT" }; 
    }

    any visitRel_expression(CSubsetParser::Rel_expressionContext *ctx) override {
        int line = ctx->getStart()->getLine();
        auto se = ctx->simple_expression();
        if (se.size() == 1) {
            ExprAttr res = any_cast<ExprAttr>(visit(se[0]));
            log(line, "rel_expression", "simple_expression", ctx->getText());
            return res;
        }

        visit(se[0]);
        visit(se[1]);
        log(line, "rel_expression", "simple_expression RELOP simple_expression", ctx->getText());
        return ExprAttr{ .type = "INT" };   
    }

    any visitSimple_expression(CSubsetParser::Simple_expressionContext *ctx) override {
        int line = ctx->getStart()->getLine();

        if (!ctx->simple_expression()) {
            ExprAttr res = any_cast<ExprAttr>(visit(ctx->term()));
            log(line, "simple_expression", "term", ctx->getText());
            return res;
        }

        ExprAttr left = any_cast<ExprAttr>(visit(ctx->simple_expression()));

        if (ctx->ASSIGNOP()) {
            logError(line, "syntax error, invalid operand '=' after '" + ctx->ADDOP()->getText() + "'");
            return ExprAttr{ .type = left.type };
        }

        ExprAttr right = any_cast<ExprAttr>(visit(ctx->term()));

        if (left.type == "VOID" || right.type == "VOID") {
            logError(line, "Void function used in expression");
            return ExprAttr{ .valid = false };
        }

        string t = (left.type == "FLOAT" || right.type == "FLOAT") ? "FLOAT" : "INT";
        log(line, "simple_expression", "simple_expression ADDOP term", ctx->getText());
        return ExprAttr{ .type = t };
    }

    any visitTerm(CSubsetParser::TermContext *ctx) override {
        int line = ctx->getStart()->getLine();

        if (!ctx->term()) {
            ExprAttr res = any_cast<ExprAttr>(visit(ctx->unary_expression()));
            log(line, "term", "unary_expression", ctx->getText());
            return res;
        }

        ExprAttr left = any_cast<ExprAttr>(visit(ctx->term()));
        ExprAttr right = any_cast<ExprAttr>(visit(ctx->unary_expression()));
        string op = ctx->MULOP()->getText();

        if (left.type == "VOID" || right.type == "VOID") {
            logError(line, "Void function used in expression");
            return ExprAttr{ .valid = false };
        }

        if (op == "%") {
            if (left.type != "INT" || right.type != "INT") {
                logError(line, "Non-Integer operand on modulus operator");
                return ExprAttr{ .valid = false };
            }
            if (ctx->unary_expression()->getText() == "0") {
                logError(line, "Modulus by Zero");
                return ExprAttr{ .valid = false };
            }
            log(line, "term", "term MULOP unary_expression", ctx->getText());
            return ExprAttr{ .type = "INT" };
        }

        string t = (left.type == "FLOAT" || right.type == "FLOAT") ? "FLOAT" : "INT";
        log(line, "term", "term MULOP unary_expression", ctx->getText());
        return ExprAttr{ .type = t };
    }

    any visitUnary_expression(CSubsetParser::Unary_expressionContext *ctx) override {
        int line = ctx->getStart()->getLine();
        if (ctx->factor()) {
            ExprAttr res = any_cast<ExprAttr>(visit(ctx->factor()));
            log(line, "unary_expression", "factor", ctx->getText());
            return res;
        }

        ExprAttr a = any_cast<ExprAttr>(visit(ctx->unary_expression()));
        if (ctx->ADDOP()) {
            log(line, "unary_expression", "ADDOP unary_expression", ctx->getText());
        } else if (ctx->NOT()) {
            log(line, "unary_expression", "NOT unary_expression", ctx->getText());
        }
        return a;  
    }

    any visitFactor(CSubsetParser::FactorContext *ctx) override {
        int line = ctx->getStart()->getLine();

        if (ctx->variable()) {
            ExprAttr a = any_cast<ExprAttr>(visit(ctx->variable()));
            log(line, "factor", "variable", ctx->getText());
            return a;
        }

        if (ctx->argument_list()) {
            string name = ctx->ID()->getText();
            vector<ExprAttr> args;
            if (ctx->argument_list()->arguments()) {
                collectArgs(ctx->argument_list()->arguments(), args);
            }

            SymbolInfo *fn = sym_tab.LookUp(name);
            if (!fn || fn->type != "FUNCTION") {
                logError(line, "Undeclared function " + name);
                return ExprAttr{ .valid = false };
            }

            int expectedCount = fn->extra_count - 1;
            if ((int)args.size() != expectedCount) {
                logError(line, "Total number of arguments mismatch in function " + name);
            } else {
                for (int i = 0; i < expectedCount; i++) {
                    string expectedType = fn->extra_types[i + 1];
                    if (args[i].valid && args[i].type != expectedType) {
                        logError(line, to_string(i + 1) + "th argument mismatch in function " + name);
                        break;
                    }
                }
            }

            log(line, "factor", "ID LPAREN argument_list RPAREN", ctx->getText());
            return ExprAttr{ .type = fn->var_type, .valid = true };
        }

        if (ctx->expression()) {
            ExprAttr a = any_cast<ExprAttr>(visit(ctx->expression()));
            log(line, "factor", "LPAREN expression RPAREN", ctx->getText());
            return a;
        }

        if (ctx->CONST_INT()) {
            log(line, "factor", "CONST_INT", ctx->getText());
            return ExprAttr{ .type = "INT" };
        }

        if (ctx->CONST_FLOAT()) {
            log(line, "factor", "CONST_FLOAT", ctx->getText());
            return ExprAttr{ .type = "FLOAT" };
        }

        return ExprAttr{ .valid = false };
    }
};