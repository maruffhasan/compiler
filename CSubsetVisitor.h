
// Generated from CSubset.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CSubsetParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CSubsetParser.
 */
class  CSubsetVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CSubsetParser.
   */
    virtual std::any visitStart(CSubsetParser::StartContext *context) = 0;

    virtual std::any visitProgram(CSubsetParser::ProgramContext *context) = 0;

    virtual std::any visitUnit(CSubsetParser::UnitContext *context) = 0;

    virtual std::any visitFuncDefNoParams(CSubsetParser::FuncDefNoParamsContext *context) = 0;

    virtual std::any visitCompoundStmtBody(CSubsetParser::CompoundStmtBodyContext *context) = 0;

    virtual std::any visitCompoundStmtEmpty(CSubsetParser::CompoundStmtEmptyContext *context) = 0;

    virtual std::any visitVarDecl(CSubsetParser::VarDeclContext *context) = 0;

    virtual std::any visitTypeInt(CSubsetParser::TypeIntContext *context) = 0;

    virtual std::any visitTypeVoid(CSubsetParser::TypeVoidContext *context) = 0;

    virtual std::any visitDeclListSingleId(CSubsetParser::DeclListSingleIdContext *context) = 0;

    virtual std::any visitDeclListCommaId(CSubsetParser::DeclListCommaIdContext *context) = 0;

    virtual std::any visitStmtSingle(CSubsetParser::StmtSingleContext *context) = 0;

    virtual std::any visitStmtSeq(CSubsetParser::StmtSeqContext *context) = 0;

    virtual std::any visitStmtVarDecl(CSubsetParser::StmtVarDeclContext *context) = 0;

    virtual std::any visitStmtExpr(CSubsetParser::StmtExprContext *context) = 0;

    virtual std::any visitStmtCompound(CSubsetParser::StmtCompoundContext *context) = 0;

    virtual std::any visitStmtPrintln(CSubsetParser::StmtPrintlnContext *context) = 0;

    virtual std::any visitStmtReturn(CSubsetParser::StmtReturnContext *context) = 0;

    virtual std::any visitExprStmtEmpty(CSubsetParser::ExprStmtEmptyContext *context) = 0;

    virtual std::any visitExprStmtExpr(CSubsetParser::ExprStmtExprContext *context) = 0;

    virtual std::any visitVarSimple(CSubsetParser::VarSimpleContext *context) = 0;

    virtual std::any visitExprLogic(CSubsetParser::ExprLogicContext *context) = 0;

    virtual std::any visitExprAssign(CSubsetParser::ExprAssignContext *context) = 0;

    virtual std::any visitLogicRel(CSubsetParser::LogicRelContext *context) = 0;

    virtual std::any visitLogicOp(CSubsetParser::LogicOpContext *context) = 0;

    virtual std::any visitRelSimple(CSubsetParser::RelSimpleContext *context) = 0;

    virtual std::any visitRelOp(CSubsetParser::RelOpContext *context) = 0;

    virtual std::any visitSimpleTerm(CSubsetParser::SimpleTermContext *context) = 0;

    virtual std::any visitSimpleAddOp(CSubsetParser::SimpleAddOpContext *context) = 0;

    virtual std::any visitTermUnary(CSubsetParser::TermUnaryContext *context) = 0;

    virtual std::any visitTermMulOp(CSubsetParser::TermMulOpContext *context) = 0;

    virtual std::any visitUnaryAddOp(CSubsetParser::UnaryAddOpContext *context) = 0;

    virtual std::any visitUnaryNot(CSubsetParser::UnaryNotContext *context) = 0;

    virtual std::any visitUnaryFactor(CSubsetParser::UnaryFactorContext *context) = 0;

    virtual std::any visitFactorVar(CSubsetParser::FactorVarContext *context) = 0;

    virtual std::any visitFactorParen(CSubsetParser::FactorParenContext *context) = 0;

    virtual std::any visitFactorConstInt(CSubsetParser::FactorConstIntContext *context) = 0;

    virtual std::any visitFactorConstFloat(CSubsetParser::FactorConstFloatContext *context) = 0;

    virtual std::any visitFactorIncop(CSubsetParser::FactorIncopContext *context) = 0;

    virtual std::any visitFactorDecop(CSubsetParser::FactorDecopContext *context) = 0;


};

