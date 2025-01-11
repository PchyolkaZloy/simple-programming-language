
// Generated from ./grammar/Smplang.g4 by ANTLR 4.13.1


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
SmplangParserStaticData *smplangParserStaticData = nullptr;

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
      "block", "statement", "varDecl", "assignment", "ifStatement", "ifBlock", 
      "elifBlock", "elseBlock", "whileStatement", "returnStatement", "expression", 
      "primaryExpression", "arrayInit", "argumentList", "functionCall", 
      "assignable", "assignablePrefix"
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
  	4,1,40,322,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,1,0,5,0,56,8,0,10,
  	0,12,0,59,9,0,1,0,5,0,62,8,0,10,0,12,0,65,9,0,1,0,5,0,68,8,0,10,0,12,
  	0,71,9,0,1,1,1,1,1,1,1,1,1,1,3,1,78,8,1,1,1,1,1,1,1,1,2,1,2,3,2,85,8,
  	2,1,3,1,3,1,3,5,3,90,8,3,10,3,12,3,93,9,3,1,4,1,4,1,4,1,5,1,5,1,5,1,5,
  	4,5,102,8,5,11,5,12,5,103,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,3,7,
  	116,8,7,1,7,1,7,5,7,120,8,7,10,7,12,7,123,9,7,1,8,1,8,1,9,1,9,1,10,1,
  	10,5,10,131,8,10,10,10,12,10,134,9,10,1,10,1,10,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,152,8,11,1,12,1,
  	12,1,12,1,12,3,12,158,8,12,1,13,1,13,1,13,1,13,1,14,1,14,5,14,166,8,14,
  	10,14,12,14,169,9,14,1,14,3,14,172,8,14,1,15,1,15,1,15,1,15,1,15,1,15,
  	3,15,180,8,15,1,16,1,16,1,16,1,16,1,16,1,16,3,16,188,8,16,1,17,1,17,1,
  	17,3,17,193,8,17,1,18,1,18,1,18,1,18,1,18,1,18,3,18,201,8,18,1,19,1,19,
  	3,19,205,8,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,
  	217,8,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,5,20,234,8,20,10,20,12,20,237,9,20,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,3,21,251,8,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,5,21,261,8,21,10,21,12,21,264,9,21,1,22,1,22,
  	1,22,1,22,5,22,270,8,22,10,22,12,22,273,9,22,3,22,275,8,22,1,22,1,22,
  	1,23,1,23,1,23,5,23,282,8,23,10,23,12,23,285,9,23,1,24,1,24,1,24,3,24,
  	290,8,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,302,8,
  	25,3,25,304,8,25,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,
  	26,5,26,317,8,26,10,26,12,26,320,9,26,1,26,0,4,14,40,42,52,27,0,2,4,6,
  	8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,0,
  	1,1,0,1,4,342,0,57,1,0,0,0,2,72,1,0,0,0,4,84,1,0,0,0,6,86,1,0,0,0,8,94,
  	1,0,0,0,10,97,1,0,0,0,12,108,1,0,0,0,14,115,1,0,0,0,16,124,1,0,0,0,18,
  	126,1,0,0,0,20,128,1,0,0,0,22,151,1,0,0,0,24,153,1,0,0,0,26,159,1,0,0,
  	0,28,163,1,0,0,0,30,173,1,0,0,0,32,181,1,0,0,0,34,189,1,0,0,0,36,194,
  	1,0,0,0,38,202,1,0,0,0,40,216,1,0,0,0,42,250,1,0,0,0,44,265,1,0,0,0,46,
  	278,1,0,0,0,48,286,1,0,0,0,50,303,1,0,0,0,52,305,1,0,0,0,54,56,3,10,5,
  	0,55,54,1,0,0,0,56,59,1,0,0,0,57,55,1,0,0,0,57,58,1,0,0,0,58,63,1,0,0,
  	0,59,57,1,0,0,0,60,62,3,2,1,0,61,60,1,0,0,0,62,65,1,0,0,0,63,61,1,0,0,
  	0,63,64,1,0,0,0,64,69,1,0,0,0,65,63,1,0,0,0,66,68,3,22,11,0,67,66,1,0,
  	0,0,68,71,1,0,0,0,69,67,1,0,0,0,69,70,1,0,0,0,70,1,1,0,0,0,71,69,1,0,
  	0,0,72,73,5,5,0,0,73,74,3,4,2,0,74,75,5,20,0,0,75,77,5,29,0,0,76,78,3,
  	6,3,0,77,76,1,0,0,0,77,78,1,0,0,0,78,79,1,0,0,0,79,80,5,30,0,0,80,81,
  	3,20,10,0,81,3,1,0,0,0,82,85,3,14,7,0,83,85,5,6,0,0,84,82,1,0,0,0,84,
  	83,1,0,0,0,85,5,1,0,0,0,86,91,3,8,4,0,87,88,5,37,0,0,88,90,3,8,4,0,89,
  	87,1,0,0,0,90,93,1,0,0,0,91,89,1,0,0,0,91,92,1,0,0,0,92,7,1,0,0,0,93,
  	91,1,0,0,0,94,95,3,14,7,0,95,96,5,20,0,0,96,9,1,0,0,0,97,98,5,13,0,0,
  	98,99,3,18,9,0,99,101,5,31,0,0,100,102,3,12,6,0,101,100,1,0,0,0,102,103,
  	1,0,0,0,103,101,1,0,0,0,103,104,1,0,0,0,104,105,1,0,0,0,105,106,5,32,
  	0,0,106,107,5,36,0,0,107,11,1,0,0,0,108,109,3,14,7,0,109,110,5,20,0,0,
  	110,111,5,36,0,0,111,13,1,0,0,0,112,113,6,7,-1,0,113,116,3,16,8,0,114,
  	116,3,18,9,0,115,112,1,0,0,0,115,114,1,0,0,0,116,121,1,0,0,0,117,118,
  	10,2,0,0,118,120,5,35,0,0,119,117,1,0,0,0,120,123,1,0,0,0,121,119,1,0,
  	0,0,121,122,1,0,0,0,122,15,1,0,0,0,123,121,1,0,0,0,124,125,7,0,0,0,125,
  	17,1,0,0,0,126,127,5,20,0,0,127,19,1,0,0,0,128,132,5,31,0,0,129,131,3,
  	22,11,0,130,129,1,0,0,0,131,134,1,0,0,0,132,130,1,0,0,0,132,133,1,0,0,
  	0,133,135,1,0,0,0,134,132,1,0,0,0,135,136,5,32,0,0,136,21,1,0,0,0,137,
  	138,3,24,12,0,138,139,5,36,0,0,139,152,1,0,0,0,140,141,3,26,13,0,141,
  	142,5,36,0,0,142,152,1,0,0,0,143,144,3,38,19,0,144,145,5,36,0,0,145,152,
  	1,0,0,0,146,147,3,40,20,0,147,148,5,36,0,0,148,152,1,0,0,0,149,152,3,
  	28,14,0,150,152,3,36,18,0,151,137,1,0,0,0,151,140,1,0,0,0,151,143,1,0,
  	0,0,151,146,1,0,0,0,151,149,1,0,0,0,151,150,1,0,0,0,152,23,1,0,0,0,153,
  	154,3,14,7,0,154,157,5,20,0,0,155,156,5,28,0,0,156,158,3,40,20,0,157,
  	155,1,0,0,0,157,158,1,0,0,0,158,25,1,0,0,0,159,160,3,50,25,0,160,161,
  	5,28,0,0,161,162,3,40,20,0,162,27,1,0,0,0,163,167,3,30,15,0,164,166,3,
  	32,16,0,165,164,1,0,0,0,166,169,1,0,0,0,167,165,1,0,0,0,167,168,1,0,0,
  	0,168,171,1,0,0,0,169,167,1,0,0,0,170,172,3,34,17,0,171,170,1,0,0,0,171,
  	172,1,0,0,0,172,29,1,0,0,0,173,174,5,10,0,0,174,175,5,29,0,0,175,176,
  	3,40,20,0,176,179,5,30,0,0,177,180,3,22,11,0,178,180,3,20,10,0,179,177,
  	1,0,0,0,179,178,1,0,0,0,180,31,1,0,0,0,181,182,5,12,0,0,182,183,5,29,
  	0,0,183,184,3,40,20,0,184,187,5,30,0,0,185,188,3,22,11,0,186,188,3,20,
  	10,0,187,185,1,0,0,0,187,186,1,0,0,0,188,33,1,0,0,0,189,192,5,11,0,0,
  	190,193,3,22,11,0,191,193,3,20,10,0,192,190,1,0,0,0,192,191,1,0,0,0,193,
  	35,1,0,0,0,194,195,5,9,0,0,195,196,5,29,0,0,196,197,3,40,20,0,197,200,
  	5,30,0,0,198,201,3,22,11,0,199,201,3,20,10,0,200,198,1,0,0,0,200,199,
  	1,0,0,0,201,37,1,0,0,0,202,204,5,7,0,0,203,205,3,40,20,0,204,203,1,0,
  	0,0,204,205,1,0,0,0,205,39,1,0,0,0,206,207,6,20,-1,0,207,208,5,29,0,0,
  	208,209,3,40,20,0,209,210,5,30,0,0,210,217,1,0,0,0,211,212,5,21,0,0,212,
  	217,3,40,20,8,213,214,5,25,0,0,214,217,3,40,20,7,215,217,3,42,21,0,216,
  	206,1,0,0,0,216,211,1,0,0,0,216,213,1,0,0,0,216,215,1,0,0,0,217,235,1,
  	0,0,0,218,219,10,6,0,0,219,220,5,26,0,0,220,234,3,40,20,7,221,222,10,
  	5,0,0,222,223,5,27,0,0,223,234,3,40,20,6,224,225,10,4,0,0,225,226,5,22,
  	0,0,226,234,3,40,20,5,227,228,10,3,0,0,228,229,5,23,0,0,229,234,3,40,
  	20,4,230,231,10,2,0,0,231,232,5,24,0,0,232,234,3,40,20,3,233,218,1,0,
  	0,0,233,221,1,0,0,0,233,224,1,0,0,0,233,227,1,0,0,0,233,230,1,0,0,0,234,
  	237,1,0,0,0,235,233,1,0,0,0,235,236,1,0,0,0,236,41,1,0,0,0,237,235,1,
  	0,0,0,238,239,6,21,-1,0,239,251,5,20,0,0,240,251,3,48,24,0,241,251,5,
  	17,0,0,242,251,5,18,0,0,243,251,5,19,0,0,244,251,5,16,0,0,245,246,5,29,
  	0,0,246,247,3,40,20,0,247,248,5,30,0,0,248,251,1,0,0,0,249,251,3,44,22,
  	0,250,238,1,0,0,0,250,240,1,0,0,0,250,241,1,0,0,0,250,242,1,0,0,0,250,
  	243,1,0,0,0,250,244,1,0,0,0,250,245,1,0,0,0,250,249,1,0,0,0,251,262,1,
  	0,0,0,252,253,10,9,0,0,253,254,5,38,0,0,254,261,5,20,0,0,255,256,10,8,
  	0,0,256,257,5,33,0,0,257,258,3,40,20,0,258,259,5,34,0,0,259,261,1,0,0,
  	0,260,252,1,0,0,0,260,255,1,0,0,0,261,264,1,0,0,0,262,260,1,0,0,0,262,
  	263,1,0,0,0,263,43,1,0,0,0,264,262,1,0,0,0,265,274,5,31,0,0,266,271,3,
  	40,20,0,267,268,5,37,0,0,268,270,3,40,20,0,269,267,1,0,0,0,270,273,1,
  	0,0,0,271,269,1,0,0,0,271,272,1,0,0,0,272,275,1,0,0,0,273,271,1,0,0,0,
  	274,266,1,0,0,0,274,275,1,0,0,0,275,276,1,0,0,0,276,277,5,32,0,0,277,
  	45,1,0,0,0,278,283,3,40,20,0,279,280,5,37,0,0,280,282,3,40,20,0,281,279,
  	1,0,0,0,282,285,1,0,0,0,283,281,1,0,0,0,283,284,1,0,0,0,284,47,1,0,0,
  	0,285,283,1,0,0,0,286,287,5,20,0,0,287,289,5,29,0,0,288,290,3,46,23,0,
  	289,288,1,0,0,0,289,290,1,0,0,0,290,291,1,0,0,0,291,292,5,30,0,0,292,
  	49,1,0,0,0,293,304,5,20,0,0,294,301,3,52,26,0,295,296,5,38,0,0,296,302,
  	5,20,0,0,297,298,5,33,0,0,298,299,3,40,20,0,299,300,5,34,0,0,300,302,
  	1,0,0,0,301,295,1,0,0,0,301,297,1,0,0,0,302,304,1,0,0,0,303,293,1,0,0,
  	0,303,294,1,0,0,0,304,51,1,0,0,0,305,306,6,26,-1,0,306,307,5,20,0,0,307,
  	318,1,0,0,0,308,309,10,2,0,0,309,310,5,38,0,0,310,317,5,20,0,0,311,312,
  	10,1,0,0,312,313,5,33,0,0,313,314,3,40,20,0,314,315,5,34,0,0,315,317,
  	1,0,0,0,316,308,1,0,0,0,316,311,1,0,0,0,317,320,1,0,0,0,318,316,1,0,0,
  	0,318,319,1,0,0,0,319,53,1,0,0,0,320,318,1,0,0,0,33,57,63,69,77,84,91,
  	103,115,121,132,151,157,167,171,179,187,192,200,204,216,233,235,250,260,
  	262,271,274,283,289,301,303,316,318
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  smplangParserStaticData = staticData.release();
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

