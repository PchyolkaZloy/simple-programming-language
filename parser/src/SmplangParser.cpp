
// Generated from grammar/Smplang.g4 by ANTLR 4.13.2


#include "SmplangListener.h"
#include "SmplangVisitor.h"

#include "SmplangParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SmplangParserStaticData final {
  SmplangParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SmplangParserStaticData(const SmplangParserStaticData&) = delete;
  SmplangParserStaticData(SmplangParserStaticData&&) = delete;
  SmplangParserStaticData& operator=(const SmplangParserStaticData&) = delete;
  SmplangParserStaticData& operator=(SmplangParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag smplangParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<SmplangParserStaticData> smplangParserStaticData = nullptr;

void smplangParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (smplangParserStaticData != nullptr) {
    return;
  }
#else
  assert(smplangParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SmplangParserStaticData>(
    std::vector<std::string>{
      "program", "functionDecl", "returnType", "parameterList", "parameter", 
      "structDecl", "fieldDecl", "type", "primitiveType", "structType", 
      "block", "statement", "varDecl", "assignment", "ifStatement", "whileStatement", 
      "breakStatement", "continueStatement", "returnStatement", "printStatement", 
      "expression", "primaryExpression", "arrayInit", "structInit", "argumentList", 
      "fieldAccess", "arrayAccess", "functionCall", "assignable"
    },
    std::vector<std::string>{
      "", "'int'", "'double'", "'char'", "'bool'", "'func'", "'void'", "'return'", 
      "'print'", "'for'", "'while'", "'if'", "'else'", "'struct'", "'break'", 
      "'continue'", "", "", "", "", "", "'--'", "", "", "", "'!'", "'&&'", 
      "'||'", "'='", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", "','", 
      "'.'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "FUNC", "VOID", "RETURN", "PRINT", "FOR", "WHILE", 
      "IF", "ELSE", "STRUCT", "BREAK", "CONTINUE", "BOOL", "INT", "DOUBLE", 
      "CHAR", "ID", "NEG", "MULT", "ADD", "COMPOP", "NOT", "AND", "OR", 
      "ASSIGN", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", 
      "SEMI", "COMMA", "DOT", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,39,305,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,1,0,1,0,1,0,5,0,62,8,0,10,0,12,0,65,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,
  	1,3,1,74,8,1,1,1,1,1,1,1,1,2,1,2,3,2,81,8,2,1,3,1,3,1,3,5,3,86,8,3,10,
  	3,12,3,89,9,3,1,4,1,4,1,4,1,5,1,5,1,5,1,5,4,5,98,8,5,11,5,12,5,99,1,5,
  	1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,3,7,112,8,7,1,7,1,7,1,7,1,7,5,7,118,
  	8,7,10,7,12,7,121,9,7,1,8,1,8,1,9,1,9,1,10,1,10,5,10,129,8,10,10,10,12,
  	10,132,9,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,3,11,160,8,11,1,12,1,12,1,12,1,12,3,12,166,8,12,1,13,1,13,1,13,1,13,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,179,8,14,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,3,18,193,8,18,1,19,1,19,1,19,
  	1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,210,
  	8,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,5,20,232,8,20,10,20,12,20,235,9,20,
  	1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,
  	3,21,251,8,21,1,22,1,22,1,22,1,22,5,22,257,8,22,10,22,12,22,260,9,22,
  	3,22,262,8,22,1,22,1,22,1,23,1,23,1,23,3,23,269,8,23,1,23,1,23,1,24,1,
  	24,1,24,5,24,276,8,24,10,24,12,24,279,9,24,1,25,1,25,1,25,4,25,284,8,
  	25,11,25,12,25,285,1,26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,3,27,296,8,
  	27,1,27,1,27,1,28,1,28,1,28,3,28,303,8,28,1,28,0,2,14,40,29,0,2,4,6,8,
  	10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,
  	56,0,1,1,0,1,4,324,0,63,1,0,0,0,2,68,1,0,0,0,4,80,1,0,0,0,6,82,1,0,0,
  	0,8,90,1,0,0,0,10,93,1,0,0,0,12,104,1,0,0,0,14,111,1,0,0,0,16,122,1,0,
  	0,0,18,124,1,0,0,0,20,126,1,0,0,0,22,159,1,0,0,0,24,161,1,0,0,0,26,167,
  	1,0,0,0,28,171,1,0,0,0,30,180,1,0,0,0,32,186,1,0,0,0,34,188,1,0,0,0,36,
  	190,1,0,0,0,38,194,1,0,0,0,40,209,1,0,0,0,42,250,1,0,0,0,44,252,1,0,0,
  	0,46,265,1,0,0,0,48,272,1,0,0,0,50,280,1,0,0,0,52,287,1,0,0,0,54,292,
  	1,0,0,0,56,302,1,0,0,0,58,62,3,2,1,0,59,62,3,10,5,0,60,62,3,22,11,0,61,
  	58,1,0,0,0,61,59,1,0,0,0,61,60,1,0,0,0,62,65,1,0,0,0,63,61,1,0,0,0,63,
  	64,1,0,0,0,64,66,1,0,0,0,65,63,1,0,0,0,66,67,5,0,0,1,67,1,1,0,0,0,68,
  	69,5,5,0,0,69,70,3,4,2,0,70,71,5,20,0,0,71,73,5,29,0,0,72,74,3,6,3,0,
  	73,72,1,0,0,0,73,74,1,0,0,0,74,75,1,0,0,0,75,76,5,30,0,0,76,77,3,20,10,
  	0,77,3,1,0,0,0,78,81,3,14,7,0,79,81,5,6,0,0,80,78,1,0,0,0,80,79,1,0,0,
  	0,81,5,1,0,0,0,82,87,3,8,4,0,83,84,5,36,0,0,84,86,3,8,4,0,85,83,1,0,0,
  	0,86,89,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,7,1,0,0,0,89,87,1,0,0,
  	0,90,91,3,14,7,0,91,92,5,20,0,0,92,9,1,0,0,0,93,94,5,13,0,0,94,95,3,18,
  	9,0,95,97,5,31,0,0,96,98,3,12,6,0,97,96,1,0,0,0,98,99,1,0,0,0,99,97,1,
  	0,0,0,99,100,1,0,0,0,100,101,1,0,0,0,101,102,5,32,0,0,102,103,5,35,0,
  	0,103,11,1,0,0,0,104,105,3,14,7,0,105,106,5,20,0,0,106,107,5,35,0,0,107,
  	13,1,0,0,0,108,109,6,7,-1,0,109,112,3,16,8,0,110,112,3,18,9,0,111,108,
  	1,0,0,0,111,110,1,0,0,0,112,119,1,0,0,0,113,114,10,2,0,0,114,115,5,33,
  	0,0,115,116,5,17,0,0,116,118,5,34,0,0,117,113,1,0,0,0,118,121,1,0,0,0,
  	119,117,1,0,0,0,119,120,1,0,0,0,120,15,1,0,0,0,121,119,1,0,0,0,122,123,
  	7,0,0,0,123,17,1,0,0,0,124,125,5,20,0,0,125,19,1,0,0,0,126,130,5,31,0,
  	0,127,129,3,22,11,0,128,127,1,0,0,0,129,132,1,0,0,0,130,128,1,0,0,0,130,
  	131,1,0,0,0,131,133,1,0,0,0,132,130,1,0,0,0,133,134,5,32,0,0,134,21,1,
  	0,0,0,135,136,3,24,12,0,136,137,5,35,0,0,137,160,1,0,0,0,138,139,3,26,
  	13,0,139,140,5,35,0,0,140,160,1,0,0,0,141,142,3,36,18,0,142,143,5,35,
  	0,0,143,160,1,0,0,0,144,145,3,38,19,0,145,146,5,35,0,0,146,160,1,0,0,
  	0,147,148,3,40,20,0,148,149,5,35,0,0,149,160,1,0,0,0,150,160,3,28,14,
  	0,151,160,3,30,15,0,152,153,3,32,16,0,153,154,5,35,0,0,154,160,1,0,0,
  	0,155,156,3,34,17,0,156,157,5,35,0,0,157,160,1,0,0,0,158,160,3,20,10,
  	0,159,135,1,0,0,0,159,138,1,0,0,0,159,141,1,0,0,0,159,144,1,0,0,0,159,
  	147,1,0,0,0,159,150,1,0,0,0,159,151,1,0,0,0,159,152,1,0,0,0,159,155,1,
  	0,0,0,159,158,1,0,0,0,160,23,1,0,0,0,161,162,3,14,7,0,162,165,5,20,0,
  	0,163,164,5,28,0,0,164,166,3,40,20,0,165,163,1,0,0,0,165,166,1,0,0,0,
  	166,25,1,0,0,0,167,168,3,56,28,0,168,169,5,28,0,0,169,170,3,40,20,0,170,
  	27,1,0,0,0,171,172,5,11,0,0,172,173,5,29,0,0,173,174,3,40,20,0,174,175,
  	5,30,0,0,175,178,3,22,11,0,176,177,5,12,0,0,177,179,3,22,11,0,178,176,
  	1,0,0,0,178,179,1,0,0,0,179,29,1,0,0,0,180,181,5,10,0,0,181,182,5,29,
  	0,0,182,183,3,40,20,0,183,184,5,30,0,0,184,185,3,22,11,0,185,31,1,0,0,
  	0,186,187,5,14,0,0,187,33,1,0,0,0,188,189,5,15,0,0,189,35,1,0,0,0,190,
  	192,5,7,0,0,191,193,3,40,20,0,192,191,1,0,0,0,192,193,1,0,0,0,193,37,
  	1,0,0,0,194,195,5,8,0,0,195,196,5,29,0,0,196,197,3,40,20,0,197,198,5,
  	30,0,0,198,39,1,0,0,0,199,200,6,20,-1,0,200,201,5,29,0,0,201,202,3,40,
  	20,0,202,203,5,30,0,0,203,210,1,0,0,0,204,205,5,21,0,0,205,210,3,40,20,
  	9,206,207,5,25,0,0,207,210,3,40,20,8,208,210,3,42,21,0,209,199,1,0,0,
  	0,209,204,1,0,0,0,209,206,1,0,0,0,209,208,1,0,0,0,210,233,1,0,0,0,211,
  	212,10,7,0,0,212,213,5,26,0,0,213,232,3,40,20,8,214,215,10,6,0,0,215,
  	216,5,27,0,0,216,232,3,40,20,7,217,218,10,5,0,0,218,219,5,22,0,0,219,
  	232,3,40,20,6,220,221,10,4,0,0,221,222,5,23,0,0,222,232,3,40,20,5,223,
  	224,10,3,0,0,224,225,5,24,0,0,225,232,3,40,20,4,226,227,10,1,0,0,227,
  	228,5,33,0,0,228,229,3,40,20,0,229,230,5,34,0,0,230,232,1,0,0,0,231,211,
  	1,0,0,0,231,214,1,0,0,0,231,217,1,0,0,0,231,220,1,0,0,0,231,223,1,0,0,
  	0,231,226,1,0,0,0,232,235,1,0,0,0,233,231,1,0,0,0,233,234,1,0,0,0,234,
  	41,1,0,0,0,235,233,1,0,0,0,236,251,5,20,0,0,237,251,3,50,25,0,238,251,
  	3,52,26,0,239,251,3,54,27,0,240,251,5,17,0,0,241,251,5,18,0,0,242,251,
  	5,19,0,0,243,251,5,16,0,0,244,245,5,29,0,0,245,246,3,40,20,0,246,247,
  	5,30,0,0,247,251,1,0,0,0,248,251,3,44,22,0,249,251,3,46,23,0,250,236,
  	1,0,0,0,250,237,1,0,0,0,250,238,1,0,0,0,250,239,1,0,0,0,250,240,1,0,0,
  	0,250,241,1,0,0,0,250,242,1,0,0,0,250,243,1,0,0,0,250,244,1,0,0,0,250,
  	248,1,0,0,0,250,249,1,0,0,0,251,43,1,0,0,0,252,261,5,31,0,0,253,258,3,
  	40,20,0,254,255,5,36,0,0,255,257,3,40,20,0,256,254,1,0,0,0,257,260,1,
  	0,0,0,258,256,1,0,0,0,258,259,1,0,0,0,259,262,1,0,0,0,260,258,1,0,0,0,
  	261,253,1,0,0,0,261,262,1,0,0,0,262,263,1,0,0,0,263,264,5,32,0,0,264,
  	45,1,0,0,0,265,266,5,20,0,0,266,268,5,29,0,0,267,269,3,48,24,0,268,267,
  	1,0,0,0,268,269,1,0,0,0,269,270,1,0,0,0,270,271,5,30,0,0,271,47,1,0,0,
  	0,272,277,3,40,20,0,273,274,5,36,0,0,274,276,3,40,20,0,275,273,1,0,0,
  	0,276,279,1,0,0,0,277,275,1,0,0,0,277,278,1,0,0,0,278,49,1,0,0,0,279,
  	277,1,0,0,0,280,283,5,20,0,0,281,282,5,37,0,0,282,284,5,20,0,0,283,281,
  	1,0,0,0,284,285,1,0,0,0,285,283,1,0,0,0,285,286,1,0,0,0,286,51,1,0,0,
  	0,287,288,5,20,0,0,288,289,5,33,0,0,289,290,3,40,20,0,290,291,5,34,0,
  	0,291,53,1,0,0,0,292,293,5,20,0,0,293,295,5,29,0,0,294,296,3,48,24,0,
  	295,294,1,0,0,0,295,296,1,0,0,0,296,297,1,0,0,0,297,298,5,30,0,0,298,
  	55,1,0,0,0,299,303,5,20,0,0,300,303,3,50,25,0,301,303,3,52,26,0,302,299,
  	1,0,0,0,302,300,1,0,0,0,302,301,1,0,0,0,303,57,1,0,0,0,24,61,63,73,80,
  	87,99,111,119,130,159,165,178,192,209,231,233,250,258,261,268,277,285,
  	295,302
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  smplangParserStaticData = std::move(staticData);
}

}

SmplangParser::SmplangParser(TokenStream *input) : SmplangParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SmplangParser::SmplangParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SmplangParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *smplangParserStaticData->atn, smplangParserStaticData->decisionToDFA, smplangParserStaticData->sharedContextCache, options);
}

