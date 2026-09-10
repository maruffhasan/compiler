
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

    virtual std::any visitProgramSingleUnit(CSubsetParser::ProgramSingleUnitContext *context) = 0;

    virtual std::any visitProgramUnit(CSubsetParser::ProgramUnitContext *context) = 0;

    virtual std::any visitUnitVarDecl(CSubsetParser::UnitVarDeclContext *context) = 0;

    virtual std::any visitUnitFuncDecl(CSubsetParser::UnitFuncDeclContext *context) = 0;

    virtual std::any visitUnitFuncDef(CSubsetParser::UnitFuncDefContext *context) = 0;

    virtual std::any visitFuncDeclWithParams(CSubsetParser::FuncDeclWithParamsContext *context) = 0;

    virtual std::any visitFuncDeclNoParams(CSubsetParser::FuncDeclNoParamsContext *context) = 0;

    virtual std::any visitFuncDefWithParams(CSubsetParser::FuncDefWithParamsContext *context) = 0;

    virtual std::any visitFuncDefNoParams(CSubsetParser::FuncDefNoParamsContext *context) = 0;

    virtual std::any visitParamListMultiUnnamed(CSubsetParser::ParamListMultiUnnamedContext *context) = 0;

    virtual std::any visitParamListSingleNamed(CSubsetParser::ParamListSingleNamedContext *context) = 0;

    virtual std::any visitParamListSingleUnnamed(CSubsetParser::ParamListSingleUnnamedContext *context) = 0;

    virtual std::any visitParamListMultiNamed(CSubsetParser::ParamListMultiNamedContext *context) = 0;

    virtual std::any visitCompoundWithStmts(CSubsetParser::CompoundWithStmtsContext *context) = 0;

    virtual std::any visitCompoundEmpty(CSubsetParser::CompoundEmptyContext *context) = 0;

    virtual std::any visitVarDecl(CSubsetParser::VarDeclContext *context) = 0;

    virtual std::any visitTypeInt(CSubsetParser::TypeIntContext *context) = 0;

    virtual std::any visitTypeFloat(CSubsetParser::TypeFloatContext *context) = 0;

    virtual std::any visitTypeVoid(CSubsetParser::TypeVoidContext *context) = 0;

    virtual std::any visitDeclListSingleIdArray(CSubsetParser::DeclListSingleIdArrayContext *context) = 0;

    virtual std::any visitDeclListSingleId(CSubsetParser::DeclListSingleIdContext *context) = 0;

    virtual std::any visitDeclListCommaId(CSubsetParser::DeclListCommaIdContext *context) = 0;

    virtual std::any visitDeclListCommaIdArray(CSubsetParser::DeclListCommaIdArrayContext *context) = 0;

    virtual std::any visitStatementsSingle(CSubsetParser::StatementsSingleContext *context) = 0;

    virtual std::any visitStatementsMulti(CSubsetParser::StatementsMultiContext *context) = 0;

    virtual std::any visitStmtVarDecl(CSubsetParser::StmtVarDeclContext *context) = 0;

    virtual std::any visitStmtExprStmt(CSubsetParser::StmtExprStmtContext *context) = 0;

    virtual std::any visitStmtCompound(CSubsetParser::StmtCompoundContext *context) = 0;

    virtual std::any visitStmtFor(CSubsetParser::StmtForContext *context) = 0;

    virtual std::any visitStmtIf(CSubsetParser::StmtIfContext *context) = 0;

    virtual std::any visitStmtIfElse(CSubsetParser::StmtIfElseContext *context) = 0;

    virtual std::any visitStmtWhile(CSubsetParser::StmtWhileContext *context) = 0;

    virtual std::any visitStmtPrintln(CSubsetParser::StmtPrintlnContext *context) = 0;

    virtual std::any visitStmtReturn(CSubsetParser::StmtReturnContext *context) = 0;

    virtual std::any visitExprStmtEmpty(CSubsetParser::ExprStmtEmptyContext *context) = 0;

    virtual std::any visitExprStmtExpr(CSubsetParser::ExprStmtExprContext *context) = 0;

    virtual std::any visitVarSimple(CSubsetParser::VarSimpleContext *context) = 0;

    virtual std::any visitVarArray(CSubsetParser::VarArrayContext *context) = 0;

    virtual std::any visitExprLogic(CSubsetParser::ExprLogicContext *context) = 0;

    virtual std::any visitExprAssign(CSubsetParser::ExprAssignContext *context) = 0;

    virtual std::any visitLogicSingle(CSubsetParser::LogicSingleContext *context) = 0;

    virtual std::any visitLogicOp(CSubsetParser::LogicOpContext *context) = 0;

    virtual std::any visitRelSingle(CSubsetParser::RelSingleContext *context) = 0;

    virtual std::any visitRelOp(CSubsetParser::RelOpContext *context) = 0;

    virtual std::any visitSimpleTerm(CSubsetParser::SimpleTermContext *context) = 0;

    virtual std::any visitSimpleAddOp(CSubsetParser::SimpleAddOpContext *context) = 0;

    virtual std::any visitTermUnary(CSubsetParser::TermUnaryContext *context) = 0;

    virtual std::any visitTermMulOp(CSubsetParser::TermMulOpContext *context) = 0;

    virtual std::any visitUnaryAddOp(CSubsetParser::UnaryAddOpContext *context) = 0;

    virtual std::any visitUnaryNot(CSubsetParser::UnaryNotContext *context) = 0;

    virtual std::any visitUnaryFactor(CSubsetParser::UnaryFactorContext *context) = 0;

    virtual std::any visitFactorVar(CSubsetParser::FactorVarContext *context) = 0;

    virtual std::any visitFactorFuncCall(CSubsetParser::FactorFuncCallContext *context) = 0;

    virtual std::any visitFactorParen(CSubsetParser::FactorParenContext *context) = 0;

    virtual std::any visitFactorConstInt(CSubsetParser::FactorConstIntContext *context) = 0;

    virtual std::any visitFactorConstFloat(CSubsetParser::FactorConstFloatContext *context) = 0;

    virtual std::any visitFactorIncop(CSubsetParser::FactorIncopContext *context) = 0;

    virtual std::any visitFactorDecop(CSubsetParser::FactorDecopContext *context) = 0;

    virtual std::any visitArgListNonEmpty(CSubsetParser::ArgListNonEmptyContext *context) = 0;

    virtual std::any visitArgListEmpty(CSubsetParser::ArgListEmptyContext *context) = 0;

    virtual std::any visitArgumentsMulti(CSubsetParser::ArgumentsMultiContext *context) = 0;

    virtual std::any visitArgumentsSingle(CSubsetParser::ArgumentsSingleContext *context) = 0;


};

