#pragma once

#include "types.h"
#include "bytecodes.h"

#include "SmplangBytecodeVisitor.h"

#include <iostream>
#include <unordered_map>
#include <array>
#include <string>
#include <variant>
#include <fstream>
#include <stack>
#include <iterator>
#include <memory>
#include <span>
#include <ranges>
#include <format>

#include "boost/multiprecision/cpp_int.hpp"

using cpp_int = boost::multiprecision::cpp_int;

struct Frame;

struct BytecodeOpBase {
    virtual void Parse(std::ifstream& stream) = 0;
    virtual void Parse(const bytecode::Operation& op) = 0;
    virtual void operator()(Frame& frame) = 0;
    virtual ByteCodes GetByteCode() = 0;
    virtual ~BytecodeOpBase() = default;
};

struct Function {
    std::vector<std::string*> Params;
    std::span<std::unique_ptr<BytecodeOpBase>> Code;
    std::vector<std::unique_ptr<BytecodeOpBase>> JitCompiled;
};

struct Frame {
    static constexpr std::array<std::shared_ptr<BaseType> (*)(const BaseType&, const BaseType&), 13> BINARY_OPS = {
        [](const BaseType& x, const BaseType& y) { return x + y; },
        [](const BaseType& x, const BaseType& y) { return x - y; },
        [](const BaseType& x, const BaseType& y) { return x * y; },
        [](const BaseType& x, const BaseType& y) { return x / y; },
        [](const BaseType& x, const BaseType& y) { return x % y; },
        [](const BaseType& x, const BaseType& y) { return x & y; },
        [](const BaseType& x, const BaseType& y) { return x | y; },
        [](const BaseType& x, const BaseType& y) { return static_cast<std::shared_ptr<BaseType>>(x == y); },
        [](const BaseType& x, const BaseType& y) { return static_cast<std::shared_ptr<BaseType>>(x != y); },
        [](const BaseType& x, const BaseType& y) { return static_cast<std::shared_ptr<BaseType>>(x < y); },
        [](const BaseType& x, const BaseType& y) { return static_cast<std::shared_ptr<BaseType>>(x > y); },
        [](const BaseType& x, const BaseType& y) { return static_cast<std::shared_ptr<BaseType>>(x <= y); },
        [](const BaseType& x, const BaseType& y) { return static_cast<std::shared_ptr<BaseType>>(x >= y); }};

    static constexpr std::array<std::shared_ptr<BaseType> (*)(const BaseType&), 2> UNARY_OPS = {
        [](const BaseType& x) { return -x; },
        [](const BaseType& x) { return static_cast<std::shared_ptr<BaseType>>(!x); }
    };

    Frame(
        std::span<std::unique_ptr<BytecodeOpBase>>& instructions,
        std::unordered_map<std::string, std::shared_ptr<BaseType>>& builtins,
        std::unordered_map<std::string, std::shared_ptr<BaseType>>& globals,
        std::unordered_map<std::string, std::shared_ptr<BaseType>>& locals,
        std::unordered_map<std::string, Function>& builtinFunctions,
        Frame* parentFrame);

    void ReadFunction(int& cur_instruction);
    std::shared_ptr<BaseType> Run();
    std::shared_ptr<BaseType>& Top();
    std::string& PopString();
    std::vector<std::shared_ptr<BaseType>> Popn(size_t n);
    std::vector<std::string*> PopnStrings(size_t n);
    void Push(std::shared_ptr<BaseType>&& value);
    void Push(const std::shared_ptr<BaseType>& value);
    void Push(std::string* value);
    void LoadInt(BaseType::IntType* num);
    void LoadChar(char* arg);
    void LoadBool(bool* arg);
    void LoadDouble(double* arg);
    void LoadString(std::string* s);
    void LoadName();
    void StoreName();
    void LoadSubscr();
    void LoadMember();
    void StoreSubscr();
    void StoreMember();
    void MakeFunction(int argc);
    void Call();
    void Return();
    void UnaryOp(UnaryOps opCode);
    void BinaryOp(BinaryOps opCode);
    void BuildArray(int count);
    void BuildStruct();
    void DefineStruct(int fieldc);
    void Jump(int offset);
    void JumpIfTrue(int offset);
    void JumpIfFalse(int offset);
    void Copy();

