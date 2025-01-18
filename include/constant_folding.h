#pragma once

#include "SmplangBytecodeVisitor.h"
#include "smplang_common.h"
#include "types.h"
#include "vm.h"
#include <vector>
#include <unordered_map>
#include "operation.h"
#include "types.h"
#include "eof_fix.h"
#include <memory>

using cpp_int = boost::multiprecision::cpp_int;

namespace bytecode {

    std::vector<Operation> foldConstants(const std::vector<Operation>& initial_code);

    inline bool isConstant(const Operation& op) {
        switch (op.code) {
            case ByteCodes::LoadInt:
            case ByteCodes::LoadChar:
            case ByteCodes::LoadBool:
            case ByteCodes::LoadDouble:
                return true;
            default:
                return false;
        }
    };

    std::shared_ptr<BaseType> getValue(const Operation& op);

    cpp_int parseIntFromBytes(const std::vector<char>& value_bytes) {
        // if size < 0, then cpp_int is negative
        int size = *reinterpret_cast<const int*>(value_bytes.data());
        cpp_int num;
        boost::multiprecision::import_bits(num, value_bytes.begin() + sizeof(int), value_bytes.end());
        if (size < 0) {
            num = -num;
        }
        return num;
    }

    template <typename T>
    T parseFromBytes(const std::vector<char>& value_bytes) {
        T value;
        return *reinterpret_cast<const T*>(value_bytes.data());
    }

    Operation foldUnop(const Operation& load_op, const Operation& unop);
    Operation foldBinop(const Operation& load_op_first, const Operation& load_op_second, const Operation& binop);

} // namespace bytecode

std::vector<bytecode::Operation> bytecode::foldConstants(const std::vector<Operation>& initial_code) {
    std::vector<Operation> result{};
    std::vector<size_t> old_to_new;
    std::unordered_map<size_t, size_t> new_to_old;
    // assuming code is correct here (e.g. BinOp can't be first operation in code)
    for (const auto& op : initial_code) {
        old_to_new.push_back(result.size());
        // they'll be counted incorrectly inside folds
        // but it doesn't matter because we can't jump inside expression
        if (!(op.code == ByteCodes::BinaryOp || op.code == ByteCodes::UnaryOp)) {
            if (op.code == ByteCodes::Jump || op.code == ByteCodes::JumpIfFalse || op.code == ByteCodes::JumpIfTrue) {
                new_to_old[result.size()] = old_to_new.size() - 1;
            }
            result.push_back(op);
            continue;
        }
        if (op.code == ByteCodes::UnaryOp) {
            const auto& load_op = result.back();
            if (!isConstant(load_op)) {
                result.push_back(op);
                continue;
            }
            result.back() = foldUnop(load_op, op);
        } else {
            const auto& load_op_first = result[result.size() - 2];
            const auto& load_op_second = result.back();
            if (!isConstant(load_op_first) || !isConstant(load_op_second)) {
                result.push_back(op);
                continue;
            }

            auto new_load_op = foldBinop(load_op_first, load_op_second, op);
            result.pop_back();
            result.back() = new_load_op;
        }
    }

    for (size_t i = 0; i < result.size(); ++i) {
        auto& op = result[i];
        if (op.code == ByteCodes::Jump || op.code == ByteCodes::JumpIfFalse || op.code == ByteCodes::JumpIfTrue) {
            int old_offset = parseFromBytes<int>(op.value_bytes);
            op.value_bytes.clear();
            size_t jump_old_pos = new_to_old[i];
            int jump_to_old_pos = static_cast<int>(jump_old_pos) + old_offset;
            int jump_to_new_pos;
            if (jump_to_old_pos > old_to_new.size() - 1 || jump_to_old_pos < 0) {
                jump_to_new_pos = jump_to_old_pos;
            } else {
                jump_to_new_pos = static_cast<int>(old_to_new[static_cast<size_t>(jump_to_old_pos)]);
            }
            int new_offset = jump_to_new_pos - static_cast<int>(i);
            appendToCharVector<int>(op.value_bytes, new_offset);
        }
    }
    return result;
}

