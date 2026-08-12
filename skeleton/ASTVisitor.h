#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CSubsetBaseVisitor.h"
#include "SymbolTable.h"

using namespace std;

extern ofstream lexLogFile;

ofstream xyz("xyz.txt");

int bucket_size = 30;
SymbolTable sym_tab(bucket_size, xyz);



struct ExprAttr {
    string type = "INT";
    bool isArray = false;
    bool isFunctionCall = false;
    string funcName;
    string name;      // NEW -- needed to report "x is an array" by name
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

    vector<Param> collectParams (CSubsetParser::Parameter_listContext *ctx) {
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

    any visitCompound_statement(CSubsetParser::Compound_statementContext *ctx) override {
        sym_tab.EnterScope();

        if(ctx->statements()) visit(ctx->statements());

        sym_tab.ExitScope();
        return nullptr;
    }



    any visitVar_declaration(CSubsetParser::Var_declarationContext *ctx) override {
        currentDeclType_ = any_cast<string>(visit(ctx->type_specifier()));
        int line = ctx->getStart()->getLine();
        if (currentDeclType_ == "VOID") {
            logError(line, "Variable type cannot be void");
        }
        return visitChildren(ctx);
    }

    any visitType_specifier(CSubsetParser::Type_specifierContext *ctx) override {
        string type;
        if (ctx->INT()) type = "INT";
        if (ctx->FLOAT()) type = "FLOAT";
        if (ctx->VOID()) type = "VOID";
        return type;
    }

    // multiple declaration error detects

    any visitDeclaration_list(CSubsetParser::Declaration_listContext *ctx) override {

        string id = ctx->ID()->getText();
        int line = ctx->getStart()->getLine();

        SymbolInfo si(id, "ID", currentDeclType_);

        if (ctx->LTHIRD()) si.array = true; 
        if (ctx->CONST_FLOAT()) {
            logError(line, "Expression inside third brackets not an integer");
        }             
        
        if(!sym_tab.Insert(si)) {
            logError(line, "Multiple declaration of " + id);
        }

        return visitChildren(ctx);
    }



    // function declaration and definition 

    any visitFunc_declaration(CSubsetParser::Func_declarationContext *ctx) override {

        string retType = any_cast<string>(visit(ctx->type_specifier()));
        string name = ctx->ID()->getText();
        int line = ctx->getStart()->getLine();
 
        SymbolInfo *existing = sym_tab.LookUp(name);
        if (existing) {
            if (existing->type != "FUNCTION") {
                logError(line, "Multiple declaration of " + name);
            }
            // if already declared as a function, treat as harmless re-declaration
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
 
        return nullptr;
    }
 

    any visitFunc_definition(CSubsetParser::Func_definitionContext *ctx) override {
        string retType = any_cast<string>(visit(ctx->type_specifier()));
        string name = ctx->ID()->getText();
        int line = ctx->getStart()->getLine();
 
        vector<Param> params = collectParams(ctx->parameter_list());
 
        // detect duplicate parameter names; keep only the first occurrence for insertion
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
                doInsert = false; // this definition matches an earlier declaration
 
                if (existing->var_type != retType) {
                    logError(line, "Return type mismatch with function declaration in function " + name);
                }
 
                int expectedCount = existing->extra_count - 1; // slot 0 is the return type
                if (expectedCount != (int)paramTypes.size()) {
                    logError(line, "Total number of arguments mismatch with declaration in function " + name);
                }
            }
            // else: existing is a plain variable -> fall through to Insert() below,
            // which will fail and report a generic multiple-declaration error.
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
 
        // Parameters and the function body share ONE scope.
        sym_tab.EnterScope();
        for (auto &p : finalParams) {
            SymbolInfo psi(p.name, "ID", p.type);
            sym_tab.Insert(psi);
        }
 
        if (ctx->compound_statement() && ctx->compound_statement()->statements()) {
            visit(ctx->compound_statement()->statements());
        }
 
        sym_tab.ExitScope();
 
        return nullptr;
    }



    // definition error


    any visitExpression(CSubsetParser::ExpressionContext *ctx) override {

        if (!ctx->ASSIGNOP()) {
            return visit(ctx->logic_expression());
        }

        int line = ctx->getStart()->getLine();
        ExprAttr lhs = any_cast<ExprAttr>(visit(ctx->variable()));
        ExprAttr rhs = any_cast<ExprAttr>(visit(ctx->logic_expression()));

        if (lhs.valid && rhs.valid) {
            if (rhs.type == "VOID") {
                logError(line, "Void function used in expression");
            } else if (lhs.type == "INT" && rhs.type == "FLOAT") {
                logError(line, "Type Mismatch");   
            }
        }

        return lhs;
    }

    any visitVariable(CSubsetParser::VariableContext *ctx) override {
        string name = ctx->ID()->getText();
        int line = ctx->getStart()->getLine();
        auto sym = sym_tab.LookUp(name); 

        
        if (!sym) {
            logError(line, "Undeclared variable " + name);
            return ExprAttr{ .valid = false};
        }
        

        ExprAttr expAttr{.type = sym->var_type, .valid = true};


        if (ctx->LTHIRD()) { // x[12] = 
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
        } else { // x = 
            if (sym->array) {
                logError(line, "Type mismatch, " + name + " is an array");
                expAttr.valid = false;
            }
        }   

        return expAttr;
    }


    any visitSimple_expression(CSubsetParser::Simple_expressionContext *ctx) override {
        if (!ctx->simple_expression()) return visit(ctx->term());
        ExprAttr left  = any_cast<ExprAttr>(visit(ctx->simple_expression()));
        ExprAttr right = any_cast<ExprAttr>(visit(ctx->term()));

        if (left.type == "VOID" || right.type == "VOID") {
            int line = ctx->getStart()->getLine();
            logError(line, "Void function used in expression");
            return ExprAttr{ .valid = false };
        }

        string t = (left.type == "FLOAT" || right.type == "FLOAT") ? "FLOAT" : "INT";
        return ExprAttr{ .type = t };
    }


    any visitTerm(CSubsetParser::TermContext *ctx) override {

        if (!ctx->term()) return visit(ctx->unary_expression());

        ExprAttr left  = any_cast<ExprAttr>(visit(ctx->term()));
        ExprAttr right = any_cast<ExprAttr>(visit(ctx->unary_expression()));
        int line = ctx->getStart()->getLine();
        string op = ctx->MULOP()->getText();


        if (left.type == "VOID" || right.type == "VOID") {
            logError(line, "Void function used in expression");
            return ExprAttr{ .valid = false };
        }
  
        if (op == "%") {
            if (left.type != "INT" || right.type != "INT") {
                logError(line, "Non-Integer operand on modulus operator");
                return ExprAttr{ .valid = false};
            }
            if (ctx->unary_expression()->getText() == "0") {
                logError(line, "Modulus by Zero");
                return ExprAttr{ .valid = false};
            }
            return ExprAttr{ .type = "INT" };
        }
        string t = (left.type == "FLOAT" || right.type == "FLOAT") ? "FLOAT" : "INT";
        return ExprAttr{ .type = t };

    }

    any visitRel_expression(CSubsetParser::Rel_expressionContext *ctx) override {
        auto se = ctx->simple_expression();
        if (se.size() == 1) return visit(se[0]);
            
        visit(se[0]);
        visit(se[1]);
        return ExprAttr{ .type = "INT" };   
    }

    any visitLogic_expression(CSubsetParser::Logic_expressionContext *ctx) override {
        auto rels = ctx->rel_expression();
        if (rels.size() == 1) return visit(rels[0]);
       
        visit(rels[0]);
        visit(rels[1]);
        return ExprAttr{ .type = "INT" }; 
    }
    
    any visitUnary_expression(CSubsetParser::Unary_expressionContext *ctx) override {
        if (ctx->factor()) return visit(ctx->factor());
        ExprAttr a = any_cast<ExprAttr>(visit(ctx->unary_expression()));
        return a;  
    }


    any visitFactor(CSubsetParser::FactorContext *ctx) override {
        if (ctx->variable()) {
            ExprAttr a = any_cast<ExprAttr>(visit(ctx->variable()));
            return a;
        }
        if (ctx->argument_list()) {
            string name = ctx->ID()->getText();
            int line = ctx->getStart()->getLine();

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
 
            return ExprAttr{ .type = fn->var_type, .valid = true };
        }

        if (ctx->expression()) {
            ExprAttr a = any_cast<ExprAttr>(visit(ctx->expression()));
            return a;
        }
        if (ctx->CONST_INT()) {
            return ExprAttr{ .type = "INT"};
        }
        if (ctx->CONST_FLOAT()) {
            return ExprAttr{ .type = "FLOAT"};
        }

        return ExprAttr{ .valid = false};
    }
 

    // printf(ID) -- ID is a bare token here, not routed through `variable`
    any visitStatement(CSubsetParser::StatementContext *ctx) override {
        if (ctx->PRINTLN()) {
            string name = ctx->ID()->getText();
            int line = ctx->getStart()->getLine();
            if (!sym_tab.LookUp(name)) {
                logError(line, "Undeclared variable " + name);
            }
            return nullptr;
        }
        return visitChildren(ctx);
    }


};

