#pragma once

#include "types.h"
#include "type_index.h"
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
#include "magic_enum/magic_enum.hpp"

using cpp_int = boost::multiprecision::cpp_int;

struct Frame;

struct BytecodeOpBase {
    virtual void Parse(std::ifstream& stream) = 0;
    virtual void Parse(const bytecode::Operation& op) = 0;
    virtual void operator()(Frame& frame) = 0;
    virtual ByteCodes GetByteCode() = 0;
    virtual std::string Str() const = 0;
    virtual ~BytecodeOpBase() = default;
};

struct Function {
    std::vector<std::string*> Params;
    std::span<std::shared_ptr<BytecodeOpBase>> Code;
    std::vector<std::shared_ptr<BytecodeOpBase>> JitCompiled;
    std::vector<std::string> JitIndexToName;
};

void JitCompile(Function& func);

struct Frame {
    static constexpr std::array<std::shared_ptr<BaseType> (*)(const BaseType&, const BaseType&), 13> BINARY_OPS = {
        [](const BaseType& x, const BaseType& y) { return x + y; },
        [](const BaseType& x, const BaseType& y) { return x - y; },
        [](const BaseType& x, const BaseType& y) { return x * y; },
        [](const BaseType& x, const BaseType& y) { return x / y; },
        [](const BaseType& x, const BaseType& y) { return x % y; },
        [](const BaseType& x, const BaseType& y) { return std::static_pointer_cast<BaseType>(x && y); },
        [](const BaseType& x, const BaseType& y) { return std::static_pointer_cast<BaseType>(x || y); },
        [](const BaseType& x, const BaseType& y) { return std::static_pointer_cast<BaseType>(x == y); },
        [](const BaseType& x, const BaseType& y) { return std::static_pointer_cast<BaseType>(x != y); },
        [](const BaseType& x, const BaseType& y) { return std::static_pointer_cast<BaseType>(x < y); },
        [](const BaseType& x, const BaseType& y) { return std::static_pointer_cast<BaseType>(x > y); },
        [](const BaseType& x, const BaseType& y) { return std::static_pointer_cast<BaseType>(x <= y); },
        [](const BaseType& x, const BaseType& y) { return std::static_pointer_cast<BaseType>(x >= y); }};

    static constexpr std::array<std::shared_ptr<BaseType> (*)(const BaseType&), 2> UNARY_OPS = {
        [](const BaseType& x) { return -x; },
        [](const BaseType& x) { return static_cast<std::shared_ptr<BaseType>>(!x); }};

    void ReadFunction(int& cur_instruction);
    std::shared_ptr<BaseType> Run();
    std::shared_ptr<BaseType>& Top();
    std::vector<std::shared_ptr<BaseType>> Popn(size_t n);
    std::vector<std::string*> PopnStrings(size_t n);
    void Push(std::shared_ptr<BaseType>&& value);
    void Push(const std::shared_ptr<BaseType>& value);
    void Push(std::string* value);
    void Push(TypeIndex* value);
    void LoadInt(BaseType::IntType* num);
    void LoadChar(char* arg);
    void LoadBool(bool* arg);
    void LoadDouble(double* arg);
    void LoadString(std::string* s);
    void LoadType(TypeIndex* type);
    void LoadName();
    void LoadVarByIndex(int idx);
    void StoreName();
    void LoadSubscr();
    void LoadMember();
    void StoreSubscr();
    void StoreMember();
    void StoreVarByIndex(int idx);
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
        std::shared_ptr<T> ret = std::move(std::static_pointer_cast<T>(Top()));
        DataStack.pop_back();
        return ret;
    }

    template <typename T>
    T& Pop() {
        T& ret = *std::get<T*>(DataStack.back());
        DataStack.pop_back();
        return ret;
    }

    std::span<std::shared_ptr<BytecodeOpBase>>& Instructions;
    std::unordered_map<std::string, std::shared_ptr<BaseType>> Builtins;
    std::unordered_map<std::string, std::shared_ptr<BaseType>> Locals;
    std::vector<std::shared_ptr<BaseType>> JitLocals;
    std::unordered_map<std::string, Function>& Functions;
    bool Jit;
    bool Verbose;
    Frame* ParentFrame = nullptr;
    std::vector<std::variant<std::shared_ptr<BaseType>, std::string*, TypeIndex*>> DataStack;
    std::shared_ptr<BaseType> ReturnValue;
    bool ShouldReturn;
    std::optional<int> Offset;
    Function* ReadingFunction = nullptr;
    std::stringstream Output;
    std::unordered_map<std::string, std::vector<std::string*>> StructInfo;
    std::vector<std::string>& JitIndexToName;
    std::vector<std::shared_ptr<BaseType>> JitIndexToVariable;
};

