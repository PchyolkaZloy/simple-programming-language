#include "SmplangStructFuncNamePositionVisitor.h"

namespace bytecode {

    std::any SmplangStructFuncNamePositionVisitor::visitProgram(SmplangParser::ProgramContext* ctx) {
        for (auto struct_decl : ctx->structDecl()) {
            auto pair = std::any_cast<std::pair<std::string, TokenPosition>>(visitStructDecl(struct_decl));
            const auto& name = pair.first;
            const auto& position = pair.second;
            if (structure_positions_.find(name) != structure_positions_.end()) {
                throw ValidatorException::doubleDefinition(position, name);
            }
            structure_positions_[name] = position;
        }
        for (auto function_decl : ctx->functionDecl()) {
            auto pair = std::any_cast<std::pair<std::string, TokenPosition>>(visitFunctionDecl(function_decl));
            const auto& name = pair.first;
            const auto& position = pair.second;
            if (function_positions_.find(name) != function_positions_.end() ||
                builtin_function_names_.find(name) != builtin_function_names_.end()) {
                throw ValidatorException::doubleDefinition(position, name);
            }
            function_positions_[name] = position;
        }
        std::any result = NamesInfo(function_positions_, structure_positions_);
        return result;
    }

    std::any SmplangStructFuncNamePositionVisitor::visitFunctionDecl(SmplangParser::FunctionDeclContext* ctx) {
        const auto* token = ctx->ID()->getSymbol();
        std::any result = std::make_pair(ctx->ID()->getText(),
                                         TokenPosition(token->getLine(), token->getCharPositionInLine()));
        return result;
    }

    std::any SmplangStructFuncNamePositionVisitor::visitStructDecl(SmplangParser::StructDeclContext* ctx) {
        return visitStructType(ctx->structType());
    }

    std::any SmplangStructFuncNamePositionVisitor::visitStructType(SmplangParser::StructTypeContext* ctx) {
        const auto* token = ctx->ID()->getSymbol();
        std::any result = std::make_pair(ctx->ID()->getText(),
                                         TokenPosition(token->getLine(), token->getCharPositionInLine()));
        return result;
    }

    SmplangStructFuncNamePositionVisitor::SmplangStructFuncNamePositionVisitor(
        const std::unordered_set<std::string>& builtin_function_names)
        : builtin_function_names_(
              builtin_function_names)
        , structure_positions_{}
        , function_positions_{} {
    }

    NamesInfo::NamesInfo(const std::unordered_map<std::string, TokenPosition>& functionPositions,
                         const std::unordered_map<std::string, TokenPosition>& structurePositions)
        : function_positions(
              functionPositions)
        , structure_positions(structurePositions) {
    }
} // namespace bytecode