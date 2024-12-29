
// Generated from grammar/SimpleLanguage.g4 by ANTLR 4.13.2


#include "SimpleLanguageLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct SimpleLanguageLexerStaticData final {
  SimpleLanguageLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SimpleLanguageLexerStaticData(const SimpleLanguageLexerStaticData&) = delete;
  SimpleLanguageLexerStaticData(SimpleLanguageLexerStaticData&&) = delete;
  SimpleLanguageLexerStaticData& operator=(const SimpleLanguageLexerStaticData&) = delete;
  SimpleLanguageLexerStaticData& operator=(SimpleLanguageLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag simplelanguagelexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<SimpleLanguageLexerStaticData> simplelanguagelexerLexerStaticData = nullptr;

void simplelanguagelexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (simplelanguagelexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(simplelanguagelexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SimpleLanguageLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "STRING", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'print'", "';'"
    },
    std::vector<std::string>{
      "", "", "", "STRING", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,4,33,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,1,0,1,0,1,0,1,0,
  	1,1,1,1,1,2,1,2,5,2,20,8,2,10,2,12,2,23,9,2,1,2,1,2,1,3,4,3,28,8,3,11,
  	3,12,3,29,1,3,1,3,1,21,0,4,1,1,3,2,5,3,7,4,1,0,1,3,0,9,10,13,13,32,32,
  	34,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,1,9,1,0,0,0,3,15,1,
  	0,0,0,5,17,1,0,0,0,7,27,1,0,0,0,9,10,5,112,0,0,10,11,5,114,0,0,11,12,
  	5,105,0,0,12,13,5,110,0,0,13,14,5,116,0,0,14,2,1,0,0,0,15,16,5,59,0,0,
  	16,4,1,0,0,0,17,21,5,34,0,0,18,20,9,0,0,0,19,18,1,0,0,0,20,23,1,0,0,0,
  	21,22,1,0,0,0,21,19,1,0,0,0,22,24,1,0,0,0,23,21,1,0,0,0,24,25,5,34,0,
  	0,25,6,1,0,0,0,26,28,7,0,0,0,27,26,1,0,0,0,28,29,1,0,0,0,29,27,1,0,0,
  	0,29,30,1,0,0,0,30,31,1,0,0,0,31,32,6,3,0,0,32,8,1,0,0,0,3,0,21,29,1,
  	6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  simplelanguagelexerLexerStaticData = std::move(staticData);
}

}

SimpleLanguageLexer::SimpleLanguageLexer(CharStream *input) : Lexer(input) {
  SimpleLanguageLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *simplelanguagelexerLexerStaticData->atn, simplelanguagelexerLexerStaticData->decisionToDFA, simplelanguagelexerLexerStaticData->sharedContextCache);
}

SimpleLanguageLexer::~SimpleLanguageLexer() {
  delete _interpreter;
}

std::string SimpleLanguageLexer::getGrammarFileName() const {
  return "SimpleLanguage.g4";
}

const std::vector<std::string>& SimpleLanguageLexer::getRuleNames() const {
  return simplelanguagelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& SimpleLanguageLexer::getChannelNames() const {
  return simplelanguagelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& SimpleLanguageLexer::getModeNames() const {
  return simplelanguagelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& SimpleLanguageLexer::getVocabulary() const {
  return simplelanguagelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SimpleLanguageLexer::getSerializedATN() const {
  return simplelanguagelexerLexerStaticData->serializedATN;
}

const atn::ATN& SimpleLanguageLexer::getATN() const {
  return *simplelanguagelexerLexerStaticData->atn;
}




void SimpleLanguageLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  simplelanguagelexerLexerInitialize();
#else
  ::antlr4::internal::call_once(simplelanguagelexerLexerOnceFlag, simplelanguagelexerLexerInitialize);
#endif
}
