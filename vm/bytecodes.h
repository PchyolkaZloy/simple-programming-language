#pragma once

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