struct NullOp: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
    }
    void Parse(const bytecode::Operation& op) override {
    }
    void operator()(Frame& frame) override {
    }
    virtual std::string Str() const override {
        return "NullOp";
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::NullOp;
    }
};

struct LoadInt: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        // if size < 0, then cpp_int is negative
        stream.read(reinterpret_cast<char*>(&size), 4);
        std::string bytes(std::abs(size), '\0');
        stream.read(bytes.data(), std::abs(size));
        boost::multiprecision::import_bits(num, bytes.begin(), bytes.end());
        if (size < 0) {
            num = -num;
        }
    }
    void Parse(const bytecode::Operation& op) override {
        // if size < 0, then cpp_int is negative
        size = *reinterpret_cast<const int*>(op.value_bytes.data());
        const std::vector<char>& bytes = op.value_bytes;
        boost::multiprecision::import_bits(num, bytes.begin() + 4, bytes.end());
        if (size < 0) {
            num = -num;
        }
    }
    void operator()(Frame& frame) override {
        frame.LoadInt(&num);
    }
    std::string Str() const override {
        return std::format("LoadInt {} {}", size, num.str());
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::LoadInt;
    }

    int size;
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
    std::string Str() const override {
        std::string out = {c};
        if (c == '\n') {
            out = "\\n";
        }
        return std::format("LoadChar '{}'", out);
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
    std::string Str() const override {
        return std::format("LoadBool {}", b);
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
    std::string Str() const override {
        return std::format("LoadDouble {}", d);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::LoadDouble;
    }

    double d;
};

struct LoadString: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        stream.read(reinterpret_cast<char*>(&size), 4);
        s.resize(size);
        stream.read(s.data(), size);
    }
    void Parse(const bytecode::Operation& op) override {
        size = *reinterpret_cast<const int*>(op.value_bytes.data());
        s = std::string(op.value_bytes.begin() + 4, op.value_bytes.end());
    }
    void operator()(Frame& frame) override {
        frame.LoadString(&s);
    }
    std::string Str() const override {
        return std::format("LoadString {} {}", size, s);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::LoadString;
    }

    int size;
    std::string s;
};

struct LoadType: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        stream.read(reinterpret_cast<char*>(&type), 2);
    }
    void Parse(const bytecode::Operation& op) override {
        type = TypeIndex(*reinterpret_cast<const uint16_t*>(op.value_bytes.data()));
    }
    void operator()(Frame& frame) override {
        frame.LoadType(&type);
    }
    std::string Str() const override {
        std::string name = "";
        if (static_cast<uint16_t>(type) <= static_cast<uint16_t>(TypeIndex::Null)) {
            name = std::string(magic_enum::enum_name(type));
        }
        return std::format("LoadType {}", name);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::LoadType;
    }

    TypeIndex type;
};

struct LoadVarByIndex: public BytecodeOpBase {
    LoadVarByIndex(int idx = 0)
        : Idx(idx) {
    }

    void Parse(std::ifstream& stream) override {
        stream.read(reinterpret_cast<char*>(&Idx), 4);
    }
    void Parse(const bytecode::Operation& op) override {
        Idx = *reinterpret_cast<const int*>(op.value_bytes.data());
    }
    void operator()(Frame& frame) override {
        frame.LoadVarByIndex(Idx);
    }
    std::string Str() const override {
        return std::format("LoadVarByIndex {}", Idx);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::LoadVarByIndex;
    }

    int Idx;
};

struct StoreVarByIndex: public BytecodeOpBase {
    StoreVarByIndex(int idx = 0)
        : Idx(idx) {
    }

    void Parse(std::ifstream& stream) override {
        stream.read(reinterpret_cast<char*>(&Idx), 4);
    }
    void Parse(const bytecode::Operation& op) override {
        Idx = *reinterpret_cast<const int*>(op.value_bytes.data());
    }
    void operator()(Frame& frame) override {
        frame.StoreVarByIndex(Idx);
    }
    std::string Str() const override {
        return std::format("StoreVarByIndex {}", Idx);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::StoreVarByIndex;
    }

