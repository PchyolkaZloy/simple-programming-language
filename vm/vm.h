#include "types.h"

#include <iostream>
#include <map>
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

#include "boost/multiprecision/cpp_int.hpp"

using cpp_int = boost::multiprecision::cpp_int;

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

struct Frame;

struct Function {
    std::vector<std::string*> Params;
    std::span<std::unique_ptr<BytecodeOpBase>> Code;
};

struct BytecodeOpBase {
    virtual void Parse(std::ifstream& stream) = 0;
    virtual void operator()(Frame& frame) = 0;
    virtual ByteCodes GetByteCode() = 0;
};

struct NullOp: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
    }
    void operator()(Frame& frame) override {
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::NullOp;
    }
};

struct LoadInt: public BytecodeOpBase {
    void Parse(std::ifstream& stream) override {
        int size = 0;
        stream.read(reinterpret_cast<char*>(&size), 4);
        char* bytes = new char[size];
        stream.read(bytes, size);
        boost::multiprecision::import_bits(num, bytes, bytes + size);
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
    void operator()(Frame& frame) override {
        frame.DefineStruct(fieldc);
    }
    ByteCodes GetByteCode() override {
        return ByteCodes::DefineStruct;
    }

    uint8_t fieldc = 0;
};

#define DefJump(Name)                                         \
    struct Name##: public BytecodeOpBase {                    \
        void Parse(std::ifstream& stream) override {          \
            stream.read(reinterpret_cast<char*>(&offset), 4); \
        }                                                     \
        void operator()(Frame& frame) override {              \
            frame.Jump(offset);                               \
        }                                                     \
        ByteCodes GetByteCode() override {                    \
            return ByteCodes::##Name;                         \
        }                                                     \
        int offset = 0;                                       \
    }

DefJump(Jump);
DefJump(JumpIfTrue);
DefJump(JumpIfFalse);

#define DefOp(Name)                                  \
    struct Name##: public BytecodeOpBase {           \
        void Parse(std::ifstream& stream) override { \
        }                                            \
        void operator()(Frame& frame) override {     \
            frame.##Name();                          \
        }                                            \
        ByteCodes GetByteCode() override {           \
            return ByteCodes::##Name;                \
        }                                            \
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

struct Frame {
    static constexpr std::array<std::shared_ptr<BaseType> (*)(const BaseType&, const BaseType&), 10> BINARY_OPS = {
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
        [](const BaseType& x, const BaseType& y) { return static_cast<std::shared_ptr<BaseType>>(x == y); },
        [](const BaseType& x, const BaseType& y) { return static_cast<std::shared_ptr<BaseType>>(x != y); },
        [](const BaseType& x, const BaseType& y) { return static_cast<std::shared_ptr<BaseType>>(x < y); },
        [](const BaseType& x, const BaseType& y) { return static_cast<std::shared_ptr<BaseType>>(x > y); },
        [](const BaseType& x, const BaseType& y) { return static_cast<std::shared_ptr<BaseType>>(x <= y); },
        [](const BaseType& x, const BaseType& y) { return static_cast<std::shared_ptr<BaseType>>(x >= y); }};

    static constexpr std::array<std::shared_ptr<BaseType> (*)(const BaseType&), 2> UNARY_OPS = {
        // [](const BaseType& x) { return -x; }};
        // [](const BaseType& x) { return !x; },
    };

    Frame(
        std::span<std::unique_ptr<BytecodeOpBase>>& instructions,
        std::unordered_map<std::string, std::shared_ptr<BaseType>>& builtins,
        std::unordered_map<std::string, std::shared_ptr<BaseType>>& globals,
        std::unordered_map<std::string, std::shared_ptr<BaseType>>& locals,
        Frame* parentFrame)
        : Instructions(instructions)
        , Builtins(builtins)
        , Globals(globals)
        , Locals(locals)
        , ParentFrame(parentFrame)
        , DataStack()
        , ReturnValue()
        , ShouldReturn()
        , Offset()
        , Functions()
        , ReadingFunction(nullptr) {
    }

    void ReadFunction(int& cur_instruction) {
        int fStart = cur_instruction;
        while (Instructions[cur_instruction]->GetByteCode() != ByteCodes::NullOp) {
            ++cur_instruction;
        }
        ReadingFunction->Code = std::span<std::unique_ptr<BytecodeOpBase>>(
            Instructions.begin() + fStart,
            Instructions.begin() + cur_instruction);
        ReadingFunction = nullptr;
    }

    std::shared_ptr<BaseType> Run() {
        int cur_instruction = 0;
        while (cur_instruction < Instructions.size()) {
            if (ReadingFunction) {
                ReadFunction(cur_instruction);
            } else {
                BytecodeOpBase& instruction = *Instructions[cur_instruction].get();
                instruction(*this);
            }
            if (ShouldReturn) {
                return ReturnValue;
            }
            if (Offset) {
                cur_instruction -= *Offset;
                Offset.reset();
            } else {
                cur_instruction += 1;
            }
        }
        return ReturnValue;
    }

    std::shared_ptr<BaseType>& Top() {
        return std::get<std::shared_ptr<BaseType>>(DataStack.back());
    }

    template <std::derived_from<BaseType> T = BaseType>
    std::shared_ptr<T> Pop() {
        std::shared_ptr<T> ret = std::move(static_cast<std::shared_ptr<T>&>(Top()));
        DataStack.pop_back();
        return ret;
    }

    std::string& PopString() {
        std::string& ret = *std::get<std::string*>(DataStack.back());
        DataStack.pop_back();
        return ret;
    }

