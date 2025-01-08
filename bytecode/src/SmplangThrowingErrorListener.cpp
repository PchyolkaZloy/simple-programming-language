
#include "SmplangThrowingErrorListener.h"
#include "smplang_common.h"

namespace bytecode {

    void SmplangThrowingErrorListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol,
                                                   size_t line,
                                                   size_t charPositionInLine, const std::string &msg,
                                                   std::exception_ptr e) {
        throw ParserException("Syntax error at line " + std::to_string(line) +
                              ", position " + std::to_string(charPositionInLine) + ": " + msg);
    }
}
