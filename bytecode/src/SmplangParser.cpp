
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
      "program", "function", "returnType", "parameterList", "parameter", 
      "structDecl", "fieldDecl", "type", "primitiveType", "structType", 
      "block", "statement", "varDecl", "assignment", "ifStatement", "whileStatement", 
      "forStatement", "returnStatement", "printStatement", "expression", 
      "primaryExpression", "arrayInit", "structInit", "argumentList", "fieldAccess", 
      "arrayAccess", "functionCall", "assignable"
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
  	4,1,34,294,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,1,0,1,
  	0,1,0,5,0,60,8,0,10,0,12,0,63,9,0,1,1,1,1,1,1,1,1,1,1,3,1,70,8,1,1,1,
  	1,1,1,1,1,2,1,2,3,2,77,8,2,1,3,1,3,1,3,5,3,82,8,3,10,3,12,3,85,9,3,1,
  	4,1,4,1,4,1,5,1,5,1,5,1,5,4,5,94,8,5,11,5,12,5,95,1,5,1,5,1,5,1,6,1,6,
  	1,6,1,6,1,7,1,7,1,7,3,7,108,8,7,1,7,1,7,1,7,1,7,5,7,114,8,7,10,7,12,7,
  	117,9,7,1,8,1,8,1,9,1,9,1,10,1,10,5,10,125,8,10,10,10,12,10,128,9,10,
  	1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,151,8,11,1,12,1,12,1,12,1,12,
  	3,12,157,8,12,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	3,14,170,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,
  	1,16,1,16,1,16,1,16,1,16,1,17,1,17,3,17,190,8,17,1,18,1,18,1,18,1,18,
  	1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,205,8,19,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,5,19,221,
  	8,19,10,19,12,19,224,9,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,3,20,240,8,20,1,21,1,21,1,21,1,21,5,21,246,8,
  	21,10,21,12,21,249,9,21,3,21,251,8,21,1,21,1,21,1,22,1,22,1,22,3,22,258,
  	8,22,1,22,1,22,1,23,1,23,1,23,5,23,265,8,23,10,23,12,23,268,9,23,1,24,
  	1,24,1,24,4,24,273,8,24,11,24,12,24,274,1,25,1,25,1,25,1,25,1,25,1,26,
  	1,26,1,26,3,26,285,8,26,1,26,1,26,1,27,1,27,1,27,3,27,292,8,27,1,27,0,
  	2,14,38,28,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,
  	42,44,46,48,50,52,54,0,1,1,0,1,4,310,0,61,1,0,0,0,2,64,1,0,0,0,4,76,1,
  	0,0,0,6,78,1,0,0,0,8,86,1,0,0,0,10,89,1,0,0,0,12,100,1,0,0,0,14,107,1,
  	0,0,0,16,118,1,0,0,0,18,120,1,0,0,0,20,122,1,0,0,0,22,150,1,0,0,0,24,
  	152,1,0,0,0,26,158,1,0,0,0,28,162,1,0,0,0,30,171,1,0,0,0,32,177,1,0,0,
  	0,34,187,1,0,0,0,36,191,1,0,0,0,38,204,1,0,0,0,40,239,1,0,0,0,42,241,
  	1,0,0,0,44,254,1,0,0,0,46,261,1,0,0,0,48,269,1,0,0,0,50,276,1,0,0,0,52,
  	281,1,0,0,0,54,291,1,0,0,0,56,60,3,2,1,0,57,60,3,10,5,0,58,60,3,22,11,
  	0,59,56,1,0,0,0,59,57,1,0,0,0,59,58,1,0,0,0,60,63,1,0,0,0,61,59,1,0,0,
  	0,61,62,1,0,0,0,62,1,1,0,0,0,63,61,1,0,0,0,64,65,5,5,0,0,65,66,3,4,2,
  	0,66,67,5,18,0,0,67,69,5,24,0,0,68,70,3,6,3,0,69,68,1,0,0,0,69,70,1,0,
  	0,0,70,71,1,0,0,0,71,72,5,25,0,0,72,73,3,20,10,0,73,3,1,0,0,0,74,77,3,
  	14,7,0,75,77,5,6,0,0,76,74,1,0,0,0,76,75,1,0,0,0,77,5,1,0,0,0,78,83,3,
  	8,4,0,79,80,5,31,0,0,80,82,3,8,4,0,81,79,1,0,0,0,82,85,1,0,0,0,83,81,
  	1,0,0,0,83,84,1,0,0,0,84,7,1,0,0,0,85,83,1,0,0,0,86,87,3,14,7,0,87,88,
  	5,18,0,0,88,9,1,0,0,0,89,90,5,13,0,0,90,91,3,18,9,0,91,93,5,26,0,0,92,
  	94,3,12,6,0,93,92,1,0,0,0,94,95,1,0,0,0,95,93,1,0,0,0,95,96,1,0,0,0,96,
  	97,1,0,0,0,97,98,5,27,0,0,98,99,5,30,0,0,99,11,1,0,0,0,100,101,3,14,7,
  	0,101,102,5,18,0,0,102,103,5,30,0,0,103,13,1,0,0,0,104,105,6,7,-1,0,105,
  	108,3,16,8,0,106,108,3,18,9,0,107,104,1,0,0,0,107,106,1,0,0,0,108,115,
  	1,0,0,0,109,110,10,2,0,0,110,111,5,28,0,0,111,112,5,15,0,0,112,114,5,
  	29,0,0,113,109,1,0,0,0,114,117,1,0,0,0,115,113,1,0,0,0,115,116,1,0,0,
  	0,116,15,1,0,0,0,117,115,1,0,0,0,118,119,7,0,0,0,119,17,1,0,0,0,120,121,
  	5,18,0,0,121,19,1,0,0,0,122,126,5,26,0,0,123,125,3,22,11,0,124,123,1,
  	0,0,0,125,128,1,0,0,0,126,124,1,0,0,0,126,127,1,0,0,0,127,129,1,0,0,0,
  	128,126,1,0,0,0,129,130,5,27,0,0,130,21,1,0,0,0,131,132,3,24,12,0,132,
  	133,5,30,0,0,133,151,1,0,0,0,134,135,3,26,13,0,135,136,5,30,0,0,136,151,
  	1,0,0,0,137,138,3,34,17,0,138,139,5,30,0,0,139,151,1,0,0,0,140,141,3,
  	36,18,0,141,142,5,30,0,0,142,151,1,0,0,0,143,144,3,38,19,0,144,145,5,
  	30,0,0,145,151,1,0,0,0,146,151,3,28,14,0,147,151,3,30,15,0,148,151,3,
  	32,16,0,149,151,3,20,10,0,150,131,1,0,0,0,150,134,1,0,0,0,150,137,1,0,
  	0,0,150,140,1,0,0,0,150,143,1,0,0,0,150,146,1,0,0,0,150,147,1,0,0,0,150,
  	148,1,0,0,0,150,149,1,0,0,0,151,23,1,0,0,0,152,153,3,14,7,0,153,156,5,
  	18,0,0,154,155,5,23,0,0,155,157,3,38,19,0,156,154,1,0,0,0,156,157,1,0,
  	0,0,157,25,1,0,0,0,158,159,3,54,27,0,159,160,5,23,0,0,160,161,3,38,19,
  	0,161,27,1,0,0,0,162,163,5,11,0,0,163,164,5,24,0,0,164,165,3,38,19,0,
  	165,166,5,25,0,0,166,169,3,22,11,0,167,168,5,12,0,0,168,170,3,22,11,0,
  	169,167,1,0,0,0,169,170,1,0,0,0,170,29,1,0,0,0,171,172,5,10,0,0,172,173,
  	5,24,0,0,173,174,3,38,19,0,174,175,5,25,0,0,175,176,3,22,11,0,176,31,
  	1,0,0,0,177,178,5,9,0,0,178,179,5,24,0,0,179,180,3,24,12,0,180,181,5,
  	30,0,0,181,182,3,38,19,0,182,183,5,30,0,0,183,184,3,26,13,0,184,185,5,
  	25,0,0,185,186,3,22,11,0,186,33,1,0,0,0,187,189,5,7,0,0,188,190,3,38,
  	19,0,189,188,1,0,0,0,189,190,1,0,0,0,190,35,1,0,0,0,191,192,5,8,0,0,192,
  	193,5,24,0,0,193,194,3,38,19,0,194,195,5,25,0,0,195,37,1,0,0,0,196,197,
  	6,19,-1,0,197,205,3,40,20,0,198,199,5,24,0,0,199,200,3,38,19,0,200,201,
  	5,25,0,0,201,205,1,0,0,0,202,203,5,20,0,0,203,205,3,38,19,4,204,196,1,
  	0,0,0,204,198,1,0,0,0,204,202,1,0,0,0,205,222,1,0,0,0,206,207,10,3,0,
  	0,207,208,5,19,0,0,208,221,3,38,19,4,209,210,10,2,0,0,210,211,5,21,0,
  	0,211,221,3,38,19,3,212,213,10,1,0,0,213,214,5,22,0,0,214,221,3,38,19,
  	2,215,216,10,5,0,0,216,217,5,28,0,0,217,218,3,38,19,0,218,219,5,29,0,
  	0,219,221,1,0,0,0,220,206,1,0,0,0,220,209,1,0,0,0,220,212,1,0,0,0,220,
  	215,1,0,0,0,221,224,1,0,0,0,222,220,1,0,0,0,222,223,1,0,0,0,223,39,1,
  	0,0,0,224,222,1,0,0,0,225,240,5,18,0,0,226,240,3,48,24,0,227,240,3,50,
  	25,0,228,240,3,52,26,0,229,240,5,15,0,0,230,240,5,16,0,0,231,240,5,17,
  	0,0,232,240,5,14,0,0,233,234,5,24,0,0,234,235,3,38,19,0,235,236,5,25,
  	0,0,236,240,1,0,0,0,237,240,3,42,21,0,238,240,3,44,22,0,239,225,1,0,0,
  	0,239,226,1,0,0,0,239,227,1,0,0,0,239,228,1,0,0,0,239,229,1,0,0,0,239,
  	230,1,0,0,0,239,231,1,0,0,0,239,232,1,0,0,0,239,233,1,0,0,0,239,237,1,
  	0,0,0,239,238,1,0,0,0,240,41,1,0,0,0,241,250,5,26,0,0,242,247,3,38,19,
  	0,243,244,5,31,0,0,244,246,3,38,19,0,245,243,1,0,0,0,246,249,1,0,0,0,
  	247,245,1,0,0,0,247,248,1,0,0,0,248,251,1,0,0,0,249,247,1,0,0,0,250,242,
  	1,0,0,0,250,251,1,0,0,0,251,252,1,0,0,0,252,253,5,27,0,0,253,43,1,0,0,
  	0,254,255,5,18,0,0,255,257,5,24,0,0,256,258,3,46,23,0,257,256,1,0,0,0,
  	257,258,1,0,0,0,258,259,1,0,0,0,259,260,5,25,0,0,260,45,1,0,0,0,261,266,
  	3,38,19,0,262,263,5,31,0,0,263,265,3,38,19,0,264,262,1,0,0,0,265,268,
  	1,0,0,0,266,264,1,0,0,0,266,267,1,0,0,0,267,47,1,0,0,0,268,266,1,0,0,
  	0,269,272,5,18,0,0,270,271,5,32,0,0,271,273,5,18,0,0,272,270,1,0,0,0,
  	273,274,1,0,0,0,274,272,1,0,0,0,274,275,1,0,0,0,275,49,1,0,0,0,276,277,
  	5,18,0,0,277,278,5,28,0,0,278,279,3,38,19,0,279,280,5,29,0,0,280,51,1,
  	0,0,0,281,282,5,18,0,0,282,284,5,24,0,0,283,285,3,46,23,0,284,283,1,0,
  	0,0,284,285,1,0,0,0,285,286,1,0,0,0,286,287,5,25,0,0,287,53,1,0,0,0,288,
  	292,5,18,0,0,289,292,3,48,24,0,290,292,3,50,25,0,291,288,1,0,0,0,291,
  	289,1,0,0,0,291,290,1,0,0,0,292,55,1,0,0,0,24,59,61,69,76,83,95,107,115,
  	126,150,156,169,189,204,220,222,239,247,250,257,266,274,284,291
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

