
// Generated from ./grammar/Smplang.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "SmplangParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SmplangParser.
 */
class  SmplangVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SmplangParser.
   */
    virtual std::any visitProgram(SmplangParser::ProgramContext *context) = 0;

    virtual std::any visitFunctionDecl(SmplangParser::FunctionDeclContext *context) = 0;

    virtual std::any visitReturnType(SmplangParser::ReturnTypeContext *context) = 0;

    virtual std::any visitParameterList(SmplangParser::ParameterListContext *context) = 0;

    virtual std::any visitParameter(SmplangParser::ParameterContext *context) = 0;

    virtual std::any visitStructDecl(SmplangParser::StructDeclContext *context) = 0;

    virtual std::any visitFieldDecl(SmplangParser::FieldDeclContext *context) = 0;

    virtual std::any visitType(SmplangParser::TypeContext *context) = 0;

    virtual std::any visitPrimitiveType(SmplangParser::PrimitiveTypeContext *context) = 0;

    virtual std::any visitStructType(SmplangParser::StructTypeContext *context) = 0;

    virtual std::any visitBlock(SmplangParser::BlockContext *context) = 0;

    virtual std::any visitStatement(SmplangParser::StatementContext *context) = 0;

    virtual std::any visitVarDecl(SmplangParser::VarDeclContext *context) = 0;

    virtual std::any visitAssignment(SmplangParser::AssignmentContext *context) = 0;

    virtual std::any visitIfStatement(SmplangParser::IfStatementContext *context) = 0;

    virtual std::any visitWhileStatement(SmplangParser::WhileStatementContext *context) = 0;

    virtual std::any visitBreakStatement(SmplangParser::BreakStatementContext *context) = 0;

    virtual std::any visitContinueStatement(SmplangParser::ContinueStatementContext *context) = 0;

    virtual std::any visitReturnStatement(SmplangParser::ReturnStatementContext *context) = 0;

    virtual std::any visitExpression(SmplangParser::ExpressionContext *context) = 0;

    virtual std::any visitPrimaryExpression(SmplangParser::PrimaryExpressionContext *context) = 0;

    virtual std::any visitArrayInit(SmplangParser::ArrayInitContext *context) = 0;

    virtual std::any visitStructInit(SmplangParser::StructInitContext *context) = 0;

    virtual std::any visitArgumentList(SmplangParser::ArgumentListContext *context) = 0;

    virtual std::any visitFieldAccess(SmplangParser::FieldAccessContext *context) = 0;

    virtual std::any visitArrayAccess(SmplangParser::ArrayAccessContext *context) = 0;

    virtual std::any visitFunctionCall(SmplangParser::FunctionCallContext *context) = 0;

    virtual std::any visitAssignable(SmplangParser::AssignableContext *context) = 0;


};

