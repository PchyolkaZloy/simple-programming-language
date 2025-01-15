#pragma once

#include "bytecodes.h"
#include <vector>
namespace bytecode {
    struct Operation {
    public:
        Operation(ByteCodes code, const std::vector<char>& valueBytes)
            : code(code)
            , value_bytes(valueBytes){};
        Operation(const Operation& other) = default;

        Operation(Operation&& other) = default;

        Operation() = default;

        explicit Operation(ByteCodes code)
            : code(code)
            , value_bytes(std::vector<char>{}){};

        Operation& operator=(const Operation& other) = default;

        Operation& operator=(Operation&& other) = default;

        ByteCodes code;
        std::vector<char> value_bytes;
    };
} // namespace bytecode