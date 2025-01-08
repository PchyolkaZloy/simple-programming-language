#include "SmplangLexer.h"
#include "SmplangParser.h"
#include "SmplangThrowingErrorListener.h"
#include "SmplangStructFuncNamePositionVisitor.h"
#include "SmplangStructDeclVisitor.h"
#include "smplang_common.h"
#include <antlr4-runtime.h>
#include <iostream>

using namespace bytecode;

// Для тестов
int main() {
    SmplangParser::ProgramContext *tree;
    try {
        std::string input = R"(
struct aoo {
double c;
};
struct aoo {
double b;

};
struct myStruct {
 int a;
};
struct secondStruct {
 int a;
};
)";
        auto *error_listener = new SmplangThrowingErrorListener();

        antlr4::ANTLRInputStream inputStream(input);
        SmplangLexer lexer(&inputStream);
        lexer.removeErrorListeners();
        lexer.addErrorListener(error_listener);

        antlr4::CommonTokenStream tokens(&lexer);
        SmplangParser parser(&tokens);
        parser.removeErrorListeners();
        parser.addErrorListener(error_listener);


        tree = parser.program();
        auto def_result = SmplangBaseVisitor().visitProgram(tree);
        SmplangStructFuncNamePositionVisitor name_visitor({"print"});
        SmplangStructDeclVisitor().visitProgram(tree);
        std::cout << std::endl;
        auto names_info = std::any_cast<NamesInfo>(name_visitor.visitProgram(tree));
        for (auto str_it = names_info.structure_positions.begin();
             str_it != names_info.structure_positions.end(); ++str_it) {
            std::cout << str_it->first << ' ' << str_it->second.toString() << std::endl;
        }
        for (auto func_it = names_info.function_positions.begin();
             func_it != names_info.function_positions.end(); ++func_it) {
            std::cout << func_it->first << ' ' << func_it->second.toString() << std::endl;
        }

//    std::cout << tree->
//        std::cout << tree->toStringTree(&parser) << std::endl;
    } catch (const ParserException &ex) {
        std::cout << "Error: " << ex.what() << '\n';
        return 1;
    } catch (const ValidatorException &ex) {
        std::cout << "Error: " << ex.what() << '\n';
        return 1;
    }


    return 0;
}
