#pragma once

#include "SmplangBytecodeVisitor.h"
#include "bytecodes.h"
#include "smplang_common.h"
#include <sstream>
#include <type_traits>
#include <limits>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include "variables_util.h"

std::any bytecode::SmplangBytecodeVisitor::visitProgram(SmplangParser::ProgramContext* ctx) {
    // first thing to do is to fetch void typed funcs names
    void_typed_program_functions_ = string_set_cast(
        SmplangBytecodeVisitor::SmplangVoidFunctionsVisitor().visitProgram(ctx));
    std::vector<Operation> program_code{};
    struct_type_codes_ = string_uint16_t_map_cast(
        SmplangBytecodeVisitor::SmplangStructTypeCodesVisitor().visitProgram(ctx));
    for (auto* struct_decl_ctx : ctx->structDecl()) {
        auto struct_decl_code = vec_cast(visitStructDecl(struct_decl_ctx));
        program_code.insert(program_code.end(), struct_decl_code.begin(), struct_decl_code.end());
    }
    for (auto* func_decl_ctx : ctx->functionDecl()) {
        auto func_decl_code = vec_cast(visitFunctionDecl(func_decl_ctx));
        program_code.insert(program_code.end(), func_decl_code.begin(), func_decl_code.end());
    }
    // program body is main function with 0 params
    program_code.push_back(loadString("main"));
    program_code.emplace_back(ByteCodes::MakeFunction,
                              std::vector<char>(1, static_cast<uint8_t>(0)));

    for (auto* statement_ctx : ctx->statement()) {
        auto statement_decl_code = vec_cast(visitStatement(statement_ctx));
        program_code.insert(program_code.end(), statement_decl_code.begin(), statement_decl_code.end());
    }

    // end of main func
    program_code.emplace_back(ByteCodes::NullOp);
    // call main
    program_code.push_back(loadString("main"));
    program_code.emplace_back(ByteCodes::Call);

    return std::any{program_code};
}

std::any bytecode::SmplangBytecodeVisitor::visitFunctionDecl(SmplangParser::FunctionDeclContext* ctx) {
    std::string func_name = ctx->ID()->getText();
    std::vector<Operation> result{};
    auto parameter_ctxes = (ctx->parameterList()) ? ctx->parameterList()->parameter()
                                                  : std::decay_t<decltype(ctx->parameterList()->parameter())>{};
    size_t params_count = parameter_ctxes.size();

    if (params_count > std::numeric_limits<uint8_t>::max()) {
        throw ASTException(std::format("{0} parameters are not allowed ({1} max)", params_count,
                                       std::numeric_limits<uint8_t>::max()));
    }
    for (auto* parameter_ctx : parameter_ctxes) {
        auto load_param_name_code = loadString(parameter_ctx->ID()->getText());
        result.push_back(load_param_name_code);
    }

    result.push_back(loadString(func_name));

    result.emplace_back(ByteCodes::MakeFunction,
                        std::vector<char>(1, static_cast<uint8_t>(params_count))); // NOLINT(*-narrowing-conversions)

    auto block_code = vec_cast(visitBlock(ctx->block()));

    result.insert(result.end(), block_code.begin(), block_code.end());

    result.emplace_back(ByteCodes::NullOp);
    return result;
}

std::any bytecode::SmplangBytecodeVisitor::visitReturnType(SmplangParser::ReturnTypeContext* ctx) {
    return SmplangBaseVisitor::visitReturnType(ctx);
}

