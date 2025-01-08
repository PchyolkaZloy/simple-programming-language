
// Generated from ./grammar/Smplang.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  SmplangLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, FUNC = 5, VOID = 6, RETURN = 7, 
    FOR = 8, PRINT = 9, WHILE = 10, IF = 11, ELSE = 12, ELIF = 13, STRUCT = 14, 
    BREAK = 15, CONTINUE = 16, BOOL = 17, INT = 18, DOUBLE = 19, CHAR = 20, 
    ID = 21, NEG = 22, MULT = 23, ADD = 24, COMPOP = 25, NOT = 26, AND = 27, 
    OR = 28, ASSIGN = 29, LPAREN = 30, RPAREN = 31, LBRACE = 32, RBRACE = 33, 
    LBRACK = 34, RBRACK = 35, ARRAYTYPE = 36, SEMI = 37, COMMA = 38, DOT = 39, 
    WS = 40, COMMENT = 41
  };

  explicit SmplangLexer(antlr4::CharStream *input);

  ~SmplangLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

