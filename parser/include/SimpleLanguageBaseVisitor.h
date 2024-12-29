
// Generated from grammar/SimpleLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SimpleLanguageVisitor.h"


/**
 * This class provides an empty implementation of SimpleLanguageVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SimpleLanguageBaseVisitor : public SimpleLanguageVisitor {
public:

  virtual std::any visitProgram(SimpleLanguageParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(SimpleLanguageParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }


};