    std::vector<std::shared_ptr<BaseType>> Popn(size_t n) {
        std::vector<std::shared_ptr<BaseType>> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = Pop();
        }
        return ret;
    }

    std::vector<std::string*> PopnStrings(size_t n) {
        std::vector<std::string*> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = &PopString();
        }
        return ret;
    }

    void Push(std::shared_ptr<BaseType>&& value) {
        DataStack.emplace_back(std::move(value));
    }

    void Push(const std::shared_ptr<BaseType>& value) {
        DataStack.emplace_back(value);
    }

    void Push(std::string* value) {
        DataStack.emplace_back(value);
    }

    void LoadInt(BaseType::IntType* num) {
        Push(std::make_shared<Int>(num));
    }

    void LoadChar(char* arg) {
        Push(std::make_shared<Char>(arg));
    }

    void LoadBool(bool* arg) {
        Push(std::make_shared<Bool>(arg));
    }

    void LoadDouble(double* arg) {
        Push(std::make_shared<Double>(arg));
    }

    void LoadString(std::string* s) {
        Push(s);
    }

    void LoadName() {
        std::string& name = PopString();
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
        Locals[name] = Pop();
    }

    void LoadSubscr() {

    }

    void LoadMember() {

    }

    void StoreSubscr() {
        std::shared_ptr<BaseType> value = Pop();
        std::shared_ptr<Int> key = Pop<Int>();
        std::shared_ptr<Array> container = Pop<Array>();
        (*container)[*key.get()] = std::move(value);
    }

    void StoreMember() {
        std::string& name = PopString();
        std::shared_ptr<Struct> obj = Pop<Struct>();
        std::shared_ptr<BaseType> value = Pop();
        obj->GetMap()[name] = value;
    }

    void MakeFunction(int argc) {
        auto code = Pop();
        Function f;
        std::string& fName = PopString();
        f.Params = PopnStrings(argc);
        Functions[fName] = std::move(f);
        ReadingFunction = &Functions[fName];
    }

    void Call() {
        std::string& fName = PopString();
        Function& f = Functions[fName];
        int argc = f.Params.size();
        std::vector<std::shared_ptr<BaseType>> args = Popn(argc);
        std::unordered_map<std::string, std::shared_ptr<BaseType>> locals{};
        for (const auto& [name, value] : std::views::zip(f.Params, args)) {
            locals[*name] = value;
        }
        auto frame = Frame(f.Code, Builtins, Globals, locals, this);
        Push(frame.Run());
    }

    void Return() {
        ReturnValue = Pop();
        ShouldReturn = true;
    }

    void UnaryOp(UnaryOps opCode) {
        DataStack.back() = UNARY_OPS[static_cast<char>(opCode)](*Top());
    }

    void BinaryOp(BinaryOps opCode) {
        auto right = Pop();
        auto left = Pop();
        Push(BINARY_OPS[static_cast<char>(opCode)](*left, *right));
    }

    void BuildArray(int count) {
        std::shared_ptr<Array> arr = std::make_shared<Array>(Popn(count));
        Push(std::move(arr));
    }
    
    void BuildStruct() {
        
    }
    
    void DefineStruct(int fieldc) {

    }

    void Jump(int offset) {
        Offset = offset;
    }

    void JumpIfTrue(int offset) {
        if (Pop()->BoolCast()) {
            Offset = offset;
        }
    }

    void JumpIfFalse(int offset) {
        if (!Pop()->BoolCast()) {
            Offset = offset;
        }
    }

    void Copy() {
        throw std::invalid_argument("not implemented");
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
    std::unordered_map<std::string, Function> Functions;
    Function* ReadingFunction;
};

template <typename T>
std::unique_ptr<BytecodeOpBase> BytecodeOpFactory(std::ifstream& code) {
    std::unique_ptr<BytecodeOpBase> op = std::make_unique<T>();
    op->Parse(code);
    return op;
}

struct VirtualMachine {
    static constexpr std::array<std::unique_ptr<BytecodeOpBase> (*)(std::ifstream&), 23> OpFactories = {
        BytecodeOpFactory<NullOp>,
        BytecodeOpFactory<LoadInt>,
        BytecodeOpFactory<LoadChar>,
        BytecodeOpFactory<LoadBool>,
        BytecodeOpFactory<LoadDouble>,
        BytecodeOpFactory<LoadString>,
        BytecodeOpFactory<LoadName>,
        BytecodeOpFactory<StoreName>,
        BytecodeOpFactory<StoreSubscr>,
        BytecodeOpFactory<StoreMember>,
        BytecodeOpFactory<MakeFunction>,
        BytecodeOpFactory<Call>,
        BytecodeOpFactory<Return>,
        BytecodeOpFactory<UnaryOp>,
        BytecodeOpFactory<BinaryOp>,
        BytecodeOpFactory<BuildArray>,
        BytecodeOpFactory<BuildStruct>,
        BytecodeOpFactory<DefineStruct>,
        BytecodeOpFactory<Jump>,
        BytecodeOpFactory<JumpIfTrue>,
        BytecodeOpFactory<JumpIfFalse>,
        BytecodeOpFactory<Copy>,
        BytecodeOpFactory<Pop>,
    };

    void Run(std::ifstream& code) {
        ByteCodes bytecode;
        while (code.read(reinterpret_cast<char*>(&bytecode), 1)) {
            Code.push_back(OpFactories[static_cast<char>(bytecode)](code));
        }

        std::unordered_map<std::string, std::shared_ptr<BaseType>> globals{};
        std::unordered_map<std::string, std::shared_ptr<BaseType>> builtins{};
        std::span<std::unique_ptr<BytecodeOpBase>> instructions(Code.begin(), Code.end());
        auto frame = Frame(instructions, builtins, globals, globals, nullptr);
        frame.Run();
    }

    std::vector<std::unique_ptr<BytecodeOpBase>> Code;
};
