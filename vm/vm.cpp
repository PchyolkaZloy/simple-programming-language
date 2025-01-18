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

gc::Ref<BaseType> Frame::Run() {
    int cur_instruction = 0;
    auto& instructions = Jit && JitInstructions.size() > 0 ? JitInstructions : Instructions;
    while (cur_instruction < instructions.size()) {
        if (ReadingFunction) {
            ReadFunction(cur_instruction);
        } else {
            BytecodeOpBase& instruction = *instructions[cur_instruction].get();
            if (Verbose) {
                std::cout << instruction.Str() << std::endl;
            }
            instruction(*this);
            if (instruction.GetByteCode() == ByteCodes::LoadVarByIndex || instruction.GetByteCode() == ByteCodes::StoreVarByIndex) {
                ++cur_instruction;
            }
            gc::gc.collect();
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
    if (Verbose && ParentFrame == nullptr) {
        std::cout << "\n----------------------------------------" << std::endl;
        std::cout << "Program output:" << std::endl;
        std::cout << Output.str() << std::endl;
    }
    return ReturnValue;
}

gc::Ref<BaseType>& Frame::Top() {
    return std::get<gc::Ref<BaseType>>(DataStack.back());
}

std::vector<gc::Ref<BaseType>> Frame::Popn(size_t n) {
    std::vector<gc::Ref<BaseType>> ret(n);
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

void Frame::Push(gc::Ref<BaseType>&& value) {
    DataStack.emplace_back(std::move(value));
}

void Frame::Push(const gc::Ref<BaseType>& value) {
    DataStack.emplace_back(value);
}

void Frame::Push(std::string* value) {
    DataStack.emplace_back(value);
}

void Frame::Push(TypeIndex* value) {
    DataStack.emplace_back(value);
}

void Frame::LoadInt(const BaseType::IntType& num) {
    Push(gc::gc.create(new Int(num)));
}

void Frame::LoadChar(const BaseType::CharType& arg) {
    Push(gc::gc.create(new Char(arg)));
}

void Frame::LoadBool(const BaseType::BoolType& arg) {
    Push(gc::gc.create(new Bool(arg)));
}

void Frame::LoadDouble(const BaseType::DoubleType& arg) {
    Push(gc::gc.create(new Double(arg)));
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
    Push(JitLocals[idx]);
}

void Frame::LoadSubscr() {
    gc::Ref<Int> key = Pop<Int>();
    gc::Ref<Array> container = Pop<Array>();
    Push((*container)[key.object()]);
}

void Frame::LoadMember() {
    std::string& name = Pop<std::string>();
    gc::Ref<Struct> obj = Pop<Struct>();
    Push(obj.object().GetMap()[name]);
}

void Frame::StoreName() {
    std::string& name = Pop<std::string>();
    gc::Ref<BaseType> value = Pop();
    Locals[name] = std::move(value);
}

void Frame::StoreSubscr() {
    gc::Ref<Int> key = Pop<Int>();
    gc::Ref<Array> container = Pop<Array>();
    gc::Ref<BaseType> value = Pop();
    (*container)[key.object()] = std::move(value);
}

void Frame::StoreMember() {
    std::string& name = Pop<std::string>();
    gc::Ref<Struct> obj = Pop<Struct>();
    gc::Ref<BaseType> value = Pop();
    obj.object().GetMap()[name] = value;
}

void Frame::StoreVarByIndex(int idx) {
    JitLocals[idx] = Pop();
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
         gc::Ref<BaseType> arg = frame.Pop();
         arg.object().Print(frame.Verbose ? frame.Output : std::cout);
     }},
    {"append", [](Frame& frame) {
         gc::Ref<BaseType> arg = frame.Pop();
         gc::Ref<Array> arr = frame.Pop<Array>();
         arr.object().Append(arg);
     }},
    {"len", [](Frame& frame) {
         gc::Ref<Array> arr = frame.Pop<Array>();
         frame.Push(gc::gc.create(new Int(BaseType::IntType(arr.object().Size()))));
     }},
    {"rand", [](Frame& frame) {
         double r = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
         frame.Push(gc::gc.create(new Double(BaseType::DoubleType(r))));
     }},
    {"randint", [](Frame& frame) {
         auto right_ptr = frame.Pop<Int>();
         auto left_ptr = frame.Pop<Int>();
         auto& right = std::get<BaseType::IntType>(right_ptr.object().Value);
         auto& left = std::get<BaseType::IntType>(left_ptr.object().Value);
         auto r = std::rand() * (right - left) / RAND_MAX + left;
         frame.Push(gc::gc.create(new Int(BaseType::IntType(r))));
     }},
    {"pop", [](Frame& frame) {
         gc::Ref<Array> arr = frame.Pop<Array>();
         frame.Push(arr.object().Pop());
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
    std::vector<gc::Ref<BaseType>> args = Popn(argc);
    if (Jit && f.JitCompiled.empty()) {
        JitCompile(f);
    }
    std::unordered_map<std::string, gc::Ref<BaseType>> locals{};

    if (Jit) {
        args.resize(f.JitIndexToName.size());
    } else {
        for (auto&& [name, value] : std::views::zip(f.Params, args)) {
            locals[*name] = std::move(value);
        }
    }
    auto jitInstructions = std::span(f.JitCompiled.begin(), f.JitCompiled.end());
    auto frame = Frame{
        .Instructions = f.Code,
        .JitInstructions = jitInstructions,
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
    if (Verbose) {
        Output << frame.Output.str() << std::endl;
    }
}

void Frame::Return() {
    if (!DataStack.empty()) {
        ReturnValue = Pop();
    }
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
    // TODO: test
    gc::Ref<Array> arr = gc::gc.create(new Array());
    auto elements = std::make_shared<Array>(Popn(count));
    for (size_t i = 0; i < count; i++) {
        arr.object()[i] = (*elements)[i];
    }
    Push(arr);
}

void Frame::BuildStruct() {
    // TODO: don't work, gc consume names of fields
    std::string& name = Pop<std::string>();
    Push(gc::gc.create(new Struct()));
}

void Frame::DefineStruct(int fieldc) {
    std::string& name = Pop<std::string>();
    StructInfo[name] = PopnStrings(fieldc);
}

void Frame::Jump(int offset) {
    Offset = offset;
}

void Frame::JumpIfTrue(int offset) {
    if (Pop().object().BoolCast()) {
        Offset = offset;
    }
}

void Frame::JumpIfFalse(int offset) {
    if (!Pop().object().BoolCast()) {
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

    for (int i = 1; i <= code.size(); ++i) {
        if (code[i - 1]->GetByteCode() != ByteCodes::LoadString ||
            code[i]->GetByteCode() != ByteCodes::StoreName && code[i]->GetByteCode() != ByteCodes::LoadName) {
            func.JitCompiled.push_back(code[i - 1]);
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
            func.JitCompiled.emplace_back(std::make_shared<LoadVarByIndex>(it->second));
        }
        func.JitCompiled.emplace_back(std::make_shared<NullOp>());
        ++i;
    }
    func.JitIndexToName.resize(nameToJitIndex.size());
    for (const auto& [k, v] : nameToJitIndex) {
        func.JitIndexToName[v] = k;
    }
}