std::vector<SmplangParser::FunctionContext *> SmplangParser::ProgramContext::function() {
  return getRuleContexts<SmplangParser::FunctionContext>();
}

SmplangParser::FunctionContext* SmplangParser::ProgramContext::function(size_t i) {
  return getRuleContext<SmplangParser::FunctionContext>(i);
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
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 85454782) != 0)) {
      setState(59);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SmplangParser::FUNC: {
          setState(56);
          function();
          break;
        }

        case SmplangParser::STRUCT: {
          setState(57);
          structDecl();
          break;
        }

        case SmplangParser::T__0:
        case SmplangParser::T__1:
        case SmplangParser::T__2:
        case SmplangParser::T__3:
        case SmplangParser::RETURN:
        case SmplangParser::PRINT:
        case SmplangParser::FOR:
        case SmplangParser::WHILE:
        case SmplangParser::IF:
        case SmplangParser::BOOL:
        case SmplangParser::INT:
        case SmplangParser::DOUBLE:
        case SmplangParser::CHAR:
        case SmplangParser::ID:
        case SmplangParser::UNAROP:
        case SmplangParser::LPAREN:
        case SmplangParser::LBRACE: {
          setState(58);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(63);
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

//----------------- FunctionContext ------------------------------------------------------------------

SmplangParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::FunctionContext::FUNC() {
  return getToken(SmplangParser::FUNC, 0);
}

SmplangParser::ReturnTypeContext* SmplangParser::FunctionContext::returnType() {
  return getRuleContext<SmplangParser::ReturnTypeContext>(0);
}

tree::TerminalNode* SmplangParser::FunctionContext::ID() {
  return getToken(SmplangParser::ID, 0);
}

tree::TerminalNode* SmplangParser::FunctionContext::LPAREN() {
  return getToken(SmplangParser::LPAREN, 0);
}

tree::TerminalNode* SmplangParser::FunctionContext::RPAREN() {
  return getToken(SmplangParser::RPAREN, 0);
}

SmplangParser::BlockContext* SmplangParser::FunctionContext::block() {
  return getRuleContext<SmplangParser::BlockContext>(0);
}

SmplangParser::ParameterListContext* SmplangParser::FunctionContext::parameterList() {
  return getRuleContext<SmplangParser::ParameterListContext>(0);
}


size_t SmplangParser::FunctionContext::getRuleIndex() const {
  return SmplangParser::RuleFunction;
}

void SmplangParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void SmplangParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}


std::any SmplangParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::FunctionContext* SmplangParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, SmplangParser::RuleFunction);
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
    setState(64);
    match(SmplangParser::FUNC);
    setState(65);
    returnType();
    setState(66);
    match(SmplangParser::ID);
    setState(67);
    match(SmplangParser::LPAREN);
    setState(69);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 262174) != 0)) {
      setState(68);
      parameterList();
    }
    setState(71);
    match(SmplangParser::RPAREN);
    setState(72);
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
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SmplangParser::T__0:
      case SmplangParser::T__1:
      case SmplangParser::T__2:
      case SmplangParser::T__3:
      case SmplangParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(74);
        type(0);
        break;
      }

      case SmplangParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(75);
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
    setState(78);
    parameter();
    setState(83);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SmplangParser::COMMA) {
      setState(79);
      match(SmplangParser::COMMA);
      setState(80);
      parameter();
      setState(85);
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
    setState(86);
    type(0);
    setState(87);
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
    setState(89);
    match(SmplangParser::STRUCT);
    setState(90);
    structType();
    setState(91);
    match(SmplangParser::LBRACE);
    setState(93); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(92);
      fieldDecl();
      setState(95); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 262174) != 0));
    setState(97);
    match(SmplangParser::RBRACE);
    setState(98);
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
    setState(100);
    type(0);
    setState(101);
    match(SmplangParser::ID);
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
    setState(107);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SmplangParser::T__0:
      case SmplangParser::T__1:
      case SmplangParser::T__2:
      case SmplangParser::T__3: {
        setState(105);
        primitiveType();
        break;
      }

      case SmplangParser::ID: {
        setState(106);
        structType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(115);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleType);
        setState(109);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(110);
        match(SmplangParser::LBRACK);
        setState(111);
        match(SmplangParser::INT);
        setState(112);
        match(SmplangParser::RBRACK); 
      }
      setState(117);
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
    setState(118);
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
    setState(120);
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
    setState(122);
    match(SmplangParser::LBRACE);
    setState(126);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 85446558) != 0)) {
      setState(123);
      statement();
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(129);
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

SmplangParser::ForStatementContext* SmplangParser::StatementContext::forStatement() {
  return getRuleContext<SmplangParser::ForStatementContext>(0);
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
    setState(150);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(131);
      varDecl();
      setState(132);
      match(SmplangParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(134);
      assignment();
      setState(135);
      match(SmplangParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(137);
      returnStatement();
      setState(138);
      match(SmplangParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(140);
      printStatement();
      setState(141);
      match(SmplangParser::SEMI);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(143);
      expression(0);
      setState(144);
      match(SmplangParser::SEMI);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(146);
      ifStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(147);
      whileStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(148);
      forStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(149);
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
    setState(152);
    type(0);
    setState(153);
    match(SmplangParser::ID);
    setState(156);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SmplangParser::ASSIGN) {
      setState(154);
      match(SmplangParser::ASSIGN);
      setState(155);
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
    setState(158);
    assignable();
    setState(159);
    match(SmplangParser::ASSIGN);
    setState(160);
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
    setState(162);
    match(SmplangParser::IF);
    setState(163);
    match(SmplangParser::LPAREN);
    setState(164);
    expression(0);
    setState(165);
    match(SmplangParser::RPAREN);
    setState(166);
    statement();
    setState(169);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(167);
      match(SmplangParser::ELSE);
      setState(168);
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
    setState(171);
    match(SmplangParser::WHILE);
    setState(172);
    match(SmplangParser::LPAREN);
    setState(173);
    expression(0);
    setState(174);
    match(SmplangParser::RPAREN);
    setState(175);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

SmplangParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SmplangParser::ForStatementContext::FOR() {
  return getToken(SmplangParser::FOR, 0);
}

tree::TerminalNode* SmplangParser::ForStatementContext::LPAREN() {
  return getToken(SmplangParser::LPAREN, 0);
}

SmplangParser::VarDeclContext* SmplangParser::ForStatementContext::varDecl() {
  return getRuleContext<SmplangParser::VarDeclContext>(0);
}

std::vector<tree::TerminalNode *> SmplangParser::ForStatementContext::SEMI() {
  return getTokens(SmplangParser::SEMI);
}

tree::TerminalNode* SmplangParser::ForStatementContext::SEMI(size_t i) {
  return getToken(SmplangParser::SEMI, i);
}

SmplangParser::ExpressionContext* SmplangParser::ForStatementContext::expression() {
  return getRuleContext<SmplangParser::ExpressionContext>(0);
}

SmplangParser::AssignmentContext* SmplangParser::ForStatementContext::assignment() {
  return getRuleContext<SmplangParser::AssignmentContext>(0);
}

tree::TerminalNode* SmplangParser::ForStatementContext::RPAREN() {
  return getToken(SmplangParser::RPAREN, 0);
}

SmplangParser::StatementContext* SmplangParser::ForStatementContext::statement() {
  return getRuleContext<SmplangParser::StatementContext>(0);
}


size_t SmplangParser::ForStatementContext::getRuleIndex() const {
  return SmplangParser::RuleForStatement;
}

void SmplangParser::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}

void SmplangParser::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SmplangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}


std::any SmplangParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SmplangVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

SmplangParser::ForStatementContext* SmplangParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, SmplangParser::RuleForStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(SmplangParser::FOR);
    setState(178);
    match(SmplangParser::LPAREN);
    setState(179);
    varDecl();
    setState(180);
    match(SmplangParser::SEMI);
    setState(181);
    expression(0);
    setState(182);
    match(SmplangParser::SEMI);
    setState(183);
    assignment();
    setState(184);
    match(SmplangParser::RPAREN);
    setState(185);
    statement();
   
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
  enterRule(_localctx, 34, SmplangParser::RuleReturnStatement);
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
    setState(187);
    match(SmplangParser::RETURN);
    setState(189);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 85442560) != 0)) {
      setState(188);
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
  enterRule(_localctx, 36, SmplangParser::RulePrintStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    match(SmplangParser::PRINT);
    setState(192);
    match(SmplangParser::LPAREN);
    setState(193);
    expression(0);
    setState(194);
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

SmplangParser::PrimaryExpressionContext* SmplangParser::ExpressionContext::primaryExpression() {
  return getRuleContext<SmplangParser::PrimaryExpressionContext>(0);
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

tree::TerminalNode* SmplangParser::ExpressionContext::UNAROP() {
  return getToken(SmplangParser::UNAROP, 0);
}

tree::TerminalNode* SmplangParser::ExpressionContext::BINOP() {
  return getToken(SmplangParser::BINOP, 0);
}

tree::TerminalNode* SmplangParser::ExpressionContext::COMPOP() {
  return getToken(SmplangParser::COMPOP, 0);
}

tree::TerminalNode* SmplangParser::ExpressionContext::LOGICOP() {
  return getToken(SmplangParser::LOGICOP, 0);
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
    setState(204);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(197);
      primaryExpression();
      break;
    }

    case 2: {
      setState(198);
      match(SmplangParser::LPAREN);
      setState(199);
      expression(0);
      setState(200);
      match(SmplangParser::RPAREN);
      break;
    }

    case 3: {
      setState(202);
      match(SmplangParser::UNAROP);
      setState(203);
      expression(4);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(222);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(220);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(206);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(207);
          match(SmplangParser::BINOP);
          setState(208);
          expression(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(209);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(210);
          match(SmplangParser::COMPOP);
          setState(211);
          expression(3);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(212);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(213);
          match(SmplangParser::LOGICOP);
          setState(214);
          expression(2);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(215);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(216);
          match(SmplangParser::LBRACK);
          setState(217);
          expression(0);
          setState(218);
          match(SmplangParser::RBRACK);
          break;
        }

        default:
          break;
        } 
      }
      setState(224);
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
  enterRule(_localctx, 40, SmplangParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(225);
      match(SmplangParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(226);
      fieldAccess();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(227);
      arrayAccess();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(228);
      functionCall();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(229);
      match(SmplangParser::INT);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(230);
      match(SmplangParser::DOUBLE);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(231);
      match(SmplangParser::CHAR);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(232);
      match(SmplangParser::BOOL);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(233);
      match(SmplangParser::LPAREN);
      setState(234);
      expression(0);
      setState(235);
      match(SmplangParser::RPAREN);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(237);
      arrayInit();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(238);
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
    setState(241);
    match(SmplangParser::LBRACE);
    setState(250);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 85442560) != 0)) {
      setState(242);
      expression(0);
      setState(247);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SmplangParser::COMMA) {
        setState(243);
        match(SmplangParser::COMMA);
        setState(244);
        expression(0);
        setState(249);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(252);
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
    setState(254);
    match(SmplangParser::ID);
    setState(255);
    match(SmplangParser::LPAREN);
    setState(257);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 85442560) != 0)) {
      setState(256);
      argumentList();
    }
    setState(259);
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
    setState(261);
    expression(0);
    setState(266);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SmplangParser::COMMA) {
      setState(262);
      match(SmplangParser::COMMA);
      setState(263);
      expression(0);
      setState(268);
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
    setState(269);
    match(SmplangParser::ID);
    setState(272); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(270);
              match(SmplangParser::DOT);
              setState(271);
              match(SmplangParser::ID);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(274); 
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
    setState(276);
    match(SmplangParser::ID);
    setState(277);
    match(SmplangParser::LBRACK);
    setState(278);
    expression(0);
    setState(279);
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
    setState(281);
    match(SmplangParser::ID);
    setState(282);
    match(SmplangParser::LPAREN);
    setState(284);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 85442560) != 0)) {
      setState(283);
      argumentList();
    }
    setState(286);
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
  enterRule(_localctx, 54, SmplangParser::RuleAssignable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(291);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(288);
      match(SmplangParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(289);
      fieldAccess();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(290);
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
    case 1: return precpred(_ctx, 3);
    case 2: return precpred(_ctx, 2);
    case 3: return precpred(_ctx, 1);
    case 4: return precpred(_ctx, 5);

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
