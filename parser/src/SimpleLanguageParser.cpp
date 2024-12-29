
// Generated from grammar/SimpleLanguage.g4 by ANTLR 4.13.2


#include "SimpleLanguageVisitor.h"

#include "SimpleLanguageParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SimpleLanguageParserStaticData final {
  SimpleLanguageParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SimpleLanguageParserStaticData(const SimpleLanguageParserStaticData&) = delete;
  SimpleLanguageParserStaticData(SimpleLanguageParserStaticData&&) = delete;
  SimpleLanguageParserStaticData& operator=(const SimpleLanguageParserStaticData&) = delete;
  SimpleLanguageParserStaticData& operator=(SimpleLanguageParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag simplelanguageParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<SimpleLanguageParserStaticData> simplelanguageParserStaticData = nullptr;

void simplelanguageParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (simplelanguageParserStaticData != nullptr) {
    return;
  }
#else
  assert(simplelanguageParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SimpleLanguageParserStaticData>(
    std::vector<std::string>{
      "program", "statement"
    },
    std::vector<std::string>{
      "", "'print'", "';'"
    },
    std::vector<std::string>{
      "", "", "", "STRING", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,4,14,2,0,7,0,2,1,7,1,1,0,4,0,6,8,0,11,0,12,0,7,1,1,1,1,1,1,1,1,1,
  	1,0,0,2,0,2,0,0,12,0,5,1,0,0,0,2,9,1,0,0,0,4,6,3,2,1,0,5,4,1,0,0,0,6,
  	7,1,0,0,0,7,5,1,0,0,0,7,8,1,0,0,0,8,1,1,0,0,0,9,10,5,1,0,0,10,11,5,3,
  	0,0,11,12,5,2,0,0,12,3,1,0,0,0,1,7
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  simplelanguageParserStaticData = std::move(staticData);
}

}

SimpleLanguageParser::SimpleLanguageParser(TokenStream *input) : SimpleLanguageParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SimpleLanguageParser::SimpleLanguageParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SimpleLanguageParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *simplelanguageParserStaticData->atn, simplelanguageParserStaticData->decisionToDFA, simplelanguageParserStaticData->sharedContextCache, options);
}

SimpleLanguageParser::~SimpleLanguageParser() {
  delete _interpreter;
}

const atn::ATN& SimpleLanguageParser::getATN() const {
  return *simplelanguageParserStaticData->atn;
}

std::string SimpleLanguageParser::getGrammarFileName() const {
  return "SimpleLanguage.g4";
}

const std::vector<std::string>& SimpleLanguageParser::getRuleNames() const {
  return simplelanguageParserStaticData->ruleNames;
}

const dfa::Vocabulary& SimpleLanguageParser::getVocabulary() const {
  return simplelanguageParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SimpleLanguageParser::getSerializedATN() const {
  return simplelanguageParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

SimpleLanguageParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimpleLanguageParser::StatementContext *> SimpleLanguageParser::ProgramContext::statement() {
  return getRuleContexts<SimpleLanguageParser::StatementContext>();
}

SimpleLanguageParser::StatementContext* SimpleLanguageParser::ProgramContext::statement(size_t i) {
  return getRuleContext<SimpleLanguageParser::StatementContext>(i);
}


size_t SimpleLanguageParser::ProgramContext::getRuleIndex() const {
  return SimpleLanguageParser::RuleProgram;
}


std::any SimpleLanguageParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleLanguageVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

SimpleLanguageParser::ProgramContext* SimpleLanguageParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, SimpleLanguageParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(5); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(4);
      statement();
      setState(7); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SimpleLanguageParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

SimpleLanguageParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleLanguageParser::StatementContext::STRING() {
  return getToken(SimpleLanguageParser::STRING, 0);
}


size_t SimpleLanguageParser::StatementContext::getRuleIndex() const {
  return SimpleLanguageParser::RuleStatement;
}


std::any SimpleLanguageParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleLanguageVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

SimpleLanguageParser::StatementContext* SimpleLanguageParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, SimpleLanguageParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(9);
    match(SimpleLanguageParser::T__0);
    setState(10);
    match(SimpleLanguageParser::STRING);
    setState(11);
    match(SimpleLanguageParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void SimpleLanguageParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  simplelanguageParserInitialize();
#else
  ::antlr4::internal::call_once(simplelanguageParserOnceFlag, simplelanguageParserInitialize);
#endif
}