    template <std::derived_from<BaseType> T = BaseType>
    std::shared_ptr<T> Pop() {
        std::shared_ptr<T> ret = std::move(reinterpret_cast<std::shared_ptr<T>&>(Top()));
        DataStack.pop_back();
        return ret;
    }

    std::span<std::unique_ptr<BytecodeOpBase>>& Instructions;
    std::unordered_map<std::string, std::shared_ptr<BaseType>> Builtins;
    std::unordered_map<std::string, std::shared_ptr<BaseType>> Globals;
    std::unordered_map<std::string, std::shared_ptr<BaseType>> Locals;
    Frame* ParentFrame;
    std::vector<std::variant<std::shared_ptr<BaseType>, std::string*>> DataStack;
    std::shared_ptr<BaseType> ReturnValue;
    bool ShouldReturn;
    std::optional<int> Offset;
    std::unordered_map<std::string, Function>& Functions;
    Function* ReadingFunction;
};

struct NullOp: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
    }
    void Parse(const bytecode::Operation& op) override {
    }
    void operator()(Frame& frame) override {
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::NullOp;
    }
};

struct LoadInt: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        // if size < 0, then cpp_int is negative
        int size = 0;
        stream.read(reinterpret_cast<char*>(&size), 4);
        char* bytes = new char[abs(size)];
        stream.read(bytes, abs(size));
        boost::multiprecision::import_bits(num, bytes, bytes + abs(size));
        if (size < 0) {
            num = -num;
        }
    }
    void Parse(const bytecode::Operation& op) override {
        // if size < 0, then cpp_int is negative
        int size = *reinterpret_cast<const int*>(op.value_bytes.data());
        const std::vector<char>& bytes = op.value_bytes;
        boost::multiprecision::import_bits(num, bytes.begin() + 4, bytes.end());
        if (size < 0) {
            num = -num;
        }
    }
    void operator()(Frame& frame) override {
        frame.LoadInt(&num);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::LoadInt;
    }

    cpp_int num;
};

struct LoadChar: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        c = stream.get();
    }
    void Parse(const bytecode::Operation& op) override {
        c = op.value_bytes[0];
    }
    void operator()(Frame& frame) override {
        frame.LoadChar(&c);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::LoadChar;
    }

    char c;
};

struct LoadBool: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        b = stream.get();
    }
    void Parse(const bytecode::Operation& op) override {
        b = op.value_bytes[0];
    }
    void operator()(Frame& frame) override {
        frame.LoadBool(&b);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::LoadBool;
    }

    bool b;
};

struct LoadDouble: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        stream.read(reinterpret_cast<char*>(&d), sizeof(double));
    }
    void Parse(const bytecode::Operation& op) override {
        d = *reinterpret_cast<const double*>(op.value_bytes.data());
    }
    void operator()(Frame& frame) override {
        frame.LoadDouble(&d);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::LoadDouble;
    }

    double d;
};

struct LoadString: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        int size = 0;
        stream.read(reinterpret_cast<char*>(&size), 4);
        s.resize(size);
        stream.read(s.data(), size);
    }
    void Parse(const bytecode::Operation& op) override {
        s = std::string(op.value_bytes.begin() + 4, op.value_bytes.end());
    }
    void operator()(Frame& frame) override {
        frame.LoadString(&s);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::LoadString;
    }

    std::string s;
};

struct MakeFunction: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        stream.read(reinterpret_cast<char*>(&argc), 1);
    }
    void Parse(const bytecode::Operation& op) override {
        argc = op.value_bytes[0];
    }
    void operator()(Frame& frame) override {
        frame.MakeFunction(argc);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::MakeFunction;
    }

    uint8_t argc = 0;
};

struct UnaryOp: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        stream.read(reinterpret_cast<char*>(&op), 1);
    }
    void Parse(const bytecode::Operation& op) override {
        this->op = UnaryOps(op.value_bytes[0]);
    }
    void operator()(Frame& frame) override {
        frame.UnaryOp(op);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::UnaryOp;
    }

    UnaryOps op;
};

