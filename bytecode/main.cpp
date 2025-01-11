#include "SmplangLexer.h"
#include "SmplangParser.h"
#include "SmplangThrowingErrorListener.h"
#include "SmplangStructFuncNamePositionVisitor.h"
//#include "SmplangStructDeclVisitor.h"
#include "smplang_common.h"
#include "SmplangBytecodeVisitor.h"
#include <iostream>
#include <fstream>

//using namespace bytecode;


// Для тестов
int main() {
//    auto it = bytecode::appendToCharVector(vec, 'b');
    std::vector<char> vec({12, 13});
    std::vector<char> vec2({12, 13});
    bytecode::appendIntToCharVector(vec, cpp_int(10));
    bytecode::appendIntToCharVector(vec2, cpp_int(-10));
    for (auto v: vec) {
        std::cout << (int) v << ' ';
    }
    std::cout << std::endl;
    for (auto v: vec2) {
        std::cout << (int) v << ' ';
    }
    std::cout << std::endl;

    SmplangParser::ProgramContext *tree;
    try {
        std::string input = R"(
if (true) {
    print(12);
}
 elif (false) {
    print(12);
    print(12);
    print(12);
}
elif (false) {
    print(12);
} else
   print(12 + 12 + 90);
int a;
)";
        auto *error_listener = new bytecode::SmplangThrowingErrorListener();

        antlr4::ANTLRInputStream inputStream(input);
        SmplangLexer lexer(&inputStream);
        lexer.removeErrorListeners();
        lexer.addErrorListener(error_listener);

        antlr4::CommonTokenStream tokens(&lexer);
        SmplangParser parser(&tokens);
        parser.removeErrorListeners();
        parser.addErrorListener(error_listener);


        tree = parser.program();
        bytecode::SmplangStructFuncNamePositionVisitor name_visitor({"print"});
//        bytecode::SmplangStructDeclVisitor().visitProgram(tree);
        std::cout << std::endl;
        auto names_info = std::any_cast<bytecode::NamesInfo>(name_visitor.visitProgram(tree));
        for (auto str_it = names_info.structure_positions.begin();
             str_it != names_info.structure_positions.end(); ++str_it) {
            std::cout << str_it->first << ' ' << str_it->second.toString() << std::endl;
        }
        for (auto func_it = names_info.function_positions.begin();
             func_it != names_info.function_positions.end(); ++func_it) {
            std::cout << func_it->first << ' ' << func_it->second.toString() << std::endl;
        }
        std::vector<std::string> void_typed_functions({"print"});
        auto code = std::any_cast<std::vector<bytecode::Operation>>(
                bytecode::SmplangBytecodeVisitor(void_typed_functions.begin(),
                                                 void_typed_functions.end()).visitProgram(tree));
        std::ofstream fout("file.spl");
        bytecode::writeByteCode(code.begin(), code.end(), fout);
//        std::ofstream fout("myfile.spl");
//        fout.write(code.data(), code.size());

//    std::cout << tree->
//        std::cout << tree->toStringTree(&parser) << std::endl;
    } catch (const std::exception &ex) {
        std::cout << "Error: " << ex.what() << '\n';
        return 1;
    } catch (const bytecode::ValidatorException &ex) {
        std::cout << "Error: " << ex.what() << '\n';
        return 1;
    } catch (const bytecode::ASTException &ex) {
        std::cout << "Error: " << ex.what() << '\n';
        return 1;
    }
//    } catch (const std::exception &ex) {
//        std::cout << "Error: " << ex.what() << '\n';
//        return 1;
//    }


    return 0;
}
