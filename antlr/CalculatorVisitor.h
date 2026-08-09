
// Generated from Calculator.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CalculatorParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CalculatorParser.
 */
class  CalculatorVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CalculatorParser.
   */
    virtual std::any visitStart(CalculatorParser::StartContext *context) = 0;

    virtual std::any visitExprTerm(CalculatorParser::ExprTermContext *context) = 0;

    virtual std::any visitPlus(CalculatorParser::PlusContext *context) = 0;

    virtual std::any visitTimes(CalculatorParser::TimesContext *context) = 0;

    virtual std::any visitTermFact(CalculatorParser::TermFactContext *context) = 0;

    virtual std::any visitParen(CalculatorParser::ParenContext *context) = 0;

    virtual std::any visitFactorInt(CalculatorParser::FactorIntContext *context) = 0;


};