struct BinaryOp: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        stream.read(reinterpret_cast<char*>(&op), 1);
    }
    void Parse(const bytecode::Operation& op) override {
        this->op = BinaryOps(op.value_bytes[0]);
    }
    void operator()(Frame& frame) override {
        frame.BinaryOp(op);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::BinaryOp;
    }

    BinaryOps op;
};

struct BuildArray: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        stream.read(reinterpret_cast<char*>(&cnt), 4);
    }
    void Parse(const bytecode::Operation& op) override {
        cnt = *reinterpret_cast<const int*>(op.value_bytes.data());
    }
    void operator()(Frame& frame) override {
        frame.BuildArray(cnt);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::BuildArray;
    }

    int cnt = 0;
};

struct DefineStruct: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        stream.read(reinterpret_cast<char*>(&fieldc), 1);
    }
    void Parse(const bytecode::Operation& op) override {
        fieldc = op.value_bytes[0];
    }
    void operator()(Frame& frame) override {
        frame.DefineStruct(fieldc);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::DefineStruct;
    }

    uint8_t fieldc = 0;
};

#define DefJump(Name)                                                      \
    struct Name: public BytecodeOpBase {                                   \
        void Parse(std::ifstream& stream) override {                       \
            stream.read(reinterpret_cast<char*>(&offset), 4);              \
        }                                                                  \
        void Parse(const bytecode::Operation& op) override {               \
            offset = *reinterpret_cast<const int*>(op.value_bytes.data()); \
        }                                                                  \
        void operator()(Frame& frame) override {                           \
            frame.Name(offset);                                            \
        }                                                                  \
        ByteCodes GetByteCode() override {                                 \
            return ByteCodes::Name;                                        \
        }                                                                  \
        int offset = 0;                                                    \
    }

DefJump(Jump);
DefJump(JumpIfTrue);
DefJump(JumpIfFalse);

#define DefOp(Name)                                          \
    struct Name: public BytecodeOpBase {                     \
        void Parse(std::ifstream& stream) override {         \
        }                                                    \
        void Parse(const bytecode::Operation& op) override { \
        }                                                    \
        void operator()(Frame& frame) override {             \
            frame.Name();                                    \
        }                                                    \
        ByteCodes GetByteCode() override {                   \
            return ByteCodes::Name;                          \
        }                                                    \
    }

DefOp(LoadName);
DefOp(LoadSubscr);
DefOp(LoadMember);
DefOp(StoreName);
DefOp(StoreSubscr);
DefOp(StoreMember);
DefOp(Call);
DefOp(Return);
DefOp(BuildStruct);
DefOp(Copy);
DefOp(Pop);

template <std::derived_from<BytecodeOpBase> T>
std::unique_ptr<BytecodeOpBase> BytecodeOpFactoryIfstream(std::ifstream& code) {
    std::unique_ptr<BytecodeOpBase> op = std::make_unique<T>();
    op->Parse(code);
    return op;
}

template <std::derived_from<BytecodeOpBase> T>
std::unique_ptr<BytecodeOpBase> BytecodeOpFactoryCompiler(const bytecode::Operation& code) {
    std::unique_ptr<BytecodeOpBase> op = std::make_unique<T>();
    op->Parse(code);
    return op;
}

struct VirtualMachine {
    static constexpr std::array<std::unique_ptr<BytecodeOpBase> (*)(std::ifstream&), 25> IfstreamBasedOpFactories = {
        BytecodeOpFactoryIfstream<NullOp>,
        BytecodeOpFactoryIfstream<::LoadInt>,
        BytecodeOpFactoryIfstream<::LoadChar>,
        BytecodeOpFactoryIfstream<LoadBool>,
        BytecodeOpFactoryIfstream<::LoadDouble>,
        BytecodeOpFactoryIfstream<::LoadString>,
        BytecodeOpFactoryIfstream<LoadName>,
        BytecodeOpFactoryIfstream<LoadSubscr>,
        BytecodeOpFactoryIfstream<LoadMember>,
        BytecodeOpFactoryIfstream<StoreName>,
        BytecodeOpFactoryIfstream<StoreSubscr>,
        BytecodeOpFactoryIfstream<StoreMember>,
        BytecodeOpFactoryIfstream<MakeFunction>,
        BytecodeOpFactoryIfstream<Call>,
        BytecodeOpFactoryIfstream<Return>,
        BytecodeOpFactoryIfstream<UnaryOp>,
        BytecodeOpFactoryIfstream<BinaryOp>,
        BytecodeOpFactoryIfstream<BuildArray>,
        BytecodeOpFactoryIfstream<BuildStruct>,
        BytecodeOpFactoryIfstream<DefineStruct>,
        BytecodeOpFactoryIfstream<Jump>,
        BytecodeOpFactoryIfstream<JumpIfTrue>,
        BytecodeOpFactoryIfstream<JumpIfFalse>,
        BytecodeOpFactoryIfstream<Copy>,
        BytecodeOpFactoryIfstream<Pop>,
    };

