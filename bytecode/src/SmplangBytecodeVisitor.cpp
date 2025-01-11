#include "SmplangBytecodeVisitor.h"
#include "bytecodes.h"
#include "smplang_common.h"
#include <sstream>
#include <type_traits>
#include <limits>
#include <string>

std::any bytecode::SmplangBytecodeVisitor::visitProgram(SmplangParser::ProgramContext *ctx) {
    std::vector<Operation> program_code{};
    for (auto *struct_decl_ctx: ctx->structDecl()) {
        auto struct_decl_code = vec_cast(visitStructDecl(struct_decl_ctx));
        program_code.insert(program_code.end(), struct_decl_code.begin(), struct_decl_code.end());
    }
    for (auto *func_decl_ctx: ctx->functionDecl()) {
        auto func_decl_code = vec_cast(visitFunctionDecl(func_decl_ctx));
        program_code.insert(program_code.end(), func_decl_code.begin(), func_decl_code.end());
    }
    for (auto *statement_ctx: ctx->statement()) {
        auto statement_decl_code = vec_cast(statement_ctx);
        program_code.insert(program_code.end(), statement_decl_code.begin(), statement_decl_code.end());
    }
    std::cout << ' ';
    return std::any{program_code};
}

std::any bytecode::SmplangBytecodeVisitor::visitFunctionDecl(SmplangParser::FunctionDeclContext *ctx) {
    std::string func_name = ctx->ID()->getText();
    std::vector<Operation> result{};
    result.push_back(loadString(func_name));
    auto parameter_ctxes = (ctx->parameterList()) ? ctx->parameterList()->parameter()
                                                  : std::decay_t<decltype(ctx->parameterList()->parameter())>{};
    size_t params_count = parameter_ctxes.size();

    if (params_count > std::numeric_limits<uint8_t>::max())
        throw ASTException(std::format("{0} parameters are not allowed ({1} max)", params_count,
                                       std::numeric_limits<uint8_t>::max()));
    for (auto *parameter_ctx: parameter_ctxes) {
        auto load_param_name_code = loadString(parameter_ctx->ID()->getText());
        result.push_back(load_param_name_code);
    }

    result.emplace_back(ByteCodes::MakeFunction,
                        std::vector<char>(1, static_cast<uint8_t >(params_count))); // NOLINT(*-narrowing-conversions)

    auto block_code = vec_cast(visitBlock(ctx->block()));

    result.insert(result.end(), block_code.begin(), block_code.end());

    result.emplace_back(ByteCodes::NullOp);
    return result;
}

std::any bytecode::SmplangBytecodeVisitor::visitReturnType(SmplangParser::ReturnTypeContext *ctx) {
    return SmplangBaseVisitor::visitReturnType(ctx);
}

std::any bytecode::SmplangBytecodeVisitor::visitStructDecl(SmplangParser::StructDeclContext *ctx) {
    std::string struct_type = ctx->structType()->ID()->getText();
    std::vector<Operation> result{};
    result.push_back(loadString(struct_type));
    size_t field_count = ctx->fieldDecl().size();
    if (field_count > std::numeric_limits<uint8_t>::max())
        throw ASTException(std::format("{0} fields are not allowed ({1} max)", field_count,
                                       std::numeric_limits<uint8_t>::max()));
    for (auto *field_decl_ptr: ctx->fieldDecl()) {
        auto load_field_str_code = loadString(field_decl_ptr->ID()->getText());
        result.push_back(load_field_str_code);
    }
    //    checking limit above ^^^
    result.emplace_back(ByteCodes::DefineStruct,
                        std::vector<char>(1, static_cast<uint8_t>(field_count))); // NOLINT(*-narrowing-conversions)

    return std::any{result};
}


std::any bytecode::SmplangBytecodeVisitor::visitType(SmplangParser::TypeContext *ctx) {
    return SmplangBaseVisitor::visitType(ctx);
}

