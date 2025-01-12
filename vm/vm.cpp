#include "vm.h"

Frame::Frame(
    std::span<std::unique_ptr<BytecodeOpBase>>& instructions,
    std::unordered_map<std::string, std::shared_ptr<BaseType>>& builtins,
    std::unordered_map<std::string, std::shared_ptr<BaseType>>& globals,
    std::unordered_map<std::string, std::shared_ptr<BaseType>>& locals,
    std::unordered_map<std::string, Function>& builtinFunctions,
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
    , Functions(builtinFunctions)
    , ReadingFunction(nullptr) {
}

void Frame::ReadFunction(int& cur_instruction) {
    int fStart = cur_instruction;
    while (Instructions[cur_instruction]->GetByteCode() != ByteCodes::NullOp) {
        ++cur_instruction;
    }
    ReadingFunction->Code = std::span<std::unique_ptr<BytecodeOpBase>>(
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
    return ReturnValue;
}

std::shared_ptr<BaseType>& Frame::Top() {
    return std::get<std::shared_ptr<BaseType>>(DataStack.back());
}

std::string& Frame::PopString() {
    std::string& ret = *std::get<std::string*>(DataStack.back());
    DataStack.pop_back();
    return ret;
}

std::vector<std::shared_ptr<BaseType>> Frame::Popn(size_t n) {
    std::vector<std::shared_ptr<BaseType>> ret(n);
    for (int i = 0; i < n; ++i) {
        ret[i] = Pop();
    }
    return ret;
}

std::vector<std::string*> Frame::PopnStrings(size_t n) {
    std::vector<std::string*> ret(n);
    for (int i = 0; i < n; ++i) {
        ret[i] = &PopString();
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

void Frame::LoadName() {
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

void Frame::StoreName() {
    std::shared_ptr<BaseType> value = Pop();
    std::string& name = PopString();
    Locals[name] = std::move(value);
}

void Frame::LoadSubscr() {
}

void Frame::LoadMember() {
}

void Frame::StoreSubscr() {
    std::shared_ptr<BaseType> value = Pop();
    std::shared_ptr<Int> key = Pop<Int>();
    std::shared_ptr<Array> container = Pop<Array>();
    (*container)[*key.get()] = std::move(value);
}

void Frame::StoreMember() {
    std::string& name = PopString();
    std::shared_ptr<Struct> obj = Pop<Struct>();
    std::shared_ptr<BaseType> value = Pop();
    obj->GetMap()[name] = value;
}

void Frame::MakeFunction(int argc) {
    Function f;
    std::string& fName = PopString();
    f.Params = PopnStrings(argc);
    Functions[fName] = std::move(f);
    ReadingFunction = &Functions[fName];
}

void Frame::Call() {
    std::string& fName = PopString();
    if (fName == "print") {
        std::shared_ptr<BaseType> arg = Pop();
        arg->Print();
        return;
    }
    Function& f = Functions[fName];
    int argc = f.Params.size();
    std::vector<std::shared_ptr<BaseType>> args = Popn(argc);
    std::unordered_map<std::string, std::shared_ptr<BaseType>> locals{};
    for (const auto& [name, value] : std::views::zip(f.Params, args)) {
        locals[*name] = value;
    }
    auto frame = Frame(f.Code, Builtins, Globals, locals, Functions, this);
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
}

void Frame::DefineStruct(int fieldc) {
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