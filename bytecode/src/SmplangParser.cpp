
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
      "block", "statement", "varDecl", "assignment", "ifStatement", "whileStatement", 
      "breakStatement", "continueStatement", "returnStatement", "expression", 
      "primaryExpression", "arrayInit", "structInit", "argumentList", "fieldAccess", 
      "arrayAccess", "functionCall", "printCall", "assignable"
    },
    std::vector<std::string>{
      "", "'int'", "'double'", "'char'", "'bool'", "'func'", "'void'", "'return'", 
      "'for'", "'print'", "'while'", "'if'", "'else'", "'elif'", "'struct'", 
      "'break'", "'continue'", "", "", "", "", "", "'--'", "", "", "", "'!'", 
      "'&&'", "'||'", "'='", "'('", "')'", "'{'", "'}'", "'['", "']'", "'[]'", 
      "';'", "','", "'.'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "FUNC", "VOID", "RETURN", "FOR", "PRINT", "WHILE", 
      "IF", "ELSE", "ELIF", "STRUCT", "BREAK", "CONTINUE", "BOOL", "INT", 
      "DOUBLE", "CHAR", "ID", "NEG", "MULT", "ADD", "COMPOP", "NOT", "AND", 
      "OR", "ASSIGN", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", 
      "RBRACK", "ARRAYTYPE", "SEMI", "COMMA", "DOT", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,41,321,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,1,0,1,0,1,0,5,0,62,8,0,10,0,12,0,65,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,
  	1,3,1,74,8,1,1,1,1,1,1,1,1,2,1,2,3,2,81,8,2,1,3,1,3,1,3,5,3,86,8,3,10,
  	3,12,3,89,9,3,1,4,1,4,1,4,1,5,1,5,1,5,1,5,4,5,98,8,5,11,5,12,5,99,1,5,
  	1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,3,7,112,8,7,1,7,1,7,5,7,116,8,7,10,
  	7,12,7,119,9,7,1,8,1,8,1,9,1,9,1,10,1,10,5,10,127,8,10,10,10,12,10,130,
  	9,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,154,8,11,1,12,1,12,
  	1,12,1,12,3,12,160,8,12,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,
  	1,14,3,14,172,8,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,180,8,14,5,14,182,
  	8,14,10,14,12,14,185,9,14,1,14,1,14,1,14,3,14,190,8,14,3,14,192,8,14,
  	1,15,1,15,1,15,1,15,1,15,1,15,3,15,200,8,15,1,16,1,16,1,17,1,17,1,18,
  	1,18,3,18,208,8,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	3,19,220,8,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,5,19,242,8,19,10,19,12,19,
  	245,9,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,3,20,262,8,20,1,21,1,21,1,21,1,21,5,21,268,8,21,10,21,
  	12,21,271,9,21,3,21,273,8,21,1,21,1,21,1,22,1,22,1,22,3,22,280,8,22,1,
  	22,1,22,1,23,1,23,1,23,5,23,287,8,23,10,23,12,23,290,9,23,1,24,1,24,1,
  	24,4,24,295,8,24,11,24,12,24,296,1,25,1,25,1,25,1,25,1,25,1,26,1,26,1,
  	26,3,26,307,8,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,28,1,28,1,28,3,
  	28,319,8,28,1,28,0,2,14,38,29,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,
  	30,32,34,36,38,40,42,44,46,48,50,52,54,56,0,1,1,0,1,4,344,0,63,1,0,0,
  	0,2,68,1,0,0,0,4,80,1,0,0,0,6,82,1,0,0,0,8,90,1,0,0,0,10,93,1,0,0,0,12,
  	104,1,0,0,0,14,111,1,0,0,0,16,120,1,0,0,0,18,122,1,0,0,0,20,124,1,0,0,
  	0,22,153,1,0,0,0,24,155,1,0,0,0,26,161,1,0,0,0,28,165,1,0,0,0,30,193,
  	1,0,0,0,32,201,1,0,0,0,34,203,1,0,0,0,36,205,1,0,0,0,38,219,1,0,0,0,40,
  	261,1,0,0,0,42,263,1,0,0,0,44,276,1,0,0,0,46,283,1,0,0,0,48,291,1,0,0,
  	0,50,298,1,0,0,0,52,303,1,0,0,0,54,310,1,0,0,0,56,318,1,0,0,0,58,62,3,
  	2,1,0,59,62,3,10,5,0,60,62,3,22,11,0,61,58,1,0,0,0,61,59,1,0,0,0,61,60,
  	1,0,0,0,62,65,1,0,0,0,63,61,1,0,0,0,63,64,1,0,0,0,64,66,1,0,0,0,65,63,
  	1,0,0,0,66,67,5,0,0,1,67,1,1,0,0,0,68,69,5,5,0,0,69,70,3,4,2,0,70,71,
  	5,21,0,0,71,73,5,30,0,0,72,74,3,6,3,0,73,72,1,0,0,0,73,74,1,0,0,0,74,
  	75,1,0,0,0,75,76,5,31,0,0,76,77,3,20,10,0,77,3,1,0,0,0,78,81,3,14,7,0,
  	79,81,5,6,0,0,80,78,1,0,0,0,80,79,1,0,0,0,81,5,1,0,0,0,82,87,3,8,4,0,
  	83,84,5,38,0,0,84,86,3,8,4,0,85,83,1,0,0,0,86,89,1,0,0,0,87,85,1,0,0,
  	0,87,88,1,0,0,0,88,7,1,0,0,0,89,87,1,0,0,0,90,91,3,14,7,0,91,92,5,21,
  	0,0,92,9,1,0,0,0,93,94,5,14,0,0,94,95,3,18,9,0,95,97,5,32,0,0,96,98,3,
  	12,6,0,97,96,1,0,0,0,98,99,1,0,0,0,99,97,1,0,0,0,99,100,1,0,0,0,100,101,
  	1,0,0,0,101,102,5,33,0,0,102,103,5,37,0,0,103,11,1,0,0,0,104,105,3,14,
  	7,0,105,106,5,21,0,0,106,107,5,37,0,0,107,13,1,0,0,0,108,109,6,7,-1,0,
  	109,112,3,16,8,0,110,112,3,18,9,0,111,108,1,0,0,0,111,110,1,0,0,0,112,
  	117,1,0,0,0,113,114,10,2,0,0,114,116,5,36,0,0,115,113,1,0,0,0,116,119,
  	1,0,0,0,117,115,1,0,0,0,117,118,1,0,0,0,118,15,1,0,0,0,119,117,1,0,0,
  	0,120,121,7,0,0,0,121,17,1,0,0,0,122,123,5,21,0,0,123,19,1,0,0,0,124,
  	128,5,32,0,0,125,127,3,22,11,0,126,125,1,0,0,0,127,130,1,0,0,0,128,126,
  	1,0,0,0,128,129,1,0,0,0,129,131,1,0,0,0,130,128,1,0,0,0,131,132,5,33,
  	0,0,132,21,1,0,0,0,133,134,3,24,12,0,134,135,5,37,0,0,135,154,1,0,0,0,
  	136,137,3,26,13,0,137,138,5,37,0,0,138,154,1,0,0,0,139,140,3,36,18,0,
  	140,141,5,37,0,0,141,154,1,0,0,0,142,143,3,38,19,0,143,144,5,37,0,0,144,
  	154,1,0,0,0,145,154,3,28,14,0,146,154,3,30,15,0,147,148,3,32,16,0,148,
  	149,5,37,0,0,149,154,1,0,0,0,150,151,3,34,17,0,151,152,5,37,0,0,152,154,
  	1,0,0,0,153,133,1,0,0,0,153,136,1,0,0,0,153,139,1,0,0,0,153,142,1,0,0,
  	0,153,145,1,0,0,0,153,146,1,0,0,0,153,147,1,0,0,0,153,150,1,0,0,0,154,
  	23,1,0,0,0,155,156,3,14,7,0,156,159,5,21,0,0,157,158,5,29,0,0,158,160,
  	3,38,19,0,159,157,1,0,0,0,159,160,1,0,0,0,160,25,1,0,0,0,161,162,3,56,
  	28,0,162,163,5,29,0,0,163,164,3,38,19,0,164,27,1,0,0,0,165,166,5,11,0,
  	0,166,167,5,30,0,0,167,168,3,38,19,0,168,171,5,31,0,0,169,172,3,22,11,
  	0,170,172,3,20,10,0,171,169,1,0,0,0,171,170,1,0,0,0,172,183,1,0,0,0,173,
  	174,5,13,0,0,174,175,5,30,0,0,175,176,3,38,19,0,176,179,5,31,0,0,177,
  	180,3,22,11,0,178,180,3,20,10,0,179,177,1,0,0,0,179,178,1,0,0,0,180,182,
  	1,0,0,0,181,173,1,0,0,0,182,185,1,0,0,0,183,181,1,0,0,0,183,184,1,0,0,
  	0,184,191,1,0,0,0,185,183,1,0,0,0,186,189,5,12,0,0,187,190,3,22,11,0,
  	188,190,3,20,10,0,189,187,1,0,0,0,189,188,1,0,0,0,190,192,1,0,0,0,191,
  	186,1,0,0,0,191,192,1,0,0,0,192,29,1,0,0,0,193,194,5,10,0,0,194,195,5,
  	30,0,0,195,196,3,38,19,0,196,199,5,31,0,0,197,200,3,22,11,0,198,200,3,
  	20,10,0,199,197,1,0,0,0,199,198,1,0,0,0,200,31,1,0,0,0,201,202,5,15,0,
  	0,202,33,1,0,0,0,203,204,5,16,0,0,204,35,1,0,0,0,205,207,5,7,0,0,206,
  	208,3,38,19,0,207,206,1,0,0,0,207,208,1,0,0,0,208,37,1,0,0,0,209,210,
  	6,19,-1,0,210,211,5,30,0,0,211,212,3,38,19,0,212,213,5,31,0,0,213,220,
  	1,0,0,0,214,215,5,22,0,0,215,220,3,38,19,9,216,217,5,26,0,0,217,220,3,
  	38,19,8,218,220,3,40,20,0,219,209,1,0,0,0,219,214,1,0,0,0,219,216,1,0,
  	0,0,219,218,1,0,0,0,220,243,1,0,0,0,221,222,10,7,0,0,222,223,5,27,0,0,
  	223,242,3,38,19,8,224,225,10,6,0,0,225,226,5,28,0,0,226,242,3,38,19,7,
  	227,228,10,5,0,0,228,229,5,23,0,0,229,242,3,38,19,6,230,231,10,4,0,0,
  	231,232,5,24,0,0,232,242,3,38,19,5,233,234,10,3,0,0,234,235,5,25,0,0,
  	235,242,3,38,19,4,236,237,10,1,0,0,237,238,5,34,0,0,238,239,3,38,19,0,
  	239,240,5,35,0,0,240,242,1,0,0,0,241,221,1,0,0,0,241,224,1,0,0,0,241,
  	227,1,0,0,0,241,230,1,0,0,0,241,233,1,0,0,0,241,236,1,0,0,0,242,245,1,
  	0,0,0,243,241,1,0,0,0,243,244,1,0,0,0,244,39,1,0,0,0,245,243,1,0,0,0,
  	246,262,5,21,0,0,247,262,3,48,24,0,248,262,3,50,25,0,249,262,3,54,27,
  	0,250,262,3,52,26,0,251,262,5,18,0,0,252,262,5,19,0,0,253,262,5,20,0,
  	0,254,262,5,17,0,0,255,256,5,30,0,0,256,257,3,38,19,0,257,258,5,31,0,
  	0,258,262,1,0,0,0,259,262,3,42,21,0,260,262,3,44,22,0,261,246,1,0,0,0,
  	261,247,1,0,0,0,261,248,1,0,0,0,261,249,1,0,0,0,261,250,1,0,0,0,261,251,
  	1,0,0,0,261,252,1,0,0,0,261,253,1,0,0,0,261,254,1,0,0,0,261,255,1,0,0,
  	0,261,259,1,0,0,0,261,260,1,0,0,0,262,41,1,0,0,0,263,272,5,32,0,0,264,
  	269,3,38,19,0,265,266,5,38,0,0,266,268,3,38,19,0,267,265,1,0,0,0,268,
  	271,1,0,0,0,269,267,1,0,0,0,269,270,1,0,0,0,270,273,1,0,0,0,271,269,1,
  	0,0,0,272,264,1,0,0,0,272,273,1,0,0,0,273,274,1,0,0,0,274,275,5,33,0,
  	0,275,43,1,0,0,0,276,277,5,21,0,0,277,279,5,30,0,0,278,280,3,46,23,0,
  	279,278,1,0,0,0,279,280,1,0,0,0,280,281,1,0,0,0,281,282,5,31,0,0,282,
  	45,1,0,0,0,283,288,3,38,19,0,284,285,5,38,0,0,285,287,3,38,19,0,286,284,
  	1,0,0,0,287,290,1,0,0,0,288,286,1,0,0,0,288,289,1,0,0,0,289,47,1,0,0,
  	0,290,288,1,0,0,0,291,294,5,21,0,0,292,293,5,39,0,0,293,295,5,21,0,0,
  	294,292,1,0,0,0,295,296,1,0,0,0,296,294,1,0,0,0,296,297,1,0,0,0,297,49,
  	1,0,0,0,298,299,5,21,0,0,299,300,5,34,0,0,300,301,3,38,19,0,301,302,5,
  	35,0,0,302,51,1,0,0,0,303,304,5,21,0,0,304,306,5,30,0,0,305,307,3,46,
  	23,0,306,305,1,0,0,0,306,307,1,0,0,0,307,308,1,0,0,0,308,309,5,31,0,0,
  	309,53,1,0,0,0,310,311,5,9,0,0,311,312,5,30,0,0,312,313,3,38,19,0,313,
  	314,5,31,0,0,314,55,1,0,0,0,315,319,5,21,0,0,316,319,3,48,24,0,317,319,
  	3,50,25,0,318,315,1,0,0,0,318,316,1,0,0,0,318,317,1,0,0,0,319,57,1,0,
  	0,0,29,61,63,73,80,87,99,111,117,128,153,159,171,179,183,189,191,199,
  	207,219,241,243,261,269,272,279,288,296,306,318
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
      ((1ULL << _la) & 5444193982) != 0)) {
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
      ((1ULL << _la) & 2097182) != 0)) {
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
      ((1ULL << _la) & 2097182) != 0));
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
    setState(117);
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
        match(SmplangParser::ARRAYTYPE); 
      }
      setState(119);
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
    setState(120);
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
    setState(122);
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
    setState(124);
    match(SmplangParser::LBRACE);
    setState(128);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5444177566) != 0)) {
      setState(125);
      statement();
      setState(130);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(131);
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

SmplangParser::BreakStatementContext* SmplangParser::StatementContext::breakStatement() {
  return getRuleContext<SmplangParser::BreakStatementContext>(0);
}

SmplangParser::ContinueStatementContext* SmplangParser::StatementContext::continueStatement() {
  return getRuleContext<SmplangParser::ContinueStatementContext>(0);
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
    setState(153);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(133);
      varDecl();
      setState(134);
      match(SmplangParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(136);
      assignment();
      setState(137);
      match(SmplangParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(139);
      returnStatement();
      setState(140);
      match(SmplangParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(142);
      expression(0);
      setState(143);
      match(SmplangParser::SEMI);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(145);
      ifStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(146);
      whileStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(147);
      breakStatement();
      setState(148);
      match(SmplangParser::SEMI);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(150);
      continueStatement();
      setState(151);
      match(SmplangParser::SEMI);
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
    setState(155);
    type(0);
    setState(156);
    match(SmplangParser::ID);
    setState(159);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SmplangParser::ASSIGN) {
      setState(157);
      match(SmplangParser::ASSIGN);
      setState(158);
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
    setState(161);
    assignable();
    setState(162);
    match(SmplangParser::ASSIGN);
    setState(163);
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

std::vector<tree::TerminalNode *> SmplangParser::IfStatementContext::LPAREN() {
  return getTokens(SmplangParser::LPAREN);
}

tree::TerminalNode* SmplangParser::IfStatementContext::LPAREN(size_t i) {
  return getToken(SmplangParser::LPAREN, i);
}

std::vector<SmplangParser::ExpressionContext *> SmplangParser::IfStatementContext::expression() {
  return getRuleContexts<SmplangParser::ExpressionContext>();
}

SmplangParser::ExpressionContext* SmplangParser::IfStatementContext::expression(size_t i) {
  return getRuleContext<SmplangParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> SmplangParser::IfStatementContext::RPAREN() {
  return getTokens(SmplangParser::RPAREN);
}

tree::TerminalNode* SmplangParser::IfStatementContext::RPAREN(size_t i) {
  return getToken(SmplangParser::RPAREN, i);
}

std::vector<SmplangParser::StatementContext *> SmplangParser::IfStatementContext::statement() {
  return getRuleContexts<SmplangParser::StatementContext>();
}

SmplangParser::StatementContext* SmplangParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<SmplangParser::StatementContext>(i);
}

std::vector<SmplangParser::BlockContext *> SmplangParser::IfStatementContext::block() {
  return getRuleContexts<SmplangParser::BlockContext>();
}

SmplangParser::BlockContext* SmplangParser::IfStatementContext::block(size_t i) {
  return getRuleContext<SmplangParser::BlockContext>(i);
}

std::vector<tree::TerminalNode *> SmplangParser::IfStatementContext::ELIF() {
  return getTokens(SmplangParser::ELIF);
}

tree::TerminalNode* SmplangParser::IfStatementContext::ELIF(size_t i) {
  return getToken(SmplangParser::ELIF, i);
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
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(165);
    match(SmplangParser::IF);
    setState(166);
    match(SmplangParser::LPAREN);
    setState(167);
    expression(0);
    setState(168);
    match(SmplangParser::RPAREN);
    setState(171);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(169);
      statement();
      break;
    }

    case 2: {
      setState(170);
      block();
      break;
    }

    default:
      break;
    }
    setState(183);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(173);
        match(SmplangParser::ELIF);
        setState(174);
        match(SmplangParser::LPAREN);
        setState(175);
        expression(0);
        setState(176);
        match(SmplangParser::RPAREN);
        setState(179);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
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
      setState(185);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
    setState(191);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(186);
      match(SmplangParser::ELSE);
      setState(189);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
      case 1: {
        setState(187);
        statement();
        break;
      }

      case 2: {
        setState(188);
        block();
        break;
      }

      default:
        break;
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
    setState(193);
    match(SmplangParser::WHILE);
    setState(194);
    match(SmplangParser::LPAREN);
    setState(195);
    expression(0);
    setState(196);
    match(SmplangParser::RPAREN);
    setState(199);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(197);
      statement();
      break;
    }

    case 2: {
      setState(198);
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
    setState(201);
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
    setState(203);
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
    setState(205);
    match(SmplangParser::RETURN);
    setState(207);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5444076032) != 0)) {
      setState(206);
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
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, SmplangParser::RuleExpression, precedence);

    

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
    setState(219);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(210);
      match(SmplangParser::LPAREN);
      setState(211);
      expression(0);
      setState(212);
      match(SmplangParser::RPAREN);
      break;
    }

    case 2: {
      setState(214);
      match(SmplangParser::NEG);
      setState(215);
      expression(9);
      break;
    }

    case 3: {
      setState(216);
      match(SmplangParser::NOT);
      setState(217);
      expression(8);
      break;
    }

    case 4: {
      setState(218);
      primaryExpression();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(243);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(241);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(221);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(222);
          match(SmplangParser::AND);
          setState(223);
          expression(8);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(224);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(225);
          match(SmplangParser::OR);
          setState(226);
          expression(7);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(227);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(228);
          match(SmplangParser::MULT);
          setState(229);
          expression(6);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(230);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(231);
          match(SmplangParser::ADD);
          setState(232);
          expression(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(233);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(234);
          match(SmplangParser::COMPOP);
          setState(235);
          expression(4);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(236);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(237);
          match(SmplangParser::LBRACK);
          setState(238);
          expression(0);
          setState(239);
          match(SmplangParser::RBRACK);
          break;
        }

        default:
          break;
        } 
      }
      setState(245);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
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