bytecode::Operation bytecode::foldUnop(const bytecode::Operation& load_op, const bytecode::Operation& unop) {
    auto unop_value = parseFromBytes<UnaryOps>(unop.value_bytes);
    std::shared_ptr<BaseType> initial_value = getValue(load_op);
    gc::Ref<BaseType> result = nullptr;
    Operation result_op;
    result = Frame::UNARY_OPS[static_cast<char>(unop_value)](*initial_value);
    if (!initial_value || !result) {
        throw ConstantFoldingException("unexpected type");
    }
    if (result.object().Type == TypeIndex::Double) {
        result_op.code = ByteCodes::LoadDouble;
        appendToCharVector<double>(result_op.value_bytes, std::get<double>(result.object().Value));
    } else if (result.object().Type == TypeIndex::Int) {
        result_op.code = ByteCodes::LoadInt;
        appendIntToCharVector(result_op.value_bytes, std::get<cpp_int>(result.object().Value));
    } else if (result.object().Type == TypeIndex::Bool) {
        result_op.code = ByteCodes::LoadBool;
        appendToCharVector<bool>(result_op.value_bytes, std::get<bool>(result.object().Value));
    } else if (result.object().Type == TypeIndex::Char) {
        result_op.code = ByteCodes::LoadChar;
        appendToCharVector<char>(result_op.value_bytes, std::get<char>(result.object().Value));
    } else {
        throw ConstantFoldingException("unknown result primitive type");
    }
    return result_op;
}

bytecode::Operation bytecode::foldBinop(const bytecode::Operation& load_op_first, const bytecode::Operation& load_op_second, const bytecode::Operation& binop) {
    using var_t = std::variant<cpp_int, double, bool, char>;
    auto binop_value = parseFromBytes<BinaryOps>(binop.value_bytes);
    std::shared_ptr<BaseType> first_value = getValue(load_op_first);
    std::shared_ptr<BaseType> second_value = getValue(load_op_second);
    gc::Ref<BaseType> result = nullptr;
    Operation result_op;
    if (!first_value || !second_value) {
        throw ConstantFoldingException("unexpected type");
    }
    result = Frame::BINARY_OPS[static_cast<char>(binop_value)](*first_value, *second_value);
    if (result.object().Type == TypeIndex::Double) {
        result_op.code = ByteCodes::LoadDouble;
        appendToCharVector<double>(result_op.value_bytes, std::get<double>(result.object().Value));
    } else if (result.object().Type == TypeIndex::Int) {
        result_op.code = ByteCodes::LoadInt;
        appendIntToCharVector(result_op.value_bytes, std::get<cpp_int>(result.object().Value));
    } else if (result.object().Type == TypeIndex::Bool) {
        result_op.code = ByteCodes::LoadBool;
        appendToCharVector<bool>(result_op.value_bytes, std::get<bool>(result.object().Value));
    } else if (result.object().Type == TypeIndex::Char) {
        result_op.code = ByteCodes::LoadChar;
        appendToCharVector<char>(result_op.value_bytes, std::get<char>(result.object().Value));
    } else {
        throw ConstantFoldingException("unknown result primitive type");
    }
    return result_op;
}

std::shared_ptr<BaseType> bytecode::getValue(const bytecode::Operation& op) {
    switch (op.code) {
        case ByteCodes::LoadInt:
            return std::make_shared<Int>(parseIntFromBytes(op.value_bytes));
        case ByteCodes::LoadChar:
            return std::make_shared<Char>(parseFromBytes<char>(op.value_bytes));
        case ByteCodes::LoadBool:
            return std::make_shared<Bool>(parseFromBytes<bool>(op.value_bytes));
        case ByteCodes::LoadDouble:
            return std::make_shared<Double>(parseFromBytes<double>(op.value_bytes));
        default:
            return nullptr;
    }
}