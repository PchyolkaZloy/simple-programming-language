#include "SmplangLexer.h"
#include "SmplangParser.h"
#include <antlr4-runtime.h>
#include <iostream>

// Для тестов
int main() {
    std::string input = "print(10);";

    antlr4::ANTLRInputStream inputStream(input);
    SmplangLexer lexer(&inputStream);

    antlr4::CommonTokenStream tokens(&lexer);
    SmplangParser parser(&tokens);

    SmplangParser::ProgramContext *tree = parser.program();

    std::cout << tree->toStringTree(&parser) << std::endl;

    return 0;
}
