#include "types.h"

#include <iostream>
#include <map>
#include <unordered_map>
#include <array>
#include <string>
#include <variant>
#include <fstream>
#include <stack>

enum class ByteCodes : char {
    NullOp,
    LoadInt,
    LoadChar,
    LoadBool,
    LoadDouble,
    LoadString,
    LoadName,
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

enum class UnaryOp : char {
    Minus,
    Not,
};

struct Frame {
    static constexpr std::array<BaseType* (*)(const BaseType&, const BaseType&), 6> BINARY_OPS = {
        [](const BaseType& x, const BaseType& y) { return x + y; },
        [](const BaseType& x, const BaseType& y) { return x - y; },
        [](const BaseType& x, const BaseType& y) { return x * y; },
        [](const BaseType& x, const BaseType& y) { return x / y; },
        // TODO
        // [](const BaseType& x, const BaseType& y) { return x % y; },
        // [](const BaseType& x, const BaseType& y) { return x & y; },
        // [](const BaseType& x, const BaseType& y) { return x | y; },
        // [](const BaseType& x, const BaseType& y) { return x << y; },
        // [](const BaseType& x, const BaseType& y) { return x >> y; },
        // [](const BaseType& x, const BaseType& y) { return x ^ y; }
        [](const BaseType& x, const BaseType& y) { return static_cast<BaseType*>(x == y); },
        [](const BaseType& x, const BaseType& y) { return static_cast<BaseType*>(x != y); }
        // TODO
        // [](const BaseType& x, const BaseType& y) { return x < y; },
        // [](const BaseType& x, const BaseType& y) { return x > y; },
        // [](const BaseType& x, const BaseType& y) { return x <= y; },
        // [](const BaseType& x, const BaseType& y) { return x >= y; }
    };

    // static constexpr std::array<BaseType* (*)(const BaseType&), 2> UNARY_OPS = {
    //     [](const BaseType& x) { return -x; }};
    //     [](const BaseType& x) { return !x; },
    // }

    Frame(
        std::ifstream code,
        std::unordered_map<std::string, BaseType*> builtins,
        std::unordered_map<std::string, BaseType*> globals,
        std::unordered_map<std::string, BaseType*> locals,
        Frame* parentFrame)
        : Code(code)
        , Builtins(builtins)
        , Globals(globals)
        , Locals(locals)
        , ParentFrame(parentFrame)
        , DataStack()
        , ReturnValue()
        , ShouldReturn()
        , Offset() {
    }

    void Run() {
        instructions = list(dis.get_instructions(self.code))
        instruction_offsets = {j.offset: i for i, j in enumerate(instructions)}
        cur_instruction = 0
        while cur_instruction < len(instructions):
            instruction = instructions[cur_instruction]
            cur_instruction += 1
            getattr(self, instruction.opname.lower() + "_op")(instruction.arg, instruction.argval)
            if self.offset:
                cur_instruction = instruction_offsets[self.offset]
                self.offset = None
            if self.should_return:
                return self.return_value
        return self.return_value
    }

    BaseType& Top() {
        return *DataStack.back();
    }

    BaseType& Pop() {
        BaseType& ret = Top();
        DataStack.pop_back();
        return ret;
    }

    std::string PopString() {
        Array& name = static_cast<Array&>(Pop());
        std::vector<BaseType*> v = name.GetArray();
        std::string nameStr = "";
        nameStr.reserve(name.Size());
        for (BaseType* i : v) {
            nameStr += *static_cast<char*>(i->Value);
        }
        return nameStr;
    }

    std::vector<BaseType*> Popn(size_t n) {
        if (n <= 0) {
            return {};
        }
        std::vector<BaseType*> ret;
        std::copy(DataStack.end() - n, DataStack.end(), std::back_inserter(ret));
        DataStack.erase(DataStack.end() - n, DataStack.end());
        return ret;
    }

    void Push(BaseType* value) {
        DataStack.push_back(value);
    }

    void LoadNull() {
        Push(new Null());
    }

    void LoadInt(int arg) {
        Push(new Int(new int(arg)));
    }

    void LoadString(const std::string& s) {
        Array* arr = new Array(TypeIndex::Char);
        for (const auto& i : s) {
            arr->Append(new Char(new char(i)));
        }
        Push(arr);
    }

    void LoadDouble(double arg) {
        Push(new Double(new double(arg)));
    }

    void LoadName() {
        std::string name = PopString();
        if (Locals.contains(name)) {
            Push(Locals.at(name));
        } else if (Globals.contains(name)) {
            Push(Globals.at(name));
        } else if (Builtins.contains(name)) {
            Push(Builtins.at(name));
        } else {
            throw std::invalid_argument(std::format("name '{}' is not defined", name));
        }
    }

    void StoreName() {
        std::string name = PopString();
        Locals[name] = &Pop();
    }

    void StoreSubscr() {
        auto key = Pop();
        auto container = Pop();
        auto value = Pop();
        container[key] = value;
    }

    void StoreMember() {
        std::string name = PopString();
        auto obj = Pop();
        auto value = Pop();
        setattr(obj, name, value);
    }

    void Return() {
        ReturnValue = &Pop();
        ShouldReturn = true;
    }

    void MakeFunction() {
        auto code = Pop();
        auto f = []() {
            std::unordered_map<std::string, BaseType*> fLocals;

            auto frame = Frame(code, Builtins, Globals, fLocals, *this);
            return frame.Run();
        };

        Push(f);
    }

    void Call() {
        int argc = Pop().IntCast();
        std::vector<BaseType*> args = Popn(argc);
        BaseType& f = Pop();
        // TODO functions
        Push(f(args));
    }

    void UnaryOp() {
        size_t opCode = Pop().IntCast();
        DataStack.back() = UNARY_OPS[opCode](*DataStack.back());
    }

    void BinaryOp() {
        size_t opCode = Pop().IntCast();
        auto right = Pop();
        auto left = Pop();
        Push(BINARY_OPS[opCode](left, right));
    }

    void BuildArray() {
        size_t count = Pop().IntCast();
        Push(Popn(count));
    }

    void ArrayAppend() {
        size_t arrayIdx = Pop().IntCast();
        auto elem = Pop();
        auto arr = *(DataStack.end() - arrayIdx);
        arr->Append(elem);
    }

    void Jump() {
        size_t instruction = Pop().IntCast();
        Offset = instruction;
    }

    void JumpIfTrue() {
        size_t instruction = Pop().IntCast();
        if (Pop()) {
            Offset = instruction;
        }
    }

    void JumpIfFalse() {
        size_t instruction = Pop().IntCast();
        if (!Pop()) {
            Offset = instruction;
        }
    }

    void Copy() {
        // TODO copy method of BaseType
        Push(DataStack.back());
    }

    std::ifstream Code;
    std::unordered_map<std::string, BaseType*> Builtins;
    std::unordered_map<std::string, BaseType*> Globals;
    std::unordered_map<std::string, BaseType*> Locals;
    Frame* ParentFrame;
    std::vector<BaseType*> DataStack;
    BaseType* ReturnValue;
    bool ShouldReturn;
    std::optional<int> Offset;
};

struct VirtualMachine {
    void run(std::ifstream code) {
        std::unordered_map<std::string, BaseType*> globals_context{};
        auto frame = Frame(code_obj, builtins.globals()['__builtins__'], globals_context, globals_context);
        frame.Run();
    }
};
