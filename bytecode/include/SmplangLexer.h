
// Generated from grammar/Smplang.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  SmplangLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, FUNC = 5, VOID = 6, RETURN = 7, 
    PRINT = 8, FOR = 9, WHILE = 10, IF = 11, ELSE = 12, STRUCT = 13, BREAK = 14, 
    CONTINUE = 15, BOOL = 16, INT = 17, DOUBLE = 18, CHAR = 19, ID = 20, 
    NEG = 21, MULT = 22, ADD = 23, COMPOP = 24, NOT = 25, AND = 26, OR = 27, 
    ASSIGN = 28, LPAREN = 29, RPAREN = 30, LBRACE = 31, RBRACE = 32, LBRACK = 33, 
    RBRACK = 34, SEMI = 35, COMMA = 36, DOT = 37, WS = 38, COMMENT = 39
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

