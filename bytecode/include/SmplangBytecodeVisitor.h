#pragma once

#include "SmplangBaseVisitor.h"
#include <vector>
#include <utility>
#include <unordered_set>
#include <ostream>
#include "eof_fix.h"
#include "bytecodes.h"
#include "type_index.h"
#include <boost/multiprecision/cpp_int.hpp>

using cpp_int = boost::multiprecision::cpp_int;

namespace bytecode {

    struct Operation {
    public:
        Operation(ByteCodes code, const std::vector<char>& valueBytes);

        Operation(const Operation& other) = default;

        Operation(Operation&& other) = default;

        Operation() = default;

        explicit Operation(ByteCodes code);

        Operation& operator=(const Operation& other) = default;

        Operation& operator=(Operation&& other) = default;

        ByteCodes code;
        std::vector<char> value_bytes;
    };

    template <typename InputIterator>
    void writeByteCode(InputIterator byte_code_begin, InputIterator byte_code_end, std::ostream& out_stream) {
        for (auto it = byte_code_begin; it != byte_code_end; ++it) {
            const Operation& op = *it;
            out_stream << static_cast<char>(op.code);
            out_stream.write(op.value_bytes.data(), op.value_bytes.size());
        }
    }

    [[nodiscard]] inline decltype(auto) vec_cast(std::any&& any) {
        return std::any_cast<std::vector<Operation>>(any);
    }

    [[nodiscard]] inline decltype(auto) string_set_cast(std::any&& any) {
        return std::any_cast<std::unordered_set<std::string>>(any);
    }

    [[nodiscard]] inline decltype(auto) string_uint16_t_map_cast(std::any&& any) {
        return std::any_cast<std::unordered_map<std::string, uint16_t>>(any);
    }

    template <typename T>
    std::vector<char>& insertToCharVector(std::vector<char>& vector, const T& value, size_t position) {
        const char* value_ptr = reinterpret_cast<const char*>(&value);
        vector.insert(vector.begin() + position, value_ptr, value_ptr + sizeof(T));
        return vector;
    }

    template <typename T>
    std::vector<char>& appendToCharVector(std::vector<char>& vector, const T& value) {
        return insertToCharVector(vector, value, vector.size());
    }

    std::vector<char>& insertIntToCharVector(std::vector<char>& vector, const cpp_int& value, size_t position);

    std::vector<char>& appendIntToCharVector(std::vector<char>& vector, const cpp_int& value);

    class SmplangBytecodeVisitor: public SmplangBaseVisitor {
    private:
        class SmplangVoidFunctionsVisitor: public SmplangBaseVisitor {
        public:
            std::any visitProgram(SmplangParser::ProgramContext* ctx) override;
        };

        class SmplangStructTypeCodesVisitor: public SmplangBaseVisitor {
        private:
            static constexpr uint16_t defaultTypeMaxCode_ = static_cast<uint16_t>(TypeIndex::Null);

        public:
            std::any visitProgram(SmplangParser::ProgramContext* ctx) override;
        };

        std::unordered_set<std::string> void_typed_builtin_functions_;
        std::unordered_set<std::string> void_typed_program_functions_ = {};
        std::unordered_map<std::string, uint16_t> struct_type_codes_ = {};

        static Operation loadInt(const cpp_int& value);

        static Operation loadBool(bool value);

        static Operation loadChar(char value);

        static Operation loadDouble(double value);

        static Operation loadString(std::string_view s);

        static std::vector<bytecode::Operation> loadField(std::string_view field_name, uint16_t type_code);

        static std::vector<Operation> loadStringThenName(std::string_view name);

        static void appendLoadMember(std::vector<Operation>& code, antlr4::tree::TerminalNode* ID_ptr);

        static char charFromEscapedString(std::string_view str);

    public:
        template <typename InputIterator>
        SmplangBytecodeVisitor(InputIterator void_typed_functions_begin, InputIterator void_typed_functions_end)
            : SmplangBaseVisitor()
            , void_typed_builtin_functions_(void_typed_functions_begin, void_typed_functions_end) {
        }

        std::any visitProgram(SmplangParser::ProgramContext* ctx) override;

        std::any visitFunctionDecl(SmplangParser::FunctionDeclContext* ctx) override;

        std::any visitReturnType(SmplangParser::ReturnTypeContext* ctx) override;

        std::any visitStructDecl(SmplangParser::StructDeclContext* ctx) override;

        std::any visitType(SmplangParser::TypeContext* ctx) override;

        std::any visitPrimitiveType(SmplangParser::PrimitiveTypeContext* ctx) override;

        std::any visitStructType(SmplangParser::StructTypeContext* ctx) override;

        std::any visitBlock(SmplangParser::BlockContext* ctx) override;

        std::any visitStatement(SmplangParser::StatementContext* ctx) override;

        std::any visitVarDecl(SmplangParser::VarDeclContext* ctx) override;

        std::any visitAssignment(SmplangParser::AssignmentContext* ctx) override;

        std::any visitIfStatement(SmplangParser::IfStatementContext* ctx) override;

        std::any visitWhileStatement(SmplangParser::WhileStatementContext* ctx) override;

        std::any visitReturnStatement(SmplangParser::ReturnStatementContext* ctx) override;

        std::any visitExpression(SmplangParser::ExpressionContext* ctx) override;

        std::any visitPrimaryExpression(SmplangParser::PrimaryExpressionContext* ctx) override;

        std::any visitArrayInit(SmplangParser::ArrayInitContext* ctx) override;

        std::any visitArgumentList(SmplangParser::ArgumentListContext* ctx) override;

        std::any visitFunctionCall(SmplangParser::FunctionCallContext* ctx) override;

        std::any visitAssignablePrefix(SmplangParser::AssignablePrefixContext* ctx) override;
    };

} // namespace bytecode