
// Generated from grammar/Smplang.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SmplangVisitor.h"


/**
 * This class provides an empty implementation of SmplangVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SmplangBaseVisitor : public SmplangVisitor {
public:

  virtual std::any visitProgram(SmplangParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDecl(SmplangParser::FunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnType(SmplangParser::ReturnTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterList(SmplangParser::ParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter(SmplangParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructDecl(SmplangParser::StructDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFieldDecl(SmplangParser::FieldDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(SmplangParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimitiveType(SmplangParser::PrimitiveTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructType(SmplangParser::StructTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(SmplangParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(SmplangParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(SmplangParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(SmplangParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(SmplangParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStatement(SmplangParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStatement(SmplangParser::BreakStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStatement(SmplangParser::ContinueStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(SmplangParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintStatement(SmplangParser::PrintStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(SmplangParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExpression(SmplangParser::PrimaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayInit(SmplangParser::ArrayInitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructInit(SmplangParser::StructInitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentList(SmplangParser::ArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFieldAccess(SmplangParser::FieldAccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayAccess(SmplangParser::ArrayAccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCall(SmplangParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignable(SmplangParser::AssignableContext *ctx) override {
    return visitChildren(ctx);
  }


};

