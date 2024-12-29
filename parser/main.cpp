#include "SimpleLanguageLexer.h"
#include "SimpleLanguageParser.h"
#include <antlr4-runtime.h>
#include <iostream>

// Для тестов
int main() {
    std::string input = "print \"Hello, World!\";";

    antlr4::ANTLRInputStream inputStream(input);
    SimpleLanguageLexer lexer(&inputStream);

    antlr4::CommonTokenStream tokens(&lexer);
    SimpleLanguageParser parser(&tokens);

    SimpleLanguageParser::ProgramContext *tree = parser.program();

    std::cout << tree->toStringTree(&parser) << std::endl;

    return 0;
}