std::any bytecode::SmplangBytecodeVisitor::visitPrimitiveType(SmplangParser::PrimitiveTypeContext *ctx) {
    return SmplangBaseVisitor::visitPrimitiveType(ctx);
}

// скип
std::any bytecode::SmplangBytecodeVisitor::visitStructType(SmplangParser::StructTypeContext *ctx) {
    return SmplangBaseVisitor::visitStructType(ctx);
}

std::any bytecode::SmplangBytecodeVisitor::visitBlock(SmplangParser::BlockContext *ctx) {
    std::vector<Operation> result{};
    for (auto *statement_ctx: ctx->statement()) {
        auto statement_code = vec_cast(visitStatement(statement_ctx));
        result.insert(result.end(), statement_code.begin(), statement_code.end());
    }
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitStatement(SmplangParser::StatementContext *ctx) {
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
        const auto &last_op = result.back();
        if (last_op.code == ByteCodes::Call) {
            std::string func_name(last_op.value_bytes.begin() + sizeof(int), last_op.value_bytes.end());
            if (void_typed_functions_.find(func_name) != void_typed_functions_.end()) {
                return result;
            }
        }
        result.emplace_back(ByteCodes::Pop);
        return result;
    }
//    TODO: throw
}

std::any bytecode::SmplangBytecodeVisitor::visitVarDecl(SmplangParser::VarDeclContext *ctx) {
    std::vector<Operation> result{};
    result.push_back(loadString(ctx->ID()->getText()));
    if (!ctx->expression()) {
        result.emplace_back(ByteCodes::Pop);
        return std::any{result};
    }
    auto expr_code = vec_cast(visitExpression(ctx->expression()));
    result.insert(result.end(), expr_code.begin(), expr_code.end());
    result.emplace_back(ByteCodes::StoreName);
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitAssignment(SmplangParser::AssignmentContext *ctx) {
    auto *assignable_ctx = ctx->assignable();
    std::vector<Operation> result{};
    if (!assignable_ctx->assignablePrefix()) {
        result.push_back(loadString(assignable_ctx->ID()->getText()));
        auto expr_code = vec_cast(visitExpression(ctx->expression()));
        result.insert(result.end(), expr_code.begin(), expr_code.end());
        result.emplace_back(ByteCodes::StoreName);
    } else {
        result = vec_cast(visitAssignablePrefix(assignable_ctx->assignablePrefix()));
        if (assignable_ctx->DOT()) {
            auto load_field_name = loadString(assignable_ctx->ID()->getText());
            result.push_back(load_field_name);
            auto expr_code = vec_cast(visitExpression(ctx->expression()));
            result.insert(result.end(), expr_code.begin(), expr_code.end());
            result.emplace_back(ByteCodes::StoreMember);
        } else if (assignable_ctx->LBRACK() && assignable_ctx->RBRACK()) {
            auto index_code = vec_cast(visitExpression(ctx->expression()));
            result.insert(result.end(), index_code.begin(), index_code.end());
            auto expr_code = vec_cast(visitExpression(ctx->expression()));
            result.insert(result.end(), expr_code.begin(), expr_code.end());
            result.emplace_back(ByteCodes::StoreSubscr);
        }
    }
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitIfStatement(SmplangParser::IfStatementContext *ctx) {
    return SmplangBaseVisitor::visitIfStatement(ctx);
}

std::any bytecode::SmplangBytecodeVisitor::visitWhileStatement(SmplangParser::WhileStatementContext *ctx) {
    auto loop_condition_expr = vec_cast(visitExpression(ctx->expression()));
    auto loop_body = (ctx->block()) ?
                     vec_cast(visitBlock(ctx->block())) :
                     vec_cast(visitStatement(ctx->statement()));
    int condition_ops_count = static_cast<int>(loop_condition_expr.size());
    int body_ops_count = static_cast<int>(loop_body.size());
    auto result = std::move(loop_condition_expr);
    result.emplace_back(ByteCodes::JumpIfFalse);
//    to be after unconditional jump
    appendToCharVector<int>(result.back().value_bytes, body_ops_count + 2);
    result.insert(result.end(), loop_body.begin(), loop_body.end());
    result.emplace_back(ByteCodes::Jump);
//    to be at condition start
    appendToCharVector<int>(result.back().value_bytes, -(body_ops_count + condition_ops_count + 1));
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitReturnStatement(SmplangParser::ReturnStatementContext *ctx) {
    std::vector<Operation> result{};
    if (ctx->expression()) {
        result = vec_cast(visitExpression(ctx->expression()));
    }
    result.emplace_back(ByteCodes::Return);
    return result;
}

std::any bytecode::SmplangBytecodeVisitor::visitExpression(SmplangParser::ExpressionContext *ctx) {
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
        if (ctx->NEG())
            result.back().value_bytes.push_back(static_cast<char>(UnaryOps::Minus));
        else if (ctx->NOT())
            result.back().value_bytes.push_back(static_cast<char>(UnaryOps::Not));
        return std::any{result};

    }
    auto first_operand = vec_cast(visitExpression(ctx->expression(0)));
    auto result = std::move(first_operand);
    auto second_operand = vec_cast(visitExpression(ctx->expression(1)));
    result.insert(result.end(), second_operand.begin(), second_operand.end());
    result.emplace_back(ByteCodes::BinaryOp);

    if (ctx->AND())
        result.back().value_bytes.push_back(static_cast<char>(BinaryOps::And));
    else if (ctx->OR())
        result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Or));
    else if (ctx->MULT()) {
        std::string op = ctx->MULT()->getText();
        if (op == "*")
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Mul));
        else if (op == "/")
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Div));
        else if (op == "%")
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Mod));
    } else if (ctx->ADD()) {
        std::string op = ctx->ADD()->getText();
        if (op == "+")
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Add));
        else if (op == "-")
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Sub));
    } else if (ctx->COMPOP()) {
        std::string op = ctx->COMPOP()->getText();
        if (op == "==")
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Eq));
        else if (op == "!=")
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::NotEq));
        else if (op == "<")
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Less));
        else if (op == ">")
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::Gr));
        else if (op == "<=")
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::LessEq));
        else if (op == ">=")
            result.back().value_bytes.push_back(static_cast<char>(BinaryOps::GrEq));
    }
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitPrimaryExpression(SmplangParser::PrimaryExpressionContext *ctx) {
    if (ctx->INT()) {
        cpp_int value(ctx->INT()->getText());
        return std::any{loadInt(value)};
    }
    if (ctx->BOOL()) {
        bool value = (ctx->BOOL()->getText() == "true") ? true : false;
        return std::any{loadBool(value)};
    }
    if (ctx->CHAR()) {
//        text ~= "\'[symbol]\'";
        char value = ctx->getText()[1];
        return std::any{loadChar(value)};
    }
    if (ctx->DOUBLE()) {
        double value = std::stod(ctx->DOUBLE()->getText());
        return std::any{loadDouble(value)};
    }
//    struct.field
    if (ctx->DOT()) {
        auto struct_expression = vec_cast(visitPrimaryExpression(ctx->primaryExpression()));
        auto result = std::move(struct_expression);
        appendLoadMember(result, ctx->ID());
        return std::any{result};
    }
//    IMPORTANT: after if DOT
//    just variable
    if (ctx->ID()) {
        return std::any{loadStringThenName(ctx->ID()->getText())};
    }
//    (...)
    if (ctx->LPAREN() && ctx->RPAREN()) {
        return visitExpression(ctx->expression());
    }
//    array[...]
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

// пока что скип
std::any bytecode::SmplangBytecodeVisitor::visitArrayInit(SmplangParser::ArrayInitContext *ctx) {
    return SmplangBaseVisitor::visitArrayInit(ctx);
}

std::any bytecode::SmplangBytecodeVisitor::visitArgumentList(SmplangParser::ArgumentListContext *ctx) {
    std::vector<Operation> result;
    for (auto *arg_expr_ctx: ctx->expression()) {
        auto expr_code = vec_cast(visitExpression(arg_expr_ctx));
        result.insert(result.end(), expr_code.begin(), expr_code.end());
    }
    return std::any{result};
}

std::any bytecode::SmplangBytecodeVisitor::visitFunctionCall(SmplangParser::FunctionCallContext *ctx) {
    std::vector<Operation> result = vec_cast(visitArgumentList(ctx->argumentList()));
    Operation load_func_name = loadString(ctx->ID()->getText());
    result.push_back(load_func_name);
    result.emplace_back(ByteCodes::Call);
    return std::any{result};
}


std::any bytecode::SmplangBytecodeVisitor::visitAssignablePrefix(SmplangParser::AssignablePrefixContext *ctx) {
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

bytecode::Operation bytecode::SmplangBytecodeVisitor::loadInt(const cpp_int &value) {
    Operation op(ByteCodes::LoadInt);
    appendIntToCharVector(op.value_bytes, value);
    return op;
}

bytecode::Operation bytecode::SmplangBytecodeVisitor::loadBool(bool value) {
    Operation op(ByteCodes::LoadBool);
    appendToCharVector(op.value_bytes, value);
    return op;
}

bytecode::Operation bytecode::SmplangBytecodeVisitor::loadChar(char value) {
    Operation op(ByteCodes::LoadChar);
    appendToCharVector(op.value_bytes, value);
    return op;
}

bytecode::Operation bytecode::SmplangBytecodeVisitor::loadDouble(double value) {
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

std::vector<bytecode::Operation> bytecode::SmplangBytecodeVisitor::loadStringThenName(std::string_view name) {
    std::vector result{1, loadString(name)};
    result.emplace_back(ByteCodes::LoadName);
    return result;
}

void bytecode::SmplangBytecodeVisitor::appendLoadMember(std::vector<bytecode::Operation> &code,
                                                        antlr4::tree::TerminalNode *ID_ptr) {
    auto load_field_name = loadString(ID_ptr->getText());
    code.push_back(load_field_name);
    code.emplace_back(ByteCodes::LoadMember);
}

std::any bytecode::SmplangBytecodeVisitor::visitIfBlock(SmplangParser::IfBlockContext *ctx) {
    return SmplangBaseVisitor::visitIfBlock(ctx);
}

std::any bytecode::SmplangBytecodeVisitor::visitElifBlock(SmplangParser::ElifBlockContext *ctx) {
    return SmplangBaseVisitor::visitElifBlock(ctx);
}

std::any bytecode::SmplangBytecodeVisitor::visitElseBlock(SmplangParser::ElseBlockContext *ctx) {
    return SmplangBaseVisitor::visitElseBlock(ctx);
}


std::vector<char> &bytecode::insertIntToCharVector(std::vector<char> &vector, const cpp_int &value, size_t position) {
    std::vector<char> v;
    std::cout << value << '\n';
    boost::multiprecision::export_bits(value, std::back_inserter(v), 8);
    insertToCharVector<int>(vector, static_cast<int>(v.size()), position);
    vector.insert(vector.begin() + position + 4, v.begin(), v.end());
    return vector;
}

std::vector<char> &bytecode::appendIntToCharVector(std::vector<char> &vector, const cpp_int &value) {
    return insertIntToCharVector(vector, value, vector.size());
}

bytecode::Operation::Operation(bytecode::ByteCodes code, const std::vector<char> &valueBytes) : code(code), value_bytes(
        valueBytes) {}

bytecode::Operation::Operation(bytecode::ByteCodes code) : code(code), value_bytes{} {}
