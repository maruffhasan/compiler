
// Generated from CSubset.g4 by ANTLR 4.13.2


#include "CSubsetVisitor.h"

#include "CSubsetParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CSubsetParserStaticData final {
  CSubsetParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CSubsetParserStaticData(const CSubsetParserStaticData&) = delete;
  CSubsetParserStaticData(CSubsetParserStaticData&&) = delete;
  CSubsetParserStaticData& operator=(const CSubsetParserStaticData&) = delete;
  CSubsetParserStaticData& operator=(CSubsetParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag csubsetParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CSubsetParserStaticData> csubsetParserStaticData = nullptr;

void csubsetParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (csubsetParserStaticData != nullptr) {
    return;
  }
#else
  assert(csubsetParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CSubsetParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list", "compound_statement", "var_declaration", "type_specifier", 
      "declaration_list", "statements", "statement", "expression_statement", 
      "variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
      "term", "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'println'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "", "", "'++'", "'--'", "'!'", "", "", 
      "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "ADDOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", 
      "ID", "CONST_INT", "CONST_FLOAT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,32,303,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,55,8,1,10,1,12,1,58,
  	9,1,1,2,1,2,1,2,3,2,63,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,3,3,78,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,3,4,93,8,4,1,5,1,5,1,5,1,5,1,5,3,5,100,8,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,5,5,110,8,5,10,5,12,5,113,9,5,1,6,1,6,1,6,1,6,1,6,1,6,3,6,121,
  	8,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,3,8,130,8,8,1,9,1,9,1,9,1,9,1,9,1,9,3,
  	9,138,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,149,8,9,10,9,12,9,152,
  	9,9,1,10,1,10,1,10,1,10,1,10,5,10,159,8,10,10,10,12,10,162,9,10,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,204,8,11,
  	1,12,1,12,1,12,1,12,3,12,210,8,12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,
  	218,8,13,1,14,1,14,1,14,1,14,1,14,3,14,225,8,14,1,15,1,15,1,15,1,15,1,
  	15,3,15,232,8,15,1,16,1,16,1,16,1,16,1,16,3,16,239,8,16,1,17,1,17,1,17,
  	1,17,1,17,1,17,5,17,247,8,17,10,17,12,17,250,9,17,1,18,1,18,1,18,1,18,
  	1,18,1,18,5,18,258,8,18,10,18,12,18,261,9,18,1,19,1,19,1,19,1,19,1,19,
  	3,19,268,8,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,288,8,20,1,21,1,21,1,22,1,22,
  	1,22,1,22,1,22,1,22,5,22,298,8,22,10,22,12,22,301,9,22,1,22,0,7,2,10,
  	18,20,34,36,44,23,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,
  	38,40,42,44,0,0,318,0,46,1,0,0,0,2,49,1,0,0,0,4,62,1,0,0,0,6,77,1,0,0,
  	0,8,92,1,0,0,0,10,99,1,0,0,0,12,120,1,0,0,0,14,122,1,0,0,0,16,129,1,0,
  	0,0,18,137,1,0,0,0,20,153,1,0,0,0,22,203,1,0,0,0,24,209,1,0,0,0,26,217,
  	1,0,0,0,28,224,1,0,0,0,30,231,1,0,0,0,32,238,1,0,0,0,34,240,1,0,0,0,36,
  	251,1,0,0,0,38,267,1,0,0,0,40,287,1,0,0,0,42,289,1,0,0,0,44,291,1,0,0,
  	0,46,47,3,2,1,0,47,48,5,0,0,1,48,1,1,0,0,0,49,50,6,1,-1,0,50,51,3,4,2,
  	0,51,56,1,0,0,0,52,53,10,2,0,0,53,55,3,4,2,0,54,52,1,0,0,0,55,58,1,0,
  	0,0,56,54,1,0,0,0,56,57,1,0,0,0,57,3,1,0,0,0,58,56,1,0,0,0,59,63,3,14,
  	7,0,60,63,3,6,3,0,61,63,3,8,4,0,62,59,1,0,0,0,62,60,1,0,0,0,62,61,1,0,
  	0,0,63,5,1,0,0,0,64,65,3,16,8,0,65,66,5,30,0,0,66,67,5,14,0,0,67,68,3,
  	10,5,0,68,69,5,15,0,0,69,70,5,20,0,0,70,78,1,0,0,0,71,72,3,16,8,0,72,
  	73,5,30,0,0,73,74,5,14,0,0,74,75,5,15,0,0,75,76,5,20,0,0,76,78,1,0,0,
  	0,77,64,1,0,0,0,77,71,1,0,0,0,78,7,1,0,0,0,79,80,3,16,8,0,80,81,5,30,
  	0,0,81,82,5,14,0,0,82,83,3,10,5,0,83,84,5,15,0,0,84,85,3,12,6,0,85,93,
  	1,0,0,0,86,87,3,16,8,0,87,88,5,30,0,0,88,89,5,14,0,0,89,90,5,15,0,0,90,
  	91,3,12,6,0,91,93,1,0,0,0,92,79,1,0,0,0,92,86,1,0,0,0,93,9,1,0,0,0,94,
  	95,6,5,-1,0,95,96,3,16,8,0,96,97,5,30,0,0,97,100,1,0,0,0,98,100,3,16,
  	8,0,99,94,1,0,0,0,99,98,1,0,0,0,100,111,1,0,0,0,101,102,10,4,0,0,102,
  	103,5,21,0,0,103,104,3,16,8,0,104,105,5,30,0,0,105,110,1,0,0,0,106,107,
  	10,3,0,0,107,108,5,21,0,0,108,110,3,16,8,0,109,101,1,0,0,0,109,106,1,
  	0,0,0,110,113,1,0,0,0,111,109,1,0,0,0,111,112,1,0,0,0,112,11,1,0,0,0,
  	113,111,1,0,0,0,114,115,5,16,0,0,115,116,3,20,10,0,116,117,5,17,0,0,117,
  	121,1,0,0,0,118,119,5,16,0,0,119,121,5,17,0,0,120,114,1,0,0,0,120,118,
  	1,0,0,0,121,13,1,0,0,0,122,123,3,16,8,0,123,124,3,18,9,0,124,125,5,20,
  	0,0,125,15,1,0,0,0,126,130,5,11,0,0,127,130,5,12,0,0,128,130,5,13,0,0,
  	129,126,1,0,0,0,129,127,1,0,0,0,129,128,1,0,0,0,130,17,1,0,0,0,131,132,
  	6,9,-1,0,132,138,5,30,0,0,133,134,5,30,0,0,134,135,5,18,0,0,135,136,5,
  	31,0,0,136,138,5,19,0,0,137,131,1,0,0,0,137,133,1,0,0,0,138,150,1,0,0,
  	0,139,140,10,4,0,0,140,141,5,21,0,0,141,149,5,30,0,0,142,143,10,3,0,0,
  	143,144,5,21,0,0,144,145,5,30,0,0,145,146,5,18,0,0,146,147,5,31,0,0,147,
  	149,5,19,0,0,148,139,1,0,0,0,148,142,1,0,0,0,149,152,1,0,0,0,150,148,
  	1,0,0,0,150,151,1,0,0,0,151,19,1,0,0,0,152,150,1,0,0,0,153,154,6,10,-1,
  	0,154,155,3,22,11,0,155,160,1,0,0,0,156,157,10,1,0,0,157,159,3,22,11,
  	0,158,156,1,0,0,0,159,162,1,0,0,0,160,158,1,0,0,0,160,161,1,0,0,0,161,
  	21,1,0,0,0,162,160,1,0,0,0,163,204,3,14,7,0,164,204,3,24,12,0,165,204,
  	3,12,6,0,166,167,5,7,0,0,167,168,5,14,0,0,168,169,3,24,12,0,169,170,3,
  	24,12,0,170,171,3,28,14,0,171,172,5,15,0,0,172,173,3,22,11,0,173,204,
  	1,0,0,0,174,175,5,5,0,0,175,176,5,14,0,0,176,177,3,28,14,0,177,178,5,
  	15,0,0,178,179,3,22,11,0,179,204,1,0,0,0,180,181,5,5,0,0,181,182,5,14,
  	0,0,182,183,3,28,14,0,183,184,5,15,0,0,184,185,3,22,11,0,185,186,5,6,
  	0,0,186,187,3,22,11,0,187,204,1,0,0,0,188,189,5,8,0,0,189,190,5,14,0,
  	0,190,191,3,28,14,0,191,192,5,15,0,0,192,193,3,22,11,0,193,204,1,0,0,
  	0,194,195,5,9,0,0,195,196,5,14,0,0,196,197,5,30,0,0,197,198,5,15,0,0,
  	198,204,5,20,0,0,199,200,5,10,0,0,200,201,3,28,14,0,201,202,5,20,0,0,
  	202,204,1,0,0,0,203,163,1,0,0,0,203,164,1,0,0,0,203,165,1,0,0,0,203,166,
  	1,0,0,0,203,174,1,0,0,0,203,180,1,0,0,0,203,188,1,0,0,0,203,194,1,0,0,
  	0,203,199,1,0,0,0,204,23,1,0,0,0,205,210,5,20,0,0,206,207,3,28,14,0,207,
  	208,5,20,0,0,208,210,1,0,0,0,209,205,1,0,0,0,209,206,1,0,0,0,210,25,1,
  	0,0,0,211,218,5,30,0,0,212,213,5,30,0,0,213,214,5,18,0,0,214,215,3,28,
  	14,0,215,216,5,19,0,0,216,218,1,0,0,0,217,211,1,0,0,0,217,212,1,0,0,0,
  	218,27,1,0,0,0,219,225,3,30,15,0,220,221,3,26,13,0,221,222,5,29,0,0,222,
  	223,3,30,15,0,223,225,1,0,0,0,224,219,1,0,0,0,224,220,1,0,0,0,225,29,
  	1,0,0,0,226,232,3,32,16,0,227,228,3,32,16,0,228,229,5,28,0,0,229,230,
  	3,32,16,0,230,232,1,0,0,0,231,226,1,0,0,0,231,227,1,0,0,0,232,31,1,0,
  	0,0,233,239,3,34,17,0,234,235,3,34,17,0,235,236,5,27,0,0,236,237,3,34,
  	17,0,237,239,1,0,0,0,238,233,1,0,0,0,238,234,1,0,0,0,239,33,1,0,0,0,240,
  	241,6,17,-1,0,241,242,3,36,18,0,242,248,1,0,0,0,243,244,10,1,0,0,244,
  	245,5,22,0,0,245,247,3,36,18,0,246,243,1,0,0,0,247,250,1,0,0,0,248,246,
  	1,0,0,0,248,249,1,0,0,0,249,35,1,0,0,0,250,248,1,0,0,0,251,252,6,18,-1,
  	0,252,253,3,38,19,0,253,259,1,0,0,0,254,255,10,1,0,0,255,256,5,23,0,0,
  	256,258,3,38,19,0,257,254,1,0,0,0,258,261,1,0,0,0,259,257,1,0,0,0,259,
  	260,1,0,0,0,260,37,1,0,0,0,261,259,1,0,0,0,262,263,5,22,0,0,263,268,3,
  	38,19,0,264,265,5,26,0,0,265,268,3,38,19,0,266,268,3,40,20,0,267,262,
  	1,0,0,0,267,264,1,0,0,0,267,266,1,0,0,0,268,39,1,0,0,0,269,288,3,26,13,
  	0,270,271,5,30,0,0,271,272,5,14,0,0,272,273,3,42,21,0,273,274,5,15,0,
  	0,274,288,1,0,0,0,275,276,5,14,0,0,276,277,3,28,14,0,277,278,5,15,0,0,
  	278,288,1,0,0,0,279,288,5,31,0,0,280,288,5,32,0,0,281,282,3,26,13,0,282,
  	283,5,24,0,0,283,288,1,0,0,0,284,285,3,26,13,0,285,286,5,25,0,0,286,288,
  	1,0,0,0,287,269,1,0,0,0,287,270,1,0,0,0,287,275,1,0,0,0,287,279,1,0,0,
  	0,287,280,1,0,0,0,287,281,1,0,0,0,287,284,1,0,0,0,288,41,1,0,0,0,289,
  	290,3,44,22,0,290,43,1,0,0,0,291,292,6,22,-1,0,292,293,3,30,15,0,293,
  	299,1,0,0,0,294,295,10,2,0,0,295,296,5,21,0,0,296,298,3,30,15,0,297,294,
  	1,0,0,0,298,301,1,0,0,0,299,297,1,0,0,0,299,300,1,0,0,0,300,45,1,0,0,
  	0,301,299,1,0,0,0,24,56,62,77,92,99,109,111,120,129,137,148,150,160,203,
  	209,217,224,231,238,248,259,267,287,299
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  csubsetParserStaticData = std::move(staticData);
}

}