SmplangParser::~SmplangParser() {
  delete _interpreter;
}

const atn::ATN& SmplangParser::getATN() const {
  return *smplangParserStaticData->atn;
}

std::string SmplangParser::getGrammarFileName() const {
  return "Smplang.g4";
}

const std::vector<std::string>& SmplangParser::getRuleNames() const {
  return smplangParserStaticData->ruleNames;
}

const dfa::Vocabulary& SmplangParser::getVocabulary() const {
  return smplangParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SmplangParser::getSerializedATN() const {
  return smplangParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

SmplangParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::ProgramContext::EOF() {
  return getToken(SmplangParser::EOF, 0);
}

std::vector<SmplangParser::FunctionDeclContext *> SmplangParser::ProgramContext::functionDecl() {
  return getRuleContexts<SmplangParser::FunctionDeclContext>();
}

SmplangParser::FunctionDeclContext* SmplangParser::ProgramContext::functionDecl(size_t i) {
  return getRuleContext<SmplangParser::FunctionDeclContext>(i);
}

std::vector<SmplangParser::StructDeclContext *> SmplangParser::ProgramContext::structDecl() {
  return getRuleContexts<SmplangParser::StructDeclContext>();
}

SmplangParser::StructDeclContext* SmplangParser::ProgramContext::structDecl(size_t i) {
  return getRuleContext<SmplangParser::StructDeclContext>(i);
}

std::vector<SmplangParser::StatementContext *> SmplangParser::ProgramContext::statement() {
  return getRuleContexts<SmplangParser::StatementContext>();
}

SmplangParser::StatementContext* SmplangParser::ProgramContext::statement(size_t i) {
  return getRuleContext<SmplangParser::StatementContext>(i);
}


size_t SmplangParser::ProgramContext::getRuleIndex() const {
  return SmplangParser::RuleProgram;
}

void SmplangParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void SmplangParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any SmplangParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::ProgramContext* SmplangParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, SmplangParser::RuleProgram);
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
    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722098622) != 0)) {
      setState(61);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SmplangParser::FUNC: {
          setState(58);
          functionDecl();
          break;
        }

        case SmplangParser::STRUCT: {
          setState(59);
          structDecl();
          break;
        }

        case SmplangParser::T__0:
        case SmplangParser::T__1:
        case SmplangParser::T__2:
        case SmplangParser::T__3:
        case SmplangParser::RETURN:
        case SmplangParser::PRINT:
        case SmplangParser::WHILE:
        case SmplangParser::IF:
        case SmplangParser::BREAK:
        case SmplangParser::CONTINUE:
        case SmplangParser::BOOL:
        case SmplangParser::INT:
        case SmplangParser::DOUBLE:
        case SmplangParser::CHAR:
        case SmplangParser::ID:
        case SmplangParser::NEG:
        case SmplangParser::NOT:
        case SmplangParser::LPAREN:
        case SmplangParser::LBRACE: {
          setState(60);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(66);
    match(SmplangParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

SmplangParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::FunctionDeclContext::FUNC() {
  return getToken(SmplangParser::FUNC, 0);
}

SmplangParser::ReturnTypeContext* SmplangParser::FunctionDeclContext::returnType() {
  return getRuleContext<SmplangParser::ReturnTypeContext>(0);
}

tree::TerminalNode* SmplangParser::FunctionDeclContext::ID() {
  return getToken(SmplangParser::ID, 0);
}

tree::TerminalNode* SmplangParser::FunctionDeclContext::LPAREN() {
  return getToken(SmplangParser::LPAREN, 0);
}

tree::TerminalNode* SmplangParser::FunctionDeclContext::RPAREN() {
  return getToken(SmplangParser::RPAREN, 0);
}

SmplangParser::BlockContext* SmplangParser::FunctionDeclContext::block() {
  return getRuleContext<SmplangParser::BlockContext>(0);
}

SmplangParser::ParameterListContext* SmplangParser::FunctionDeclContext::parameterList() {
  return getRuleContext<SmplangParser::ParameterListContext>(0);
}


size_t SmplangParser::FunctionDeclContext::getRuleIndex() const {
  return SmplangParser::RuleFunctionDecl;
}

void SmplangParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void SmplangParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}


std::any SmplangParser::FunctionDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitFunctionDecl(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::FunctionDeclContext* SmplangParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, SmplangParser::RuleFunctionDecl);
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
    setState(68);
    match(SmplangParser::FUNC);
    setState(69);
    returnType();
    setState(70);
    match(SmplangParser::ID);
    setState(71);
    match(SmplangParser::LPAREN);
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1048606) != 0)) {
      setState(72);
      parameterList();
    }
    setState(75);
    match(SmplangParser::RPAREN);
    setState(76);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnTypeContext ------------------------------------------------------------------

