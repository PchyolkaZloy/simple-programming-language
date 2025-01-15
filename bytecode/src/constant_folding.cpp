#include "constant_folding.h"
#include "type_inference.h"
#include "variables_util.h"
#include "SmplangBytecodeVisitor.h"

// LoadInt,
// LoadChar,
// LoadBool,
// LoadDouble,

std::vector<bytecode::Operation> bytecode::foldConstants(const std::vector<Operation>& initial_code) {
    std::vector<Operation> result{};
    // assuming code is correct here (e.g. BinOp can't be first operation in code)
    for (const auto& op : initial_code) {
        if (!(op.code == ByteCodes::BinaryOp || op.code == ByteCodes::UnaryOp)) {
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
    return result;
}

cpp_int bytecode::parseIntFromBytes(const std::vector<char>& value_bytes) {
    // if size < 0, then cpp_int is negative
    int size = *reinterpret_cast<const int*>(value_bytes.data());
    cpp_int num;
    boost::multiprecision::import_bits(num, value_bytes.begin() + sizeof(int), value_bytes.end());
    if (size < 0) {
        num = -num;
    }
    return num;
}

bytecode::Operation bytecode::foldUnop(const bytecode::Operation& load_op, const bytecode::Operation& unop) {
    auto unop_value = parseFromBytes<UnaryOps>(unop.value_bytes);
    return bytecode::Operation();
}

bytecode::Operation bytecode::foldBinop(const bytecode::Operation& load_op_first, const bytecode::Operation& load_op_second, const bytecode::Operation& unop) {
    return bytecode::Operation();
}

template <typename T>
T bytecode::parseFromBytes(const std::vector<char>& value_bytes) {
    T value;
    return *reinterpret_cast<const T*>(value_bytes.data());
}