std::vector<SmplangParser::StructDeclContext *> SmplangParser::ProgramContext::structDecl() {
  return getRuleContexts<SmplangParser::StructDeclContext>();
}

SmplangParser::StructDeclContext* SmplangParser::ProgramContext::structDecl(size_t i) {
  return getRuleContext<SmplangParser::StructDeclContext>(i);
}

std::vector<SmplangParser::FunctionDeclContext *> SmplangParser::ProgramContext::functionDecl() {
  return getRuleContexts<SmplangParser::FunctionDeclContext>();
}

SmplangParser::FunctionDeclContext* SmplangParser::ProgramContext::functionDecl(size_t i) {
  return getRuleContext<SmplangParser::FunctionDeclContext>(i);
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
    setState(57);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SmplangParser::STRUCT) {
      setState(54);
      structDecl();
      setState(59);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SmplangParser::FUNC) {
      setState(60);
      functionDecl();
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722039454) != 0)) {
      setState(66);
      statement();
      setState(71);
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
    setState(72);
    match(SmplangParser::FUNC);
    setState(73);
    returnType();
    setState(74);
    match(SmplangParser::ID);
    setState(75);
    match(SmplangParser::LPAREN);
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1048606) != 0)) {
      setState(76);
      parameterList();
    }
    setState(79);
    match(SmplangParser::RPAREN);
    setState(80);
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
    setState(84);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SmplangParser::T__0:
      case SmplangParser::T__1:
      case SmplangParser::T__2:
      case SmplangParser::T__3:
      case SmplangParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(82);
        type(0);
        break;
      }

      case SmplangParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(83);
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
    setState(86);
    parameter();
    setState(91);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SmplangParser::COMMA) {
      setState(87);
      match(SmplangParser::COMMA);
      setState(88);
      parameter();
      setState(93);
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
    setState(94);
    type(0);
    setState(95);
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
    setState(97);
    match(SmplangParser::STRUCT);
    setState(98);
    structType();
    setState(99);
    match(SmplangParser::LBRACE);
    setState(101); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(100);
      fieldDecl();
      setState(103); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1048606) != 0));
    setState(105);
    match(SmplangParser::RBRACE);
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
    setState(108);
    type(0);
    setState(109);
    match(SmplangParser::ID);
    setState(110);
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

