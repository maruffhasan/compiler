
// Generated from Calculator.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CalculatorVisitor.h"


/**
 * This class provides an empty implementation of CalculatorVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CalculatorBaseVisitor : public CalculatorVisitor {
public:

  virtual std::any visitStart(CalculatorParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprTerm(CalculatorParser::ExprTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPlus(CalculatorParser::PlusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTimes(CalculatorParser::TimesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTermFact(CalculatorParser::TermFactContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParen(CalculatorParser::ParenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorInt(CalculatorParser::FactorIntContext *ctx) override {
    return visitChildren(ctx);
  }


};

