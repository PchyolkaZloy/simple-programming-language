#pragma once

#include "SmplangBaseVisitor.h"
#include "variables_util.h"
#include "smplang_common.h"
#include <unordered_map>

namespace bytecode {
    struct NamesInfo {
        NamesInfo(NamesInfo &&other) noexcept = default;

        NamesInfo(const NamesInfo &other) noexcept = default;

        NamesInfo(const std::unordered_map<std::string, TokenPosition> &functionPositions,
                  const std::unordered_map<std::string, TokenPosition> &structurePositions);

    public:
        std::unordered_map<std::string, TokenPosition> function_positions;
        std::unordered_map<std::string, TokenPosition> structure_positions;
    };

    class SmplangStructFuncNamePositionVisitor : public SmplangBaseVisitor {
    private:
        std::unordered_set<std::string> builtin_function_names_;
        std::unordered_map<std::string, TokenPosition> function_positions_;
        std::unordered_map<std::string, TokenPosition> structure_positions_;
    public:
        explicit SmplangStructFuncNamePositionVisitor(const std::unordered_set<std::string> &builtin_function_names);

        std::any visitProgram(SmplangParser::ProgramContext *ctx) override;

        std::any visitFunctionDecl(SmplangParser::FunctionDeclContext *ctx) override;

        std::any visitReturnType(SmplangParser::ReturnTypeContext *ctx) override;

        std::any visitParameterList(SmplangParser::ParameterListContext *ctx) override;

        std::any visitParameter(SmplangParser::ParameterContext *ctx) override;

        std::any visitStructDecl(SmplangParser::StructDeclContext *ctx) override;

        std::any visitFieldDecl(SmplangParser::FieldDeclContext *ctx) override;

        std::any visitType(SmplangParser::TypeContext *ctx) override;

        std::any visitPrimitiveType(SmplangParser::PrimitiveTypeContext *ctx) override;

        std::any visitStructType(SmplangParser::StructTypeContext *ctx) override;

        std::any visitBlock(SmplangParser::BlockContext *ctx) override;

        std::any visitStatement(SmplangParser::StatementContext *ctx) override;

        std::any visitVarDecl(SmplangParser::VarDeclContext *ctx) override;

        std::any visitAssignment(SmplangParser::AssignmentContext *ctx) override;

        std::any visitIfStatement(SmplangParser::IfStatementContext *ctx) override;

        std::any visitWhileStatement(SmplangParser::WhileStatementContext *ctx) override;

        std::any visitBreakStatement(SmplangParser::BreakStatementContext *ctx) override;

        std::any visitContinueStatement(SmplangParser::ContinueStatementContext *ctx) override;

        std::any visitReturnStatement(SmplangParser::ReturnStatementContext *ctx) override;

        std::any visitExpression(SmplangParser::ExpressionContext *ctx) override;

        std::any visitPrimaryExpression(SmplangParser::PrimaryExpressionContext *ctx) override;

        std::any visitArrayInit(SmplangParser::ArrayInitContext *ctx) override;

        std::any visitStructInit(SmplangParser::StructInitContext *ctx) override;

        std::any visitArgumentList(SmplangParser::ArgumentListContext *ctx) override;

        std::any visitFieldAccess(SmplangParser::FieldAccessContext *ctx) override;

        std::any visitArrayAccess(SmplangParser::ArrayAccessContext *ctx) override;

        std::any visitFunctionCall(SmplangParser::FunctionCallContext *ctx) override;

        std::any visitPrintCall(SmplangParser::PrintCallContext *ctx) override;

        std::any visitAssignable(SmplangParser::AssignableContext *ctx) override;

    private:


    };
}