#include "vm.h"
#include "SmplangLexer.h"
#include "SmplangParser.h"
#include "SmplangThrowingErrorListener.h"
#include "SmplangStructFuncNamePositionVisitor.h"
#include "smplang_common.h"
#include "SmplangBytecodeVisitor.h"

#include <iostream>
#include <array>

std::vector<bytecode::Operation> GenerateByteCode(std::istream& input) {
    static std::unordered_set<std::string> builtinFunctions = {
        "print",
        "append"};

    static std::array<std::string, 2> voidFunctions = {
        "print",
        "append"};

    SmplangParser::ProgramContext* tree;
    auto* error_listener = new bytecode::SmplangThrowingErrorListener();

    antlr4::ANTLRInputStream inputStream(input);
    SmplangLexer lexer(&inputStream);
    lexer.removeErrorListeners();
    lexer.addErrorListener(error_listener);

    antlr4::CommonTokenStream tokens(&lexer);
    SmplangParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(error_listener);

    tree = parser.program();
    bytecode::SmplangStructFuncNamePositionVisitor name_visitor(builtinFunctions);
    auto names_info = std::any_cast<bytecode::NamesInfo>(name_visitor.visitProgram(tree));
    auto ret = bytecode::SmplangBytecodeVisitor(voidFunctions.begin(), voidFunctions.end()).visitProgram(tree);
    return std::any_cast<std::vector<bytecode::Operation>>(ret);
}

void InterpreteCode(std::ifstream& input, bool verbose = false) {
    auto code = GenerateByteCode(input);
    VirtualMachine vm;
    vm.Run(code, verbose);
}

void InterpreteCode(const std::string& input, bool verbose = false) {
    std::stringstream ss(input);
    auto code = GenerateByteCode(ss);
    VirtualMachine vm;
    vm.Run(code, verbose);
}
