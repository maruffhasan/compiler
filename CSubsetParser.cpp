
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
  	4,1,32,304,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,54,8,1,10,1,12,1,57,9,1,
  	1,2,1,2,1,2,3,2,62,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,3,3,77,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	3,4,92,8,4,1,5,1,5,1,5,1,5,1,5,3,5,99,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,5,5,109,8,5,10,5,12,5,112,9,5,1,6,1,6,1,6,1,6,1,6,1,6,3,6,120,8,6,
  	1,7,1,7,1,7,1,7,1,8,1,8,1,8,3,8,129,8,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,137,
  	8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,148,8,9,10,9,12,9,151,9,9,
  	1,10,1,10,1,10,1,10,1,10,5,10,158,8,10,10,10,12,10,161,9,10,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,203,8,11,1,12,
  	1,12,1,12,1,12,3,12,209,8,12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,217,8,
  	13,1,14,1,14,1,14,1,14,1,14,3,14,224,8,14,1,15,1,15,1,15,1,15,1,15,3,
  	15,231,8,15,1,16,1,16,1,16,1,16,1,16,3,16,238,8,16,1,17,1,17,1,17,1,17,
  	1,17,1,17,5,17,246,8,17,10,17,12,17,249,9,17,1,18,1,18,1,18,1,18,1,18,
  	1,18,5,18,257,8,18,10,18,12,18,260,9,18,1,19,1,19,1,19,1,19,1,19,3,19,
  	267,8,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,3,20,287,8,20,1,21,1,21,3,21,291,8,21,1,
  	22,1,22,1,22,1,22,1,22,1,22,5,22,299,8,22,10,22,12,22,302,9,22,1,22,0,
  	7,2,10,18,20,34,36,44,23,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,
  	34,36,38,40,42,44,0,0,320,0,46,1,0,0,0,2,48,1,0,0,0,4,61,1,0,0,0,6,76,
  	1,0,0,0,8,91,1,0,0,0,10,98,1,0,0,0,12,119,1,0,0,0,14,121,1,0,0,0,16,128,
  	1,0,0,0,18,136,1,0,0,0,20,152,1,0,0,0,22,202,1,0,0,0,24,208,1,0,0,0,26,
  	216,1,0,0,0,28,223,1,0,0,0,30,230,1,0,0,0,32,237,1,0,0,0,34,239,1,0,0,
  	0,36,250,1,0,0,0,38,266,1,0,0,0,40,286,1,0,0,0,42,290,1,0,0,0,44,292,
  	1,0,0,0,46,47,3,2,1,0,47,1,1,0,0,0,48,49,6,1,-1,0,49,50,3,4,2,0,50,55,
  	1,0,0,0,51,52,10,2,0,0,52,54,3,4,2,0,53,51,1,0,0,0,54,57,1,0,0,0,55,53,
  	1,0,0,0,55,56,1,0,0,0,56,3,1,0,0,0,57,55,1,0,0,0,58,62,3,14,7,0,59,62,
  	3,6,3,0,60,62,3,8,4,0,61,58,1,0,0,0,61,59,1,0,0,0,61,60,1,0,0,0,62,5,
  	1,0,0,0,63,64,3,16,8,0,64,65,5,30,0,0,65,66,5,14,0,0,66,67,3,10,5,0,67,
  	68,5,15,0,0,68,69,5,20,0,0,69,77,1,0,0,0,70,71,3,16,8,0,71,72,5,30,0,
  	0,72,73,5,14,0,0,73,74,5,15,0,0,74,75,5,20,0,0,75,77,1,0,0,0,76,63,1,
  	0,0,0,76,70,1,0,0,0,77,7,1,0,0,0,78,79,3,16,8,0,79,80,5,30,0,0,80,81,
  	5,14,0,0,81,82,3,10,5,0,82,83,5,15,0,0,83,84,3,12,6,0,84,92,1,0,0,0,85,
  	86,3,16,8,0,86,87,5,30,0,0,87,88,5,14,0,0,88,89,5,15,0,0,89,90,3,12,6,
  	0,90,92,1,0,0,0,91,78,1,0,0,0,91,85,1,0,0,0,92,9,1,0,0,0,93,94,6,5,-1,
  	0,94,95,3,16,8,0,95,96,5,30,0,0,96,99,1,0,0,0,97,99,3,16,8,0,98,93,1,
  	0,0,0,98,97,1,0,0,0,99,110,1,0,0,0,100,101,10,4,0,0,101,102,5,21,0,0,
  	102,103,3,16,8,0,103,104,5,30,0,0,104,109,1,0,0,0,105,106,10,3,0,0,106,
  	107,5,21,0,0,107,109,3,16,8,0,108,100,1,0,0,0,108,105,1,0,0,0,109,112,
  	1,0,0,0,110,108,1,0,0,0,110,111,1,0,0,0,111,11,1,0,0,0,112,110,1,0,0,
  	0,113,114,5,16,0,0,114,115,3,20,10,0,115,116,5,17,0,0,116,120,1,0,0,0,
  	117,118,5,16,0,0,118,120,5,17,0,0,119,113,1,0,0,0,119,117,1,0,0,0,120,
  	13,1,0,0,0,121,122,3,16,8,0,122,123,3,18,9,0,123,124,5,20,0,0,124,15,
  	1,0,0,0,125,129,5,11,0,0,126,129,5,12,0,0,127,129,5,13,0,0,128,125,1,
  	0,0,0,128,126,1,0,0,0,128,127,1,0,0,0,129,17,1,0,0,0,130,131,6,9,-1,0,
  	131,137,5,30,0,0,132,133,5,30,0,0,133,134,5,18,0,0,134,135,5,31,0,0,135,
  	137,5,19,0,0,136,130,1,0,0,0,136,132,1,0,0,0,137,149,1,0,0,0,138,139,
  	10,4,0,0,139,140,5,21,0,0,140,148,5,30,0,0,141,142,10,3,0,0,142,143,5,
  	21,0,0,143,144,5,30,0,0,144,145,5,18,0,0,145,146,5,31,0,0,146,148,5,19,
  	0,0,147,138,1,0,0,0,147,141,1,0,0,0,148,151,1,0,0,0,149,147,1,0,0,0,149,
  	150,1,0,0,0,150,19,1,0,0,0,151,149,1,0,0,0,152,153,6,10,-1,0,153,154,
  	3,22,11,0,154,159,1,0,0,0,155,156,10,1,0,0,156,158,3,22,11,0,157,155,
  	1,0,0,0,158,161,1,0,0,0,159,157,1,0,0,0,159,160,1,0,0,0,160,21,1,0,0,
  	0,161,159,1,0,0,0,162,203,3,14,7,0,163,203,3,24,12,0,164,203,3,12,6,0,
  	165,166,5,7,0,0,166,167,5,14,0,0,167,168,3,24,12,0,168,169,3,24,12,0,
  	169,170,3,28,14,0,170,171,5,15,0,0,171,172,3,22,11,0,172,203,1,0,0,0,
  	173,174,5,5,0,0,174,175,5,14,0,0,175,176,3,28,14,0,176,177,5,15,0,0,177,
  	178,3,22,11,0,178,203,1,0,0,0,179,180,5,5,0,0,180,181,5,14,0,0,181,182,
  	3,28,14,0,182,183,5,15,0,0,183,184,3,22,11,0,184,185,5,6,0,0,185,186,
  	3,22,11,0,186,203,1,0,0,0,187,188,5,8,0,0,188,189,5,14,0,0,189,190,3,
  	28,14,0,190,191,5,15,0,0,191,192,3,22,11,0,192,203,1,0,0,0,193,194,5,
  	9,0,0,194,195,5,14,0,0,195,196,5,30,0,0,196,197,5,15,0,0,197,203,5,20,
  	0,0,198,199,5,10,0,0,199,200,3,28,14,0,200,201,5,20,0,0,201,203,1,0,0,
  	0,202,162,1,0,0,0,202,163,1,0,0,0,202,164,1,0,0,0,202,165,1,0,0,0,202,
  	173,1,0,0,0,202,179,1,0,0,0,202,187,1,0,0,0,202,193,1,0,0,0,202,198,1,
  	0,0,0,203,23,1,0,0,0,204,209,5,20,0,0,205,206,3,28,14,0,206,207,5,20,
  	0,0,207,209,1,0,0,0,208,204,1,0,0,0,208,205,1,0,0,0,209,25,1,0,0,0,210,
  	217,5,30,0,0,211,212,5,30,0,0,212,213,5,18,0,0,213,214,3,28,14,0,214,
  	215,5,19,0,0,215,217,1,0,0,0,216,210,1,0,0,0,216,211,1,0,0,0,217,27,1,
  	0,0,0,218,224,3,30,15,0,219,220,3,26,13,0,220,221,5,29,0,0,221,222,3,
  	30,15,0,222,224,1,0,0,0,223,218,1,0,0,0,223,219,1,0,0,0,224,29,1,0,0,
  	0,225,231,3,32,16,0,226,227,3,32,16,0,227,228,5,28,0,0,228,229,3,32,16,
  	0,229,231,1,0,0,0,230,225,1,0,0,0,230,226,1,0,0,0,231,31,1,0,0,0,232,
  	238,3,34,17,0,233,234,3,34,17,0,234,235,5,27,0,0,235,236,3,34,17,0,236,
  	238,1,0,0,0,237,232,1,0,0,0,237,233,1,0,0,0,238,33,1,0,0,0,239,240,6,
  	17,-1,0,240,241,3,36,18,0,241,247,1,0,0,0,242,243,10,1,0,0,243,244,5,
  	22,0,0,244,246,3,36,18,0,245,242,1,0,0,0,246,249,1,0,0,0,247,245,1,0,
  	0,0,247,248,1,0,0,0,248,35,1,0,0,0,249,247,1,0,0,0,250,251,6,18,-1,0,
  	251,252,3,38,19,0,252,258,1,0,0,0,253,254,10,1,0,0,254,255,5,23,0,0,255,
  	257,3,38,19,0,256,253,1,0,0,0,257,260,1,0,0,0,258,256,1,0,0,0,258,259,
  	1,0,0,0,259,37,1,0,0,0,260,258,1,0,0,0,261,262,5,22,0,0,262,267,3,38,
  	19,0,263,264,5,26,0,0,264,267,3,38,19,0,265,267,3,40,20,0,266,261,1,0,
  	0,0,266,263,1,0,0,0,266,265,1,0,0,0,267,39,1,0,0,0,268,287,3,26,13,0,
  	269,270,5,30,0,0,270,271,5,14,0,0,271,272,3,42,21,0,272,273,5,15,0,0,
  	273,287,1,0,0,0,274,275,5,14,0,0,275,276,3,28,14,0,276,277,5,15,0,0,277,
  	287,1,0,0,0,278,287,5,31,0,0,279,287,5,32,0,0,280,281,3,26,13,0,281,282,
  	5,24,0,0,282,287,1,0,0,0,283,284,3,26,13,0,284,285,5,25,0,0,285,287,1,
  	0,0,0,286,268,1,0,0,0,286,269,1,0,0,0,286,274,1,0,0,0,286,278,1,0,0,0,
  	286,279,1,0,0,0,286,280,1,0,0,0,286,283,1,0,0,0,287,41,1,0,0,0,288,291,
  	3,44,22,0,289,291,1,0,0,0,290,288,1,0,0,0,290,289,1,0,0,0,291,43,1,0,
  	0,0,292,293,6,22,-1,0,293,294,3,30,15,0,294,300,1,0,0,0,295,296,10,2,
  	0,0,296,297,5,21,0,0,297,299,3,30,15,0,298,295,1,0,0,0,299,302,1,0,0,
  	0,300,298,1,0,0,0,300,301,1,0,0,0,301,45,1,0,0,0,302,300,1,0,0,0,25,55,
  	61,76,91,98,108,110,119,128,136,147,149,159,202,208,216,223,230,237,247,
  	258,266,286,290,300
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


