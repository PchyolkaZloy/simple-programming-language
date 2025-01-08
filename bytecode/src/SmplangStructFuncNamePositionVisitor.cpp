#include "SmplangStructFuncNamePositionVisitor.h"

namespace bytecode {

    std::any SmplangStructFuncNamePositionVisitor::visitProgram(SmplangParser::ProgramContext *ctx) {
        for (auto struct_decl: ctx->structDecl()) {
            auto pair = std::any_cast<std::pair<std::string, TokenPosition>>(visitStructDecl(struct_decl));
            const auto &name = pair.first;
            const auto &position = pair.second;
            if (structure_positions_.find(name) != structure_positions_.end())
                throw ValidatorException::doubleDefinition(position, name);
            structure_positions_[name] = position;
        }
        for (auto function_decl: ctx->functionDecl()) {
            auto pair = std::any_cast<std::pair<std::string, TokenPosition>>(visitFunctionDecl(function_decl));
            const auto &name = pair.first;
            const auto &position = pair.second;
            if (function_positions_.find(name) != function_positions_.end() ||
                builtin_function_names_.find(name) != builtin_function_names_.end())
                throw ValidatorException::doubleDefinition(position, name);
            function_positions_[name] = position;
        }
        std::any result = NamesInfo(function_positions_, structure_positions_);
        return result;
    }

    std::any SmplangStructFuncNamePositionVisitor::visitFunctionDecl(SmplangParser::FunctionDeclContext *ctx) {
        const auto *token = ctx->ID()->getSymbol();
        std::any result = std::make_pair(ctx->ID()->getText(),
                                         TokenPosition(token->getLine(), token->getCharPositionInLine()));
        return result;
    }

    std::any SmplangStructFuncNamePositionVisitor::visitReturnType(SmplangParser::ReturnTypeContext *ctx) {
        return SmplangBaseVisitor::visitReturnType(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitParameterList(SmplangParser::ParameterListContext *ctx) {
        return SmplangBaseVisitor::visitParameterList(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitParameter(SmplangParser::ParameterContext *ctx) {
        return SmplangBaseVisitor::visitParameter(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitStructDecl(SmplangParser::StructDeclContext *ctx) {
        return visitStructType(ctx->structType());
    }

    std::any SmplangStructFuncNamePositionVisitor::visitFieldDecl(SmplangParser::FieldDeclContext *ctx) {
        return SmplangBaseVisitor::visitFieldDecl(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitType(SmplangParser::TypeContext *ctx) {
        return SmplangBaseVisitor::visitType(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitPrimitiveType(SmplangParser::PrimitiveTypeContext *ctx) {
        return SmplangBaseVisitor::visitPrimitiveType(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitStructType(SmplangParser::StructTypeContext *ctx) {
//        const auto *token = ctx->getStart();
        const auto *token = ctx->ID()->getSymbol();
        std::any result = std::make_pair(ctx->ID()->getText(),
                                         TokenPosition(token->getLine(), token->getCharPositionInLine()));
        return result;
    }

    std::any SmplangStructFuncNamePositionVisitor::visitBlock(SmplangParser::BlockContext *ctx) {
        return SmplangBaseVisitor::visitBlock(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitStatement(SmplangParser::StatementContext *ctx) {
        return SmplangBaseVisitor::visitStatement(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitVarDecl(SmplangParser::VarDeclContext *ctx) {
        return SmplangBaseVisitor::visitVarDecl(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitAssignment(SmplangParser::AssignmentContext *ctx) {
        return SmplangBaseVisitor::visitAssignment(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitIfStatement(SmplangParser::IfStatementContext *ctx) {
        return SmplangBaseVisitor::visitIfStatement(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitWhileStatement(SmplangParser::WhileStatementContext *ctx) {
        return SmplangBaseVisitor::visitWhileStatement(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitBreakStatement(SmplangParser::BreakStatementContext *ctx) {
        return SmplangBaseVisitor::visitBreakStatement(ctx);
    }

    std::any
    SmplangStructFuncNamePositionVisitor::visitContinueStatement(SmplangParser::ContinueStatementContext *ctx) {
        return SmplangBaseVisitor::visitContinueStatement(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitReturnStatement(SmplangParser::ReturnStatementContext *ctx) {
        return SmplangBaseVisitor::visitReturnStatement(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitExpression(SmplangParser::ExpressionContext *ctx) {
        return SmplangBaseVisitor::visitExpression(ctx);
    }

    std::any
    SmplangStructFuncNamePositionVisitor::visitPrimaryExpression(SmplangParser::PrimaryExpressionContext *ctx) {
        return SmplangBaseVisitor::visitPrimaryExpression(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitArrayInit(SmplangParser::ArrayInitContext *ctx) {
        return SmplangBaseVisitor::visitArrayInit(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitStructInit(SmplangParser::StructInitContext *ctx) {
        return SmplangBaseVisitor::visitStructInit(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitArgumentList(SmplangParser::ArgumentListContext *ctx) {
        return SmplangBaseVisitor::visitArgumentList(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitFieldAccess(SmplangParser::FieldAccessContext *ctx) {
        return SmplangBaseVisitor::visitFieldAccess(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitArrayAccess(SmplangParser::ArrayAccessContext *ctx) {
        return SmplangBaseVisitor::visitArrayAccess(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitFunctionCall(SmplangParser::FunctionCallContext *ctx) {
        return SmplangBaseVisitor::visitFunctionCall(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitPrintCall(SmplangParser::PrintCallContext *ctx) {
        return SmplangBaseVisitor::visitPrintCall(ctx);
    }

    std::any SmplangStructFuncNamePositionVisitor::visitAssignable(SmplangParser::AssignableContext *ctx) {
        return SmplangBaseVisitor::visitAssignable(ctx);
    }

    SmplangStructFuncNamePositionVisitor::SmplangStructFuncNamePositionVisitor(
            const std::unordered_set<std::string> &builtin_function_names) : builtin_function_names_(
            builtin_function_names), structure_positions_{}, function_positions_{} {}

    NamesInfo::NamesInfo(const std::unordered_map<std::string, TokenPosition> &functionPositions,
                         const std::unordered_map<std::string, TokenPosition> &structurePositions) : function_positions(
            functionPositions), structure_positions(structurePositions) {}
}