#include "vm.h"

#include <ranges>
#include <memory>

void Frame::ReadFunction(int& cur_instruction) {
    int fStart = cur_instruction;
    while (Instructions[cur_instruction]->GetByteCode() != ByteCodes::NullOp) {
        ++cur_instruction;
    }
    ReadingFunction->Code = std::span<std::shared_ptr<BytecodeOpBase>>(
        Instructions.begin() + fStart,
        Instructions.begin() + cur_instruction);
    ReadingFunction = nullptr;
}

std::shared_ptr<BaseType> Frame::Run() {
    int cur_instruction = 0;
    while (cur_instruction < Instructions.size()) {
        if (ReadingFunction) {
            ReadFunction(cur_instruction);
        } else {
            BytecodeOpBase& instruction = *Instructions[cur_instruction].get();
            if (Verbose) {
                std::cout << instruction.Str() << std::endl;
            }
            instruction(*this);
        }
        if (ShouldReturn) {
            return ReturnValue;
        }
        if (Offset) {
            cur_instruction += *Offset;
            Offset.reset();
        } else {
            cur_instruction += 1;
        }
    }
    if (Verbose) {
        std::cout << "\n----------------------------------------" << std::endl;
        std::cout << "Program output:" << std::endl;
        std::cout << Output.str() << std::endl;
    }
    return ReturnValue;
}

std::shared_ptr<BaseType>& Frame::Top() {
    return std::get<std::shared_ptr<BaseType>>(DataStack.back());
}

std::vector<std::shared_ptr<BaseType>> Frame::Popn(size_t n) {
    std::vector<std::shared_ptr<BaseType>> ret(n);
    for (int i = n - 1; i >= 0; --i) {
        ret[i] = Pop();
    }
    return ret;
}

std::vector<std::string*> Frame::PopnStrings(size_t n) {
    std::vector<std::string*> ret(n);
    for (int i = n - 1; i >= 0; --i) {
        ret[i] = &Pop<std::string>();
    }
    return ret;
}

void Frame::Push(std::shared_ptr<BaseType>&& value) {
    DataStack.emplace_back(std::move(value));
}

void Frame::Push(const std::shared_ptr<BaseType>& value) {
    DataStack.emplace_back(value);
}

void Frame::Push(std::string* value) {
    DataStack.emplace_back(value);
}

void Frame::Push(TypeIndex* value) {
    DataStack.emplace_back(value);
}

void Frame::LoadInt(BaseType::IntType* num) {
    Push(std::make_shared<Int>(num));
}

void Frame::LoadChar(char* arg) {
    Push(std::make_shared<Char>(arg));
}

void Frame::LoadBool(bool* arg) {
    Push(std::make_shared<Bool>(arg));
}

void Frame::LoadDouble(double* arg) {
    Push(std::make_shared<Double>(arg));
}

void Frame::LoadString(std::string* s) {
    Push(s);
}

void Frame::LoadType(TypeIndex* type) {
    Push(type);
}

void Frame::LoadName() {
    std::string& name = Pop<std::string>();
    if (Locals.contains(name)) {
        Push(Locals.at(name));
    } else if (Builtins.contains(name)) {
        Push(Builtins.at(name));
    } else {
        throw std::invalid_argument(std::format("name '{}' is not defined", name));
    }
}

void Frame::LoadVarByIndex(int idx) {
    Push(JitIndexToVariable[idx]);
}

void Frame::LoadSubscr() {
    std::shared_ptr<Int> key = Pop<Int>();
    std::shared_ptr<Array> container = Pop<Array>();
    Push((*container)[*key.get()]);
}

void Frame::LoadMember() {
    std::string& name = Pop<std::string>();
    std::shared_ptr<Struct> obj = Pop<Struct>();
    Push(obj->GetMap()[name]);
}

void Frame::StoreName() {
    std::string& name = Pop<std::string>();
    std::shared_ptr<BaseType> value = Pop();
    Locals[name] = std::move(value);
}

void Frame::StoreSubscr() {
    std::shared_ptr<Int> key = Pop<Int>();
    std::shared_ptr<Array> container = Pop<Array>();
    std::shared_ptr<BaseType> value = Pop();
    (*container)[*key.get()] = std::move(value);
}

void Frame::StoreMember() {
    std::string& name = Pop<std::string>();
    std::shared_ptr<Struct> obj = Pop<Struct>();
    std::shared_ptr<BaseType> value = Pop();
    obj->GetMap()[name] = value;
}

void Frame::StoreVarByIndex(int idx) {
    JitIndexToVariable[idx] = Pop();
}