SmplangParser::ReturnTypeContext::ReturnTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SmplangParser::TypeContext* SmplangParser::ReturnTypeContext::type() {
  return getRuleContext<SmplangParser::TypeContext>(0);
}

tree::TerminalNode* SmplangParser::ReturnTypeContext::VOID() {
  return getToken(SmplangParser::VOID, 0);
}


size_t SmplangParser::ReturnTypeContext::getRuleIndex() const {
  return SmplangParser::RuleReturnType;
}

void SmplangParser::ReturnTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnType(this);
}

void SmplangParser::ReturnTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnType(this);
}


std::any SmplangParser::ReturnTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitReturnType(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::ReturnTypeContext* SmplangParser::returnType() {
  ReturnTypeContext *_localctx = _tracker.createInstance<ReturnTypeContext>(_ctx, getState());
  enterRule(_localctx, 4, SmplangParser::RuleReturnType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(80);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SmplangParser::T__0:
      case SmplangParser::T__1:
      case SmplangParser::T__2:
      case SmplangParser::T__3:
      case SmplangParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(78);
        type(0);
        break;
      }

      case SmplangParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(79);
        match(SmplangParser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

SmplangParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SmplangParser::ParameterContext *> SmplangParser::ParameterListContext::parameter() {
  return getRuleContexts<SmplangParser::ParameterContext>();
}

SmplangParser::ParameterContext* SmplangParser::ParameterListContext::parameter(size_t i) {
  return getRuleContext<SmplangParser::ParameterContext>(i);
}

std::vector<tree::TerminalNode *> SmplangParser::ParameterListContext::COMMA() {
  return getTokens(SmplangParser::COMMA);
}

tree::TerminalNode* SmplangParser::ParameterListContext::COMMA(size_t i) {
  return getToken(SmplangParser::COMMA, i);
}


size_t SmplangParser::ParameterListContext::getRuleIndex() const {
  return SmplangParser::RuleParameterList;
}

void SmplangParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void SmplangParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}


std::any SmplangParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::ParameterListContext* SmplangParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 6, SmplangParser::RuleParameterList);
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
    setState(82);
    parameter();
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SmplangParser::COMMA) {
      setState(83);
      match(SmplangParser::COMMA);
      setState(84);
      parameter();
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

SmplangParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SmplangParser::TypeContext* SmplangParser::ParameterContext::type() {
  return getRuleContext<SmplangParser::TypeContext>(0);
}

tree::TerminalNode* SmplangParser::ParameterContext::ID() {
  return getToken(SmplangParser::ID, 0);
}


size_t SmplangParser::ParameterContext::getRuleIndex() const {
  return SmplangParser::RuleParameter;
}

void SmplangParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void SmplangParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}


