#pragma once

#include <cstdint>

enum class TypeIndex : uint16_t {
    Bool,
    Char,
    Int,
    Double,
    Array,
    Struct,
    Null,
};
