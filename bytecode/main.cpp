#include "SmplangLexer.h"
#include "SmplangParser.h"
#include "SmplangThrowingErrorListener.h"
#include "smplang_common.h"
#include <antlr4-runtime.h>
#include <iostream>

// Для тестов
int main() {
    try {
        std::string input = "int a =11;[];";
        auto *error_listener = new SmplangThrowingErrorListener();

        antlr4::ANTLRInputStream inputStream(input);
        SmplangLexer lexer(&inputStream);
        lexer.removeErrorListeners();
        lexer.addErrorListener(error_listener);

        antlr4::CommonTokenStream tokens(&lexer);
        SmplangParser parser(&tokens);
        parser.removeErrorListeners();
        parser.addErrorListener(error_listener);


        SmplangParser::ProgramContext *tree = parser.program();

//    std::cout << tree->
        std::cout << tree->toStringTree(&parser) << std::endl;
    } catch (ParserException ex) {
        std::cout << ex.what();
    }

    return 0;
}
