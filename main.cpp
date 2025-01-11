#include "vm.h"

#include "SmplangLexer.h"
#include "SmplangParser.h"
#include "SmplangThrowingErrorListener.h"
#include "SmplangStructFuncNamePositionVisitor.h"
#include "smplang_common.h"
#include "SmplangBytecodeVisitor.h"
#include <iostream>
#include <fstream>
#include <array>

int main(int argc, char** argv) {
    std::unordered_set<std::string> builtinFunctions = {
        "print",
        "append"};
    std::array<std::string, 2> voidFunctions = {
        "print",
        "append"};

    if (argc < 2) {
        std::cout << "specify input file" << std::endl;
    }
    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "File doesn't exist" << std::endl;
        return 1;
    }
    SmplangParser::ProgramContext* tree;
    try {
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
        auto code = std::any_cast<std::vector<bytecode::Operation>>(
            bytecode::SmplangBytecodeVisitor(voidFunctions.begin(),
                                             voidFunctions.end())
                .visitProgram(tree));

        VirtualMachine vm;
        vm.Run(code);
    } catch (const std::exception& ex) {
        std::cout << "Error: " << ex.what() << '\n';
        return 1;
    }

    return 0;
}