std::any SmplangParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::ParameterContext* SmplangParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 8, SmplangParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    type(0);
    setState(91);
    match(SmplangParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclContext ------------------------------------------------------------------

SmplangParser::StructDeclContext::StructDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::StructDeclContext::STRUCT() {
  return getToken(SmplangParser::STRUCT, 0);
}

SmplangParser::StructTypeContext* SmplangParser::StructDeclContext::structType() {
  return getRuleContext<SmplangParser::StructTypeContext>(0);
}

tree::TerminalNode* SmplangParser::StructDeclContext::LBRACE() {
  return getToken(SmplangParser::LBRACE, 0);
}

tree::TerminalNode* SmplangParser::StructDeclContext::RBRACE() {
  return getToken(SmplangParser::RBRACE, 0);
}

tree::TerminalNode* SmplangParser::StructDeclContext::SEMI() {
  return getToken(SmplangParser::SEMI, 0);
}

std::vector<SmplangParser::FieldDeclContext *> SmplangParser::StructDeclContext::fieldDecl() {
  return getRuleContexts<SmplangParser::FieldDeclContext>();
}

SmplangParser::FieldDeclContext* SmplangParser::StructDeclContext::fieldDecl(size_t i) {
  return getRuleContext<SmplangParser::FieldDeclContext>(i);
}


size_t SmplangParser::StructDeclContext::getRuleIndex() const {
  return SmplangParser::RuleStructDecl;
}

void SmplangParser::StructDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDecl(this);
}

void SmplangParser::StructDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDecl(this);
}


std::any SmplangParser::StructDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitStructDecl(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::StructDeclContext* SmplangParser::structDecl() {
  StructDeclContext *_localctx = _tracker.createInstance<StructDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, SmplangParser::RuleStructDecl);
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
    setState(93);
    match(SmplangParser::STRUCT);
    setState(94);
    structType();
    setState(95);
    match(SmplangParser::LBRACE);
    setState(97); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(96);
      fieldDecl();
      setState(99); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1048606) != 0));
    setState(101);
    match(SmplangParser::RBRACE);
    setState(102);
    match(SmplangParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldDeclContext ------------------------------------------------------------------

SmplangParser::FieldDeclContext::FieldDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SmplangParser::TypeContext* SmplangParser::FieldDeclContext::type() {
  return getRuleContext<SmplangParser::TypeContext>(0);
}

tree::TerminalNode* SmplangParser::FieldDeclContext::ID() {
  return getToken(SmplangParser::ID, 0);
}

tree::TerminalNode* SmplangParser::FieldDeclContext::SEMI() {
  return getToken(SmplangParser::SEMI, 0);
}


size_t SmplangParser::FieldDeclContext::getRuleIndex() const {
  return SmplangParser::RuleFieldDecl;
}

void SmplangParser::FieldDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFieldDecl(this);
}

void SmplangParser::FieldDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFieldDecl(this);
}


std::any SmplangParser::FieldDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitFieldDecl(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::FieldDeclContext* SmplangParser::fieldDecl() {
  FieldDeclContext *_localctx = _tracker.createInstance<FieldDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, SmplangParser::RuleFieldDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    type(0);
    setState(105);
    match(SmplangParser::ID);
    setState(106);
    match(SmplangParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

SmplangParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SmplangParser::PrimitiveTypeContext* SmplangParser::TypeContext::primitiveType() {
  return getRuleContext<SmplangParser::PrimitiveTypeContext>(0);
}

SmplangParser::StructTypeContext* SmplangParser::TypeContext::structType() {
  return getRuleContext<SmplangParser::StructTypeContext>(0);
}

SmplangParser::TypeContext* SmplangParser::TypeContext::type() {
  return getRuleContext<SmplangParser::TypeContext>(0);
}

tree::TerminalNode* SmplangParser::TypeContext::LBRACK() {
  return getToken(SmplangParser::LBRACK, 0);
}

tree::TerminalNode* SmplangParser::TypeContext::INT() {
  return getToken(SmplangParser::INT, 0);
}

tree::TerminalNode* SmplangParser::TypeContext::RBRACK() {
  return getToken(SmplangParser::RBRACK, 0);
}


size_t SmplangParser::TypeContext::getRuleIndex() const {
  return SmplangParser::RuleType;
}

void SmplangParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void SmplangParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any SmplangParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}


SmplangParser::TypeContext* SmplangParser::type() {
   return type(0);
}

SmplangParser::TypeContext* SmplangParser::type(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SmplangParser::TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, parentState);
  SmplangParser::TypeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, SmplangParser::RuleType, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(111);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SmplangParser::T__0:
      case SmplangParser::T__1:
      case SmplangParser::T__2:
      case SmplangParser::T__3: {
        setState(109);
        primitiveType();
        break;
      }

      case SmplangParser::ID: {
        setState(110);
        structType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(119);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleType);
        setState(113);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(114);
        match(SmplangParser::LBRACK);
        setState(115);
        match(SmplangParser::INT);
        setState(116);
        match(SmplangParser::RBRACK); 
      }
      setState(121);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimitiveTypeContext ------------------------------------------------------------------

SmplangParser::PrimitiveTypeContext::PrimitiveTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SmplangParser::PrimitiveTypeContext::getRuleIndex() const {
  return SmplangParser::RulePrimitiveType;
}

void SmplangParser::PrimitiveTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimitiveType(this);
}

void SmplangParser::PrimitiveTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimitiveType(this);
}


std::any SmplangParser::PrimitiveTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitPrimitiveType(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::PrimitiveTypeContext* SmplangParser::primitiveType() {
  PrimitiveTypeContext *_localctx = _tracker.createInstance<PrimitiveTypeContext>(_ctx, getState());
  enterRule(_localctx, 16, SmplangParser::RulePrimitiveType);
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
    setState(122);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 30) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructTypeContext ------------------------------------------------------------------

SmplangParser::StructTypeContext::StructTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::StructTypeContext::ID() {
  return getToken(SmplangParser::ID, 0);
}


size_t SmplangParser::StructTypeContext::getRuleIndex() const {
  return SmplangParser::RuleStructType;
}

void SmplangParser::StructTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructType(this);
}

