
// Generated from grammar/Smplang.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "SmplangListener.h"


/**
 * This class provides an empty implementation of SmplangListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SmplangBaseListener : public SmplangListener {
public:

  virtual void enterProgram(SmplangParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(SmplangParser::ProgramContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(SmplangParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(SmplangParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterReturnType(SmplangParser::ReturnTypeContext * /*ctx*/) override { }
  virtual void exitReturnType(SmplangParser::ReturnTypeContext * /*ctx*/) override { }

  virtual void enterParameterList(SmplangParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(SmplangParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameter(SmplangParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(SmplangParser::ParameterContext * /*ctx*/) override { }

  virtual void enterStructDecl(SmplangParser::StructDeclContext * /*ctx*/) override { }
  virtual void exitStructDecl(SmplangParser::StructDeclContext * /*ctx*/) override { }

  virtual void enterFieldDecl(SmplangParser::FieldDeclContext * /*ctx*/) override { }
  virtual void exitFieldDecl(SmplangParser::FieldDeclContext * /*ctx*/) override { }

  virtual void enterType(SmplangParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(SmplangParser::TypeContext * /*ctx*/) override { }

  virtual void enterPrimitiveType(SmplangParser::PrimitiveTypeContext * /*ctx*/) override { }
  virtual void exitPrimitiveType(SmplangParser::PrimitiveTypeContext * /*ctx*/) override { }

  virtual void enterStructType(SmplangParser::StructTypeContext * /*ctx*/) override { }
  virtual void exitStructType(SmplangParser::StructTypeContext * /*ctx*/) override { }

  virtual void enterBlock(SmplangParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(SmplangParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatement(SmplangParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(SmplangParser::StatementContext * /*ctx*/) override { }

  virtual void enterVarDecl(SmplangParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(SmplangParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterAssignment(SmplangParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(SmplangParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterIfStatement(SmplangParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(SmplangParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfBlock(SmplangParser::IfBlockContext * /*ctx*/) override { }
  virtual void exitIfBlock(SmplangParser::IfBlockContext * /*ctx*/) override { }

  virtual void enterElifBlock(SmplangParser::ElifBlockContext * /*ctx*/) override { }
  virtual void exitElifBlock(SmplangParser::ElifBlockContext * /*ctx*/) override { }

  virtual void enterElseBlock(SmplangParser::ElseBlockContext * /*ctx*/) override { }
  virtual void exitElseBlock(SmplangParser::ElseBlockContext * /*ctx*/) override { }

  virtual void enterWhileStatement(SmplangParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(SmplangParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(SmplangParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(SmplangParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterExpression(SmplangParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(SmplangParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterPrimaryExpression(SmplangParser::PrimaryExpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryExpression(SmplangParser::PrimaryExpressionContext * /*ctx*/) override { }

  virtual void enterArrayInit(SmplangParser::ArrayInitContext * /*ctx*/) override { }
  virtual void exitArrayInit(SmplangParser::ArrayInitContext * /*ctx*/) override { }

  virtual void enterArgumentList(SmplangParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(SmplangParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterFunctionCall(SmplangParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(SmplangParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterAssignable(SmplangParser::AssignableContext * /*ctx*/) override { }
  virtual void exitAssignable(SmplangParser::AssignableContext * /*ctx*/) override { }

  virtual void enterAssignablePrefix(SmplangParser::AssignablePrefixContext * /*ctx*/) override { }
  virtual void exitAssignablePrefix(SmplangParser::AssignablePrefixContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