std::any bytecode::SmplangBytecodeVisitor::visitStructDecl(SmplangParser::StructDeclContext* ctx) {
    std::string struct_type = ctx->structType()->ID()->getText();
    std::vector<Operation> result{};
    size_t field_count = ctx->fieldDecl().size();
    if (field_count > std::numeric_limits<uint8_t>::max()) {
        throw ASTException(std::format("{0} fields are not allowed ({1} max)", field_count,
                                       std::numeric_limits<uint8_t>::max()));
    }
    for (auto* field_decl_ctx : ctx->fieldDecl()) {
        auto field_type_ctx = field_decl_ctx->type();
        uint16_t type_code;
        if (field_type_ctx->primitiveType()) {
            auto type_ctx = field_type_ctx->primitiveType();
            if (type_ctx->getText() == "int") {
                type_code = static_cast<uint16_t>(TypeIndex::Int);
            } else if (type_ctx->getText() == "double") {
                type_code = static_cast<uint16_t>(TypeIndex::Double);
            } else if (type_ctx->getText() == "char") {
                type_code = static_cast<uint16_t>(TypeIndex::Char);
            } else if (type_ctx->getText() == "bool") {
                type_code = static_cast<uint16_t>(TypeIndex::Bool);
            }
        } else if (field_type_ctx->ARRAYTYPE()) {
            type_code = static_cast<uint16_t>(TypeIndex::Array);
        } else {
            type_code = struct_type_codes_[field_type_ctx->structType()->getText()];
        }
        auto load_field_code = loadField(field_decl_ctx->ID()->getText(), type_code);
        result.insert(result.end(), load_field_code.begin(), load_field_code.end());
    }
    result.push_back(loadString(struct_type));
    result.emplace_back(ByteCodes::LoadType);
    appendToCharVector<uint16_t>(result.back().value_bytes, struct_type_codes_[struct_type]);
    // checking limit above ^^^
    result.emplace_back(ByteCodes::DefineStruct,
                        std::vector<char>(1, static_cast<uint8_t>(field_count))); // NOLINT(*-narrowing-conversions)
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitType(SmplangParser::TypeContext* ctx) {
    return SmplangBaseVisitor::visitType(ctx);
}

std::any bytecode::SmplangBytecodeVisitor::visitPrimitiveType(SmplangParser::PrimitiveTypeContext* ctx) {
    return SmplangBaseVisitor::visitPrimitiveType(ctx);
}

// скип
std::any bytecode::SmplangBytecodeVisitor::visitStructType(SmplangParser::StructTypeContext* ctx) {
    return SmplangBaseVisitor::visitStructType(ctx);
}

std::any bytecode::SmplangBytecodeVisitor::visitBlock(SmplangParser::BlockContext* ctx) {
    std::vector<Operation> result{};
    for (auto* statement_ctx : ctx->statement()) {
        auto statement_code = vec_cast(visitStatement(statement_ctx));
        result.insert(result.end(), statement_code.begin(), statement_code.end());
    }
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitStatement(SmplangParser::StatementContext* ctx) {
    if (ctx->varDecl()) {
        return visitVarDecl(ctx->varDecl());
    }
    if (ctx->whileStatement()) {
        return visitWhileStatement(ctx->whileStatement());
    }
    if (ctx->returnStatement()) {
        return visitReturnStatement(ctx->returnStatement());
    }
    if (ctx->assignment()) {
        return visitAssignment(ctx->assignment());
    }
    if (ctx->ifStatement()) {
        return visitIfStatement(ctx->ifStatement());
    }
    if (ctx->expression()) {
        auto result = vec_cast(visitExpression(ctx->expression()));
        const auto& last_op = result.back();
        if (last_op.code == ByteCodes::Call) {
            Operation load_func_name_op = result[result.size() - 2];
            std::string func_name(load_func_name_op.value_bytes.begin() + sizeof(int),
                                  load_func_name_op.value_bytes.end());
            if (void_typed_builtin_functions_.find(func_name) != void_typed_builtin_functions_.end() ||
                void_typed_program_functions_.find(func_name) != void_typed_program_functions_.end()) {
                return std::any{result};
            }
        }
        result.emplace_back(ByteCodes::Pop);
        return std::any{result};
    }
    // TODO: throw
}

std::any bytecode::SmplangBytecodeVisitor::visitVarDecl(SmplangParser::VarDeclContext* ctx) {
    std::vector<Operation> result{};
    if (!ctx->expression()) {
        if (ctx->type()->ARRAYTYPE()) {
            result.emplace_back(ByteCodes::BuildArray);
            // array of 0 size
            appendToCharVector<int>(result.back().value_bytes, 0);
            // then var name
            result.push_back(loadString(ctx->ID()->getText()));
            result.emplace_back(ByteCodes::StoreName);
            return std::any{result};
        }

        if (ctx->type()->structType()) {
            std::string struct_type = ctx->type()->structType()->ID()->getText();
            // building struct
            result.emplace_back(ByteCodes::LoadType);
            appendToCharVector<uint16_t>(result.back().value_bytes, struct_type_codes_[struct_type]);
            result.emplace_back(ByteCodes::BuildStruct);
            // then var name
            result.push_back(loadString(ctx->ID()->getText()));
            result.emplace_back(ByteCodes::StoreName);
            return std::any{result};
        }
        return std::any{result};
    }
    // expression
    auto expr_code = vec_cast(visitExpression(ctx->expression()));
    result.insert(result.end(), expr_code.begin(), expr_code.end());
    // then var name
    result.push_back(loadString(ctx->ID()->getText()));
    result.emplace_back(ByteCodes::StoreName);
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitAssignment(SmplangParser::AssignmentContext* ctx) {
    auto* assignable_ctx = ctx->assignable();
    std::vector<Operation> result{};
    if (!assignable_ctx->assignablePrefix()) {
        // expression
        auto expr_code = vec_cast(visitExpression(ctx->expression()));
        result.insert(result.end(), expr_code.begin(), expr_code.end());
        // then var name
        result.push_back(loadString(assignable_ctx->ID()->getText()));
        result.emplace_back(ByteCodes::StoreName);
    } else {
        auto expr_code = vec_cast(visitExpression(ctx->expression()));
        // expr first
        result = std::move(expr_code);
        if (assignable_ctx->DOT()) {
            auto load_field_name = loadString(assignable_ctx->ID()->getText());
            auto load_struct_code = vec_cast(visitAssignablePrefix(assignable_ctx->assignablePrefix()));
            // then struct
            result.insert(result.end(), load_struct_code.begin(), load_struct_code.end());
            // then field
            result.push_back(load_field_name);
            result.emplace_back(ByteCodes::StoreMember);
        } else if (assignable_ctx->LBRACK() && assignable_ctx->RBRACK()) {
            auto index_code = vec_cast(visitExpression(assignable_ctx->expression()));
            auto load_array_code = vec_cast(visitAssignablePrefix(assignable_ctx->assignablePrefix()));
            // then array
            result.insert(result.end(), load_array_code.begin(), load_array_code.end());
            // then index
            result.insert(result.end(), index_code.begin(), index_code.end());
            result.emplace_back(ByteCodes::StoreSubscr);
        }
    }
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitIfStatement(SmplangParser::IfStatementContext* ctx) {
    int left_size = 0;
    std::vector<std::vector<Operation>> if_bodies{};
    std::vector<std::vector<Operation>> if_conditions{};
    std::vector<Operation> else_body{};
    std::vector<Operation> result{};
    if (ctx->elseBlock()) {
        auto* else_ctx = ctx->elseBlock();
        if (else_ctx->statement()) {
            else_body = vec_cast(visitStatement(ctx->elseBlock()->statement()));
        } else {
            else_body = vec_cast(visitBlock(else_ctx->block()));
        }
        left_size += static_cast<int>(else_body.size());
    }

    auto* if_ctx = ctx->ifBlock();
    if (if_ctx->statement()) {
        if_bodies.push_back(vec_cast(visitStatement(if_ctx->statement())));
    } else {
        if_bodies.push_back(vec_cast(visitBlock(if_ctx->block())));
    }
    if_conditions.push_back(vec_cast(visitExpression(if_ctx->expression())));
    left_size += static_cast<int>(if_conditions.back().size()) + 1;
    left_size += static_cast<int>(if_bodies.back().size()) + 1;

    // if_bodies_op_count.push_back(if_bodies[0].size());
    // if_conditions_op_count.push_back(if_conditions[0].size());

    for (auto* elif_ctx : ctx->elifBlock()) {
        if_conditions.push_back(vec_cast(visitExpression(elif_ctx->expression())));
        if (elif_ctx->statement()) {
            if_bodies.push_back(vec_cast(visitStatement(elif_ctx->statement())));
        } else {
            if_bodies.push_back(vec_cast(visitBlock(elif_ctx->block())));
        }
        left_size += static_cast<int>(if_conditions.back().size()) + 1;
        left_size += static_cast<int>(if_bodies.back().size()) + 1;
    }
    // no need in last jump if else is not present
    if (!ctx->elseBlock()) {
        --left_size;
    }
    // left size is total if chain size now

    for (size_t i = 0; i + 1 < if_conditions.size(); ++i) {
        // if condition
        result.insert(result.end(), if_conditions[i].begin(), if_conditions[i].end());
        // then goes jump
        result.emplace_back(ByteCodes::JumpIfFalse);
        // jumping to pos after unconditional jump (hence (n + 1) + 1 where n is body size)
        appendToCharVector<int>(result.back().value_bytes, static_cast<int>(if_bodies[i].size() + 2));
        // body
        result.insert(result.end(), if_bodies[i].begin(), if_bodies[i].end());
        // unconditional jump
        result.emplace_back(ByteCodes::Jump);
        // we added k (condition), n (body), 2 jumps
        left_size -= static_cast<int>((if_conditions[i].size() + if_bodies[i].size() + 2));
        // now left size is size of the block after our unconditional jump, jumping over it (hence size + 1)
        appendToCharVector<int>(result.back().value_bytes, left_size + 1);
    }

    // last if now
    result.insert(result.end(), if_conditions.back().begin(), if_conditions.back().end());
    result.emplace_back(ByteCodes::JumpIfFalse);
    if (ctx->elseBlock()) {
        // else statement is present -> it is the very case of prev jump(s)
        appendToCharVector<int>(result.back().value_bytes, static_cast<int>(if_bodies.back().size() + 2));
        result.insert(result.end(), if_bodies.back().begin(), if_bodies.back().end());
        result.emplace_back(ByteCodes::Jump);
        left_size -= static_cast<int>((if_conditions.back().size() + if_bodies.back().size() + 2));
        appendToCharVector<int>(result.back().value_bytes, left_size + 1);
        // add else block
        result.insert(result.end(), else_body.begin(), else_body.end());
    } else {
        // it's the last if -> unconditional jump at the end is absent
        // no need in last size anymore -> no need to change it
        appendToCharVector<int>(result.back().value_bytes, static_cast<int>(if_bodies.back().size() + 1));
        result.insert(result.end(), if_bodies.back().begin(), if_bodies.back().end());
    }
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitWhileStatement(SmplangParser::WhileStatementContext* ctx) {
    auto loop_condition_expr = vec_cast(visitExpression(ctx->expression()));
    auto loop_body = (ctx->block()) ? vec_cast(visitBlock(ctx->block())) : vec_cast(visitStatement(ctx->statement()));
    int condition_ops_count = static_cast<int>(loop_condition_expr.size());
    int body_ops_count = static_cast<int>(loop_body.size());
    auto result = std::move(loop_condition_expr);
    result.emplace_back(ByteCodes::JumpIfFalse);
    // to be after unconditional jump
    appendToCharVector<int>(result.back().value_bytes, body_ops_count + 2);
    result.insert(result.end(), loop_body.begin(), loop_body.end());
    result.emplace_back(ByteCodes::Jump);
    // to be at condition start
    appendToCharVector<int>(result.back().value_bytes, -(body_ops_count + condition_ops_count + 1));
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitReturnStatement(SmplangParser::ReturnStatementContext* ctx) {
    std::vector<Operation> result{};
    if (ctx->expression()) {
        result = vec_cast(visitExpression(ctx->expression()));
    }
    result.emplace_back(ByteCodes::Return);
    return result;
}

std::any bytecode::SmplangBytecodeVisitor::visitExpression(SmplangParser::ExpressionContext* ctx) {
    if (ctx->primaryExpression()) {
        return visitPrimaryExpression(ctx->primaryExpression());
    }
    if (ctx->LPAREN() && ctx->RPAREN()) {
        return visitExpression(ctx->expression(0));
    }
    if (ctx->expression().size() == 1) {
        auto operand = vec_cast(visitExpression(ctx->expression(0)));
        auto result = std::move(operand);
        result.emplace_back(ByteCodes::UnaryOp);
        if (ctx->NEG()) {
            result.back().value_bytes.push_back(static_cast<char>(UnaryOps::Minus));
        } else if (ctx->NOT()) {
            result.back().value_bytes.push_back(static_cast<char>(UnaryOps::Not));
        }
        return std::any{result};
    }
    auto first_operand = vec_cast(visitExpression(ctx->expression(0)));
    auto result = std::move(first_operand);
    auto second_operand = vec_cast(visitExpression(ctx->expression(1)));
    result.insert(result.end(), second_operand.begin(), second_operand.end());
    result.emplace_back(ByteCodes::BinaryOp);

    if (ctx->AND()) {
        result.back().value_bytes.push_back(static_cast<char>(BinaryOps::And));
    } else if (ctx->OR()) {
        result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Or));
    } else if (ctx->MULT()) {
        std::string op = ctx->MULT()->getText();
        if (op == "*") {
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Mul));
        } else if (op == "/") {
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Div));
        } else if (op == "%") {
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Mod));
        }
    } else if (ctx->ADD()) {
        std::string op = ctx->ADD()->getText();
        if (op == "+") {
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Add));
        } else if (op == "-") {
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Sub));
        }
    } else if (ctx->COMPOP()) {
        std::string op = ctx->COMPOP()->getText();
        if (op == "==") {
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Eq));
        } else if (op == "!=") {
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::NotEq));
        } else if (op == "<") {
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Less));
        } else if (op == ">") {
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Gr));
        } else if (op == "<=") {
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::LessEq));
        } else if (op == ">=") {
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::GrEq));
        }
    }
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitPrimaryExpression(SmplangParser::PrimaryExpressionContext* ctx) {
    if (ctx->INT()) {
        cpp_int value(ctx->INT()->getText());
        return std::any{std::vector(1, loadInt(value))};
    }
    if (ctx->BOOL()) {
        bool value = (ctx->BOOL()->getText() == "true") ? true : false;
        return std::any{std::vector(1, loadBool(value))};
    }
    if (ctx->CHAR()) {
        char value;
        std::string char_str = ctx->CHAR()->getText();
        // text ~= "\'[symbol]\'"
        if (char_str.size() == 3) {
            value = char_str[1];
        } else {
            value = charFromEscapedString(char_str);
        }
        // else if(ctx->)
        return std::any{std::vector(1, loadChar(value))};
    }
    if (ctx->DOUBLE()) {
        double value = std::stod(ctx->DOUBLE()->getText());
        return std::any{std::vector(1, loadDouble(value))};
    }
    // struct.field
    if (ctx->DOT()) {
        auto struct_expression = vec_cast(visitPrimaryExpression(ctx->primaryExpression()));
        auto result = std::move(struct_expression);
        appendLoadMember(result, ctx->ID());
        return std::any{result};
    }
    // IMPORTANT: after if DOT
    // just variable
    if (ctx->ID()) {
        return std::any{loadStringThenName(ctx->ID()->getText())};
    }
    // (...)
    if (ctx->LPAREN() && ctx->RPAREN()) {
        return visitExpression(ctx->expression());
    }
    // array[...]
    if (ctx->LBRACK() && ctx->RBRACK()) {
        auto array_code = vec_cast(visitPrimaryExpression(ctx->primaryExpression()));
        auto result = std::move(array_code);
        auto index_code = vec_cast(visitExpression(ctx->expression()));
        result.insert(result.end(), index_code.begin(), index_code.end());
        result.emplace_back(ByteCodes::LoadSubscr);
        return std::any{result};
    }
    if (ctx->functionCall()) {
        return visitFunctionCall(ctx->functionCall());
    }
    if (ctx->arrayInit()) {
        return visitArrayInit(ctx->arrayInit());
    }
    throw ASTException("unknown AST child node");
}

