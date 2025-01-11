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

        std::any visitStructDecl(SmplangParser::StructDeclContext *ctx) override;

        std::any visitStructType(SmplangParser::StructTypeContext *ctx) override;

    };
}