size_t CSubsetParser::ProgramContext::getRuleIndex() const {
  return CSubsetParser::RuleProgram;
}

void CSubsetParser::ProgramContext::copyFrom(ProgramContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProgramSingleUnitContext ------------------------------------------------------------------

CSubsetParser::UnitContext* CSubsetParser::ProgramSingleUnitContext::unit() {
  return getRuleContext<CSubsetParser::UnitContext>(0);
}

CSubsetParser::ProgramSingleUnitContext::ProgramSingleUnitContext(ProgramContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ProgramSingleUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitProgramSingleUnit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProgramUnitContext ------------------------------------------------------------------

CSubsetParser::ProgramContext* CSubsetParser::ProgramUnitContext::program() {
  return getRuleContext<CSubsetParser::ProgramContext>(0);
}

CSubsetParser::UnitContext* CSubsetParser::ProgramUnitContext::unit() {
  return getRuleContext<CSubsetParser::UnitContext>(0);
}

CSubsetParser::ProgramUnitContext::ProgramUnitContext(ProgramContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ProgramUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitProgramUnit(this);
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
    _localctx = _tracker.createInstance<ProgramSingleUnitContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(49);
    unit();
    _ctx->stop = _input->LT(-1);
    setState(55);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ProgramUnitContext>(_tracker.createInstance<ProgramContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleProgram);
        setState(51);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(52);
        unit(); 
      }
      setState(57);
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


size_t CSubsetParser::UnitContext::getRuleIndex() const {
  return CSubsetParser::RuleUnit;
}

void CSubsetParser::UnitContext::copyFrom(UnitContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnitVarDeclContext ------------------------------------------------------------------

CSubsetParser::Var_declarationContext* CSubsetParser::UnitVarDeclContext::var_declaration() {
  return getRuleContext<CSubsetParser::Var_declarationContext>(0);
}

CSubsetParser::UnitVarDeclContext::UnitVarDeclContext(UnitContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnitVarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnitVarDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnitFuncDefContext ------------------------------------------------------------------

CSubsetParser::Func_definitionContext* CSubsetParser::UnitFuncDefContext::func_definition() {
  return getRuleContext<CSubsetParser::Func_definitionContext>(0);
}

CSubsetParser::UnitFuncDefContext::UnitFuncDefContext(UnitContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnitFuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnitFuncDef(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnitFuncDeclContext ------------------------------------------------------------------

CSubsetParser::Func_declarationContext* CSubsetParser::UnitFuncDeclContext::func_declaration() {
  return getRuleContext<CSubsetParser::Func_declarationContext>(0);
}

CSubsetParser::UnitFuncDeclContext::UnitFuncDeclContext(UnitContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnitFuncDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnitFuncDecl(this);
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
    setState(61);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::UnitVarDeclContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(58);
      var_declaration();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::UnitFuncDeclContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(59);
      func_declaration();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::UnitFuncDefContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(60);
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
    setState(76);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::FuncDeclWithParamsContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(63);
      type_specifier();
      setState(64);
      match(CSubsetParser::ID);
      setState(65);
      match(CSubsetParser::LPAREN);
      setState(66);
      parameter_list(0);
      setState(67);
      match(CSubsetParser::RPAREN);
      setState(68);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::FuncDeclNoParamsContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(70);
      type_specifier();
      setState(71);
      match(CSubsetParser::ID);
      setState(72);
      match(CSubsetParser::LPAREN);
      setState(73);
      match(CSubsetParser::RPAREN);
      setState(74);
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
    setState(91);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::FuncDefWithParamsContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(78);
      type_specifier();
      setState(79);
      match(CSubsetParser::ID);
      setState(80);
      match(CSubsetParser::LPAREN);
      setState(81);
      parameter_list(0);
      setState(82);
      match(CSubsetParser::RPAREN);
      setState(83);
      compound_statement();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::FuncDefNoParamsContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(85);
      type_specifier();
      setState(86);
      match(CSubsetParser::ID);
      setState(87);
      match(CSubsetParser::LPAREN);
      setState(88);
      match(CSubsetParser::RPAREN);
      setState(89);
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

//----------------- ParamListMultiUnnamedContext ------------------------------------------------------------------

CSubsetParser::Parameter_listContext* CSubsetParser::ParamListMultiUnnamedContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::ParamListMultiUnnamedContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Type_specifierContext* CSubsetParser::ParamListMultiUnnamedContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::ParamListMultiUnnamedContext::ParamListMultiUnnamedContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParamListMultiUnnamedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParamListMultiUnnamed(this);
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
//----------------- ParamListSingleUnnamedContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::ParamListSingleUnnamedContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::ParamListSingleUnnamedContext::ParamListSingleUnnamedContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParamListSingleUnnamedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParamListSingleUnnamed(this);
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
    setState(98);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParamListSingleNamedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(94);
      type_specifier();
      setState(95);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParamListSingleUnnamedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(97);
      type_specifier();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(110);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(108);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ParamListMultiNamedContext>(_tracker.createInstance<Parameter_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleParameter_list);
          setState(100);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(101);
          match(CSubsetParser::COMMA);
          setState(102);
          type_specifier();
          setState(103);
          match(CSubsetParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ParamListMultiUnnamedContext>(_tracker.createInstance<Parameter_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleParameter_list);
          setState(105);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(106);
          match(CSubsetParser::COMMA);
          setState(107);
          type_specifier();
          break;
        }

        default:
          break;
        } 
      }
      setState(112);
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

//----------------- CompoundWithStmtsContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::CompoundWithStmtsContext::LCURL() {
  return getToken(CSubsetParser::LCURL, 0);
}

CSubsetParser::StatementsContext* CSubsetParser::CompoundWithStmtsContext::statements() {
  return getRuleContext<CSubsetParser::StatementsContext>(0);
}

tree::TerminalNode* CSubsetParser::CompoundWithStmtsContext::RCURL() {
  return getToken(CSubsetParser::RCURL, 0);
}

CSubsetParser::CompoundWithStmtsContext::CompoundWithStmtsContext(Compound_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::CompoundWithStmtsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitCompoundWithStmts(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompoundEmptyContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::CompoundEmptyContext::LCURL() {
  return getToken(CSubsetParser::LCURL, 0);
}

tree::TerminalNode* CSubsetParser::CompoundEmptyContext::RCURL() {
  return getToken(CSubsetParser::RCURL, 0);
}

CSubsetParser::CompoundEmptyContext::CompoundEmptyContext(Compound_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::CompoundEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitCompoundEmpty(this);
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
    setState(119);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::CompoundWithStmtsContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(113);
      match(CSubsetParser::LCURL);
      setState(114);
      statements(0);
      setState(115);
      match(CSubsetParser::RCURL);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::CompoundEmptyContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(117);
      match(CSubsetParser::LCURL);
      setState(118);
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
    setState(121);
    type_specifier();
    setState(122);
    declaration_list(0);
    setState(123);
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
    setState(128);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::INT: {
        _localctx = _tracker.createInstance<CSubsetParser::TypeIntContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(125);
        match(CSubsetParser::INT);
        break;
      }

      case CSubsetParser::FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::TypeFloatContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(126);
        match(CSubsetParser::FLOAT);
        break;
      }

      case CSubsetParser::VOID: {
        _localctx = _tracker.createInstance<CSubsetParser::TypeVoidContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(127);
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

//----------------- DeclListSingleIdArrayContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::DeclListSingleIdArrayContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::DeclListSingleIdArrayContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

tree::TerminalNode* CSubsetParser::DeclListSingleIdArrayContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

tree::TerminalNode* CSubsetParser::DeclListSingleIdArrayContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::DeclListSingleIdArrayContext::DeclListSingleIdArrayContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclListSingleIdArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclListSingleIdArray(this);
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
//----------------- DeclListCommaIdArrayContext ------------------------------------------------------------------

CSubsetParser::Declaration_listContext* CSubsetParser::DeclListCommaIdArrayContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::DeclListCommaIdArrayContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

tree::TerminalNode* CSubsetParser::DeclListCommaIdArrayContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::DeclListCommaIdArrayContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

tree::TerminalNode* CSubsetParser::DeclListCommaIdArrayContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

tree::TerminalNode* CSubsetParser::DeclListCommaIdArrayContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::DeclListCommaIdArrayContext::DeclListCommaIdArrayContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclListCommaIdArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclListCommaIdArray(this);
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
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<DeclListSingleIdContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(131);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<DeclListSingleIdArrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(132);
      match(CSubsetParser::ID);
      setState(133);
      match(CSubsetParser::LTHIRD);
      setState(134);
      match(CSubsetParser::CONST_INT);
      setState(135);
      match(CSubsetParser::RTHIRD);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(149);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(147);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<DeclListCommaIdContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(138);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(139);
          match(CSubsetParser::COMMA);
          setState(140);
          match(CSubsetParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DeclListCommaIdArrayContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(141);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(142);
          match(CSubsetParser::COMMA);
          setState(143);
          match(CSubsetParser::ID);
          setState(144);
          match(CSubsetParser::LTHIRD);
          setState(145);
          match(CSubsetParser::CONST_INT);
          setState(146);
          match(CSubsetParser::RTHIRD);
          break;
        }

        default:
          break;
        } 
      }
      setState(151);
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

//----------------- StatementsSingleContext ------------------------------------------------------------------

CSubsetParser::StatementContext* CSubsetParser::StatementsSingleContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StatementsSingleContext::StatementsSingleContext(StatementsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementsSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementsSingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementsMultiContext ------------------------------------------------------------------

CSubsetParser::StatementsContext* CSubsetParser::StatementsMultiContext::statements() {
  return getRuleContext<CSubsetParser::StatementsContext>(0);
}

CSubsetParser::StatementContext* CSubsetParser::StatementsMultiContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StatementsMultiContext::StatementsMultiContext(StatementsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementsMultiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementsMulti(this);
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
    _localctx = _tracker.createInstance<StatementsSingleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(153);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(159);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<StatementsMultiContext>(_tracker.createInstance<StatementsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleStatements);
        setState(155);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(156);
        statement(); 
      }
      setState(161);
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
//----------------- StmtExprStmtContext ------------------------------------------------------------------

CSubsetParser::Expression_statementContext* CSubsetParser::StmtExprStmtContext::expression_statement() {
  return getRuleContext<CSubsetParser::Expression_statementContext>(0);
}

CSubsetParser::StmtExprStmtContext::StmtExprStmtContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StmtExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStmtExprStmt(this);
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
    setState(202);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtVarDeclContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(162);
      var_declaration();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtExprStmtContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(163);
      expression_statement();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtCompoundContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(164);
      compound_statement();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtForContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(165);
      match(CSubsetParser::FOR);
      setState(166);
      match(CSubsetParser::LPAREN);
      setState(167);
      expression_statement();
      setState(168);
      expression_statement();
      setState(169);
      expression();
      setState(170);
      match(CSubsetParser::RPAREN);
      setState(171);
      statement();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtIfContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(173);
      match(CSubsetParser::IF);
      setState(174);
      match(CSubsetParser::LPAREN);
      setState(175);
      expression();
      setState(176);
      match(CSubsetParser::RPAREN);
      setState(177);
      statement();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtIfElseContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(179);
      match(CSubsetParser::IF);
      setState(180);
      match(CSubsetParser::LPAREN);
      setState(181);
      expression();
      setState(182);
      match(CSubsetParser::RPAREN);
      setState(183);
      statement();
      setState(184);
      match(CSubsetParser::ELSE);
      setState(185);
      statement();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtWhileContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(187);
      match(CSubsetParser::WHILE);
      setState(188);
      match(CSubsetParser::LPAREN);
      setState(189);
      expression();
      setState(190);
      match(CSubsetParser::RPAREN);
      setState(191);
      statement();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtPrintlnContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(193);
      match(CSubsetParser::PRINTLN);
      setState(194);
      match(CSubsetParser::LPAREN);
      setState(195);
      match(CSubsetParser::ID);
      setState(196);
      match(CSubsetParser::RPAREN);
      setState(197);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<CSubsetParser::StmtReturnContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(198);
      match(CSubsetParser::RETURN);
      setState(199);
      expression();
      setState(200);
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
    setState(208);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::SEMICOLON: {
        _localctx = _tracker.createInstance<CSubsetParser::ExprStmtEmptyContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(204);
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
        setState(205);
        expression();
        setState(206);
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
    setState(216);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::VarSimpleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(210);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::VarArrayContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(211);
      match(CSubsetParser::ID);
      setState(212);
      match(CSubsetParser::LTHIRD);
      setState(213);
      expression();
      setState(214);
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
    setState(223);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::ExprLogicContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(218);
      logic_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::ExprAssignContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(219);
      variable();
      setState(220);
      match(CSubsetParser::ASSIGNOP);
      setState(221);
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

//----------------- LogicSingleContext ------------------------------------------------------------------

CSubsetParser::Rel_expressionContext* CSubsetParser::LogicSingleContext::rel_expression() {
  return getRuleContext<CSubsetParser::Rel_expressionContext>(0);
}

CSubsetParser::LogicSingleContext::LogicSingleContext(Logic_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::LogicSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitLogicSingle(this);
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
    setState(230);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::LogicSingleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(225);
      rel_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::LogicOpContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(226);
      rel_expression();
      setState(227);
      match(CSubsetParser::LOGICOP);
      setState(228);
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

//----------------- RelSingleContext ------------------------------------------------------------------

CSubsetParser::Simple_expressionContext* CSubsetParser::RelSingleContext::simple_expression() {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(0);
}

CSubsetParser::RelSingleContext::RelSingleContext(Rel_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::RelSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitRelSingle(this);
  else
    return visitor->visitChildren(this);
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
    setState(237);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::RelSingleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(232);
      simple_expression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::RelOpContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(233);
      simple_expression(0);
      setState(234);
      match(CSubsetParser::RELOP);
      setState(235);
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

    setState(240);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(247);
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
        setState(242);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(243);
        match(CSubsetParser::ADDOP);
        setState(244);
        term(0); 
      }
      setState(249);
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

    setState(251);
    unary_expression();
    _ctx->stop = _input->LT(-1);
    setState(258);
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
        setState(253);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(254);
        match(CSubsetParser::MULOP);
        setState(255);
        unary_expression(); 
      }
      setState(260);
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
    setState(266);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::ADDOP: {
        _localctx = _tracker.createInstance<CSubsetParser::UnaryAddOpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(261);
        match(CSubsetParser::ADDOP);
        setState(262);
        unary_expression();
        break;
      }

      case CSubsetParser::NOT: {
        _localctx = _tracker.createInstance<CSubsetParser::UnaryNotContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(263);
        match(CSubsetParser::NOT);
        setState(264);
        unary_expression();
        break;
      }

      case CSubsetParser::LPAREN:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::UnaryFactorContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(265);
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
    setState(286);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorVarContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(268);
      variable();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorFuncCallContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(269);
      match(CSubsetParser::ID);
      setState(270);
      match(CSubsetParser::LPAREN);
      setState(271);
      argument_list();
      setState(272);
      match(CSubsetParser::RPAREN);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorParenContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(274);
      match(CSubsetParser::LPAREN);
      setState(275);
      expression();
      setState(276);
      match(CSubsetParser::RPAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorConstIntContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(278);
      match(CSubsetParser::CONST_INT);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorConstFloatContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(279);
      match(CSubsetParser::CONST_FLOAT);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorIncopContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(280);
      variable();
      setState(281);
      match(CSubsetParser::INCOP);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorDecopContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(283);
      variable();
      setState(284);
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

//----------------- ArgListEmptyContext ------------------------------------------------------------------

CSubsetParser::ArgListEmptyContext::ArgListEmptyContext(Argument_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArgListEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgListEmpty(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArgListNonEmptyContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext* CSubsetParser::ArgListNonEmptyContext::arguments() {
  return getRuleContext<CSubsetParser::ArgumentsContext>(0);
}

CSubsetParser::ArgListNonEmptyContext::ArgListNonEmptyContext(Argument_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArgListNonEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgListNonEmpty(this);
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
    setState(290);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::LPAREN:
      case CSubsetParser::ADDOP:
      case CSubsetParser::NOT:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::ArgListNonEmptyContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(288);
        arguments(0);
        break;
      }

      case CSubsetParser::RPAREN: {
        _localctx = _tracker.createInstance<CSubsetParser::ArgListEmptyContext>(_localctx);
        enterOuterAlt(_localctx, 2);

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

//----------------- ArgumentsMultiContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext* CSubsetParser::ArgumentsMultiContext::arguments() {
  return getRuleContext<CSubsetParser::ArgumentsContext>(0);
}

tree::TerminalNode* CSubsetParser::ArgumentsMultiContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Logic_expressionContext* CSubsetParser::ArgumentsMultiContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::ArgumentsMultiContext::ArgumentsMultiContext(ArgumentsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArgumentsMultiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgumentsMulti(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArgumentsSingleContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext* CSubsetParser::ArgumentsSingleContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::ArgumentsSingleContext::ArgumentsSingleContext(ArgumentsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArgumentsSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgumentsSingle(this);
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
    _localctx = _tracker.createInstance<ArgumentsSingleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(293);
    logic_expression();
    _ctx->stop = _input->LT(-1);
    setState(300);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ArgumentsMultiContext>(_tracker.createInstance<ArgumentsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleArguments);
        setState(295);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(296);
        match(CSubsetParser::COMMA);
        setState(297);
        logic_expression(); 
      }
      setState(302);
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
