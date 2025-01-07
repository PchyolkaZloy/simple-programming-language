
// Generated from ./grammar/Smplang.g4 by ANTLR 4.13.1


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
SmplangLexerStaticData *smplanglexerLexerStaticData = nullptr;

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
      "T__0", "T__1", "T__2", "T__3", "FUNC", "VOID", "RETURN", "FOR", "WHILE", 
      "IF", "ELSE", "ELIF", "STRUCT", "BREAK", "CONTINUE", "BOOL", "INT", 
      "DOUBLE", "CHAR", "ID", "NEG", "MULT", "ADD", "COMPOP", "NOT", "AND", 
      "OR", "ASSIGN", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", 
      "RBRACK", "ARRAYTYPE", "SEMI", "COMMA", "DOT", "WS", "COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'int'", "'double'", "'char'", "'bool'", "'func'", "'void'", "'return'", 
      "'for'", "'while'", "'if'", "'else'", "'elif'", "'struct'", "'break'", 
      "'continue'", "", "", "", "", "", "'--'", "", "", "", "'!'", "'&&'", 
      "'||'", "'='", "'('", "')'", "'{'", "'}'", "'['", "']'", "'[]'", "';'", 
      "','", "'.'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "FUNC", "VOID", "RETURN", "FOR", "WHILE", "IF", 
      "ELSE", "ELIF", "STRUCT", "BREAK", "CONTINUE", "BOOL", "INT", "DOUBLE", 
      "CHAR", "ID", "NEG", "MULT", "ADD", "COMPOP", "NOT", "AND", "OR", 
      "ASSIGN", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", 
      "ARRAYTYPE", "SEMI", "COMMA", "DOT", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,40,270,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,1,0,1,0,1,0,1,0,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,
  	4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,
  	1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,11,
  	1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,174,8,15,1,16,4,16,177,8,16,11,
  	16,12,16,178,1,17,4,17,182,8,17,11,17,12,17,183,1,17,1,17,5,17,188,8,
  	17,10,17,12,17,191,9,17,1,18,1,18,1,18,1,18,1,19,1,19,5,19,199,8,19,10,
  	19,12,19,202,9,19,1,20,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,23,1,
  	23,1,23,1,23,1,23,1,23,1,23,3,23,220,8,23,1,24,1,24,1,25,1,25,1,25,1,
  	26,1,26,1,26,1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,
  	32,1,33,1,33,1,34,1,34,1,34,1,35,1,35,1,36,1,36,1,37,1,37,1,38,4,38,254,
  	8,38,11,38,12,38,255,1,38,1,38,1,39,1,39,1,39,1,39,5,39,264,8,39,10,39,
  	12,39,267,9,39,1,39,1,39,0,0,40,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,
  	9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,
  	21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,
  	65,33,67,34,69,35,71,36,73,37,75,38,77,39,79,40,1,0,8,1,0,48,57,3,0,65,
  	90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,2,0,42,42,47,47,2,0,43,43,
  	45,45,2,0,60,60,62,62,3,0,9,10,13,13,32,32,2,0,10,10,13,13,280,0,1,1,
  	0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,
  	13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,
  	0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,
  	0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,
  	45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,
  	0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,
  	0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,
  	77,1,0,0,0,0,79,1,0,0,0,1,81,1,0,0,0,3,85,1,0,0,0,5,92,1,0,0,0,7,97,1,
  	0,0,0,9,102,1,0,0,0,11,107,1,0,0,0,13,112,1,0,0,0,15,119,1,0,0,0,17,123,
  	1,0,0,0,19,129,1,0,0,0,21,132,1,0,0,0,23,137,1,0,0,0,25,142,1,0,0,0,27,
  	149,1,0,0,0,29,155,1,0,0,0,31,173,1,0,0,0,33,176,1,0,0,0,35,181,1,0,0,
  	0,37,192,1,0,0,0,39,196,1,0,0,0,41,203,1,0,0,0,43,206,1,0,0,0,45,208,
  	1,0,0,0,47,219,1,0,0,0,49,221,1,0,0,0,51,223,1,0,0,0,53,226,1,0,0,0,55,
  	229,1,0,0,0,57,231,1,0,0,0,59,233,1,0,0,0,61,235,1,0,0,0,63,237,1,0,0,
  	0,65,239,1,0,0,0,67,241,1,0,0,0,69,243,1,0,0,0,71,246,1,0,0,0,73,248,
  	1,0,0,0,75,250,1,0,0,0,77,253,1,0,0,0,79,259,1,0,0,0,81,82,5,105,0,0,
  	82,83,5,110,0,0,83,84,5,116,0,0,84,2,1,0,0,0,85,86,5,100,0,0,86,87,5,
  	111,0,0,87,88,5,117,0,0,88,89,5,98,0,0,89,90,5,108,0,0,90,91,5,101,0,
  	0,91,4,1,0,0,0,92,93,5,99,0,0,93,94,5,104,0,0,94,95,5,97,0,0,95,96,5,
  	114,0,0,96,6,1,0,0,0,97,98,5,98,0,0,98,99,5,111,0,0,99,100,5,111,0,0,
  	100,101,5,108,0,0,101,8,1,0,0,0,102,103,5,102,0,0,103,104,5,117,0,0,104,
  	105,5,110,0,0,105,106,5,99,0,0,106,10,1,0,0,0,107,108,5,118,0,0,108,109,
  	5,111,0,0,109,110,5,105,0,0,110,111,5,100,0,0,111,12,1,0,0,0,112,113,
  	5,114,0,0,113,114,5,101,0,0,114,115,5,116,0,0,115,116,5,117,0,0,116,117,
  	5,114,0,0,117,118,5,110,0,0,118,14,1,0,0,0,119,120,5,102,0,0,120,121,
  	5,111,0,0,121,122,5,114,0,0,122,16,1,0,0,0,123,124,5,119,0,0,124,125,
  	5,104,0,0,125,126,5,105,0,0,126,127,5,108,0,0,127,128,5,101,0,0,128,18,
  	1,0,0,0,129,130,5,105,0,0,130,131,5,102,0,0,131,20,1,0,0,0,132,133,5,
  	101,0,0,133,134,5,108,0,0,134,135,5,115,0,0,135,136,5,101,0,0,136,22,
  	1,0,0,0,137,138,5,101,0,0,138,139,5,108,0,0,139,140,5,105,0,0,140,141,
  	5,102,0,0,141,24,1,0,0,0,142,143,5,115,0,0,143,144,5,116,0,0,144,145,
  	5,114,0,0,145,146,5,117,0,0,146,147,5,99,0,0,147,148,5,116,0,0,148,26,
  	1,0,0,0,149,150,5,98,0,0,150,151,5,114,0,0,151,152,5,101,0,0,152,153,
  	5,97,0,0,153,154,5,107,0,0,154,28,1,0,0,0,155,156,5,99,0,0,156,157,5,
  	111,0,0,157,158,5,110,0,0,158,159,5,116,0,0,159,160,5,105,0,0,160,161,
  	5,110,0,0,161,162,5,117,0,0,162,163,5,101,0,0,163,30,1,0,0,0,164,165,
  	5,116,0,0,165,166,5,114,0,0,166,167,5,117,0,0,167,174,5,101,0,0,168,169,
  	5,102,0,0,169,170,5,97,0,0,170,171,5,108,0,0,171,172,5,115,0,0,172,174,
  	5,101,0,0,173,164,1,0,0,0,173,168,1,0,0,0,174,32,1,0,0,0,175,177,7,0,
  	0,0,176,175,1,0,0,0,177,178,1,0,0,0,178,176,1,0,0,0,178,179,1,0,0,0,179,
  	34,1,0,0,0,180,182,7,0,0,0,181,180,1,0,0,0,182,183,1,0,0,0,183,181,1,
  	0,0,0,183,184,1,0,0,0,184,185,1,0,0,0,185,189,3,75,37,0,186,188,7,0,0,
  	0,187,186,1,0,0,0,188,191,1,0,0,0,189,187,1,0,0,0,189,190,1,0,0,0,190,
  	36,1,0,0,0,191,189,1,0,0,0,192,193,5,39,0,0,193,194,9,0,0,0,194,195,5,
  	39,0,0,195,38,1,0,0,0,196,200,7,1,0,0,197,199,7,2,0,0,198,197,1,0,0,0,
  	199,202,1,0,0,0,200,198,1,0,0,0,200,201,1,0,0,0,201,40,1,0,0,0,202,200,
  	1,0,0,0,203,204,5,45,0,0,204,205,5,45,0,0,205,42,1,0,0,0,206,207,7,3,
  	0,0,207,44,1,0,0,0,208,209,7,4,0,0,209,46,1,0,0,0,210,211,5,61,0,0,211,
  	220,5,61,0,0,212,213,5,33,0,0,213,220,5,61,0,0,214,220,7,5,0,0,215,216,
  	5,60,0,0,216,220,5,61,0,0,217,218,5,62,0,0,218,220,5,61,0,0,219,210,1,
  	0,0,0,219,212,1,0,0,0,219,214,1,0,0,0,219,215,1,0,0,0,219,217,1,0,0,0,
  	220,48,1,0,0,0,221,222,5,33,0,0,222,50,1,0,0,0,223,224,5,38,0,0,224,225,
  	5,38,0,0,225,52,1,0,0,0,226,227,5,124,0,0,227,228,5,124,0,0,228,54,1,
  	0,0,0,229,230,5,61,0,0,230,56,1,0,0,0,231,232,5,40,0,0,232,58,1,0,0,0,
  	233,234,5,41,0,0,234,60,1,0,0,0,235,236,5,123,0,0,236,62,1,0,0,0,237,
  	238,5,125,0,0,238,64,1,0,0,0,239,240,5,91,0,0,240,66,1,0,0,0,241,242,
  	5,93,0,0,242,68,1,0,0,0,243,244,5,91,0,0,244,245,5,93,0,0,245,70,1,0,
  	0,0,246,247,5,59,0,0,247,72,1,0,0,0,248,249,5,44,0,0,249,74,1,0,0,0,250,
  	251,5,46,0,0,251,76,1,0,0,0,252,254,7,6,0,0,253,252,1,0,0,0,254,255,1,
  	0,0,0,255,253,1,0,0,0,255,256,1,0,0,0,256,257,1,0,0,0,257,258,6,38,0,
  	0,258,78,1,0,0,0,259,260,5,47,0,0,260,261,5,47,0,0,261,265,1,0,0,0,262,
  	264,8,7,0,0,263,262,1,0,0,0,264,267,1,0,0,0,265,263,1,0,0,0,265,266,1,
  	0,0,0,266,268,1,0,0,0,267,265,1,0,0,0,268,269,6,39,0,0,269,80,1,0,0,0,
  	9,0,173,178,183,189,200,219,255,265,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  smplanglexerLexerStaticData = staticData.release();
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