CSubsetParser::CSubsetParser(TokenStream *input) : CSubsetParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CSubsetParser::CSubsetParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CSubsetParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *csubsetParserStaticData->atn, csubsetParserStaticData->decisionToDFA, csubsetParserStaticData->sharedContextCache, options);
}

CSubsetParser::~CSubsetParser() {
  delete _interpreter;
}

const atn::ATN& CSubsetParser::getATN() const {
  return *csubsetParserStaticData->atn;
}

std::string CSubsetParser::getGrammarFileName() const {
  return "CSubset.g4";
}

const std::vector<std::string>& CSubsetParser::getRuleNames() const {
  return csubsetParserStaticData->ruleNames;
}

const dfa::Vocabulary& CSubsetParser::getVocabulary() const {
  return csubsetParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CSubsetParser::getSerializedATN() const {
  return csubsetParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

CSubsetParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::ProgramContext* CSubsetParser::StartContext::program() {
  return getRuleContext<CSubsetParser::ProgramContext>(0);
}

tree::TerminalNode* CSubsetParser::StartContext::EOF() {
  return getToken(CSubsetParser::EOF, 0);
}


size_t CSubsetParser::StartContext::getRuleIndex() const {
  return CSubsetParser::RuleStart;
}


std::any CSubsetParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::StartContext* CSubsetParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, CSubsetParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    program(0);
    setState(47);
    match(CSubsetParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

CSubsetParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::UnitContext* CSubsetParser::ProgramContext::unit() {
  return getRuleContext<CSubsetParser::UnitContext>(0);
}

CSubsetParser::ProgramContext* CSubsetParser::ProgramContext::program() {
  return getRuleContext<CSubsetParser::ProgramContext>(0);
}


size_t CSubsetParser::ProgramContext::getRuleIndex() const {
  return CSubsetParser::RuleProgram;
}


std::any CSubsetParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}


CSubsetParser::ProgramContext* CSubsetParser::program() {
   return program(0);
}

CSubsetParser::ProgramContext* CSubsetParser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  CSubsetParser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, CSubsetParser::RuleProgram, precedence);

    

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
    setState(50);
    unit();
    _ctx->stop = _input->LT(-1);
    setState(56);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(52);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(53);
        unit(); 
      }
      setState(58);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