SmplangParser::PrintCallContext* SmplangParser::PrimaryExpressionContext::printCall() {
  return getRuleContext<SmplangParser::PrintCallContext>(0);
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
  enterRule(_localctx, 40, SmplangParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(261);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(246);
      match(SmplangParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(247);
      fieldAccess();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(248);
      arrayAccess();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(249);
      printCall();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(250);
      functionCall();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(251);
      match(SmplangParser::INT);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(252);
      match(SmplangParser::DOUBLE);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(253);
      match(SmplangParser::CHAR);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(254);
      match(SmplangParser::BOOL);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(255);
      match(SmplangParser::LPAREN);
      setState(256);
      expression(0);
      setState(257);
      match(SmplangParser::RPAREN);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(259);
      arrayInit();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(260);
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
  enterRule(_localctx, 42, SmplangParser::RuleArrayInit);
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
    setState(263);
    match(SmplangParser::LBRACE);
    setState(272);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5444076032) != 0)) {
      setState(264);
      expression(0);
      setState(269);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SmplangParser::COMMA) {
        setState(265);
        match(SmplangParser::COMMA);
        setState(266);
        expression(0);
        setState(271);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(274);
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
  enterRule(_localctx, 44, SmplangParser::RuleStructInit);
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
    setState(276);
    match(SmplangParser::ID);
    setState(277);
    match(SmplangParser::LPAREN);
    setState(279);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5444076032) != 0)) {
      setState(278);
      argumentList();
    }
    setState(281);
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
    setState(283);
    expression(0);
    setState(288);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SmplangParser::COMMA) {
      setState(284);
      match(SmplangParser::COMMA);
      setState(285);
      expression(0);
      setState(290);
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
  enterRule(_localctx, 48, SmplangParser::RuleFieldAccess);

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
    setState(291);
    match(SmplangParser::ID);
    setState(294); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(292);
              match(SmplangParser::DOT);
              setState(293);
              match(SmplangParser::ID);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(296); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
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
  enterRule(_localctx, 50, SmplangParser::RuleArrayAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(298);
    match(SmplangParser::ID);
    setState(299);
    match(SmplangParser::LBRACK);
    setState(300);
    expression(0);
    setState(301);
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
  enterRule(_localctx, 52, SmplangParser::RuleFunctionCall);
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
    setState(303);
    match(SmplangParser::ID);
    setState(304);
    match(SmplangParser::LPAREN);
    setState(306);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5444076032) != 0)) {
      setState(305);
      argumentList();
    }
    setState(308);
    match(SmplangParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintCallContext ------------------------------------------------------------------

SmplangParser::PrintCallContext::PrintCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::PrintCallContext::PRINT() {
  return getToken(SmplangParser::PRINT, 0);
}

tree::TerminalNode* SmplangParser::PrintCallContext::LPAREN() {
  return getToken(SmplangParser::LPAREN, 0);
}

SmplangParser::ExpressionContext* SmplangParser::PrintCallContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}

tree::TerminalNode* SmplangParser::PrintCallContext::RPAREN() {
  return getToken(SmplangParser::RPAREN, 0);
}


size_t SmplangParser::PrintCallContext::getRuleIndex() const {
  return SmplangParser::RulePrintCall;
}

void SmplangParser::PrintCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintCall(this);
}

void SmplangParser::PrintCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintCall(this);
}


std::any SmplangParser::PrintCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitPrintCall(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::PrintCallContext* SmplangParser::printCall() {
  PrintCallContext *_localctx = _tracker.createInstance<PrintCallContext>(_ctx, getState());
  enterRule(_localctx, 54, SmplangParser::RulePrintCall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    match(SmplangParser::PRINT);
    setState(311);
    match(SmplangParser::LPAREN);
    setState(312);
    expression(0);
    setState(313);
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
    setState(318);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(315);
      match(SmplangParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(316);
      fieldAccess();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(317);
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
    case 19: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

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
