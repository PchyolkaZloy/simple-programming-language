
// Generated from grammar/SimpleLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SimpleLanguageParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SimpleLanguageParser.
 */
class  SimpleLanguageVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SimpleLanguageParser.
   */
    virtual std::any visitProgram(SimpleLanguageParser::ProgramContext *context) = 0;

    virtual std::any visitStatement(SimpleLanguageParser::StatementContext *context) = 0;


};