tree::TerminalNode* SmplangParser::TypeContext::ARRAYTYPE() {
  return getToken(SmplangParser::ARRAYTYPE, 0);
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
    setState(115);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SmplangParser::T__0:
      case SmplangParser::T__1:
      case SmplangParser::T__2:
      case SmplangParser::T__3: {
        setState(113);
        primitiveType();
        break;
      }

      case SmplangParser::ID: {
        setState(114);
        structType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(121);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleType);
        setState(117);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(118);
        match(SmplangParser::ARRAYTYPE); 
      }
      setState(123);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
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
    setState(124);
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
    setState(126);
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
    setState(128);
    match(SmplangParser::LBRACE);
    setState(132);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722039454) != 0)) {
      setState(129);
      statement();
      setState(134);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(135);
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

SmplangParser::ExpressionContext* SmplangParser::StatementContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}

SmplangParser::IfStatementContext* SmplangParser::StatementContext::ifStatement() {
  return getRuleContext<SmplangParser::IfStatementContext>(0);
}

SmplangParser::WhileStatementContext* SmplangParser::StatementContext::whileStatement() {
  return getRuleContext<SmplangParser::WhileStatementContext>(0);
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
    setState(151);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(137);
      varDecl();
      setState(138);
      match(SmplangParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(140);
      assignment();
      setState(141);
      match(SmplangParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(143);
      returnStatement();
      setState(144);
      match(SmplangParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(146);
      expression(0);
      setState(147);
      match(SmplangParser::SEMI);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(149);
      ifStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(150);
      whileStatement();
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
    setState(153);
    type(0);
    setState(154);
    match(SmplangParser::ID);
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SmplangParser::ASSIGN) {
      setState(155);
      match(SmplangParser::ASSIGN);
      setState(156);
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
    setState(159);
    assignable();
    setState(160);
    match(SmplangParser::ASSIGN);
    setState(161);
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

SmplangParser::IfBlockContext* SmplangParser::IfStatementContext::ifBlock() {
  return getRuleContext<SmplangParser::IfBlockContext>(0);
}

std::vector<SmplangParser::ElifBlockContext *> SmplangParser::IfStatementContext::elifBlock() {
  return getRuleContexts<SmplangParser::ElifBlockContext>();
}

SmplangParser::ElifBlockContext* SmplangParser::IfStatementContext::elifBlock(size_t i) {
  return getRuleContext<SmplangParser::ElifBlockContext>(i);
}

SmplangParser::ElseBlockContext* SmplangParser::IfStatementContext::elseBlock() {
  return getRuleContext<SmplangParser::ElseBlockContext>(0);
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
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(163);
    ifBlock();
    setState(167);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(164);
        elifBlock(); 
      }
      setState(169);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
    setState(171);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(170);
      elseBlock();
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

//----------------- IfBlockContext ------------------------------------------------------------------

SmplangParser::IfBlockContext::IfBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::IfBlockContext::IF() {
  return getToken(SmplangParser::IF, 0);
}

tree::TerminalNode* SmplangParser::IfBlockContext::LPAREN() {
  return getToken(SmplangParser::LPAREN, 0);
}

SmplangParser::ExpressionContext* SmplangParser::IfBlockContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}

tree::TerminalNode* SmplangParser::IfBlockContext::RPAREN() {
  return getToken(SmplangParser::RPAREN, 0);
}

SmplangParser::StatementContext* SmplangParser::IfBlockContext::statement() {
  return getRuleContext<SmplangParser::StatementContext>(0);
}

SmplangParser::BlockContext* SmplangParser::IfBlockContext::block() {
  return getRuleContext<SmplangParser::BlockContext>(0);
}


size_t SmplangParser::IfBlockContext::getRuleIndex() const {
  return SmplangParser::RuleIfBlock;
}

void SmplangParser::IfBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfBlock(this);
}

void SmplangParser::IfBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfBlock(this);
}


std::any SmplangParser::IfBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitIfBlock(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::IfBlockContext* SmplangParser::ifBlock() {
  IfBlockContext *_localctx = _tracker.createInstance<IfBlockContext>(_ctx, getState());
  enterRule(_localctx, 30, SmplangParser::RuleIfBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    match(SmplangParser::IF);
    setState(174);
    match(SmplangParser::LPAREN);
    setState(175);
    expression(0);
    setState(176);
    match(SmplangParser::RPAREN);
    setState(179);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(177);
      statement();
      break;
    }

    case 2: {
      setState(178);
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

//----------------- ElifBlockContext ------------------------------------------------------------------

SmplangParser::ElifBlockContext::ElifBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::ElifBlockContext::ELIF() {
  return getToken(SmplangParser::ELIF, 0);
}

tree::TerminalNode* SmplangParser::ElifBlockContext::LPAREN() {
  return getToken(SmplangParser::LPAREN, 0);
}

SmplangParser::ExpressionContext* SmplangParser::ElifBlockContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}

tree::TerminalNode* SmplangParser::ElifBlockContext::RPAREN() {
  return getToken(SmplangParser::RPAREN, 0);
}

SmplangParser::StatementContext* SmplangParser::ElifBlockContext::statement() {
  return getRuleContext<SmplangParser::StatementContext>(0);
}

SmplangParser::BlockContext* SmplangParser::ElifBlockContext::block() {
  return getRuleContext<SmplangParser::BlockContext>(0);
}


size_t SmplangParser::ElifBlockContext::getRuleIndex() const {
  return SmplangParser::RuleElifBlock;
}

void SmplangParser::ElifBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElifBlock(this);
}

void SmplangParser::ElifBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElifBlock(this);
}


std::any SmplangParser::ElifBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitElifBlock(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::ElifBlockContext* SmplangParser::elifBlock() {
  ElifBlockContext *_localctx = _tracker.createInstance<ElifBlockContext>(_ctx, getState());
  enterRule(_localctx, 32, SmplangParser::RuleElifBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(SmplangParser::ELIF);
    setState(182);
    match(SmplangParser::LPAREN);
    setState(183);
    expression(0);
    setState(184);
    match(SmplangParser::RPAREN);
    setState(187);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(185);
      statement();
      break;
    }

    case 2: {
      setState(186);
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

//----------------- ElseBlockContext ------------------------------------------------------------------

SmplangParser::ElseBlockContext::ElseBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::ElseBlockContext::ELSE() {
  return getToken(SmplangParser::ELSE, 0);
}

SmplangParser::StatementContext* SmplangParser::ElseBlockContext::statement() {
  return getRuleContext<SmplangParser::StatementContext>(0);
}

SmplangParser::BlockContext* SmplangParser::ElseBlockContext::block() {
  return getRuleContext<SmplangParser::BlockContext>(0);
}


size_t SmplangParser::ElseBlockContext::getRuleIndex() const {
  return SmplangParser::RuleElseBlock;
}

void SmplangParser::ElseBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseBlock(this);
}

void SmplangParser::ElseBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseBlock(this);
}


std::any SmplangParser::ElseBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitElseBlock(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::ElseBlockContext* SmplangParser::elseBlock() {
  ElseBlockContext *_localctx = _tracker.createInstance<ElseBlockContext>(_ctx, getState());
  enterRule(_localctx, 34, SmplangParser::RuleElseBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    match(SmplangParser::ELSE);
    setState(192);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(190);
      statement();
      break;
    }

    case 2: {
      setState(191);
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

SmplangParser::BlockContext* SmplangParser::WhileStatementContext::block() {
  return getRuleContext<SmplangParser::BlockContext>(0);
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
  enterRule(_localctx, 36, SmplangParser::RuleWhileStatement);

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
    match(SmplangParser::WHILE);
    setState(195);
    match(SmplangParser::LPAREN);
    setState(196);
    expression(0);
    setState(197);
    match(SmplangParser::RPAREN);
    setState(200);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(198);
      statement();
      break;
    }

    case 2: {
      setState(199);
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
  enterRule(_localctx, 38, SmplangParser::RuleReturnStatement);
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
    setState(202);
    match(SmplangParser::RETURN);
    setState(204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722037760) != 0)) {
      setState(203);
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
    setState(216);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(207);
      match(SmplangParser::LPAREN);
      setState(208);
      expression(0);
      setState(209);
      match(SmplangParser::RPAREN);
      break;
    }

    case 2: {
      setState(211);
      match(SmplangParser::NEG);
      setState(212);
      expression(8);
      break;
    }

    case 3: {
      setState(213);
      match(SmplangParser::NOT);
      setState(214);
      expression(7);
      break;
    }

    case 4: {
      setState(215);
      primaryExpression(0);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(235);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(233);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(218);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(219);
          match(SmplangParser::AND);
          setState(220);
          expression(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(221);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(222);
          match(SmplangParser::OR);
          setState(223);
          expression(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(224);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(225);
          match(SmplangParser::MULT);
          setState(226);
          expression(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(227);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(228);
          match(SmplangParser::ADD);
          setState(229);
          expression(4);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(230);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(231);
          match(SmplangParser::COMPOP);
          setState(232);
          expression(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(237);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
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

SmplangParser::PrimaryExpressionContext* SmplangParser::PrimaryExpressionContext::primaryExpression() {
  return getRuleContext<SmplangParser::PrimaryExpressionContext>(0);
}

tree::TerminalNode* SmplangParser::PrimaryExpressionContext::DOT() {
  return getToken(SmplangParser::DOT, 0);
}

tree::TerminalNode* SmplangParser::PrimaryExpressionContext::LBRACK() {
  return getToken(SmplangParser::LBRACK, 0);
}

tree::TerminalNode* SmplangParser::PrimaryExpressionContext::RBRACK() {
  return getToken(SmplangParser::RBRACK, 0);
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
   return primaryExpression(0);
}

SmplangParser::PrimaryExpressionContext* SmplangParser::primaryExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SmplangParser::PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, parentState);
  SmplangParser::PrimaryExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, SmplangParser::RulePrimaryExpression, precedence);

    

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
    setState(250);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      setState(239);
      match(SmplangParser::ID);
      break;
    }

    case 2: {
      setState(240);
      functionCall();
      break;
    }

    case 3: {
      setState(241);
      match(SmplangParser::INT);
      break;
    }

    case 4: {
      setState(242);
      match(SmplangParser::DOUBLE);
      break;
    }

    case 5: {
      setState(243);
      match(SmplangParser::CHAR);
      break;
    }

    case 6: {
      setState(244);
      match(SmplangParser::BOOL);
      break;
    }

    case 7: {
      setState(245);
      match(SmplangParser::LPAREN);
      setState(246);
      expression(0);
      setState(247);
      match(SmplangParser::RPAREN);
      break;
    }

    case 8: {
      setState(249);
      arrayInit();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(262);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(260);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PrimaryExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePrimaryExpression);
          setState(252);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(253);
          match(SmplangParser::DOT);
          setState(254);
          match(SmplangParser::ID);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PrimaryExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePrimaryExpression);
          setState(255);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(256);
          match(SmplangParser::LBRACK);
          setState(257);
          expression(0);
          setState(258);
          match(SmplangParser::RBRACK);
          break;
        }

        default:
          break;
        } 
      }
      setState(264);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
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
    setState(265);
    match(SmplangParser::LBRACE);
    setState(274);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722037760) != 0)) {
      setState(266);
      expression(0);
      setState(271);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SmplangParser::COMMA) {
        setState(267);
        match(SmplangParser::COMMA);
        setState(268);
        expression(0);
        setState(273);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(276);
    match(SmplangParser::RBRACE);
   
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
  enterRule(_localctx, 46, SmplangParser::RuleArgumentList);
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
    setState(278);
    expression(0);
    setState(283);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SmplangParser::COMMA) {
      setState(279);
      match(SmplangParser::COMMA);
      setState(280);
      expression(0);
      setState(285);
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
  enterRule(_localctx, 48, SmplangParser::RuleFunctionCall);
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
    setState(286);
    match(SmplangParser::ID);
    setState(287);
    match(SmplangParser::LPAREN);
    setState(289);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2722037760) != 0)) {
      setState(288);
      argumentList();
    }
    setState(291);
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