void SmplangParser::StructTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructType(this);
}


std::any SmplangParser::StructTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitStructType(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::StructTypeContext* SmplangParser::structType() {
  StructTypeContext *_localctx = _tracker.createInstance<StructTypeContext>(_ctx, getState());
  enterRule(_localctx, 18, SmplangParser::RuleStructType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    match(SmplangParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

SmplangParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::BlockContext::LBRACE() {
  return getToken(SmplangParser::LBRACE, 0);
}

tree::TerminalNode* SmplangParser::BlockContext::RBRACE() {
  return getToken(SmplangParser::RBRACE, 0);
}

std::vector<SmplangParser::StatementContext *> SmplangParser::BlockContext::statement() {
  return getRuleContexts<SmplangParser::StatementContext>();
}

SmplangParser::StatementContext* SmplangParser::BlockContext::statement(size_t i) {
  return getRuleContext<SmplangParser::StatementContext>(i);
}


size_t SmplangParser::BlockContext::getRuleIndex() const {
  return SmplangParser::RuleBlock;
}

void SmplangParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void SmplangParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any SmplangParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::BlockContext* SmplangParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 20, SmplangParser::RuleBlock);
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
    setState(126);
    match(SmplangParser::LBRACE);
    setState(130);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722090398) != 0)) {
      setState(127);
      statement();
      setState(132);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(133);
    match(SmplangParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

SmplangParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SmplangParser::VarDeclContext* SmplangParser::StatementContext::varDecl() {
  return getRuleContext<SmplangParser::VarDeclContext>(0);
}

tree::TerminalNode* SmplangParser::StatementContext::SEMI() {
  return getToken(SmplangParser::SEMI, 0);
}

SmplangParser::AssignmentContext* SmplangParser::StatementContext::assignment() {
  return getRuleContext<SmplangParser::AssignmentContext>(0);
}

SmplangParser::ReturnStatementContext* SmplangParser::StatementContext::returnStatement() {
  return getRuleContext<SmplangParser::ReturnStatementContext>(0);
}

SmplangParser::PrintStatementContext* SmplangParser::StatementContext::printStatement() {
  return getRuleContext<SmplangParser::PrintStatementContext>(0);
}

SmplangParser::ExpressionContext* SmplangParser::StatementContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}

SmplangParser::IfStatementContext* SmplangParser::StatementContext::ifStatement() {
  return getRuleContext<SmplangParser::IfStatementContext>(0);
}

SmplangParser::WhileStatementContext* SmplangParser::StatementContext::whileStatement() {
  return getRuleContext<SmplangParser::WhileStatementContext>(0);
}

SmplangParser::BreakStatementContext* SmplangParser::StatementContext::breakStatement() {
  return getRuleContext<SmplangParser::BreakStatementContext>(0);
}

SmplangParser::ContinueStatementContext* SmplangParser::StatementContext::continueStatement() {
  return getRuleContext<SmplangParser::ContinueStatementContext>(0);
}

SmplangParser::BlockContext* SmplangParser::StatementContext::block() {
  return getRuleContext<SmplangParser::BlockContext>(0);
}


size_t SmplangParser::StatementContext::getRuleIndex() const {
  return SmplangParser::RuleStatement;
}

void SmplangParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void SmplangParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any SmplangParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::StatementContext* SmplangParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, SmplangParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(159);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(135);
      varDecl();
      setState(136);
      match(SmplangParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(138);
      assignment();
      setState(139);
      match(SmplangParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(141);
      returnStatement();
      setState(142);
      match(SmplangParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(144);
      printStatement();
      setState(145);
      match(SmplangParser::SEMI);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(147);
      expression(0);
      setState(148);
      match(SmplangParser::SEMI);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(150);
      ifStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(151);
      whileStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(152);
      breakStatement();
      setState(153);
      match(SmplangParser::SEMI);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(155);
      continueStatement();
      setState(156);
      match(SmplangParser::SEMI);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(158);
      block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

SmplangParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SmplangParser::TypeContext* SmplangParser::VarDeclContext::type() {
  return getRuleContext<SmplangParser::TypeContext>(0);
}

tree::TerminalNode* SmplangParser::VarDeclContext::ID() {
  return getToken(SmplangParser::ID, 0);
}

tree::TerminalNode* SmplangParser::VarDeclContext::ASSIGN() {
  return getToken(SmplangParser::ASSIGN, 0);
}

SmplangParser::ExpressionContext* SmplangParser::VarDeclContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}


size_t SmplangParser::VarDeclContext::getRuleIndex() const {
  return SmplangParser::RuleVarDecl;
}

void SmplangParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void SmplangParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}


std::any SmplangParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::VarDeclContext* SmplangParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, SmplangParser::RuleVarDecl);
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
    setState(161);
    type(0);
    setState(162);
    match(SmplangParser::ID);
    setState(165);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SmplangParser::ASSIGN) {
      setState(163);
      match(SmplangParser::ASSIGN);
      setState(164);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

SmplangParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SmplangParser::AssignableContext* SmplangParser::AssignmentContext::assignable() {
  return getRuleContext<SmplangParser::AssignableContext>(0);
}

tree::TerminalNode* SmplangParser::AssignmentContext::ASSIGN() {
  return getToken(SmplangParser::ASSIGN, 0);
}

SmplangParser::ExpressionContext* SmplangParser::AssignmentContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}


size_t SmplangParser::AssignmentContext::getRuleIndex() const {
  return SmplangParser::RuleAssignment;
}

void SmplangParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void SmplangParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


std::any SmplangParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::AssignmentContext* SmplangParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 26, SmplangParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    assignable();
    setState(168);
    match(SmplangParser::ASSIGN);
    setState(169);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

SmplangParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::IfStatementContext::IF() {
  return getToken(SmplangParser::IF, 0);
}

tree::TerminalNode* SmplangParser::IfStatementContext::LPAREN() {
  return getToken(SmplangParser::LPAREN, 0);
}

SmplangParser::ExpressionContext* SmplangParser::IfStatementContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}

tree::TerminalNode* SmplangParser::IfStatementContext::RPAREN() {
  return getToken(SmplangParser::RPAREN, 0);
}

std::vector<SmplangParser::StatementContext *> SmplangParser::IfStatementContext::statement() {
  return getRuleContexts<SmplangParser::StatementContext>();
}

SmplangParser::StatementContext* SmplangParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<SmplangParser::StatementContext>(i);
}

tree::TerminalNode* SmplangParser::IfStatementContext::ELSE() {
  return getToken(SmplangParser::ELSE, 0);
}


size_t SmplangParser::IfStatementContext::getRuleIndex() const {
  return SmplangParser::RuleIfStatement;
}

void SmplangParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void SmplangParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}


std::any SmplangParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::IfStatementContext* SmplangParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, SmplangParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(SmplangParser::IF);
    setState(172);
    match(SmplangParser::LPAREN);
    setState(173);
    expression(0);
    setState(174);
    match(SmplangParser::RPAREN);
    setState(175);
    statement();
    setState(178);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(176);
      match(SmplangParser::ELSE);
      setState(177);
      statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

SmplangParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::WhileStatementContext::WHILE() {
  return getToken(SmplangParser::WHILE, 0);
}

tree::TerminalNode* SmplangParser::WhileStatementContext::LPAREN() {
  return getToken(SmplangParser::LPAREN, 0);
}

SmplangParser::ExpressionContext* SmplangParser::WhileStatementContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}

tree::TerminalNode* SmplangParser::WhileStatementContext::RPAREN() {
  return getToken(SmplangParser::RPAREN, 0);
}

SmplangParser::StatementContext* SmplangParser::WhileStatementContext::statement() {
  return getRuleContext<SmplangParser::StatementContext>(0);
}


size_t SmplangParser::WhileStatementContext::getRuleIndex() const {
  return SmplangParser::RuleWhileStatement;
}

void SmplangParser::WhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStatement(this);
}

void SmplangParser::WhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStatement(this);
}


std::any SmplangParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::WhileStatementContext* SmplangParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, SmplangParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    match(SmplangParser::WHILE);
    setState(181);
    match(SmplangParser::LPAREN);
    setState(182);
    expression(0);
    setState(183);
    match(SmplangParser::RPAREN);
    setState(184);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

SmplangParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::BreakStatementContext::BREAK() {
  return getToken(SmplangParser::BREAK, 0);
}


size_t SmplangParser::BreakStatementContext::getRuleIndex() const {
  return SmplangParser::RuleBreakStatement;
}

void SmplangParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void SmplangParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}


std::any SmplangParser::BreakStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitBreakStatement(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::BreakStatementContext* SmplangParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, SmplangParser::RuleBreakStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(SmplangParser::BREAK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStatementContext ------------------------------------------------------------------

SmplangParser::ContinueStatementContext::ContinueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::ContinueStatementContext::CONTINUE() {
  return getToken(SmplangParser::CONTINUE, 0);
}


size_t SmplangParser::ContinueStatementContext::getRuleIndex() const {
  return SmplangParser::RuleContinueStatement;
}

void SmplangParser::ContinueStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueStatement(this);
}

void SmplangParser::ContinueStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueStatement(this);
}


std::any SmplangParser::ContinueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitContinueStatement(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::ContinueStatementContext* SmplangParser::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, SmplangParser::RuleContinueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(SmplangParser::CONTINUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

SmplangParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::ReturnStatementContext::RETURN() {
  return getToken(SmplangParser::RETURN, 0);
}

SmplangParser::ExpressionContext* SmplangParser::ReturnStatementContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}


size_t SmplangParser::ReturnStatementContext::getRuleIndex() const {
  return SmplangParser::RuleReturnStatement;
}

void SmplangParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void SmplangParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}


std::any SmplangParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::ReturnStatementContext* SmplangParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, SmplangParser::RuleReturnStatement);
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
    setState(190);
    match(SmplangParser::RETURN);
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722037760) != 0)) {
      setState(191);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintStatementContext ------------------------------------------------------------------

SmplangParser::PrintStatementContext::PrintStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::PrintStatementContext::PRINT() {
  return getToken(SmplangParser::PRINT, 0);
}

tree::TerminalNode* SmplangParser::PrintStatementContext::LPAREN() {
  return getToken(SmplangParser::LPAREN, 0);
}

SmplangParser::ExpressionContext* SmplangParser::PrintStatementContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}

tree::TerminalNode* SmplangParser::PrintStatementContext::RPAREN() {
  return getToken(SmplangParser::RPAREN, 0);
}


size_t SmplangParser::PrintStatementContext::getRuleIndex() const {
  return SmplangParser::RulePrintStatement;
}

void SmplangParser::PrintStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintStatement(this);
}

void SmplangParser::PrintStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintStatement(this);
}


std::any SmplangParser::PrintStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitPrintStatement(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::PrintStatementContext* SmplangParser::printStatement() {
  PrintStatementContext *_localctx = _tracker.createInstance<PrintStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, SmplangParser::RulePrintStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    match(SmplangParser::PRINT);
    setState(195);
    match(SmplangParser::LPAREN);
    setState(196);
    expression(0);
    setState(197);
    match(SmplangParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

SmplangParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::ExpressionContext::LPAREN() {
  return getToken(SmplangParser::LPAREN, 0);
}

std::vector<SmplangParser::ExpressionContext *> SmplangParser::ExpressionContext::expression() {
  return getRuleContexts<SmplangParser::ExpressionContext>();
}

SmplangParser::ExpressionContext* SmplangParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<SmplangParser::ExpressionContext>(i);
}

tree::TerminalNode* SmplangParser::ExpressionContext::RPAREN() {
  return getToken(SmplangParser::RPAREN, 0);
}

tree::TerminalNode* SmplangParser::ExpressionContext::NEG() {
  return getToken(SmplangParser::NEG, 0);
}

tree::TerminalNode* SmplangParser::ExpressionContext::NOT() {
  return getToken(SmplangParser::NOT, 0);
}

SmplangParser::PrimaryExpressionContext* SmplangParser::ExpressionContext::primaryExpression() {
  return getRuleContext<SmplangParser::PrimaryExpressionContext>(0);
}

tree::TerminalNode* SmplangParser::ExpressionContext::AND() {
  return getToken(SmplangParser::AND, 0);
}

tree::TerminalNode* SmplangParser::ExpressionContext::OR() {
  return getToken(SmplangParser::OR, 0);
}

tree::TerminalNode* SmplangParser::ExpressionContext::MULT() {
  return getToken(SmplangParser::MULT, 0);
}

tree::TerminalNode* SmplangParser::ExpressionContext::ADD() {
  return getToken(SmplangParser::ADD, 0);
}

tree::TerminalNode* SmplangParser::ExpressionContext::COMPOP() {
  return getToken(SmplangParser::COMPOP, 0);
}

tree::TerminalNode* SmplangParser::ExpressionContext::LBRACK() {
  return getToken(SmplangParser::LBRACK, 0);
}

tree::TerminalNode* SmplangParser::ExpressionContext::RBRACK() {
  return getToken(SmplangParser::RBRACK, 0);
}


size_t SmplangParser::ExpressionContext::getRuleIndex() const {
  return SmplangParser::RuleExpression;
}

void SmplangParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void SmplangParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any SmplangParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


SmplangParser::ExpressionContext* SmplangParser::expression() {
   return expression(0);
}

SmplangParser::ExpressionContext* SmplangParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SmplangParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  SmplangParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, SmplangParser::RuleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(209);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(200);
      match(SmplangParser::LPAREN);
      setState(201);
      expression(0);
      setState(202);
      match(SmplangParser::RPAREN);
      break;
    }

    case 2: {
      setState(204);
      match(SmplangParser::NEG);
      setState(205);
      expression(9);
      break;
    }

    case 3: {
      setState(206);
      match(SmplangParser::NOT);
      setState(207);
      expression(8);
      break;
    }

    case 4: {
      setState(208);
      primaryExpression();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(233);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(231);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(211);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(212);
          match(SmplangParser::AND);
          setState(213);
          expression(8);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(214);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(215);
          match(SmplangParser::OR);
          setState(216);
          expression(7);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(217);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(218);
          match(SmplangParser::MULT);
          setState(219);
          expression(6);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(220);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(221);
          match(SmplangParser::ADD);
          setState(222);
          expression(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(223);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(224);
          match(SmplangParser::COMPOP);
          setState(225);
          expression(4);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(226);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(227);
          match(SmplangParser::LBRACK);
          setState(228);
          expression(0);
          setState(229);
          match(SmplangParser::RBRACK);
          break;
        }

        default:
          break;
        } 
      }
      setState(235);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryExpressionContext ------------------------------------------------------------------

SmplangParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::PrimaryExpressionContext::ID() {
  return getToken(SmplangParser::ID, 0);
}

SmplangParser::FieldAccessContext* SmplangParser::PrimaryExpressionContext::fieldAccess() {
  return getRuleContext<SmplangParser::FieldAccessContext>(0);
}

SmplangParser::ArrayAccessContext* SmplangParser::PrimaryExpressionContext::arrayAccess() {
  return getRuleContext<SmplangParser::ArrayAccessContext>(0);
}

SmplangParser::FunctionCallContext* SmplangParser::PrimaryExpressionContext::functionCall() {
  return getRuleContext<SmplangParser::FunctionCallContext>(0);
}

tree::TerminalNode* SmplangParser::PrimaryExpressionContext::INT() {
  return getToken(SmplangParser::INT, 0);
}

tree::TerminalNode* SmplangParser::PrimaryExpressionContext::DOUBLE() {
  return getToken(SmplangParser::DOUBLE, 0);
}

tree::TerminalNode* SmplangParser::PrimaryExpressionContext::CHAR() {
  return getToken(SmplangParser::CHAR, 0);
}

tree::TerminalNode* SmplangParser::PrimaryExpressionContext::BOOL() {
  return getToken(SmplangParser::BOOL, 0);
}

tree::TerminalNode* SmplangParser::PrimaryExpressionContext::LPAREN() {
  return getToken(SmplangParser::LPAREN, 0);
}

SmplangParser::ExpressionContext* SmplangParser::PrimaryExpressionContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}

tree::TerminalNode* SmplangParser::PrimaryExpressionContext::RPAREN() {
  return getToken(SmplangParser::RPAREN, 0);
}

SmplangParser::ArrayInitContext* SmplangParser::PrimaryExpressionContext::arrayInit() {
  return getRuleContext<SmplangParser::ArrayInitContext>(0);
}

SmplangParser::StructInitContext* SmplangParser::PrimaryExpressionContext::structInit() {
  return getRuleContext<SmplangParser::StructInitContext>(0);
}


size_t SmplangParser::PrimaryExpressionContext::getRuleIndex() const {
  return SmplangParser::RulePrimaryExpression;
}

void SmplangParser::PrimaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpression(this);
}

void SmplangParser::PrimaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpression(this);
}


std::any SmplangParser::PrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::PrimaryExpressionContext* SmplangParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 42, SmplangParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(250);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(236);
      match(SmplangParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(237);
      fieldAccess();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(238);
      arrayAccess();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(239);
      functionCall();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(240);
      match(SmplangParser::INT);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(241);
      match(SmplangParser::DOUBLE);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(242);
      match(SmplangParser::CHAR);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(243);
      match(SmplangParser::BOOL);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(244);
      match(SmplangParser::LPAREN);
      setState(245);
      expression(0);
      setState(246);
      match(SmplangParser::RPAREN);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(248);
      arrayInit();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(249);
      structInit();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayInitContext ------------------------------------------------------------------

SmplangParser::ArrayInitContext::ArrayInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::ArrayInitContext::LBRACE() {
  return getToken(SmplangParser::LBRACE, 0);
}

tree::TerminalNode* SmplangParser::ArrayInitContext::RBRACE() {
  return getToken(SmplangParser::RBRACE, 0);
}

std::vector<SmplangParser::ExpressionContext *> SmplangParser::ArrayInitContext::expression() {
  return getRuleContexts<SmplangParser::ExpressionContext>();
}

SmplangParser::ExpressionContext* SmplangParser::ArrayInitContext::expression(size_t i) {
  return getRuleContext<SmplangParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> SmplangParser::ArrayInitContext::COMMA() {
  return getTokens(SmplangParser::COMMA);
}

tree::TerminalNode* SmplangParser::ArrayInitContext::COMMA(size_t i) {
  return getToken(SmplangParser::COMMA, i);
}


size_t SmplangParser::ArrayInitContext::getRuleIndex() const {
  return SmplangParser::RuleArrayInit;
}

void SmplangParser::ArrayInitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayInit(this);
}

void SmplangParser::ArrayInitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayInit(this);
}


std::any SmplangParser::ArrayInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitArrayInit(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::ArrayInitContext* SmplangParser::arrayInit() {
  ArrayInitContext *_localctx = _tracker.createInstance<ArrayInitContext>(_ctx, getState());
  enterRule(_localctx, 44, SmplangParser::RuleArrayInit);
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
    setState(252);
    match(SmplangParser::LBRACE);
    setState(261);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722037760) != 0)) {
      setState(253);
      expression(0);
      setState(258);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SmplangParser::COMMA) {
        setState(254);
        match(SmplangParser::COMMA);
        setState(255);
        expression(0);
        setState(260);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(263);
    match(SmplangParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructInitContext ------------------------------------------------------------------

SmplangParser::StructInitContext::StructInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::StructInitContext::ID() {
  return getToken(SmplangParser::ID, 0);
}

tree::TerminalNode* SmplangParser::StructInitContext::LPAREN() {
  return getToken(SmplangParser::LPAREN, 0);
}

tree::TerminalNode* SmplangParser::StructInitContext::RPAREN() {
  return getToken(SmplangParser::RPAREN, 0);
}

SmplangParser::ArgumentListContext* SmplangParser::StructInitContext::argumentList() {
  return getRuleContext<SmplangParser::ArgumentListContext>(0);
}


size_t SmplangParser::StructInitContext::getRuleIndex() const {
  return SmplangParser::RuleStructInit;
}

void SmplangParser::StructInitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructInit(this);
}

void SmplangParser::StructInitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructInit(this);
}


