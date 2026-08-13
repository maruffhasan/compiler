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
extern ofstream logFile;
extern ofstream errorFile;

int bucket_size = 30;
SymbolTable sym_tab(bucket_size, logFile);

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
        logFile << text << "\n\n";
    }

    void logBlock(int line, const string &ruleLHS, const string &ruleRHS, const string &text) {
        log(line, ruleLHS, ruleRHS, text);
        logFile << "\n";
    }

    string keyword(const string &type) {
        if (type == "INT") return "int";
        if (type == "FLOAT") return "float";
        if (type == "VOID") return "void";
        return "";
    }

    string specifierTypeName(CSubsetParser::Type_specifierContext *ctx) {
        if (!ctx) return "";
        if (ctx->INT()) return "INT";
        if (ctx->FLOAT()) return "FLOAT";
        return "VOID";
    }

    vector<Param> collectParams(CSubsetParser::Parameter_listContext *ctx) {
        vector<Param> result;
        if (!ctx) return result;
        if (ctx->parameter_list())
            result = collectParams(ctx->parameter_list());

        Param p;
        p.type = specifierTypeName(ctx->type_specifier());
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


    string compoundBody(CSubsetParser::Compound_statementContext *ctx, bool ownScope) {
        int line = ctx->getStart()->getLine();
        if (ownScope) sym_tab.EnterScope();

        string text;
        if (ctx->statements()) {
            string stmtsText = any_cast<string>(visit(ctx->statements()));
            text = "{\n" + stmtsText + "\n}";
            logBlock(line, "compound_statement", "LCURL statements RCURL", text);
        } else {
            text = "{}";
            logBlock(line, "compound_statement", "LCURL RCURL", text);
        }

        sym_tab.PrintAllScopes();
        if (ownScope) sym_tab.ExitScope();

        return text;
    }

public:
    ASTVisitor() {}

    // root node
    any visitStart(CSubsetParser::StartContext *ctx) override {
        visitChildren(ctx);
        int totalLines = ctx->getStop()->getLine();

        log(1, "start", "program", "");

        sym_tab.PrintAllScopes();

        logFile << "Total lines: " << totalLines << "\n";
        logFile << "Total errors: " << errorCount << "\n";

        return nullptr;
    }

    any visitProgram(CSubsetParser::ProgramContext *ctx) override {
        int line = ctx->getStart()->getLine();
        string text;
        if (ctx->program()) {
            string progText = any_cast<string>(visit(ctx->program()));
            string unitText = any_cast<string>(visit(ctx->unit()));
            text = progText + "\n\n" + unitText;
            logBlock(line, "program", "program unit", text);
        } else {
            text = any_cast<string>(visit(ctx->unit()));
            logBlock(line, "program", "unit", text);
        }
        return text;
    }

    any visitUnit(CSubsetParser::UnitContext *ctx) override {
        int line = ctx->getStart()->getLine();
        string text;
        if (ctx->var_declaration()) {
            text = any_cast<string>(visit(ctx->var_declaration()));
            logBlock(line, "unit", "var_declaration", text);
        } else if (ctx->func_declaration()) {
            text = any_cast<string>(visit(ctx->func_declaration()));
            logBlock(line, "unit", "func_declaration", text);
        } else if (ctx->func_definition()) {
            text = any_cast<string>(visit(ctx->func_definition()));
            logBlock(line, "unit", "func_definition", text);
        }
        return text;
    }

    // declarations and types 

    any visitVar_declaration(CSubsetParser::Var_declarationContext *ctx) override {
        int line = ctx->getStart()->getLine();
        currentDeclType_ = any_cast<string>(visit(ctx->type_specifier()));
        string declText = any_cast<string>(visit(ctx->declaration_list()));

        if (currentDeclType_ == "VOID") {
            logError(line, "Variable type cannot be void");
        }

        string text = keyword(currentDeclType_) + " " + declText + ";";
        log(line, "var_declaration", "type_specifier declaration_list SEMICOLON", text);
        return text;
    }

    any visitType_specifier(CSubsetParser::Type_specifierContext *ctx) override {
        int line = ctx->getStart()->getLine();
        string type = specifierTypeName(ctx);
        log(line, "type_specifier", type, keyword(type));
        return type;
    }

    any visitDeclaration_list(CSubsetParser::Declaration_listContext *ctx) override {
        int line = ctx->getStart()->getLine();
        string id = ctx->ID() ? ctx->ID()->getText() : "";

        if (ctx->ADDOP()) {
            string childText = any_cast<string>(visit(ctx->declaration_list()));
            logError(line, "syntax error, unexpected token(s) '" + ctx->ADDOP()->getText() + " " + id + "' in declaration list");
            return childText;
        }

        string bracket;
        if (ctx->LTHIRD()) {
            string idxText = ctx->CONST_INT() ? ctx->CONST_INT()->getText()
                            : ctx->CONST_FLOAT() ? ctx->CONST_FLOAT()->getText() : "";
            bracket = "[" + idxText + "]";
        }

        string text;
        if (ctx->declaration_list()) {
            string childText = any_cast<string>(visit(ctx->declaration_list()));
            text = childText + "," + id;
            if (ctx->LTHIRD()) {
                text += bracket;
                log(line, "declaration_list", "declaration_list COMMA ID LTHIRD CONST_INT RTHIRD", text);
            } else {
                log(line, "declaration_list", "declaration_list COMMA ID", text);
            }
        } else {
            text = id;
            if (ctx->LTHIRD()) {
                text += bracket;
                log(line, "declaration_list", "ID LTHIRD CONST_INT RTHIRD", text);
            } else {
                log(line, "declaration_list", "ID", text);
            }
        }

        SymbolInfo si(id, "ID", currentDeclType_);
        if (ctx->LTHIRD()) si.array = true;
        if (ctx->CONST_FLOAT()) {
            logError(line, "Expression inside third brackets not an integer");
        }

        if (!sym_tab.Insert(si)) {
            logError(line, "Multiple declaration of " + id);
        }

        return text;
    }

    // parameters 

    any visitParameter_list(CSubsetParser::Parameter_listContext *ctx) override {
        int line = ctx->getStart()->getLine();

        string prefix;
        if (ctx->parameter_list()) {
            prefix = any_cast<string>(visit(ctx->parameter_list())) + ",";
        }

        string typeText = any_cast<string>(visit(ctx->type_specifier()));
        string idPart = ctx->ID() ? (" " + ctx->ID()->getText()) : "";

        string text = prefix + keyword(typeText) + idPart;

        string rhs;
        if (ctx->parameter_list()) {
            if (ctx->ADDOP()) {
                rhs = ctx->ID() ? "parameter_list COMMA type_specifier ADDOP ID" : "parameter_list COMMA type_specifier ADDOP";
            } else {
                rhs = ctx->ID() ? "parameter_list COMMA type_specifier ID" : "parameter_list COMMA type_specifier";
            }
        } else {
            if (ctx->ADDOP()) {
                rhs = ctx->ID() ? "type_specifier ADDOP ID" : "type_specifier ADDOP";
            } else {
                rhs = ctx->ID() ? "type_specifier ID" : "type_specifier";
            }
        }

        log(line, "parameter_list", rhs, text);
        return text;
    }

    // functions 

    any visitFunc_declaration(CSubsetParser::Func_declarationContext *ctx) override {
        string retType = any_cast<string>(visit(ctx->type_specifier()));
        string name = ctx->ID()->getText();
        int line = ctx->getStart()->getLine();

        SymbolInfo *existing = sym_tab.LookUp(name);
        if (existing) {
            if (existing->type != "FUNCTION") {
                logError(line, "Multiple declaration of " + name);
            }
            return keyword(retType) + " " + name + "();";
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

        string paramText = ctx->parameter_list() ? any_cast<string>(visit(ctx->parameter_list())) : "";
        string text = keyword(retType) + " " + name + "(" + paramText + ");";

        if (ctx->parameter_list()) {
            logBlock(line, "func_declaration", "type_specifier ID LPAREN parameter_list RPAREN SEMICOLON", text);
        } else {
            logBlock(line, "func_declaration", "type_specifier ID LPAREN RPAREN SEMICOLON", text);
        }

        return text;
    }

    any visitFunc_definition(CSubsetParser::Func_definitionContext *ctx) override {
        string retType = any_cast<string>(visit(ctx->type_specifier()));
        string name = ctx->ID()->getText();
        int line = ctx->getStart()->getLine();

        vector<Param> params = collectParams(ctx->parameter_list());
        string paramText = ctx->parameter_list() ? any_cast<string>(visit(ctx->parameter_list())) : "";

        auto x = ctx->parameter_list();
        while (x) {
            if (x->ADDOP()) {
                logError(line, "syntax error, unexpected token(s) '" + x->ADDOP()->getText() + "' before ')'");
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

        string bodyText;
        if (ctx->compound_statement()) {
            bodyText = compoundBody(ctx->compound_statement(), false);
        }

        sym_tab.ExitScope();

        string text = keyword(retType) + " " + name + "(" + paramText + ")" + bodyText;

        if (ctx->parameter_list()) {
            logBlock(line, "func_definition", "type_specifier ID LPAREN parameter_list RPAREN compound_statement", text);
        } else {
            logBlock(line, "func_definition", "type_specifier ID LPAREN RPAREN compound_statement", text);
        }

        return text;
    }

    //  compound statements and statements 

    any visitCompound_statement(CSubsetParser::Compound_statementContext *ctx) override {
        return compoundBody(ctx, true);
    }

    any visitStatements(CSubsetParser::StatementsContext *ctx) override {
        int line = ctx->getStart()->getLine();
        string text;
        if (ctx->statements()) {
            string prevText = any_cast<string>(visit(ctx->statements()));
            string stmtText = any_cast<string>(visit(ctx->statement()));
            text = prevText + "\n" + stmtText;
            logBlock(line, "statements", "statements statement", text);
        } else {
            text = any_cast<string>(visit(ctx->statement()));
            logBlock(line, "statements", "statement", text);
        }
        return text;
    }

    any visitStatement(CSubsetParser::StatementContext *ctx) override {
        int line = ctx->getStart()->getLine();
        string text;

        if (ctx->PRINTLN()) {
            string name = ctx->ID()->getText();
            if (!sym_tab.LookUp(name)) {
                logError(line, "Undeclared variable " + name);
            }
            text = "println(" + name + ");";
            logBlock(line, "statement", "PRINTLN LPAREN ID RPAREN SEMICOLON", text);
        } else if (ctx->RETURN()) {
            ExprAttr res = any_cast<ExprAttr>(visit(ctx->expression()));
            text = "return " + res.value + ";";
            logBlock(line, "statement", "RETURN expression SEMICOLON", text);
        } else if (ctx->var_declaration()) {
            text = any_cast<string>(visit(ctx->var_declaration()));
            logBlock(line, "statement", "var_declaration", text);
        } else if (!ctx->expression_statement().empty()) {
            ExprAttr res = any_cast<ExprAttr>(visit(ctx->expression_statement(0)));
            text = res.value;
            logBlock(line, "statement", "expression_statement", text);
        } else if (ctx->compound_statement()) {
            text = any_cast<string>(visit(ctx->compound_statement()));
            logBlock(line, "statement", "compound_statement", text);
        } else if (ctx->FOR()) {
            ExprAttr e1 = any_cast<ExprAttr>(visit(ctx->expression_statement(0)));
            ExprAttr e2 = any_cast<ExprAttr>(visit(ctx->expression_statement(1)));
            ExprAttr e3 = any_cast<ExprAttr>(visit(ctx->expression()));
            string bodyText = any_cast<string>(visit(ctx->statement(0)));
            text = "for(" + e1.value + e2.value + e3.value + ")" + bodyText;
            logBlock(line, "statement", "FOR LPAREN expression_statement expression_statement expression RPAREN statement", text);
        } else if (ctx->IF() && ctx->ELSE()) {
            ExprAttr cond = any_cast<ExprAttr>(visit(ctx->expression()));
            string thenText = any_cast<string>(visit(ctx->statement(0)));
            string elseText = any_cast<string>(visit(ctx->statement(1)));
            text = "if(" + cond.value + ")" + thenText + "else" + elseText;
            logBlock(line, "statement", "IF LPAREN expression RPAREN statement ELSE statement", text);
        } else if (ctx->IF()) {
            ExprAttr cond = any_cast<ExprAttr>(visit(ctx->expression()));
            string thenText = any_cast<string>(visit(ctx->statement(0)));
            text = "if(" + cond.value + ")" + thenText;
            logBlock(line, "statement", "IF LPAREN expression RPAREN statement", text);
        } else if (ctx->WHILE()) {
            ExprAttr cond = any_cast<ExprAttr>(visit(ctx->expression()));
            string bodyText = any_cast<string>(visit(ctx->statement(0)));
            text = "while(" + cond.value + ")" + bodyText;
            logBlock(line, "statement", "WHILE LPAREN expression RPAREN statement", text);
        }

        return text;
    }

    any visitExpression_statement(CSubsetParser::Expression_statementContext *ctx) override {
        int line = ctx->getStart()->getLine();
        ExprAttr result;

        if (!ctx->SEMICOLON()) {
            string exprText;
            if (ctx->expression()) {
                ExprAttr res = any_cast<ExprAttr>(visit(ctx->expression()));
                exprText = res.value;
            }
            logError(line, "syntax error, missing ';' after expression '" + exprText + "'");
            log(line, "expression_statement", "expression (missing SEMICOLON)", exprText);
            result.value = exprText;
        } else if (ctx->expression()) {
            ExprAttr res = any_cast<ExprAttr>(visit(ctx->expression()));
            result.value = res.value + ";";
            log(line, "expression_statement", "expression SEMICOLON", result.value);
        } else {
            result.value = ";";
            log(line, "expression_statement", "SEMICOLON", result.value);
        }

        return result;
    }

    // expressions 

    any visitExpression(CSubsetParser::ExpressionContext *ctx) override {
        int line = ctx->getStart()->getLine();
        if (!ctx->ASSIGNOP()) {
            ExprAttr res = any_cast<ExprAttr>(visit(ctx->logic_expression()));
            log(line, "expression", "logic expression", res.value);
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

        ExprAttr result;
        result.type = lhs.type;
        result.valid = lhs.valid;
        result.value = lhs.value + "=" + rhs.value;
        log(line, "expression", "variable ASSIGNOP logic_expression", result.value);
        return result;
    }

    any visitVariable(CSubsetParser::VariableContext *ctx) override {
        string name = ctx->ID()->getText();
        int line = ctx->getStart()->getLine();
        auto sym = sym_tab.LookUp(name);

        if (!sym) {
            logError(line, "Undeclared variable " + name);
            return ExprAttr{ .valid = false, .value = name };
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
            expAttr.value = name + "[" + idx.value + "]";
            log(line, "variable", "ID LTHIRD expression RTHIRD", expAttr.value);
        } else {
            if (sym->array) {
                logError(line, "Type mismatch, " + name + " is an array");
                expAttr.valid = false;
            }
            expAttr.value = name;
            log(line, "variable", "ID", expAttr.value);
        }

        return expAttr;
    }

    any visitLogic_expression(CSubsetParser::Logic_expressionContext *ctx) override {
        int line = ctx->getStart()->getLine();
        auto rels = ctx->rel_expression();
        if (rels.size() == 1) {
            ExprAttr res = any_cast<ExprAttr>(visit(rels[0]));
            log(line, "logic_expression", "rel_expression", res.value);
            return res;
        }

        ExprAttr left = any_cast<ExprAttr>(visit(rels[0]));
        ExprAttr right = any_cast<ExprAttr>(visit(rels[1]));
        ExprAttr result;
        result.type = "INT";
        result.value = left.value + ctx->LOGICOP()->getText() + right.value;
        log(line, "logic_expression", "rel_expression LOGICOP rel_expression", result.value);
        return result;
    }

    any visitRel_expression(CSubsetParser::Rel_expressionContext *ctx) override {
        int line = ctx->getStart()->getLine();
        auto se = ctx->simple_expression();
        if (se.size() == 1) {
            ExprAttr res = any_cast<ExprAttr>(visit(se[0]));
            log(line, "rel_expression", "simple_expression", res.value);
            return res;
        }

        ExprAttr left = any_cast<ExprAttr>(visit(se[0]));
        ExprAttr right = any_cast<ExprAttr>(visit(se[1]));
        ExprAttr result;
        result.type = "INT";
        result.value = left.value + ctx->RELOP()->getText() + right.value;
        log(line, "rel_expression", "simple_expression RELOP simple_expression", result.value);
        return result;
    }

    any visitSimple_expression(CSubsetParser::Simple_expressionContext *ctx) override {
        int line = ctx->getStart()->getLine();

        if (!ctx->simple_expression()) {
            ExprAttr res = any_cast<ExprAttr>(visit(ctx->term()));
            log(line, "simple_expression", "term", res.value);
            return res;
        }

        ExprAttr left = any_cast<ExprAttr>(visit(ctx->simple_expression()));

        if (ctx->ASSIGNOP()) {
            logError(line, "syntax error, invalid operand '=' after '" + ctx->ADDOP()->getText() + "'");
            return ExprAttr{ .type = left.type, .value = left.value };
        }

        ExprAttr right = any_cast<ExprAttr>(visit(ctx->term()));

        if (left.type == "VOID" || right.type == "VOID") {
            logError(line, "Void function used in expression");
            return ExprAttr{ .valid = false };
        }

        string t = (left.type == "FLOAT" || right.type == "FLOAT") ? "FLOAT" : "INT";
        ExprAttr result;
        result.type = t;
        result.value = left.value + ctx->ADDOP()->getText() + right.value;
        log(line, "simple_expression", "simple_expression ADDOP term", result.value);
        return result;
    }

    any visitTerm(CSubsetParser::TermContext *ctx) override {
        int line = ctx->getStart()->getLine();

        if (!ctx->term()) {
            ExprAttr res = any_cast<ExprAttr>(visit(ctx->unary_expression()));
            log(line, "term", "unary_expression", res.value);
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
            ExprAttr result;
            result.type = "INT";
            result.value = left.value + op + right.value;

            if (left.type != "INT" || right.type != "INT") {
                logError(line, "Non-Integer operand on modulus operator");
                result.valid = false;
            }
            if (ctx->unary_expression()->getText() == "0") {
                logError(line, "Modulus by Zero");
                result.valid = false;
            }
            log(line, "term", "term MULOP unary_expression", result.value);
            return result;
        }

        string t = (left.type == "FLOAT" || right.type == "FLOAT") ? "FLOAT" : "INT";
        ExprAttr result;
        result.type = t;
        result.value = left.value + op + right.value;
        log(line, "term", "term MULOP unary_expression", result.value);
        return result;
    }

    any visitUnary_expression(CSubsetParser::Unary_expressionContext *ctx) override {
        int line = ctx->getStart()->getLine();
        if (ctx->factor()) {
            ExprAttr res = any_cast<ExprAttr>(visit(ctx->factor()));
            log(line, "unary_expression", "factor", res.value);
            return res;
        }

        ExprAttr a = any_cast<ExprAttr>(visit(ctx->unary_expression()));
        if (ctx->ADDOP()) {
            a.value = ctx->ADDOP()->getText() + a.value;
            log(line, "unary_expression", "ADDOP unary_expression", a.value);
        } else if (ctx->NOT()) {
            a.value = "!" + a.value;
            log(line, "unary_expression", "NOT unary_expression", a.value);
        }
        return a;
    }

    any visitFactor(CSubsetParser::FactorContext *ctx) override {
        int line = ctx->getStart()->getLine();

        if (ctx->variable()) {
            ExprAttr a = any_cast<ExprAttr>(visit(ctx->variable()));
            if (ctx->INCOP()) {
                a.value += "++";
                log(line, "factor", "variable INCOP", a.value);
            } else if (ctx->DECOP()) {
                a.value += "--";
                log(line, "factor", "variable DECOP", a.value);
            } else {
                log(line, "factor", "variable", a.value);
            }
            return a;
        }

        if (ctx->argument_list()) {
            string name = ctx->ID()->getText();
            vector<ExprAttr> args;
            if (ctx->argument_list()->arguments()) {
                collectArgs(ctx->argument_list()->arguments(), args);
            }

            string argsText;
            for (size_t i = 0; i < args.size(); i++) {
                if (i) argsText += ",";
                argsText += args[i].value;
            }
            string text = name + "(" + argsText + ")";

            SymbolInfo *fn = sym_tab.LookUp(name);
            if (!fn || fn->type != "FUNCTION") {
                logError(line, "Undeclared function " + name);
                return ExprAttr{ .valid = false, .value = text };
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

            log(line, "factor", "ID LPAREN argument_list RPAREN", text);
            return ExprAttr{ .type = fn->var_type, .valid = true, .value = text };
        }

        if (ctx->expression()) {
            ExprAttr a = any_cast<ExprAttr>(visit(ctx->expression()));
            a.value = "(" + a.value + ")";
            log(line, "factor", "LPAREN expression RPAREN", a.value);
            return a;
        }

        if (ctx->CONST_INT()) {
            string text = ctx->CONST_INT()->getText();
            log(line, "factor", "CONST_INT", text);
            return ExprAttr{ .type = "INT", .value = text };
        }

        if (ctx->CONST_FLOAT()) {
            string text = ctx->CONST_FLOAT()->getText();
            log(line, "factor", "CONST_FLOAT", text);
            return ExprAttr{ .type = "FLOAT", .value = text };
        }

        return ExprAttr{ .valid = false };
    }
};