SmplangParser::AssignablePrefixContext* SmplangParser::AssignableContext::assignablePrefix() {
  return getRuleContext<SmplangParser::AssignablePrefixContext>(0);
}

tree::TerminalNode* SmplangParser::AssignableContext::DOT() {
  return getToken(SmplangParser::DOT, 0);
}

tree::TerminalNode* SmplangParser::AssignableContext::LBRACK() {
  return getToken(SmplangParser::LBRACK, 0);
}

SmplangParser::ExpressionContext* SmplangParser::AssignableContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}

tree::TerminalNode* SmplangParser::AssignableContext::RBRACK() {
  return getToken(SmplangParser::RBRACK, 0);
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
  enterRule(_localctx, 50, SmplangParser::RuleAssignable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(303);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(293);
      match(SmplangParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(294);
      assignablePrefix(0);
      setState(301);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SmplangParser::DOT: {
          setState(295);
          match(SmplangParser::DOT);
          setState(296);
          match(SmplangParser::ID);
          break;
        }

        case SmplangParser::LBRACK: {
          setState(297);
          match(SmplangParser::LBRACK);
          setState(298);
          expression(0);
          setState(299);
          match(SmplangParser::RBRACK);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
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

//----------------- AssignablePrefixContext ------------------------------------------------------------------

SmplangParser::AssignablePrefixContext::AssignablePrefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::AssignablePrefixContext::ID() {
  return getToken(SmplangParser::ID, 0);
}

SmplangParser::AssignablePrefixContext* SmplangParser::AssignablePrefixContext::assignablePrefix() {
  return getRuleContext<SmplangParser::AssignablePrefixContext>(0);
}

tree::TerminalNode* SmplangParser::AssignablePrefixContext::DOT() {
  return getToken(SmplangParser::DOT, 0);
}

tree::TerminalNode* SmplangParser::AssignablePrefixContext::LBRACK() {
  return getToken(SmplangParser::LBRACK, 0);
}

SmplangParser::ExpressionContext* SmplangParser::AssignablePrefixContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}

tree::TerminalNode* SmplangParser::AssignablePrefixContext::RBRACK() {
  return getToken(SmplangParser::RBRACK, 0);
}


size_t SmplangParser::AssignablePrefixContext::getRuleIndex() const {
  return SmplangParser::RuleAssignablePrefix;
}

void SmplangParser::AssignablePrefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignablePrefix(this);
}

void SmplangParser::AssignablePrefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignablePrefix(this);
}


std::any SmplangParser::AssignablePrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitAssignablePrefix(this);
  else
    return visitor->visitChildren(this);
}


