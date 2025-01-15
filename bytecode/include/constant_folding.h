#pragma once
#include <vector>
#include "operation.h"
#include <boost/multiprecision/cpp_int.hpp>

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

    cpp_int parseIntFromBytes(const std::vector<char>& value_bytes);

    template <typename T>
    T parseFromBytes(const std::vector<char>& value_bytes);

    Operation foldUnop(const Operation& load_op, const Operation& unop);
    Operation foldBinop(const Operation& load_op_first, const Operation& load_op_second, const Operation& unop);

} // namespace bytecode