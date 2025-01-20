#pragma once

enum class ByteCodes : char {
    NullOp,
    LoadNull,
    LoadInt,
    LoadChar,
    LoadBool,
    LoadDouble,
    LoadString,
    LoadType,
    LoadName,
    LoadSubscr,
    LoadMember,
    LoadVarByIndex, // for jit compiled code
    StoreName,
    StoreSubscr,
    StoreMember,
    StoreVarByIndex, // for jit compiled code
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
    Incorrect, // ending op for counting size of ByteCodes
};

enum class BinaryOps : char {
    Add,
    Sub,
    Mul,
    Div,
    Mod,
    And,
    Or,
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
