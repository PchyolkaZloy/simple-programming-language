
// Generated from grammar/Smplang.g4 by ANTLR 4.13.2


#include "SmplangLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct SmplangLexerStaticData final {
  SmplangLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SmplangLexerStaticData(const SmplangLexerStaticData&) = delete;
  SmplangLexerStaticData(SmplangLexerStaticData&&) = delete;
  SmplangLexerStaticData& operator=(const SmplangLexerStaticData&) = delete;
  SmplangLexerStaticData& operator=(SmplangLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag smplanglexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<SmplangLexerStaticData> smplanglexerLexerStaticData = nullptr;

void smplanglexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (smplanglexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(smplanglexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SmplangLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "FUNC", "VOID", "RETURN", "PRINT", 
      "FOR", "WHILE", "IF", "ELSE", "STRUCT", "BOOL", "INT", "DOUBLE", "CHAR", 
      "ID", "BINOP", "UNAROP", "COMPOP", "LOGICOP", "ASSIGN", "LPAREN", 
      "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", 
      "DOT", "WS", "COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'int'", "'double'", "'char'", "'bool'", "'func'", "'void'", "'return'", 
      "'print'", "'for'", "'while'", "'if'", "'else'", "'struct'", "", "", 
      "", "", "", "", "", "", "", "'='", "'('", "')'", "'{'", "'}'", "'['", 
      "']'", "';'", "','", "'.'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "FUNC", "VOID", "RETURN", "PRINT", "FOR", "WHILE", 
      "IF", "ELSE", "STRUCT", "BOOL", "INT", "DOUBLE", "CHAR", "ID", "BINOP", 
      "UNAROP", "COMPOP", "LOGICOP", "ASSIGN", "LPAREN", "RPAREN", "LBRACE", 
      "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", "DOT", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,34,236,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,1,0,1,0,1,0,1,
  	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,
  	1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,
  	10,1,10,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,148,8,13,1,14,4,14,151,
  	8,14,11,14,12,14,152,1,15,4,15,156,8,15,11,15,12,15,157,1,15,1,15,5,15,
  	162,8,15,10,15,12,15,165,9,15,1,16,1,16,1,16,1,16,1,17,1,17,5,17,173,
  	8,17,10,17,12,17,176,9,17,1,18,1,18,1,19,1,19,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,3,20,191,8,20,1,21,1,21,1,21,1,21,3,21,197,8,21,1,
  	22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,27,1,27,1,28,1,28,1,
  	29,1,29,1,30,1,30,1,31,1,31,1,32,4,32,220,8,32,11,32,12,32,221,1,32,1,
  	32,1,33,1,33,1,33,1,33,5,33,230,8,33,10,33,12,33,233,9,33,1,33,1,33,0,
  	0,34,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,
  	27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,
  	25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,1,0,8,1,0,48,
  	57,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,3,0,42,43,45,45,
  	47,47,2,0,33,33,45,45,2,0,60,60,62,62,3,0,9,10,13,13,32,32,2,0,10,10,
  	13,13,247,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,
  	0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,
  	1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,
  	0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,
  	0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,
  	1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,
  	0,0,0,65,1,0,0,0,0,67,1,0,0,0,1,69,1,0,0,0,3,73,1,0,0,0,5,80,1,0,0,0,
  	7,85,1,0,0,0,9,90,1,0,0,0,11,95,1,0,0,0,13,100,1,0,0,0,15,107,1,0,0,0,
  	17,113,1,0,0,0,19,117,1,0,0,0,21,123,1,0,0,0,23,126,1,0,0,0,25,131,1,
  	0,0,0,27,147,1,0,0,0,29,150,1,0,0,0,31,155,1,0,0,0,33,166,1,0,0,0,35,
  	170,1,0,0,0,37,177,1,0,0,0,39,179,1,0,0,0,41,190,1,0,0,0,43,196,1,0,0,
  	0,45,198,1,0,0,0,47,200,1,0,0,0,49,202,1,0,0,0,51,204,1,0,0,0,53,206,
  	1,0,0,0,55,208,1,0,0,0,57,210,1,0,0,0,59,212,1,0,0,0,61,214,1,0,0,0,63,
  	216,1,0,0,0,65,219,1,0,0,0,67,225,1,0,0,0,69,70,5,105,0,0,70,71,5,110,
  	0,0,71,72,5,116,0,0,72,2,1,0,0,0,73,74,5,100,0,0,74,75,5,111,0,0,75,76,
  	5,117,0,0,76,77,5,98,0,0,77,78,5,108,0,0,78,79,5,101,0,0,79,4,1,0,0,0,
  	80,81,5,99,0,0,81,82,5,104,0,0,82,83,5,97,0,0,83,84,5,114,0,0,84,6,1,
  	0,0,0,85,86,5,98,0,0,86,87,5,111,0,0,87,88,5,111,0,0,88,89,5,108,0,0,
  	89,8,1,0,0,0,90,91,5,102,0,0,91,92,5,117,0,0,92,93,5,110,0,0,93,94,5,
  	99,0,0,94,10,1,0,0,0,95,96,5,118,0,0,96,97,5,111,0,0,97,98,5,105,0,0,
  	98,99,5,100,0,0,99,12,1,0,0,0,100,101,5,114,0,0,101,102,5,101,0,0,102,
  	103,5,116,0,0,103,104,5,117,0,0,104,105,5,114,0,0,105,106,5,110,0,0,106,
  	14,1,0,0,0,107,108,5,112,0,0,108,109,5,114,0,0,109,110,5,105,0,0,110,
  	111,5,110,0,0,111,112,5,116,0,0,112,16,1,0,0,0,113,114,5,102,0,0,114,
  	115,5,111,0,0,115,116,5,114,0,0,116,18,1,0,0,0,117,118,5,119,0,0,118,
  	119,5,104,0,0,119,120,5,105,0,0,120,121,5,108,0,0,121,122,5,101,0,0,122,
  	20,1,0,0,0,123,124,5,105,0,0,124,125,5,102,0,0,125,22,1,0,0,0,126,127,
  	5,101,0,0,127,128,5,108,0,0,128,129,5,115,0,0,129,130,5,101,0,0,130,24,
  	1,0,0,0,131,132,5,115,0,0,132,133,5,116,0,0,133,134,5,114,0,0,134,135,
  	5,117,0,0,135,136,5,99,0,0,136,137,5,116,0,0,137,26,1,0,0,0,138,139,5,
  	116,0,0,139,140,5,114,0,0,140,141,5,117,0,0,141,148,5,101,0,0,142,143,
  	5,102,0,0,143,144,5,97,0,0,144,145,5,108,0,0,145,146,5,115,0,0,146,148,
  	5,101,0,0,147,138,1,0,0,0,147,142,1,0,0,0,148,28,1,0,0,0,149,151,7,0,
  	0,0,150,149,1,0,0,0,151,152,1,0,0,0,152,150,1,0,0,0,152,153,1,0,0,0,153,
  	30,1,0,0,0,154,156,7,0,0,0,155,154,1,0,0,0,156,157,1,0,0,0,157,155,1,
  	0,0,0,157,158,1,0,0,0,158,159,1,0,0,0,159,163,3,63,31,0,160,162,7,0,0,
  	0,161,160,1,0,0,0,162,165,1,0,0,0,163,161,1,0,0,0,163,164,1,0,0,0,164,
  	32,1,0,0,0,165,163,1,0,0,0,166,167,5,39,0,0,167,168,9,0,0,0,168,169,5,
  	39,0,0,169,34,1,0,0,0,170,174,7,1,0,0,171,173,7,2,0,0,172,171,1,0,0,0,
  	173,176,1,0,0,0,174,172,1,0,0,0,174,175,1,0,0,0,175,36,1,0,0,0,176,174,
  	1,0,0,0,177,178,7,3,0,0,178,38,1,0,0,0,179,180,7,4,0,0,180,40,1,0,0,0,
  	181,182,5,61,0,0,182,191,5,61,0,0,183,184,5,33,0,0,184,191,5,61,0,0,185,
  	191,7,5,0,0,186,187,5,60,0,0,187,191,5,61,0,0,188,189,5,62,0,0,189,191,
  	5,61,0,0,190,181,1,0,0,0,190,183,1,0,0,0,190,185,1,0,0,0,190,186,1,0,
  	0,0,190,188,1,0,0,0,191,42,1,0,0,0,192,193,5,38,0,0,193,197,5,38,0,0,
  	194,195,5,124,0,0,195,197,5,124,0,0,196,192,1,0,0,0,196,194,1,0,0,0,197,
  	44,1,0,0,0,198,199,5,61,0,0,199,46,1,0,0,0,200,201,5,40,0,0,201,48,1,
  	0,0,0,202,203,5,41,0,0,203,50,1,0,0,0,204,205,5,123,0,0,205,52,1,0,0,
  	0,206,207,5,125,0,0,207,54,1,0,0,0,208,209,5,91,0,0,209,56,1,0,0,0,210,
  	211,5,93,0,0,211,58,1,0,0,0,212,213,5,59,0,0,213,60,1,0,0,0,214,215,5,
  	44,0,0,215,62,1,0,0,0,216,217,5,46,0,0,217,64,1,0,0,0,218,220,7,6,0,0,
  	219,218,1,0,0,0,220,221,1,0,0,0,221,219,1,0,0,0,221,222,1,0,0,0,222,223,
  	1,0,0,0,223,224,6,32,0,0,224,66,1,0,0,0,225,226,5,47,0,0,226,227,5,47,
  	0,0,227,231,1,0,0,0,228,230,8,7,0,0,229,228,1,0,0,0,230,233,1,0,0,0,231,
  	229,1,0,0,0,231,232,1,0,0,0,232,234,1,0,0,0,233,231,1,0,0,0,234,235,6,
  	33,0,0,235,68,1,0,0,0,10,0,147,152,157,163,174,190,196,221,231,1,6,0,
  	0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  smplanglexerLexerStaticData = std::move(staticData);
}

}

SmplangLexer::SmplangLexer(CharStream *input) : Lexer(input) {
  SmplangLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *smplanglexerLexerStaticData->atn, smplanglexerLexerStaticData->decisionToDFA, smplanglexerLexerStaticData->sharedContextCache);
}

SmplangLexer::~SmplangLexer() {
  delete _interpreter;
}

std::string SmplangLexer::getGrammarFileName() const {
  return "Smplang.g4";
}

const std::vector<std::string>& SmplangLexer::getRuleNames() const {
  return smplanglexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& SmplangLexer::getChannelNames() const {
  return smplanglexerLexerStaticData->channelNames;
}

const std::vector<std::string>& SmplangLexer::getModeNames() const {
  return smplanglexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& SmplangLexer::getVocabulary() const {
  return smplanglexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SmplangLexer::getSerializedATN() const {
  return smplanglexerLexerStaticData->serializedATN;
}

const atn::ATN& SmplangLexer::getATN() const {
  return *smplanglexerLexerStaticData->atn;
}




void SmplangLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  smplanglexerLexerInitialize();
#else
  ::antlr4::internal::call_once(smplanglexerLexerOnceFlag, smplanglexerLexerInitialize);
#endif
}
