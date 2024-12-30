
// Generated from grammar/Smplang.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  SmplangLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, FUNC = 5, VOID = 6, RETURN = 7, 
    PRINT = 8, FOR = 9, WHILE = 10, IF = 11, ELSE = 12, STRUCT = 13, BOOL = 14, 
    INT = 15, DOUBLE = 16, CHAR = 17, ID = 18, BINOP = 19, UNAROP = 20, 
    COMPOP = 21, LOGICOP = 22, ASSIGN = 23, LPAREN = 24, RPAREN = 25, LBRACE = 26, 
    RBRACE = 27, LBRACK = 28, RBRACK = 29, SEMI = 30, COMMA = 31, DOT = 32, 
    WS = 33, COMMENT = 34
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

