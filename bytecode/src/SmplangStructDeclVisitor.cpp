#include "SmplangStructDeclVisitor.h"
#include "variables_util.h"
#include "smplang_common.h"
#include <memory>

std::any bytecode::SmplangStructDeclVisitor::visitProgram(SmplangParser::ProgramContext *ctx) {
    auto children =  SmplangBaseVisitor::visitProgram(ctx);
    return nullptr;
}

std::any bytecode::SmplangStructDeclVisitor::visitFunctionDecl(SmplangParser::FunctionDeclContext *ctx) {
    std::cout << "func decl" << std::endl;
    return SmplangBaseVisitor::visitFunctionDecl(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitReturnType(SmplangParser::ReturnTypeContext *ctx) {
    return SmplangBaseVisitor::visitReturnType(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitParameterList(SmplangParser::ParameterListContext *ctx) {
    return SmplangBaseVisitor::visitParameterList(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitParameter(SmplangParser::ParameterContext *ctx) {
    return SmplangBaseVisitor::visitParameter(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitStructDecl(SmplangParser::StructDeclContext *ctx) {
    std::cout << "struct decl" << std::endl;

    return SmplangBaseVisitor::visitStructDecl(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitFieldDecl(SmplangParser::FieldDeclContext *ctx) {
    return SmplangBaseVisitor::visitFieldDecl(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitType(SmplangParser::TypeContext *ctx) {
    if (ctx->structType()) {
        return visitStructType(ctx->structType());
    }
    if (ctx->primitiveType()) {
        return visitPrimitiveType(ctx->primitiveType());
    }
    auto type_ptr = std::any_cast<std::shared_ptr<Type>>(visitType(ctx->type()));
    if (ctx->ARRAYTYPE()) {
        type_ptr->setArrayDepth(type_ptr->getArrayDepth() + 1);
    }
    return std::any{type_ptr};
}

std::any bytecode::SmplangStructDeclVisitor::visitPrimitiveType(SmplangParser::PrimitiveTypeContext *ctx) {
    if (ctx->getText() == "int")
        return std::any{std::shared_ptr<Type>(new PrimitiveType(PrimitiveTypeValue::Int, 0))};
    if (ctx->getText() == "double")
        return std::any{std::shared_ptr<Type>(new PrimitiveType(PrimitiveTypeValue::Double, 0))};
    if (ctx->getText() == "char")
        return std::any{std::shared_ptr<Type>(new PrimitiveType(PrimitiveTypeValue::Char, 0))};
    if (ctx->getText() == "bool")
        return std::any{std::shared_ptr<Type>(new PrimitiveType(PrimitiveTypeValue::Bool, 0))};
    auto *token = ctx->getStart();
    throw ValidatorException::unknownName(TokenPosition(token->getLine(), token->getCharPositionInLine()),
                                          ctx->getText());
}

std::any bytecode::SmplangStructDeclVisitor::visitStructType(SmplangParser::StructTypeContext *ctx) {
    return std::any{std::shared_ptr<Type>(new StructType(ctx->ID()->getText(), 0))};
}

std::any bytecode::SmplangStructDeclVisitor::visitBlock(SmplangParser::BlockContext *ctx) {
    return SmplangBaseVisitor::visitBlock(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitStatement(SmplangParser::StatementContext *ctx) {
    return SmplangBaseVisitor::visitStatement(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitVarDecl(SmplangParser::VarDeclContext *ctx) {
    return SmplangBaseVisitor::visitVarDecl(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitAssignment(SmplangParser::AssignmentContext *ctx) {
    return SmplangBaseVisitor::visitAssignment(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitIfStatement(SmplangParser::IfStatementContext *ctx) {
    return SmplangBaseVisitor::visitIfStatement(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitWhileStatement(SmplangParser::WhileStatementContext *ctx) {
    return SmplangBaseVisitor::visitWhileStatement(ctx);
}

std::any
bytecode::SmplangStructDeclVisitor::visitReturnStatement(SmplangParser::ReturnStatementContext *ctx) {
    return SmplangBaseVisitor::visitReturnStatement(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitExpression(SmplangParser::ExpressionContext *ctx) {
    return SmplangBaseVisitor::visitExpression(ctx);
}

std::any
bytecode::SmplangStructDeclVisitor::visitPrimaryExpression(SmplangParser::PrimaryExpressionContext *ctx) {
    return SmplangBaseVisitor::visitPrimaryExpression(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitArrayInit(SmplangParser::ArrayInitContext *ctx) {
    return SmplangBaseVisitor::visitArrayInit(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitStructInit(SmplangParser::StructInitContext *ctx) {
    return SmplangBaseVisitor::visitStructInit(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitArgumentList(SmplangParser::ArgumentListContext *ctx) {
    return SmplangBaseVisitor::visitArgumentList(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitFieldAccess(SmplangParser::FieldAccessContext *ctx) {
    return SmplangBaseVisitor::visitFieldAccess(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitArrayAccess(SmplangParser::ArrayAccessContext *ctx) {
    return SmplangBaseVisitor::visitArrayAccess(ctx);
}

std::any bytecode::SmplangStructDeclVisitor::visitFunctionCall(SmplangParser::FunctionCallContext *ctx) {
    return SmplangBaseVisitor::visitFunctionCall(ctx);
}
std::any bytecode::SmplangStructDeclVisitor::visitAssignable(SmplangParser::AssignableContext *ctx) {
    return SmplangBaseVisitor::visitAssignable(ctx);
}