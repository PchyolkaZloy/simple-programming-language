#pragma once
namespace bytecode {

    enum class BinaryOperator {
        Mult,
        Div,
        Mod,
        Add,
        Sub,
        Eq,
        Neq,
        Lt,
        Gt,
        Le,
        Ge,
        And,
        Or
    };
    enum class UnaryOperator {
        Minus,
        Not
    };
}