    static constexpr std::array<std::unique_ptr<BytecodeOpBase> (*)(const bytecode::Operation&), 25> CompilerBasedOpFactories = {
        BytecodeOpFactoryCompiler<NullOp>,
        BytecodeOpFactoryCompiler<::LoadInt>,
        BytecodeOpFactoryCompiler<::LoadChar>,
        BytecodeOpFactoryCompiler<LoadBool>,
        BytecodeOpFactoryCompiler<::LoadDouble>,
        BytecodeOpFactoryCompiler<::LoadString>,
        BytecodeOpFactoryCompiler<LoadName>,
        BytecodeOpFactoryCompiler<LoadSubscr>,
        BytecodeOpFactoryCompiler<LoadMember>,
        BytecodeOpFactoryCompiler<StoreName>,
        BytecodeOpFactoryCompiler<StoreSubscr>,
        BytecodeOpFactoryCompiler<StoreMember>,
        BytecodeOpFactoryCompiler<MakeFunction>,
        BytecodeOpFactoryCompiler<Call>,
        BytecodeOpFactoryCompiler<Return>,
        BytecodeOpFactoryCompiler<UnaryOp>,
        BytecodeOpFactoryCompiler<BinaryOp>,
        BytecodeOpFactoryCompiler<BuildArray>,
        BytecodeOpFactoryCompiler<BuildStruct>,
        BytecodeOpFactoryCompiler<DefineStruct>,
        BytecodeOpFactoryCompiler<Jump>,
        BytecodeOpFactoryCompiler<JumpIfTrue>,
        BytecodeOpFactoryCompiler<JumpIfFalse>,
        BytecodeOpFactoryCompiler<Copy>,
        BytecodeOpFactoryCompiler<Pop>,
    };

    static_assert(IfstreamBasedOpFactories.size() == static_cast<char>(ByteCodes::Incorrect));
    static_assert(CompilerBasedOpFactories.size() == static_cast<char>(ByteCodes::Incorrect));

    std::unordered_map<std::string, Function> CreateBuiltinFunctions() {
        return {};
    }

    void Run(std::ifstream& code) {
        ByteCodes bytecode;
        while (code.read(reinterpret_cast<char*>(&bytecode), 1)) {
            Code.push_back(IfstreamBasedOpFactories[static_cast<char>(bytecode)](code));
        }

        std::unordered_map<std::string, std::shared_ptr<BaseType>> globals{};
        std::unordered_map<std::string, std::shared_ptr<BaseType>> builtins{};
        std::span<std::unique_ptr<BytecodeOpBase>> instructions(Code.begin(), Code.end());
        std::unordered_map<std::string, Function> builtinFunctions = CreateBuiltinFunctions();
        auto frame = Frame(instructions, builtins, globals, globals, builtinFunctions, nullptr);
        frame.Run();
    }

    void Run(const std::vector<bytecode::Operation>& code) {
        for (const auto& c : code) {
            Code.push_back(CompilerBasedOpFactories[static_cast<char>(c.code)](c));
        }

        std::unordered_map<std::string, std::shared_ptr<BaseType>> globals{};
        std::unordered_map<std::string, std::shared_ptr<BaseType>> builtins{};
        std::span<std::unique_ptr<BytecodeOpBase>> instructions(Code.begin(), Code.end());
        std::unordered_map<std::string, Function> builtinFunctions = CreateBuiltinFunctions();
        auto frame = Frame(instructions, builtins, globals, globals, builtinFunctions, nullptr);
        frame.Run();
    }

    std::vector<std::unique_ptr<BytecodeOpBase>> Code;
};
