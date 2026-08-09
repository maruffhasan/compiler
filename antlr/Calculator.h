
// Generated from Calculator.g4 by ANTLR 4.13.2

#pragma once


#include "CalculatorBaseVisitor.h"

using namespace std;

/**
 * This class provides an empty implementation of CalculatorVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  Calculator : public CalculatorBaseVisitor {
public:

  any visitStart(CalculatorParser::StartContext *ctx) override {
    return visit(ctx->expression());
  }

  any visitExprTerm(CalculatorParser::ExprTermContext *ctx) override {
    return visit(ctx->term());
  }

  any visitPlus(CalculatorParser::PlusContext *ctx) override {
    int expr = any_cast<int>(visit(ctx->expression()));
    int term = any_cast<int>(visit(ctx->term()));
    return expr + term;
  }

  any visitTimes(CalculatorParser::TimesContext *ctx) override {
    int term = any_cast<int>(visit(ctx->term()));
    int fact = any_cast<int>(visit(ctx->f));
    return term * fact;
  }

  any visitTermFact(CalculatorParser::TermFactContext *ctx) override {
    return visit(ctx->factor());
  }

  any visitParen(CalculatorParser::ParenContext *ctx) override {
    return visit(ctx->expression());
  }

  any visitFactorInt(CalculatorParser::FactorIntContext *ctx) override {
    return stoi(ctx->INT()->getText());
  }

};



