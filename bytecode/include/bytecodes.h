#pragma once
namespace bytecode {
    enum class ByteCodes : char {
        NullOp,
        LoadInt,
        LoadChar,
        LoadBool,
        LoadDouble,
        LoadString,
        LoadName,
        LoadSubscr,
        LoadMember,
        StoreName,
        StoreSubscr,
        StoreMember,
        MakeFunction,
        Call,
        Return,
        UnaryOp,
        BinaryOp,
        BuildArray,
        BuildStruct,
        DefineStruct,
        Jump,
        JumpIfTrue,
        JumpIfFalse,
        Copy,
        Pop,
    };

    enum class BinaryOps : char {
        Add,
        Sub,
        Mul,
        Div,
        Mod,
        And,
        Or,
        RShift,
        LShift,
        Xor,
        Eq,
        NotEq,
        Less,
        Gr,
        LessEq,
        GrEq,
    };

    enum class UnaryOps : char {
        Minus,
        Not,
    };
}