void Frame::MakeFunction(int argc) {
    Function f;
    std::string& fName = Pop<std::string>();
    f.Params = PopnStrings(argc);
    Functions[fName] = std::move(f);
    ReadingFunction = &Functions[fName];
}

std::map<std::string, void (*)(Frame&)> BuiltinFunctions = {
    {"print", [](Frame& frame) {
         std::shared_ptr<BaseType> arg = frame.Pop();
         arg->Print(frame.Verbose ? frame.Output : std::cout);
     }},
    {"append", [](Frame& frame) {
         std::shared_ptr<BaseType> arg = frame.Pop();
         std::shared_ptr<Array> arr = frame.Pop<Array>();
         arr->Append(arg);
     }},
    {"len", [](Frame& frame) {
         std::shared_ptr<Array> arr = frame.Pop<Array>();
         frame.Push(std::make_shared<Int>(new BaseType::IntType(arr->Size())));
     }},
};

void Frame::Call() {
    std::string& fName = Pop<std::string>();
    if (BuiltinFunctions.contains(fName)) {
        BuiltinFunctions[fName](*this);
        return;
    }
    Function& f = Functions[fName];
    int argc = f.Params.size();
    std::vector<std::shared_ptr<BaseType>> args = Popn(argc);
    if (Jit && f.JitCompiled.empty()) {
        JitCompile(f);
    }
    std::vector<std::shared_ptr<BaseType>> jutLocals{};
    std::unordered_map<std::string, std::shared_ptr<BaseType>> locals{};

    if (Jit) {
        args.resize(JitIndexToName.size());
    } else {
        for (auto&& [name, value] : std::views::zip(f.Params, args)) {
            locals[*name] = std::move(value);
        }
    }
    auto frame = Frame{
        .Instructions = f.Code,
        .Builtins = Builtins,
        .Locals = locals,
        .JitLocals = args,
        .Functions = Functions,
        .Jit = Jit,
        .Verbose = Verbose,
        .ParentFrame = this,
        .JitIndexToName = f.JitIndexToName};
    if (auto res = frame.Run()) {
        Push(res);
    }
}

void Frame::Return() {
    ReturnValue = Pop();
    ShouldReturn = true;
}

void Frame::UnaryOp(UnaryOps opCode) {
    DataStack.back() = UNARY_OPS[static_cast<char>(opCode)](*Top());
}

void Frame::BinaryOp(BinaryOps opCode) {
    auto right = Pop();
    auto left = Pop();
    Push(BINARY_OPS[static_cast<char>(opCode)](*left, *right));
}

void Frame::BuildArray(int count) {
    std::shared_ptr<Array> arr = std::make_shared<Array>(Popn(count));
    Push(std::move(arr));
}

void Frame::BuildStruct() {
    std::string& name = Pop<std::string>();
    Push(std::make_shared<Struct>());
}

void Frame::DefineStruct(int fieldc) {
    std::string& name = Pop<std::string>();
    StructInfo[name] = PopnStrings(fieldc);
}

void Frame::Jump(int offset) {
    Offset = offset;
}

void Frame::JumpIfTrue(int offset) {
    if (Pop()->BoolCast()) {
        Offset = offset;
    }
}

void Frame::JumpIfFalse(int offset) {
    if (!Pop()->BoolCast()) {
        Offset = offset;
    }
}

void Frame::Copy() {
    throw std::invalid_argument("not implemented");
}

void JitCompile(Function& func) {
    std::unordered_map<std::string, int> nameToJitIndex;
    for (int i = 0; i < func.Params.size(); ++i) {
        nameToJitIndex[*func.Params[i]] = i;
    }
    auto& code = func.Code;

    for (int i = 1; i < code.size(); ++i) {
        if (code[i - 1]->GetByteCode() != ByteCodes::LoadString) {
            func.JitCompiled.push_back(code[i - 1]);
            continue;
        }
        if (code[i]->GetByteCode() != ByteCodes::StoreName && code[i]->GetByteCode() != ByteCodes::LoadName) {
            continue;
        }
        std::shared_ptr<LoadString>& op = reinterpret_cast<std::shared_ptr<LoadString>&>(code[i - 1]);
        auto it = nameToJitIndex.find(op->s);
        if (it == nameToJitIndex.end()) {
            it = nameToJitIndex.insert({op->s, nameToJitIndex.size()}).first;
        }
        if (code[i]->GetByteCode() == ByteCodes::StoreName) {
            func.JitCompiled.emplace_back(std::make_shared<StoreVarByIndex>(it->second));
        } else if (code[i]->GetByteCode() == ByteCodes::LoadName) {
            func.JitCompiled.emplace_back(std::make_shared<StoreVarByIndex>(it->second));
        }
    }
}