std::any SmplangParser::StructInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitStructInit(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::StructInitContext* SmplangParser::structInit() {
  StructInitContext *_localctx = _tracker.createInstance<StructInitContext>(_ctx, getState());
  enterRule(_localctx, 46, SmplangParser::RuleStructInit);
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
    setState(265);
    match(SmplangParser::ID);
    setState(266);
    match(SmplangParser::LPAREN);
    setState(268);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722037760) != 0)) {
      setState(267);
      argumentList();
    }
    setState(270);
    match(SmplangParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

SmplangParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SmplangParser::ExpressionContext *> SmplangParser::ArgumentListContext::expression() {
  return getRuleContexts<SmplangParser::ExpressionContext>();
}

SmplangParser::ExpressionContext* SmplangParser::ArgumentListContext::expression(size_t i) {
  return getRuleContext<SmplangParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> SmplangParser::ArgumentListContext::COMMA() {
  return getTokens(SmplangParser::COMMA);
}

tree::TerminalNode* SmplangParser::ArgumentListContext::COMMA(size_t i) {
  return getToken(SmplangParser::COMMA, i);
}


size_t SmplangParser::ArgumentListContext::getRuleIndex() const {
  return SmplangParser::RuleArgumentList;
}

void SmplangParser::ArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentList(this);
}

void SmplangParser::ArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentList(this);
}


std::any SmplangParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::ArgumentListContext* SmplangParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 48, SmplangParser::RuleArgumentList);
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
    setState(272);
    expression(0);
    setState(277);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SmplangParser::COMMA) {
      setState(273);
      match(SmplangParser::COMMA);
      setState(274);
      expression(0);
      setState(279);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldAccessContext ------------------------------------------------------------------

SmplangParser::FieldAccessContext::FieldAccessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SmplangParser::FieldAccessContext::ID() {
  return getTokens(SmplangParser::ID);
}

tree::TerminalNode* SmplangParser::FieldAccessContext::ID(size_t i) {
  return getToken(SmplangParser::ID, i);
}

std::vector<tree::TerminalNode *> SmplangParser::FieldAccessContext::DOT() {
  return getTokens(SmplangParser::DOT);
}

tree::TerminalNode* SmplangParser::FieldAccessContext::DOT(size_t i) {
  return getToken(SmplangParser::DOT, i);
}


size_t SmplangParser::FieldAccessContext::getRuleIndex() const {
  return SmplangParser::RuleFieldAccess;
}

void SmplangParser::FieldAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFieldAccess(this);
}

void SmplangParser::FieldAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFieldAccess(this);
}


std::any SmplangParser::FieldAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitFieldAccess(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::FieldAccessContext* SmplangParser::fieldAccess() {
  FieldAccessContext *_localctx = _tracker.createInstance<FieldAccessContext>(_ctx, getState());
  enterRule(_localctx, 50, SmplangParser::RuleFieldAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(280);
    match(SmplangParser::ID);
    setState(283); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(281);
              match(SmplangParser::DOT);
              setState(282);
              match(SmplangParser::ID);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(285); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayAccessContext ------------------------------------------------------------------

SmplangParser::ArrayAccessContext::ArrayAccessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::ArrayAccessContext::ID() {
  return getToken(SmplangParser::ID, 0);
}

tree::TerminalNode* SmplangParser::ArrayAccessContext::LBRACK() {
  return getToken(SmplangParser::LBRACK, 0);
}

SmplangParser::ExpressionContext* SmplangParser::ArrayAccessContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}

tree::TerminalNode* SmplangParser::ArrayAccessContext::RBRACK() {
  return getToken(SmplangParser::RBRACK, 0);
}


size_t SmplangParser::ArrayAccessContext::getRuleIndex() const {
  return SmplangParser::RuleArrayAccess;
}

void SmplangParser::ArrayAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayAccess(this);
}

void SmplangParser::ArrayAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayAccess(this);
}


std::any SmplangParser::ArrayAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitArrayAccess(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::ArrayAccessContext* SmplangParser::arrayAccess() {
  ArrayAccessContext *_localctx = _tracker.createInstance<ArrayAccessContext>(_ctx, getState());
  enterRule(_localctx, 52, SmplangParser::RuleArrayAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    match(SmplangParser::ID);
    setState(288);
    match(SmplangParser::LBRACK);
    setState(289);
    expression(0);
    setState(290);
    match(SmplangParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

SmplangParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::FunctionCallContext::ID() {
  return getToken(SmplangParser::ID, 0);
}

tree::TerminalNode* SmplangParser::FunctionCallContext::LPAREN() {
  return getToken(SmplangParser::LPAREN, 0);
}

tree::TerminalNode* SmplangParser::FunctionCallContext::RPAREN() {
  return getToken(SmplangParser::RPAREN, 0);
}

SmplangParser::ArgumentListContext* SmplangParser::FunctionCallContext::argumentList() {
  return getRuleContext<SmplangParser::ArgumentListContext>(0);
}


size_t SmplangParser::FunctionCallContext::getRuleIndex() const {
  return SmplangParser::RuleFunctionCall;
}

void SmplangParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void SmplangParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}


std::any SmplangParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::FunctionCallContext* SmplangParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 54, SmplangParser::RuleFunctionCall);
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
    setState(292);
    match(SmplangParser::ID);
    setState(293);
    match(SmplangParser::LPAREN);
    setState(295);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722037760) != 0)) {
      setState(294);
      argumentList();
    }
    setState(297);
    match(SmplangParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignableContext ------------------------------------------------------------------

SmplangParser::AssignableContext::AssignableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::AssignableContext::ID() {
  return getToken(SmplangParser::ID, 0);
}

SmplangParser::FieldAccessContext* SmplangParser::AssignableContext::fieldAccess() {
  return getRuleContext<SmplangParser::FieldAccessContext>(0);
}

SmplangParser::ArrayAccessContext* SmplangParser::AssignableContext::arrayAccess() {
  return getRuleContext<SmplangParser::ArrayAccessContext>(0);
}


size_t SmplangParser::AssignableContext::getRuleIndex() const {
  return SmplangParser::RuleAssignable;
}

void SmplangParser::AssignableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignable(this);
}

void SmplangParser::AssignableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignable(this);
}


std::any SmplangParser::AssignableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitAssignable(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::AssignableContext* SmplangParser::assignable() {
  AssignableContext *_localctx = _tracker.createInstance<AssignableContext>(_ctx, getState());
  enterRule(_localctx, 56, SmplangParser::RuleAssignable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(302);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(299);
      match(SmplangParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(300);
      fieldAccess();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(301);
      arrayAccess();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SmplangParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 7: return typeSempred(antlrcpp::downCast<TypeContext *>(context), predicateIndex);
    case 20: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SmplangParser::typeSempred(TypeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool SmplangParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void SmplangParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  smplangParserInitialize();
#else
  ::antlr4::internal::call_once(smplangParserOnceFlag, smplangParserInitialize);
#endif
}