CSubsetParser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::Var_declarationContext* CSubsetParser::UnitContext::var_declaration() {
  return getRuleContext<CSubsetParser::Var_declarationContext>(0);
}

CSubsetParser::Func_declarationContext* CSubsetParser::UnitContext::func_declaration() {
  return getRuleContext<CSubsetParser::Func_declarationContext>(0);
}

CSubsetParser::Func_definitionContext* CSubsetParser::UnitContext::func_definition() {
  return getRuleContext<CSubsetParser::Func_definitionContext>(0);
}


size_t CSubsetParser::UnitContext::getRuleIndex() const {
  return CSubsetParser::RuleUnit;
}


std::any CSubsetParser::UnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnit(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::UnitContext* CSubsetParser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, CSubsetParser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(62);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(59);
      var_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(60);
      func_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(61);
      func_definition();
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

//----------------- Func_declarationContext ------------------------------------------------------------------

CSubsetParser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Func_declarationContext::getRuleIndex() const {
  return CSubsetParser::RuleFunc_declaration;
}

void CSubsetParser::Func_declarationContext::copyFrom(Func_declarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FuncDeclWithParamsContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::FuncDeclWithParamsContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::FuncDeclWithParamsContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FuncDeclWithParamsContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::FuncDeclWithParamsContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::FuncDeclWithParamsContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::FuncDeclWithParamsContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::FuncDeclWithParamsContext::FuncDeclWithParamsContext(Func_declarationContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FuncDeclWithParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFuncDeclWithParams(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncDeclNoParamsContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::FuncDeclNoParamsContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::FuncDeclNoParamsContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FuncDeclNoParamsContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::FuncDeclNoParamsContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::FuncDeclNoParamsContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::FuncDeclNoParamsContext::FuncDeclNoParamsContext(Func_declarationContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FuncDeclNoParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFuncDeclNoParams(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Func_declarationContext* CSubsetParser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, CSubsetParser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(77);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::FuncDeclWithParamsContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(64);
      type_specifier();
      setState(65);
      match(CSubsetParser::ID);
      setState(66);
      match(CSubsetParser::LPAREN);
      setState(67);
      parameter_list(0);
      setState(68);
      match(CSubsetParser::RPAREN);
      setState(69);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::FuncDeclNoParamsContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(71);
      type_specifier();
      setState(72);
      match(CSubsetParser::ID);
      setState(73);
      match(CSubsetParser::LPAREN);
      setState(74);
      match(CSubsetParser::RPAREN);
      setState(75);
      match(CSubsetParser::SEMICOLON);
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

//----------------- Func_definitionContext ------------------------------------------------------------------

CSubsetParser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Func_definitionContext::getRuleIndex() const {
  return CSubsetParser::RuleFunc_definition;
}

void CSubsetParser::Func_definitionContext::copyFrom(Func_definitionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FuncDefNoParamsContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::FuncDefNoParamsContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::FuncDefNoParamsContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FuncDefNoParamsContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::FuncDefNoParamsContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::Compound_statementContext* CSubsetParser::FuncDefNoParamsContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}

CSubsetParser::FuncDefNoParamsContext::FuncDefNoParamsContext(Func_definitionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FuncDefNoParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFuncDefNoParams(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncDefWithParamsContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::FuncDefWithParamsContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::FuncDefWithParamsContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FuncDefWithParamsContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::FuncDefWithParamsContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::FuncDefWithParamsContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::Compound_statementContext* CSubsetParser::FuncDefWithParamsContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}

CSubsetParser::FuncDefWithParamsContext::FuncDefWithParamsContext(Func_definitionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FuncDefWithParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFuncDefWithParams(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Func_definitionContext* CSubsetParser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, CSubsetParser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::FuncDefWithParamsContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(79);
      type_specifier();
      setState(80);
      match(CSubsetParser::ID);
      setState(81);
      match(CSubsetParser::LPAREN);
      setState(82);
      parameter_list(0);
      setState(83);
      match(CSubsetParser::RPAREN);
      setState(84);
      compound_statement();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::FuncDefNoParamsContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(86);
      type_specifier();
      setState(87);
      match(CSubsetParser::ID);
      setState(88);
      match(CSubsetParser::LPAREN);
      setState(89);
      match(CSubsetParser::RPAREN);
      setState(90);
      compound_statement();
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

//----------------- Parameter_listContext ------------------------------------------------------------------

CSubsetParser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Parameter_listContext::getRuleIndex() const {
  return CSubsetParser::RuleParameter_list;
}

void CSubsetParser::Parameter_listContext::copyFrom(Parameter_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParamListSingleAnonContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::ParamListSingleAnonContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::ParamListSingleAnonContext::ParamListSingleAnonContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParamListSingleAnonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParamListSingleAnon(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParamListMultiAnonContext ------------------------------------------------------------------

CSubsetParser::Parameter_listContext* CSubsetParser::ParamListMultiAnonContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::ParamListMultiAnonContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Type_specifierContext* CSubsetParser::ParamListMultiAnonContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::ParamListMultiAnonContext::ParamListMultiAnonContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParamListMultiAnonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParamListMultiAnon(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParamListSingleNamedContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::ParamListSingleNamedContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::ParamListSingleNamedContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::ParamListSingleNamedContext::ParamListSingleNamedContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParamListSingleNamedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParamListSingleNamed(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParamListMultiNamedContext ------------------------------------------------------------------

CSubsetParser::Parameter_listContext* CSubsetParser::ParamListMultiNamedContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::ParamListMultiNamedContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Type_specifierContext* CSubsetParser::ParamListMultiNamedContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::ParamListMultiNamedContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::ParamListMultiNamedContext::ParamListMultiNamedContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParamListMultiNamedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParamListMultiNamed(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Parameter_listContext* CSubsetParser::parameter_list() {
   return parameter_list(0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  CSubsetParser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, CSubsetParser::RuleParameter_list, precedence);

    

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
    setState(99);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParamListSingleNamedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(95);
      type_specifier();
      setState(96);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParamListSingleAnonContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(98);
      type_specifier();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(111);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(109);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ParamListMultiNamedContext>(_tracker.createInstance<Parameter_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleParameter_list);
          setState(101);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(102);
          match(CSubsetParser::COMMA);
          setState(103);
          type_specifier();
          setState(104);
          match(CSubsetParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ParamListMultiAnonContext>(_tracker.createInstance<Parameter_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleParameter_list);
          setState(106);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(107);
          match(CSubsetParser::COMMA);
          setState(108);
          type_specifier();
          break;
        }

        default:
          break;
        } 
      }
      setState(113);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

CSubsetParser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Compound_statementContext::getRuleIndex() const {
  return CSubsetParser::RuleCompound_statement;
}

void CSubsetParser::Compound_statementContext::copyFrom(Compound_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CompoundStmtEmptyContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::CompoundStmtEmptyContext::LCURL() {
  return getToken(CSubsetParser::LCURL, 0);
}

tree::TerminalNode* CSubsetParser::CompoundStmtEmptyContext::RCURL() {
  return getToken(CSubsetParser::RCURL, 0);
}

CSubsetParser::CompoundStmtEmptyContext::CompoundStmtEmptyContext(Compound_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::CompoundStmtEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitCompoundStmtEmpty(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompoundStmtBodyContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::CompoundStmtBodyContext::LCURL() {
  return getToken(CSubsetParser::LCURL, 0);
}

CSubsetParser::StatementsContext* CSubsetParser::CompoundStmtBodyContext::statements() {
  return getRuleContext<CSubsetParser::StatementsContext>(0);
}

tree::TerminalNode* CSubsetParser::CompoundStmtBodyContext::RCURL() {
  return getToken(CSubsetParser::RCURL, 0);
}

CSubsetParser::CompoundStmtBodyContext::CompoundStmtBodyContext(Compound_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::CompoundStmtBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitCompoundStmtBody(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Compound_statementContext* CSubsetParser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, CSubsetParser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(120);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::CompoundStmtBodyContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(114);
      match(CSubsetParser::LCURL);
      setState(115);
      statements(0);
      setState(116);
      match(CSubsetParser::RCURL);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::CompoundStmtEmptyContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(118);
      match(CSubsetParser::LCURL);
      setState(119);
      match(CSubsetParser::RCURL);
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

//----------------- Var_declarationContext ------------------------------------------------------------------

CSubsetParser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Var_declarationContext::getRuleIndex() const {
  return CSubsetParser::RuleVar_declaration;
}

void CSubsetParser::Var_declarationContext::copyFrom(Var_declarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VarDeclContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::VarDeclContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::VarDeclContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::VarDeclContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::VarDeclContext::VarDeclContext(Var_declarationContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Var_declarationContext* CSubsetParser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, CSubsetParser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<CSubsetParser::VarDeclContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(122);
    type_specifier();
    setState(123);
    declaration_list(0);
    setState(124);
    match(CSubsetParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Type_specifierContext::getRuleIndex() const {
  return CSubsetParser::RuleType_specifier;
}

void CSubsetParser::Type_specifierContext::copyFrom(Type_specifierContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TypeFloatContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::TypeFloatContext::FLOAT() {
  return getToken(CSubsetParser::FLOAT, 0);
}

CSubsetParser::TypeFloatContext::TypeFloatContext(Type_specifierContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::TypeFloatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTypeFloat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeVoidContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::TypeVoidContext::VOID() {
  return getToken(CSubsetParser::VOID, 0);
}

CSubsetParser::TypeVoidContext::TypeVoidContext(Type_specifierContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::TypeVoidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTypeVoid(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeIntContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::TypeIntContext::INT() {
  return getToken(CSubsetParser::INT, 0);
}

CSubsetParser::TypeIntContext::TypeIntContext(Type_specifierContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::TypeIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTypeInt(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Type_specifierContext* CSubsetParser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 16, CSubsetParser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(129);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::INT: {
        _localctx = _tracker.createInstance<CSubsetParser::TypeIntContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(126);
        match(CSubsetParser::INT);
        break;
      }

      case CSubsetParser::FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::TypeFloatContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(127);
        match(CSubsetParser::FLOAT);
        break;
      }

      case CSubsetParser::VOID: {
        _localctx = _tracker.createInstance<CSubsetParser::TypeVoidContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(128);
        match(CSubsetParser::VOID);
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

//----------------- Declaration_listContext ------------------------------------------------------------------

CSubsetParser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Declaration_listContext::getRuleIndex() const {
  return CSubsetParser::RuleDeclaration_list;
}

void CSubsetParser::Declaration_listContext::copyFrom(Declaration_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DeclListCommaArrayContext ------------------------------------------------------------------

CSubsetParser::Declaration_listContext* CSubsetParser::DeclListCommaArrayContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::DeclListCommaArrayContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

tree::TerminalNode* CSubsetParser::DeclListCommaArrayContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::DeclListCommaArrayContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

tree::TerminalNode* CSubsetParser::DeclListCommaArrayContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

tree::TerminalNode* CSubsetParser::DeclListCommaArrayContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::DeclListCommaArrayContext::DeclListCommaArrayContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclListCommaArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclListCommaArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclListSingleIdContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::DeclListSingleIdContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::DeclListSingleIdContext::DeclListSingleIdContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclListSingleIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclListSingleId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclListSingleArrayContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::DeclListSingleArrayContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::DeclListSingleArrayContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

tree::TerminalNode* CSubsetParser::DeclListSingleArrayContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

tree::TerminalNode* CSubsetParser::DeclListSingleArrayContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::DeclListSingleArrayContext::DeclListSingleArrayContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclListSingleArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclListSingleArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclListCommaIdContext ------------------------------------------------------------------

CSubsetParser::Declaration_listContext* CSubsetParser::DeclListCommaIdContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::DeclListCommaIdContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

tree::TerminalNode* CSubsetParser::DeclListCommaIdContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::DeclListCommaIdContext::DeclListCommaIdContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclListCommaIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclListCommaId(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Declaration_listContext* CSubsetParser::declaration_list() {
   return declaration_list(0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  CSubsetParser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, CSubsetParser::RuleDeclaration_list, precedence);

    

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
    setState(137);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<DeclListSingleIdContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(132);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<DeclListSingleArrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(133);
      match(CSubsetParser::ID);
      setState(134);
      match(CSubsetParser::LTHIRD);
      setState(135);
      match(CSubsetParser::CONST_INT);
      setState(136);
      match(CSubsetParser::RTHIRD);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(150);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(148);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<DeclListCommaIdContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(139);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(140);
          match(CSubsetParser::COMMA);
          setState(141);
          match(CSubsetParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DeclListCommaArrayContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(142);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(143);
          match(CSubsetParser::COMMA);
          setState(144);
          match(CSubsetParser::ID);
          setState(145);
          match(CSubsetParser::LTHIRD);
          setState(146);
          match(CSubsetParser::CONST_INT);
          setState(147);
          match(CSubsetParser::RTHIRD);
          break;
        }

        default:
          break;
        } 
      }
      setState(152);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

CSubsetParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::StatementsContext::getRuleIndex() const {
  return CSubsetParser::RuleStatements;
}

void CSubsetParser::StatementsContext::copyFrom(StatementsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StmtSingleContext ------------------------------------------------------------------

CSubsetParser::StatementContext* CSubsetParser::StmtSingleContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StmtSingleContext::StmtSingleContext(StatementsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StmtSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStmtSingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtSeqContext ------------------------------------------------------------------

CSubsetParser::StatementsContext* CSubsetParser::StmtSeqContext::statements() {
  return getRuleContext<CSubsetParser::StatementsContext>(0);
}

CSubsetParser::StatementContext* CSubsetParser::StmtSeqContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StmtSeqContext::StmtSeqContext(StatementsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StmtSeqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStmtSeq(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::StatementsContext* CSubsetParser::statements() {
   return statements(0);
}

CSubsetParser::StatementsContext* CSubsetParser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  CSubsetParser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, CSubsetParser::RuleStatements, precedence);

    

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
    _localctx = _tracker.createInstance<StmtSingleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(154);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(160);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<StmtSeqContext>(_tracker.createInstance<StatementsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleStatements);
        setState(156);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(157);
        statement(); 
      }
      setState(162);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CSubsetParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::StatementContext::getRuleIndex() const {
  return CSubsetParser::RuleStatement;
}

void CSubsetParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StmtReturnContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::StmtReturnContext::RETURN() {
  return getToken(CSubsetParser::RETURN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::StmtReturnContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::StmtReturnContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::StmtReturnContext::StmtReturnContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StmtReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStmtReturn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtCompoundContext ------------------------------------------------------------------

CSubsetParser::Compound_statementContext* CSubsetParser::StmtCompoundContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}

CSubsetParser::StmtCompoundContext::StmtCompoundContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StmtCompoundContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStmtCompound(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtVarDeclContext ------------------------------------------------------------------

CSubsetParser::Var_declarationContext* CSubsetParser::StmtVarDeclContext::var_declaration() {
  return getRuleContext<CSubsetParser::Var_declarationContext>(0);
}

CSubsetParser::StmtVarDeclContext::StmtVarDeclContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StmtVarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStmtVarDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtExprContext ------------------------------------------------------------------

CSubsetParser::Expression_statementContext* CSubsetParser::StmtExprContext::expression_statement() {
  return getRuleContext<CSubsetParser::Expression_statementContext>(0);
}

CSubsetParser::StmtExprContext::StmtExprContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StmtExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStmtExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtWhileContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::StmtWhileContext::WHILE() {
  return getToken(CSubsetParser::WHILE, 0);
}

tree::TerminalNode* CSubsetParser::StmtWhileContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::StmtWhileContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::StmtWhileContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::StatementContext* CSubsetParser::StmtWhileContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StmtWhileContext::StmtWhileContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StmtWhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStmtWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtPrintlnContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::StmtPrintlnContext::PRINTLN() {
  return getToken(CSubsetParser::PRINTLN, 0);
}

tree::TerminalNode* CSubsetParser::StmtPrintlnContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::StmtPrintlnContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::StmtPrintlnContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::StmtPrintlnContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::StmtPrintlnContext::StmtPrintlnContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StmtPrintlnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStmtPrintln(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtIfElseContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::StmtIfElseContext::IF() {
  return getToken(CSubsetParser::IF, 0);
}

tree::TerminalNode* CSubsetParser::StmtIfElseContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::StmtIfElseContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::StmtIfElseContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

std::vector<CSubsetParser::StatementContext *> CSubsetParser::StmtIfElseContext::statement() {
  return getRuleContexts<CSubsetParser::StatementContext>();
}

CSubsetParser::StatementContext* CSubsetParser::StmtIfElseContext::statement(size_t i) {
  return getRuleContext<CSubsetParser::StatementContext>(i);
}

tree::TerminalNode* CSubsetParser::StmtIfElseContext::ELSE() {
  return getToken(CSubsetParser::ELSE, 0);
}

CSubsetParser::StmtIfElseContext::StmtIfElseContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StmtIfElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStmtIfElse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtForContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::StmtForContext::FOR() {
  return getToken(CSubsetParser::FOR, 0);
}

tree::TerminalNode* CSubsetParser::StmtForContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

std::vector<CSubsetParser::Expression_statementContext *> CSubsetParser::StmtForContext::expression_statement() {
  return getRuleContexts<CSubsetParser::Expression_statementContext>();
}

CSubsetParser::Expression_statementContext* CSubsetParser::StmtForContext::expression_statement(size_t i) {
  return getRuleContext<CSubsetParser::Expression_statementContext>(i);
}

CSubsetParser::ExpressionContext* CSubsetParser::StmtForContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::StmtForContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::StatementContext* CSubsetParser::StmtForContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StmtForContext::StmtForContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StmtForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStmtFor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtIfContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::StmtIfContext::IF() {
  return getToken(CSubsetParser::IF, 0);
}

tree::TerminalNode* CSubsetParser::StmtIfContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::StmtIfContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::StmtIfContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::StatementContext* CSubsetParser::StmtIfContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StmtIfContext::StmtIfContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StmtIfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStmtIf(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::StatementContext* CSubsetParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, CSubsetParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(203);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtVarDeclContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(163);
      var_declaration();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtExprContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(164);
      expression_statement();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtCompoundContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(165);
      compound_statement();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtForContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(166);
      match(CSubsetParser::FOR);
      setState(167);
      match(CSubsetParser::LPAREN);
      setState(168);
      expression_statement();
      setState(169);
      expression_statement();
      setState(170);
      expression();
      setState(171);
      match(CSubsetParser::RPAREN);
      setState(172);
      statement();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtIfContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(174);
      match(CSubsetParser::IF);
      setState(175);
      match(CSubsetParser::LPAREN);
      setState(176);
      expression();
      setState(177);
      match(CSubsetParser::RPAREN);
      setState(178);
      statement();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtIfElseContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(180);
      match(CSubsetParser::IF);
      setState(181);
      match(CSubsetParser::LPAREN);
      setState(182);
      expression();
      setState(183);
      match(CSubsetParser::RPAREN);
      setState(184);
      statement();
      setState(185);
      match(CSubsetParser::ELSE);
      setState(186);
      statement();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtWhileContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(188);
      match(CSubsetParser::WHILE);
      setState(189);
      match(CSubsetParser::LPAREN);
      setState(190);
      expression();
      setState(191);
      match(CSubsetParser::RPAREN);
      setState(192);
      statement();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtPrintlnContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(194);
      match(CSubsetParser::PRINTLN);
      setState(195);
      match(CSubsetParser::LPAREN);
      setState(196);
      match(CSubsetParser::ID);
      setState(197);
      match(CSubsetParser::RPAREN);
      setState(198);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtReturnContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(199);
      match(CSubsetParser::RETURN);
      setState(200);
      expression();
      setState(201);
      match(CSubsetParser::SEMICOLON);
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

//----------------- Expression_statementContext ------------------------------------------------------------------

CSubsetParser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Expression_statementContext::getRuleIndex() const {
  return CSubsetParser::RuleExpression_statement;
}

void CSubsetParser::Expression_statementContext::copyFrom(Expression_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprStmtEmptyContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::ExprStmtEmptyContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::ExprStmtEmptyContext::ExprStmtEmptyContext(Expression_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ExprStmtEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExprStmtEmpty(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprStmtExprContext ------------------------------------------------------------------

CSubsetParser::ExpressionContext* CSubsetParser::ExprStmtExprContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::ExprStmtExprContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::ExprStmtExprContext::ExprStmtExprContext(Expression_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ExprStmtExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExprStmtExpr(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Expression_statementContext* CSubsetParser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 24, CSubsetParser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(209);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::SEMICOLON: {
        _localctx = _tracker.createInstance<CSubsetParser::ExprStmtEmptyContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(205);
        match(CSubsetParser::SEMICOLON);
        break;
      }

      case CSubsetParser::LPAREN:
      case CSubsetParser::ADDOP:
      case CSubsetParser::NOT:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::ExprStmtExprContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(206);
        expression();
        setState(207);
        match(CSubsetParser::SEMICOLON);
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

//----------------- VariableContext ------------------------------------------------------------------

CSubsetParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::VariableContext::getRuleIndex() const {
  return CSubsetParser::RuleVariable;
}

void CSubsetParser::VariableContext::copyFrom(VariableContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VarArrayContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::VarArrayContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::VarArrayContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::VarArrayContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::VarArrayContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::VarArrayContext::VarArrayContext(VariableContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::VarArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVarArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarSimpleContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::VarSimpleContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::VarSimpleContext::VarSimpleContext(VariableContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::VarSimpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVarSimple(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::VariableContext* CSubsetParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 26, CSubsetParser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(217);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::VarSimpleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(211);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::VarArrayContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(212);
      match(CSubsetParser::ID);
      setState(213);
      match(CSubsetParser::LTHIRD);
      setState(214);
      expression();
      setState(215);
      match(CSubsetParser::RTHIRD);
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

//----------------- ExpressionContext ------------------------------------------------------------------

CSubsetParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::ExpressionContext::getRuleIndex() const {
  return CSubsetParser::RuleExpression;
}

void CSubsetParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprAssignContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::ExprAssignContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::ExprAssignContext::ASSIGNOP() {
  return getToken(CSubsetParser::ASSIGNOP, 0);
}

CSubsetParser::Logic_expressionContext* CSubsetParser::ExprAssignContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::ExprAssignContext::ExprAssignContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ExprAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExprAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprLogicContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext* CSubsetParser::ExprLogicContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::ExprLogicContext::ExprLogicContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ExprLogicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExprLogic(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::ExpressionContext* CSubsetParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 28, CSubsetParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(224);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::ExprLogicContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(219);
      logic_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::ExprAssignContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(220);
      variable();
      setState(221);
      match(CSubsetParser::ASSIGNOP);
      setState(222);
      logic_expression();
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

//----------------- Logic_expressionContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Logic_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleLogic_expression;
}

void CSubsetParser::Logic_expressionContext::copyFrom(Logic_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LogicRelContext ------------------------------------------------------------------

CSubsetParser::Rel_expressionContext* CSubsetParser::LogicRelContext::rel_expression() {
  return getRuleContext<CSubsetParser::Rel_expressionContext>(0);
}

CSubsetParser::LogicRelContext::LogicRelContext(Logic_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::LogicRelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitLogicRel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicOpContext ------------------------------------------------------------------

std::vector<CSubsetParser::Rel_expressionContext *> CSubsetParser::LogicOpContext::rel_expression() {
  return getRuleContexts<CSubsetParser::Rel_expressionContext>();
}

CSubsetParser::Rel_expressionContext* CSubsetParser::LogicOpContext::rel_expression(size_t i) {
  return getRuleContext<CSubsetParser::Rel_expressionContext>(i);
}

tree::TerminalNode* CSubsetParser::LogicOpContext::LOGICOP() {
  return getToken(CSubsetParser::LOGICOP, 0);
}

CSubsetParser::LogicOpContext::LogicOpContext(Logic_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::LogicOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitLogicOp(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Logic_expressionContext* CSubsetParser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 30, CSubsetParser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(231);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::LogicRelContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(226);
      rel_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::LogicOpContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(227);
      rel_expression();
      setState(228);
      match(CSubsetParser::LOGICOP);
      setState(229);
      rel_expression();
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

//----------------- Rel_expressionContext ------------------------------------------------------------------

CSubsetParser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Rel_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleRel_expression;
}

void CSubsetParser::Rel_expressionContext::copyFrom(Rel_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RelOpContext ------------------------------------------------------------------

std::vector<CSubsetParser::Simple_expressionContext *> CSubsetParser::RelOpContext::simple_expression() {
  return getRuleContexts<CSubsetParser::Simple_expressionContext>();
}

CSubsetParser::Simple_expressionContext* CSubsetParser::RelOpContext::simple_expression(size_t i) {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(i);
}

tree::TerminalNode* CSubsetParser::RelOpContext::RELOP() {
  return getToken(CSubsetParser::RELOP, 0);
}

CSubsetParser::RelOpContext::RelOpContext(Rel_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelSimpleContext ------------------------------------------------------------------

CSubsetParser::Simple_expressionContext* CSubsetParser::RelSimpleContext::simple_expression() {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(0);
}

CSubsetParser::RelSimpleContext::RelSimpleContext(Rel_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::RelSimpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitRelSimple(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Rel_expressionContext* CSubsetParser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, CSubsetParser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(238);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::RelSimpleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(233);
      simple_expression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::RelOpContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(234);
      simple_expression(0);
      setState(235);
      match(CSubsetParser::RELOP);
      setState(236);
      simple_expression(0);
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

//----------------- Simple_expressionContext ------------------------------------------------------------------

CSubsetParser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Simple_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleSimple_expression;
}

void CSubsetParser::Simple_expressionContext::copyFrom(Simple_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SimpleTermContext ------------------------------------------------------------------

CSubsetParser::TermContext* CSubsetParser::SimpleTermContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

CSubsetParser::SimpleTermContext::SimpleTermContext(Simple_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::SimpleTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSimpleTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SimpleAddOpContext ------------------------------------------------------------------

CSubsetParser::Simple_expressionContext* CSubsetParser::SimpleAddOpContext::simple_expression() {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(0);
}

tree::TerminalNode* CSubsetParser::SimpleAddOpContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

CSubsetParser::TermContext* CSubsetParser::SimpleAddOpContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

CSubsetParser::SimpleAddOpContext::SimpleAddOpContext(Simple_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::SimpleAddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSimpleAddOp(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Simple_expressionContext* CSubsetParser::simple_expression() {
   return simple_expression(0);
}

CSubsetParser::Simple_expressionContext* CSubsetParser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  CSubsetParser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, CSubsetParser::RuleSimple_expression, precedence);

    

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
    _localctx = _tracker.createInstance<SimpleTermContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(241);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(248);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<SimpleAddOpContext>(_tracker.createInstance<Simple_expressionContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleSimple_expression);
        setState(243);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(244);
        match(CSubsetParser::ADDOP);
        setState(245);
        term(0); 
      }
      setState(250);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

CSubsetParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::TermContext::getRuleIndex() const {
  return CSubsetParser::RuleTerm;
}

void CSubsetParser::TermContext::copyFrom(TermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TermUnaryContext ------------------------------------------------------------------

CSubsetParser::Unary_expressionContext* CSubsetParser::TermUnaryContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::TermUnaryContext::TermUnaryContext(TermContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::TermUnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTermUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TermMulOpContext ------------------------------------------------------------------

CSubsetParser::TermContext* CSubsetParser::TermMulOpContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

tree::TerminalNode* CSubsetParser::TermMulOpContext::MULOP() {
  return getToken(CSubsetParser::MULOP, 0);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::TermMulOpContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::TermMulOpContext::TermMulOpContext(TermContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::TermMulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTermMulOp(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::TermContext* CSubsetParser::term() {
   return term(0);
}

CSubsetParser::TermContext* CSubsetParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  CSubsetParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, CSubsetParser::RuleTerm, precedence);

    

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
    _localctx = _tracker.createInstance<TermUnaryContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(252);
    unary_expression();
    _ctx->stop = _input->LT(-1);
    setState(259);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<TermMulOpContext>(_tracker.createInstance<TermContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleTerm);
        setState(254);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(255);
        match(CSubsetParser::MULOP);
        setState(256);
        unary_expression(); 
      }
      setState(261);
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

//----------------- Unary_expressionContext ------------------------------------------------------------------

CSubsetParser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Unary_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleUnary_expression;
}

void CSubsetParser::Unary_expressionContext::copyFrom(Unary_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryNotContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::UnaryNotContext::NOT() {
  return getToken(CSubsetParser::NOT, 0);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::UnaryNotContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::UnaryNotContext::UnaryNotContext(Unary_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnaryNotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnaryNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryFactorContext ------------------------------------------------------------------

CSubsetParser::FactorContext* CSubsetParser::UnaryFactorContext::factor() {
  return getRuleContext<CSubsetParser::FactorContext>(0);
}

CSubsetParser::UnaryFactorContext::UnaryFactorContext(Unary_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnaryFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnaryFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryAddOpContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::UnaryAddOpContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::UnaryAddOpContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::UnaryAddOpContext::UnaryAddOpContext(Unary_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnaryAddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnaryAddOp(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Unary_expressionContext* CSubsetParser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 38, CSubsetParser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(267);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::ADDOP: {
        _localctx = _tracker.createInstance<CSubsetParser::UnaryAddOpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(262);
        match(CSubsetParser::ADDOP);
        setState(263);
        unary_expression();
        break;
      }

      case CSubsetParser::NOT: {
        _localctx = _tracker.createInstance<CSubsetParser::UnaryNotContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(264);
        match(CSubsetParser::NOT);
        setState(265);
        unary_expression();
        break;
      }

      case CSubsetParser::LPAREN:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::UnaryFactorContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(266);
        factor();
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

//----------------- FactorContext ------------------------------------------------------------------

CSubsetParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::FactorContext::getRuleIndex() const {
  return CSubsetParser::RuleFactor;
}

void CSubsetParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FactorIncopContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::FactorIncopContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::FactorIncopContext::INCOP() {
  return getToken(CSubsetParser::INCOP, 0);
}

CSubsetParser::FactorIncopContext::FactorIncopContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorIncopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorIncop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorDecopContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::FactorDecopContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::FactorDecopContext::DECOP() {
  return getToken(CSubsetParser::DECOP, 0);
}

CSubsetParser::FactorDecopContext::FactorDecopContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorDecopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorDecop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorFuncCallContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::FactorFuncCallContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FactorFuncCallContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Argument_listContext* CSubsetParser::FactorFuncCallContext::argument_list() {
  return getRuleContext<CSubsetParser::Argument_listContext>(0);
}

tree::TerminalNode* CSubsetParser::FactorFuncCallContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::FactorFuncCallContext::FactorFuncCallContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorFuncCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorFuncCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorConstFloatContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::FactorConstFloatContext::CONST_FLOAT() {
  return getToken(CSubsetParser::CONST_FLOAT, 0);
}

CSubsetParser::FactorConstFloatContext::FactorConstFloatContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorConstFloatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorConstFloat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorParenContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::FactorParenContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::FactorParenContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::FactorParenContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::FactorParenContext::FactorParenContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorParenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorParen(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorConstIntContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::FactorConstIntContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

CSubsetParser::FactorConstIntContext::FactorConstIntContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorConstIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorConstInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorVarContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::FactorVarContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

CSubsetParser::FactorVarContext::FactorVarContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorVar(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::FactorContext* CSubsetParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 40, CSubsetParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(287);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorVarContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(269);
      variable();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorFuncCallContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(270);
      match(CSubsetParser::ID);
      setState(271);
      match(CSubsetParser::LPAREN);
      setState(272);
      argument_list();
      setState(273);
      match(CSubsetParser::RPAREN);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorParenContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(275);
      match(CSubsetParser::LPAREN);
      setState(276);
      expression();
      setState(277);
      match(CSubsetParser::RPAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorConstIntContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(279);
      match(CSubsetParser::CONST_INT);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorConstFloatContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(280);
      match(CSubsetParser::CONST_FLOAT);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorIncopContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(281);
      variable();
      setState(282);
      match(CSubsetParser::INCOP);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorDecopContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(284);
      variable();
      setState(285);
      match(CSubsetParser::DECOP);
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

//----------------- Argument_listContext ------------------------------------------------------------------

CSubsetParser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Argument_listContext::getRuleIndex() const {
  return CSubsetParser::RuleArgument_list;
}

void CSubsetParser::Argument_listContext::copyFrom(Argument_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArgListContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext* CSubsetParser::ArgListContext::arguments() {
  return getRuleContext<CSubsetParser::ArgumentsContext>(0);
}

CSubsetParser::ArgListContext::ArgListContext(Argument_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgList(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Argument_listContext* CSubsetParser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 42, CSubsetParser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<CSubsetParser::ArgListContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(289);
    arguments(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::ArgumentsContext::getRuleIndex() const {
  return CSubsetParser::RuleArguments;
}

void CSubsetParser::ArgumentsContext::copyFrom(ArgumentsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArgsMultiContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext* CSubsetParser::ArgsMultiContext::arguments() {
  return getRuleContext<CSubsetParser::ArgumentsContext>(0);
}

tree::TerminalNode* CSubsetParser::ArgsMultiContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Logic_expressionContext* CSubsetParser::ArgsMultiContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::ArgsMultiContext::ArgsMultiContext(ArgumentsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArgsMultiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgsMulti(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArgsSingleContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext* CSubsetParser::ArgsSingleContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::ArgsSingleContext::ArgsSingleContext(ArgumentsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArgsSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgsSingle(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::ArgumentsContext* CSubsetParser::arguments() {
   return arguments(0);
}

CSubsetParser::ArgumentsContext* CSubsetParser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  CSubsetParser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, CSubsetParser::RuleArguments, precedence);

    

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
    _localctx = _tracker.createInstance<ArgsSingleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(292);
    logic_expression();
    _ctx->stop = _input->LT(-1);
    setState(299);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ArgsMultiContext>(_tracker.createInstance<ArgumentsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleArguments);
        setState(294);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(295);
        match(CSubsetParser::COMMA);
        setState(296);
        logic_expression(); 
      }
      setState(301);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CSubsetParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 9: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 10: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 17: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 18: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 22: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void CSubsetParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  csubsetParserInitialize();
#else
  ::antlr4::internal::call_once(csubsetParserOnceFlag, csubsetParserInitialize);
#endif
}
