#include "SmplangLexer.h"
#include "SmplangParser.h"
#include <antlr4-runtime.h>
#include <iostream>

// Для тестов
int main() {
    std::string inputFile = "../grammar/syntax_example.smplng";

    std::ifstream stream;
    stream.open(inputFile);

    if (!stream.is_open()) {
        std::cerr << "Failed to open file: " << inputFile << std::endl;
        return 1;
    }

    antlr4::ANTLRInputStream inputStream(stream);
    SmplangLexer lexer(&inputStream);

    antlr4::CommonTokenStream tokens(&lexer);
    SmplangParser parser(&tokens);

    try {
        parser.program();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
