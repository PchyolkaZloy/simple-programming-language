#include "SmplangLexer.h"
#include "SmplangParser.h"
#include <antlr4-runtime.h>
#include <iostream>

// Для тестов
int main() {
    std::string input = "int a = 10 / 2 + 5 * 2;";

    antlr4::ANTLRInputStream inputStream(input);
    SmplangLexer lexer(&inputStream);

    antlr4::CommonTokenStream tokens(&lexer);
    SmplangParser parser(&tokens);

    SmplangParser::ProgramContext *tree = parser.program();

//    std::cout << tree->
    std::cout << tree->toStringTree(&parser) << std::endl;

    return 0;
}
