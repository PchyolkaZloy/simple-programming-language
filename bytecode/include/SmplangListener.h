
// Generated from ./grammar/Smplang.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "SmplangParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SmplangParser.
 */
class  SmplangListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(SmplangParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(SmplangParser::ProgramContext *ctx) = 0;

  virtual void enterFunctionDecl(SmplangParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(SmplangParser::FunctionDeclContext *ctx) = 0;

  virtual void enterReturnType(SmplangParser::ReturnTypeContext *ctx) = 0;
  virtual void exitReturnType(SmplangParser::ReturnTypeContext *ctx) = 0;

  virtual void enterParameterList(SmplangParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(SmplangParser::ParameterListContext *ctx) = 0;

  virtual void enterParameter(SmplangParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(SmplangParser::ParameterContext *ctx) = 0;

  virtual void enterStructDecl(SmplangParser::StructDeclContext *ctx) = 0;
  virtual void exitStructDecl(SmplangParser::StructDeclContext *ctx) = 0;

  virtual void enterFieldDecl(SmplangParser::FieldDeclContext *ctx) = 0;
  virtual void exitFieldDecl(SmplangParser::FieldDeclContext *ctx) = 0;

  virtual void enterType(SmplangParser::TypeContext *ctx) = 0;
  virtual void exitType(SmplangParser::TypeContext *ctx) = 0;

  virtual void enterPrimitiveType(SmplangParser::PrimitiveTypeContext *ctx) = 0;
  virtual void exitPrimitiveType(SmplangParser::PrimitiveTypeContext *ctx) = 0;

  virtual void enterStructType(SmplangParser::StructTypeContext *ctx) = 0;
  virtual void exitStructType(SmplangParser::StructTypeContext *ctx) = 0;

  virtual void enterBlock(SmplangParser::BlockContext *ctx) = 0;
  virtual void exitBlock(SmplangParser::BlockContext *ctx) = 0;

  virtual void enterStatement(SmplangParser::StatementContext *ctx) = 0;
  virtual void exitStatement(SmplangParser::StatementContext *ctx) = 0;

  virtual void enterVarDecl(SmplangParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(SmplangParser::VarDeclContext *ctx) = 0;

  virtual void enterAssignment(SmplangParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(SmplangParser::AssignmentContext *ctx) = 0;

  virtual void enterIfStatement(SmplangParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(SmplangParser::IfStatementContext *ctx) = 0;

  virtual void enterWhileStatement(SmplangParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(SmplangParser::WhileStatementContext *ctx) = 0;

  virtual void enterBreakStatement(SmplangParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(SmplangParser::BreakStatementContext *ctx) = 0;

  virtual void enterContinueStatement(SmplangParser::ContinueStatementContext *ctx) = 0;
  virtual void exitContinueStatement(SmplangParser::ContinueStatementContext *ctx) = 0;

  virtual void enterReturnStatement(SmplangParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(SmplangParser::ReturnStatementContext *ctx) = 0;

  virtual void enterExpression(SmplangParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(SmplangParser::ExpressionContext *ctx) = 0;

  virtual void enterPrimaryExpression(SmplangParser::PrimaryExpressionContext *ctx) = 0;
  virtual void exitPrimaryExpression(SmplangParser::PrimaryExpressionContext *ctx) = 0;

  virtual void enterArrayInit(SmplangParser::ArrayInitContext *ctx) = 0;
  virtual void exitArrayInit(SmplangParser::ArrayInitContext *ctx) = 0;

  virtual void enterStructInit(SmplangParser::StructInitContext *ctx) = 0;
  virtual void exitStructInit(SmplangParser::StructInitContext *ctx) = 0;

  virtual void enterArgumentList(SmplangParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(SmplangParser::ArgumentListContext *ctx) = 0;

  virtual void enterFieldAccess(SmplangParser::FieldAccessContext *ctx) = 0;
  virtual void exitFieldAccess(SmplangParser::FieldAccessContext *ctx) = 0;

  virtual void enterArrayAccess(SmplangParser::ArrayAccessContext *ctx) = 0;
  virtual void exitArrayAccess(SmplangParser::ArrayAccessContext *ctx) = 0;

  virtual void enterFunctionCall(SmplangParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(SmplangParser::FunctionCallContext *ctx) = 0;

  virtual void enterBuiltinCall(SmplangParser::BuiltinCallContext *ctx) = 0;
  virtual void exitBuiltinCall(SmplangParser::BuiltinCallContext *ctx) = 0;

  virtual void enterAssignable(SmplangParser::AssignableContext *ctx) = 0;
  virtual void exitAssignable(SmplangParser::AssignableContext *ctx) = 0;


};