    int Idx;
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
    std::string Str() const override {
        return std::format("MakeFunction");
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
    std::string Str() const override {
        return std::format("UnaryOp {}", magic_enum::enum_name(op));
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
    std::string Str() const override {
        return std::format("BinaryOp {}", magic_enum::enum_name(op));
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
    std::string Str() const override {
        return std::format("BuildArray {}", cnt);
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
    std::string Str() const override {
        return std::format("DefineStruct {}", fieldc);
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
        std::string Str() const override {                                 \
            return std::format("{} {}", #Name, offset);                    \
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
        std::string Str() const override {                   \
            return std::format("{}", #Name);                 \
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
std::shared_ptr<BytecodeOpBase> BytecodeOpFactoryIfstream(std::ifstream& code) {
    std::shared_ptr<BytecodeOpBase> op = std::make_unique<T>();
    op->Parse(code);
    return op;
}

template <std::derived_from<BytecodeOpBase> T>
std::shared_ptr<BytecodeOpBase> BytecodeOpFactoryCompiler(const bytecode::Operation& code) {
    std::shared_ptr<BytecodeOpBase> op = std::make_unique<T>();
    op->Parse(code);
    return op;
}

struct VirtualMachine {
    static constexpr auto IfstreamBasedOpFactories = std::array{
        BytecodeOpFactoryIfstream<NullOp>,
        BytecodeOpFactoryIfstream<::LoadInt>,
        BytecodeOpFactoryIfstream<::LoadChar>,
        BytecodeOpFactoryIfstream<LoadBool>,
        BytecodeOpFactoryIfstream<::LoadDouble>,
        BytecodeOpFactoryIfstream<::LoadString>,
        BytecodeOpFactoryIfstream<LoadType>,
        BytecodeOpFactoryIfstream<LoadName>,
        BytecodeOpFactoryIfstream<LoadVarByIndex>,
        BytecodeOpFactoryIfstream<LoadSubscr>,
        BytecodeOpFactoryIfstream<LoadMember>,
        BytecodeOpFactoryIfstream<StoreName>,
        BytecodeOpFactoryIfstream<StoreSubscr>,
        BytecodeOpFactoryIfstream<StoreMember>,
        BytecodeOpFactoryIfstream<StoreVarByIndex>,
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

    static constexpr auto CompilerBasedOpFactories = std::array{
        BytecodeOpFactoryCompiler<NullOp>,
        BytecodeOpFactoryCompiler<::LoadInt>,
        BytecodeOpFactoryCompiler<::LoadChar>,
        BytecodeOpFactoryCompiler<LoadBool>,
        BytecodeOpFactoryCompiler<::LoadDouble>,
        BytecodeOpFactoryCompiler<::LoadString>,
        BytecodeOpFactoryCompiler<LoadVarByIndex>,
        BytecodeOpFactoryCompiler<LoadName>,
        BytecodeOpFactoryCompiler<LoadType>,
        BytecodeOpFactoryCompiler<LoadSubscr>,
        BytecodeOpFactoryCompiler<LoadMember>,
        BytecodeOpFactoryCompiler<StoreName>,
        BytecodeOpFactoryCompiler<StoreSubscr>,
        BytecodeOpFactoryCompiler<StoreMember>,
        BytecodeOpFactoryCompiler<StoreVarByIndex>,
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

    void IfVerbose(bool verbose) {
        if (verbose) {
            std::cout << "\n----------------------------------------" << std::endl;
            std::cout << "Execution:" << std::endl;
        }
    }

    void Run(std::ifstream& code, bool jit = false, bool verbose = false) {
        ByteCodes bytecode;
        std::cout << "Bytecode:" << std::endl;
        while (code.read(reinterpret_cast<char*>(&bytecode), 1)) {
            Code.push_back(IfstreamBasedOpFactories[static_cast<char>(bytecode)](code));
            std::cout << Code.back()->Str() << std::endl;
        }
        IfVerbose(verbose);

        std::unordered_map<std::string, std::shared_ptr<BaseType>> locals{};
        std::unordered_map<std::string, std::shared_ptr<BaseType>> builtins{};
        std::span<std::shared_ptr<BytecodeOpBase>> instructions(Code.begin(), Code.end());
        std::unordered_map<std::string, Function> functions{};
        std::vector<std::string> jitIndexToName{};
        auto frame = Frame{
            .Instructions = instructions,
            .Builtins = builtins,
            .Locals = locals,
            .Functions = functions,
            .Jit = jit,
            .Verbose = verbose,
            .JitIndexToName = jitIndexToName};
        frame.Run();
    }

    void Run(const std::vector<bytecode::Operation>& code, bool jit = false, bool verbose = false) {
        std::cout << "Bytecode:" << std::endl;
        for (const auto& c : code) {
            Code.push_back(CompilerBasedOpFactories[static_cast<char>(c.code)](c));
            std::cout << Code.back()->Str() << std::endl;
        }
        IfVerbose(verbose);

        std::unordered_map<std::string, std::shared_ptr<BaseType>> builtins{};
        std::unordered_map<std::string, std::shared_ptr<BaseType>> locals{};
        std::span<std::shared_ptr<BytecodeOpBase>> instructions(Code.begin(), Code.end());
        std::unordered_map<std::string, Function> functions{};
        std::vector<std::string> jitIndexToName{};
        auto frame = Frame{
            .Instructions = instructions,
            .Builtins = builtins,
            .Locals = locals,
            .Functions = functions,
            .Jit = jit,
            .Verbose = verbose,
            .JitIndexToName = jitIndexToName};
        frame.Run();
    }

    std::vector<std::shared_ptr<BytecodeOpBase>> Code;
};
