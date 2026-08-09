#pragma once

#include <iostream>
#include <fstream>
#include "CSubsetBaseVisitor.h"
#include "SymbolTable.h"

using namespace std;

extern ofstream lexLogFile;

ofstream xyz("xyz.txt");

int bucket_size = 7;
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

        string t = (left.type == "FLOAT" || right.type == "FLOAT") ? "FLOAT" : "INT";
        return ExprAttr{ .type = t };
    }


    any visitTerm(CSubsetParser::TermContext *ctx) override {

        if (!ctx->term()) return visit(ctx->unary_expression());

        ExprAttr left  = any_cast<ExprAttr>(visit(ctx->term()));
        ExprAttr right = any_cast<ExprAttr>(visit(ctx->unary_expression()));
        int line = ctx->getStart()->getLine();
        string op = ctx->MULOP()->getText();
  
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

        if (ctx->CONST_INT()) {
            return ExprAttr{ .type = "INT"};
        }
        if (ctx->CONST_FLOAT()) {
            return ExprAttr{ .type = "FLOAT"};
        }
        if (ctx->variable()) {
            return visit(ctx->variable());
        }
        if (ctx->LPAREN() && ctx->expression()) {
            ExprAttr a = any_cast<ExprAttr>(visit(ctx->expression()));
            return a;
        }
        if (ctx->variable()) {
            ExprAttr a = any_cast<ExprAttr>(visit(ctx->variable()));
            return a;
        }

    }


};

