
// Generated from CSubset.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CSubsetVisitor.h"


/**
 * This class provides an empty implementation of CSubsetVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CSubsetBaseVisitor : public CSubsetVisitor {
public:

  virtual std::any visitStart(CSubsetParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramSingleUnit(CSubsetParser::ProgramSingleUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramUnit(CSubsetParser::ProgramUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnitVarDecl(CSubsetParser::UnitVarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnitFuncDecl(CSubsetParser::UnitFuncDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnitFuncDef(CSubsetParser::UnitFuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDeclWithParams(CSubsetParser::FuncDeclWithParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDeclNoParams(CSubsetParser::FuncDeclNoParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDefWithParams(CSubsetParser::FuncDefWithParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDefNoParams(CSubsetParser::FuncDefNoParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamListMultiUnnamed(CSubsetParser::ParamListMultiUnnamedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamListSingleNamed(CSubsetParser::ParamListSingleNamedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamListSingleUnnamed(CSubsetParser::ParamListSingleUnnamedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamListMultiNamed(CSubsetParser::ParamListMultiNamedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompoundWithStmts(CSubsetParser::CompoundWithStmtsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompoundEmpty(CSubsetParser::CompoundEmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(CSubsetParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeInt(CSubsetParser::TypeIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeFloat(CSubsetParser::TypeFloatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeVoid(CSubsetParser::TypeVoidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclListSingleIdArray(CSubsetParser::DeclListSingleIdArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclListSingleId(CSubsetParser::DeclListSingleIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclListCommaId(CSubsetParser::DeclListCommaIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclListCommaIdArray(CSubsetParser::DeclListCommaIdArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementsSingle(CSubsetParser::StatementsSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementsMulti(CSubsetParser::StatementsMultiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtVarDecl(CSubsetParser::StmtVarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtExprStmt(CSubsetParser::StmtExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtCompound(CSubsetParser::StmtCompoundContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtFor(CSubsetParser::StmtForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtIf(CSubsetParser::StmtIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtIfElse(CSubsetParser::StmtIfElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtWhile(CSubsetParser::StmtWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtPrintln(CSubsetParser::StmtPrintlnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtReturn(CSubsetParser::StmtReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStmtEmpty(CSubsetParser::ExprStmtEmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStmtExpr(CSubsetParser::ExprStmtExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarSimple(CSubsetParser::VarSimpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarArray(CSubsetParser::VarArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprLogic(CSubsetParser::ExprLogicContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprAssign(CSubsetParser::ExprAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicSingle(CSubsetParser::LogicSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicOp(CSubsetParser::LogicOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelSingle(CSubsetParser::RelSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelOp(CSubsetParser::RelOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleTerm(CSubsetParser::SimpleTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleAddOp(CSubsetParser::SimpleAddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTermUnary(CSubsetParser::TermUnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTermMulOp(CSubsetParser::TermMulOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryAddOp(CSubsetParser::UnaryAddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryNot(CSubsetParser::UnaryNotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryFactor(CSubsetParser::UnaryFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorVar(CSubsetParser::FactorVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorFuncCall(CSubsetParser::FactorFuncCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorParen(CSubsetParser::FactorParenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorConstInt(CSubsetParser::FactorConstIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorConstFloat(CSubsetParser::FactorConstFloatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorIncop(CSubsetParser::FactorIncopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorDecop(CSubsetParser::FactorDecopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgListNonEmpty(CSubsetParser::ArgListNonEmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgListEmpty(CSubsetParser::ArgListEmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentsMulti(CSubsetParser::ArgumentsMultiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentsSingle(CSubsetParser::ArgumentsSingleContext *ctx) override {
    return visitChildren(ctx);
  }


};