SmplangParser::AssignablePrefixContext* SmplangParser::assignablePrefix() {
   return assignablePrefix(0);
}

SmplangParser::AssignablePrefixContext* SmplangParser::assignablePrefix(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SmplangParser::AssignablePrefixContext *_localctx = _tracker.createInstance<AssignablePrefixContext>(_ctx, parentState);
  SmplangParser::AssignablePrefixContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, SmplangParser::RuleAssignablePrefix, precedence);

    

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
    setState(306);
    match(SmplangParser::ID);
    _ctx->stop = _input->LT(-1);
    setState(318);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(316);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<AssignablePrefixContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAssignablePrefix);
          setState(308);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(309);
          match(SmplangParser::DOT);
          setState(310);
          match(SmplangParser::ID);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<AssignablePrefixContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAssignablePrefix);
          setState(311);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(312);
          match(SmplangParser::LBRACK);
          setState(313);
          expression(0);
          setState(314);
          match(SmplangParser::RBRACK);
          break;
        }

        default:
          break;
        } 
      }
      setState(320);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
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
    case 21: return primaryExpressionSempred(antlrcpp::downCast<PrimaryExpressionContext *>(context), predicateIndex);
    case 26: return assignablePrefixSempred(antlrcpp::downCast<AssignablePrefixContext *>(context), predicateIndex);

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
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool SmplangParser::primaryExpressionSempred(PrimaryExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 9);
    case 7: return precpred(_ctx, 8);

  default:
    break;
  }
  return true;
}

bool SmplangParser::assignablePrefixSempred(AssignablePrefixContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 2);
    case 9: return precpred(_ctx, 1);

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
