
// Generated from grammar/Smplang.g4 by ANTLR 4.13.1

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

  virtual void enterIfBlock(SmplangParser::IfBlockContext *ctx) = 0;
  virtual void exitIfBlock(SmplangParser::IfBlockContext *ctx) = 0;

  virtual void enterElifBlock(SmplangParser::ElifBlockContext *ctx) = 0;
  virtual void exitElifBlock(SmplangParser::ElifBlockContext *ctx) = 0;

  virtual void enterElseBlock(SmplangParser::ElseBlockContext *ctx) = 0;
  virtual void exitElseBlock(SmplangParser::ElseBlockContext *ctx) = 0;

  virtual void enterWhileStatement(SmplangParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(SmplangParser::WhileStatementContext *ctx) = 0;

  virtual void enterReturnStatement(SmplangParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(SmplangParser::ReturnStatementContext *ctx) = 0;

  virtual void enterExpression(SmplangParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(SmplangParser::ExpressionContext *ctx) = 0;

  virtual void enterPrimaryExpression(SmplangParser::PrimaryExpressionContext *ctx) = 0;
  virtual void exitPrimaryExpression(SmplangParser::PrimaryExpressionContext *ctx) = 0;

  virtual void enterArrayInit(SmplangParser::ArrayInitContext *ctx) = 0;
  virtual void exitArrayInit(SmplangParser::ArrayInitContext *ctx) = 0;

  virtual void enterArgumentList(SmplangParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(SmplangParser::ArgumentListContext *ctx) = 0;

  virtual void enterFunctionCall(SmplangParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(SmplangParser::FunctionCallContext *ctx) = 0;

  virtual void enterAssignable(SmplangParser::AssignableContext *ctx) = 0;
  virtual void exitAssignable(SmplangParser::AssignableContext *ctx) = 0;

  virtual void enterAssignablePrefix(SmplangParser::AssignablePrefixContext *ctx) = 0;
  virtual void exitAssignablePrefix(SmplangParser::AssignablePrefixContext *ctx) = 0;


};