std::any bytecode::SmplangBytecodeVisitor::visitArrayInit(SmplangParser::ArrayInitContext* ctx) {
    std::vector<Operation> result;
    size_t elements_count = ctx->expression().size();
    for (auto* arg_expr_ctx : ctx->expression()) {
        auto expr_code = vec_cast(visitExpression(arg_expr_ctx));
        result.insert(result.end(), expr_code.begin(), expr_code.end());
    }
    result.emplace_back(ByteCodes::BuildArray);
    appendToCharVector<int>(result.back().value_bytes, static_cast<int>(elements_count));
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitArgumentList(SmplangParser::ArgumentListContext* ctx) {
    std::vector<Operation> result;
    for (auto* arg_expr_ctx : ctx->expression()) {
        auto expr_code = vec_cast(visitExpression(arg_expr_ctx));
        result.insert(result.end(), expr_code.begin(), expr_code.end());
    }
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitFunctionCall(SmplangParser::FunctionCallContext* ctx) {
    std::vector<Operation> result{};
    if (ctx->argumentList()) {
        result = vec_cast(visitArgumentList(ctx->argumentList()));
    }
    Operation load_func_name = loadString(ctx->ID()->getText());
    result.push_back(load_func_name);
    result.emplace_back(ByteCodes::Call);
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitAssignablePrefix(SmplangParser::AssignablePrefixContext* ctx) {
    if (!ctx->assignablePrefix()) {
        std::vector<Operation> result = loadStringThenName(ctx->ID()->getText());
        return result;
    }
    if (ctx->DOT()) {
        std::vector<Operation> load_prev_code = vec_cast(visitAssignablePrefix(ctx->assignablePrefix()));
        std::vector<Operation> result = std::move(load_prev_code);
        appendLoadMember(result, ctx->ID());
        return result;
    }
    if (ctx->LBRACK() && ctx->LBRACK()) {
        std::vector<Operation> load_prev_code = vec_cast(visitAssignablePrefix(ctx->assignablePrefix()));
        std::vector<Operation> result = std::move(load_prev_code);
        auto index_code = vec_cast(visitExpression(ctx->expression()));
        result.insert(result.end(), index_code.begin(), index_code.end());
        result.emplace_back(ByteCodes::LoadSubscr);
        return result;
    }
    throw ASTException("");
}

bytecode::Operation bytecode::loadInt(const cpp_int& value) {
    Operation op(ByteCodes::LoadInt);
    appendIntToCharVector(op.value_bytes, value);
    return op;
}

bytecode::Operation bytecode::loadBool(bool value) {
    Operation op(ByteCodes::LoadBool);
    appendToCharVector(op.value_bytes, value);
    return op;
}

bytecode::Operation bytecode::loadChar(char value) {
    Operation op(ByteCodes::LoadChar);
    appendToCharVector(op.value_bytes, value);
    return op;
}

bytecode::Operation bytecode::loadDouble(double value) {
    Operation op(ByteCodes::LoadDouble);
    appendToCharVector<double>(op.value_bytes, value);
    return op;
}

bytecode::Operation bytecode::SmplangBytecodeVisitor::loadString(std::string_view s) {
    Operation op(ByteCodes::LoadString);
    int len = static_cast<int>(s.size());
    appendToCharVector<int>(op.value_bytes, len);
    op.value_bytes.insert(op.value_bytes.end(), s.begin(), s.end());
    return op;
}

std::vector<bytecode::Operation>
bytecode::SmplangBytecodeVisitor::loadField(std::string_view field_name, uint16_t type_code) {
    std::vector result{1, loadString(field_name)};
    result.emplace_back(ByteCodes::LoadType);
    appendToCharVector<uint16_t>(result.back().value_bytes, type_code);
    return result;
}

std::vector<bytecode::Operation> bytecode::SmplangBytecodeVisitor::loadStringThenName(std::string_view name) {
    std::vector result{1, loadString(name)};
    result.emplace_back(ByteCodes::LoadName);
    return result;
}

void bytecode::SmplangBytecodeVisitor::appendLoadMember(std::vector<bytecode::Operation>& code,
                                                        antlr4::tree::TerminalNode* ID_ptr) {
    auto load_field_name = loadString(ID_ptr->getText());
    code.push_back(load_field_name);
    code.emplace_back(ByteCodes::LoadMember);
}

std::vector<char>& bytecode::insertIntToCharVector(std::vector<char>& vector, const cpp_int& value, size_t position) {
    std::vector<char> v;
    boost::multiprecision::export_bits(value, std::back_inserter(v), 7);
    int size = static_cast<int>(v.size());
    if (value < 0) {
        size = -size;
    }
    insertToCharVector<int>(vector, size, position);
    vector.insert(vector.begin() + position + 4, v.begin(), v.end());
    return vector;
}

std::vector<char>& bytecode::appendIntToCharVector(std::vector<char>& vector, const cpp_int& value) {
    return insertIntToCharVector(vector, value, vector.size());
}

char bytecode::SmplangBytecodeVisitor::charFromEscapedString(std::string_view str) {
    // ['"\\anbrvt]
    switch (str[2]) {
        case '\'':
        case '\"':
        case '\\':
            return str[2];
        case 'n':
            return '\n';
        case 'a':
            return '\a';
        case 'b':
            return '\b';
        case 'v':
            return '\v';
        case 'r':
            return '\r';
        case 't':
            return '\t';
        default:
            return 0;
    }
}

std::any
bytecode::SmplangBytecodeVisitor::SmplangVoidFunctionsVisitor::visitProgram(SmplangParser::ProgramContext* ctx) {
    std::unordered_set<std::string> void_typed_function_names = {};
    for (auto func_decl_ctx : ctx->functionDecl()) {
        auto type_ctx = func_decl_ctx->returnType();
        if (type_ctx->VOID()) {
            void_typed_function_names.insert(func_decl_ctx->ID()->getText());
        }
    }
    return std::any{void_typed_function_names};
}

std::any
bytecode::SmplangBytecodeVisitor::SmplangStructTypeCodesVisitor::visitProgram(SmplangParser::ProgramContext* ctx) {
    std::unordered_map<std::string, uint16_t> struct_type_codes = {};
    uint16_t prev_code = SmplangStructTypeCodesVisitor::defaultTypeMaxCode_;
    for (auto struct_decl_ctx : ctx->structDecl()) {
        auto struct_name = struct_decl_ctx->structType()->getText();
        struct_type_codes[struct_name] = ++prev_code;
    }
    return std::any{struct_type_codes};
}
