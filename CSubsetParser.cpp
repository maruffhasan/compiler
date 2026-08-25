
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
      "start", "program", "unit", "func_definition", "compound_statement", 
      "var_declaration", "type_specifier", "declaration_list", "statements", 
      "statement", "expression_statement", "variable", "expression", "logic_expression", 
      "rel_expression", "simple_expression", "term", "unary_expression", 
      "factor"
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
  	4,1,32,186,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,1,0,1,0,1,1,1,1,1,1,1,
  	1,1,1,5,1,47,8,1,10,1,12,1,50,9,1,1,2,1,2,3,2,54,8,2,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,3,4,68,8,4,1,5,1,5,1,5,1,5,1,6,1,6,3,
  	6,76,8,6,1,7,1,7,1,7,1,7,1,7,1,7,5,7,84,8,7,10,7,12,7,87,9,7,1,8,1,8,
  	1,8,1,8,1,8,5,8,94,8,8,10,8,12,8,97,9,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,3,9,111,8,9,1,10,1,10,1,10,1,10,3,10,117,8,10,1,11,
  	1,11,1,12,1,12,1,12,1,12,1,12,3,12,126,8,12,1,13,1,13,1,13,1,13,1,13,
  	3,13,133,8,13,1,14,1,14,1,14,1,14,1,14,3,14,140,8,14,1,15,1,15,1,15,1,
  	15,1,15,1,15,5,15,148,8,15,10,15,12,15,151,9,15,1,16,1,16,1,16,1,16,1,
  	16,1,16,5,16,159,8,16,10,16,12,16,162,9,16,1,17,1,17,1,17,1,17,1,17,3,
  	17,169,8,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,3,18,184,8,18,1,18,0,5,2,14,16,30,32,19,0,2,4,6,8,10,12,14,16,
  	18,20,22,24,26,28,30,32,34,36,0,0,189,0,38,1,0,0,0,2,41,1,0,0,0,4,53,
  	1,0,0,0,6,55,1,0,0,0,8,67,1,0,0,0,10,69,1,0,0,0,12,75,1,0,0,0,14,77,1,
  	0,0,0,16,88,1,0,0,0,18,110,1,0,0,0,20,116,1,0,0,0,22,118,1,0,0,0,24,125,
  	1,0,0,0,26,132,1,0,0,0,28,139,1,0,0,0,30,141,1,0,0,0,32,152,1,0,0,0,34,
  	168,1,0,0,0,36,183,1,0,0,0,38,39,3,2,1,0,39,40,5,0,0,1,40,1,1,0,0,0,41,
  	42,6,1,-1,0,42,43,3,4,2,0,43,48,1,0,0,0,44,45,10,2,0,0,45,47,3,4,2,0,
  	46,44,1,0,0,0,47,50,1,0,0,0,48,46,1,0,0,0,48,49,1,0,0,0,49,3,1,0,0,0,
  	50,48,1,0,0,0,51,54,3,10,5,0,52,54,3,6,3,0,53,51,1,0,0,0,53,52,1,0,0,
  	0,54,5,1,0,0,0,55,56,3,12,6,0,56,57,5,30,0,0,57,58,5,14,0,0,58,59,5,15,
  	0,0,59,60,3,8,4,0,60,7,1,0,0,0,61,62,5,16,0,0,62,63,3,16,8,0,63,64,5,
  	17,0,0,64,68,1,0,0,0,65,66,5,16,0,0,66,68,5,17,0,0,67,61,1,0,0,0,67,65,
  	1,0,0,0,68,9,1,0,0,0,69,70,3,12,6,0,70,71,3,14,7,0,71,72,5,20,0,0,72,
  	11,1,0,0,0,73,76,5,11,0,0,74,76,5,13,0,0,75,73,1,0,0,0,75,74,1,0,0,0,
  	76,13,1,0,0,0,77,78,6,7,-1,0,78,79,5,30,0,0,79,85,1,0,0,0,80,81,10,2,
  	0,0,81,82,5,21,0,0,82,84,5,30,0,0,83,80,1,0,0,0,84,87,1,0,0,0,85,83,1,
  	0,0,0,85,86,1,0,0,0,86,15,1,0,0,0,87,85,1,0,0,0,88,89,6,8,-1,0,89,90,
  	3,18,9,0,90,95,1,0,0,0,91,92,10,1,0,0,92,94,3,18,9,0,93,91,1,0,0,0,94,
  	97,1,0,0,0,95,93,1,0,0,0,95,96,1,0,0,0,96,17,1,0,0,0,97,95,1,0,0,0,98,
  	111,3,10,5,0,99,111,3,20,10,0,100,111,3,8,4,0,101,102,5,9,0,0,102,103,
  	5,14,0,0,103,104,5,30,0,0,104,105,5,15,0,0,105,111,5,20,0,0,106,107,5,
  	10,0,0,107,108,3,24,12,0,108,109,5,20,0,0,109,111,1,0,0,0,110,98,1,0,
  	0,0,110,99,1,0,0,0,110,100,1,0,0,0,110,101,1,0,0,0,110,106,1,0,0,0,111,
  	19,1,0,0,0,112,117,5,20,0,0,113,114,3,24,12,0,114,115,5,20,0,0,115,117,
  	1,0,0,0,116,112,1,0,0,0,116,113,1,0,0,0,117,21,1,0,0,0,118,119,5,30,0,
  	0,119,23,1,0,0,0,120,126,3,26,13,0,121,122,3,22,11,0,122,123,5,29,0,0,
  	123,124,3,26,13,0,124,126,1,0,0,0,125,120,1,0,0,0,125,121,1,0,0,0,126,
  	25,1,0,0,0,127,133,3,28,14,0,128,129,3,28,14,0,129,130,5,28,0,0,130,131,
  	3,28,14,0,131,133,1,0,0,0,132,127,1,0,0,0,132,128,1,0,0,0,133,27,1,0,
  	0,0,134,140,3,30,15,0,135,136,3,30,15,0,136,137,5,27,0,0,137,138,3,30,
  	15,0,138,140,1,0,0,0,139,134,1,0,0,0,139,135,1,0,0,0,140,29,1,0,0,0,141,
  	142,6,15,-1,0,142,143,3,32,16,0,143,149,1,0,0,0,144,145,10,1,0,0,145,
  	146,5,22,0,0,146,148,3,32,16,0,147,144,1,0,0,0,148,151,1,0,0,0,149,147,
  	1,0,0,0,149,150,1,0,0,0,150,31,1,0,0,0,151,149,1,0,0,0,152,153,6,16,-1,
  	0,153,154,3,34,17,0,154,160,1,0,0,0,155,156,10,1,0,0,156,157,5,23,0,0,
  	157,159,3,34,17,0,158,155,1,0,0,0,159,162,1,0,0,0,160,158,1,0,0,0,160,
  	161,1,0,0,0,161,33,1,0,0,0,162,160,1,0,0,0,163,164,5,22,0,0,164,169,3,
  	34,17,0,165,166,5,26,0,0,166,169,3,34,17,0,167,169,3,36,18,0,168,163,
  	1,0,0,0,168,165,1,0,0,0,168,167,1,0,0,0,169,35,1,0,0,0,170,184,3,22,11,
  	0,171,172,5,14,0,0,172,173,3,24,12,0,173,174,5,15,0,0,174,184,1,0,0,0,
  	175,184,5,31,0,0,176,184,5,32,0,0,177,178,3,22,11,0,178,179,5,24,0,0,
  	179,184,1,0,0,0,180,181,3,22,11,0,181,182,5,25,0,0,182,184,1,0,0,0,183,
  	170,1,0,0,0,183,171,1,0,0,0,183,175,1,0,0,0,183,176,1,0,0,0,183,177,1,
  	0,0,0,183,180,1,0,0,0,184,37,1,0,0,0,15,48,53,67,75,85,95,110,116,125,
  	132,139,149,160,168,183
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
    setState(38);
    program(0);
    setState(39);
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
    setState(42);
    unit();
    _ctx->stop = _input->LT(-1);
    setState(48);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(44);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(45);
        unit(); 
      }
      setState(50);
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
    setState(53);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(51);
      var_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(52);
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
CSubsetParser::Func_definitionContext* CSubsetParser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 6, CSubsetParser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<CSubsetParser::FuncDefNoParamsContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(55);
    type_specifier();
    setState(56);
    match(CSubsetParser::ID);
    setState(57);
    match(CSubsetParser::LPAREN);
    setState(58);
    match(CSubsetParser::RPAREN);
    setState(59);
    compound_statement();
   
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
  enterRule(_localctx, 8, CSubsetParser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(67);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::CompoundStmtBodyContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(61);
      match(CSubsetParser::LCURL);
      setState(62);
      statements(0);
      setState(63);
      match(CSubsetParser::RCURL);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::CompoundStmtEmptyContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(65);
      match(CSubsetParser::LCURL);
      setState(66);
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
  enterRule(_localctx, 10, CSubsetParser::RuleVar_declaration);

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
    setState(69);
    type_specifier();
    setState(70);
    declaration_list(0);
    setState(71);
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
  enterRule(_localctx, 12, CSubsetParser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::INT: {
        _localctx = _tracker.createInstance<CSubsetParser::TypeIntContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(73);
        match(CSubsetParser::INT);
        break;
      }

      case CSubsetParser::VOID: {
        _localctx = _tracker.createInstance<CSubsetParser::TypeVoidContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(74);
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

CSubsetParser::Declaration_listContext* CSubsetParser::declaration_list() {
   return declaration_list(0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  CSubsetParser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, CSubsetParser::RuleDeclaration_list, precedence);

    

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
    _localctx = _tracker.createInstance<DeclListSingleIdContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(78);
    match(CSubsetParser::ID);
    _ctx->stop = _input->LT(-1);
    setState(85);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<DeclListCommaIdContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
        setState(80);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(81);
        match(CSubsetParser::COMMA);
        setState(82);
        match(CSubsetParser::ID); 
      }
      setState(87);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
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
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, CSubsetParser::RuleStatements, precedence);

    

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

    setState(89);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(95);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<StmtSeqContext>(_tracker.createInstance<StatementsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleStatements);
        setState(91);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(92);
        statement(); 
      }
      setState(97);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
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
CSubsetParser::StatementContext* CSubsetParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 18, CSubsetParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(110);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::INT:
      case CSubsetParser::VOID: {
        _localctx = _tracker.createInstance<CSubsetParser::StmtVarDeclContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(98);
        var_declaration();
        break;
      }

      case CSubsetParser::LPAREN:
      case CSubsetParser::SEMICOLON:
      case CSubsetParser::ADDOP:
      case CSubsetParser::NOT:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::StmtExprContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(99);
        expression_statement();
        break;
      }

      case CSubsetParser::LCURL: {
        _localctx = _tracker.createInstance<CSubsetParser::StmtCompoundContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(100);
        compound_statement();
        break;
      }

      case CSubsetParser::PRINTLN: {
        _localctx = _tracker.createInstance<CSubsetParser::StmtPrintlnContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(101);
        match(CSubsetParser::PRINTLN);
        setState(102);
        match(CSubsetParser::LPAREN);
        setState(103);
        match(CSubsetParser::ID);
        setState(104);
        match(CSubsetParser::RPAREN);
        setState(105);
        match(CSubsetParser::SEMICOLON);
        break;
      }

      case CSubsetParser::RETURN: {
        _localctx = _tracker.createInstance<CSubsetParser::StmtReturnContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(106);
        match(CSubsetParser::RETURN);
        setState(107);
        expression();
        setState(108);
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
  enterRule(_localctx, 20, CSubsetParser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(116);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::SEMICOLON: {
        _localctx = _tracker.createInstance<CSubsetParser::ExprStmtEmptyContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(112);
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
        setState(113);
        expression();
        setState(114);
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
  enterRule(_localctx, 22, CSubsetParser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<CSubsetParser::VarSimpleContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(CSubsetParser::ID);
   
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
  enterRule(_localctx, 24, CSubsetParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(125);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::ExprLogicContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(120);
      logic_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::ExprAssignContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(121);
      variable();
      setState(122);
      match(CSubsetParser::ASSIGNOP);
      setState(123);
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
  enterRule(_localctx, 26, CSubsetParser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(132);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::LogicRelContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(127);
      rel_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::LogicOpContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(128);
      rel_expression();
      setState(129);
      match(CSubsetParser::LOGICOP);
      setState(130);
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
  enterRule(_localctx, 28, CSubsetParser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(139);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::RelSimpleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(134);
      simple_expression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::RelOpContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(135);
      simple_expression(0);
      setState(136);
      match(CSubsetParser::RELOP);
      setState(137);
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
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, CSubsetParser::RuleSimple_expression, precedence);

    

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

    setState(142);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(149);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<SimpleAddOpContext>(_tracker.createInstance<Simple_expressionContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleSimple_expression);
        setState(144);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(145);
        match(CSubsetParser::ADDOP);
        setState(146);
        term(0); 
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
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, CSubsetParser::RuleTerm, precedence);

    

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

    setState(153);
    unary_expression();
    _ctx->stop = _input->LT(-1);
    setState(160);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<TermMulOpContext>(_tracker.createInstance<TermContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleTerm);
        setState(155);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(156);
        match(CSubsetParser::MULOP);
        setState(157);
        unary_expression(); 
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
  enterRule(_localctx, 34, CSubsetParser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(168);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::ADDOP: {
        _localctx = _tracker.createInstance<CSubsetParser::UnaryAddOpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(163);
        match(CSubsetParser::ADDOP);
        setState(164);
        unary_expression();
        break;
      }

      case CSubsetParser::NOT: {
        _localctx = _tracker.createInstance<CSubsetParser::UnaryNotContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(165);
        match(CSubsetParser::NOT);
        setState(166);
        unary_expression();
        break;
      }

      case CSubsetParser::LPAREN:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::UnaryFactorContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(167);
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
  enterRule(_localctx, 36, CSubsetParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(183);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorVarContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(170);
      variable();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorParenContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(171);
      match(CSubsetParser::LPAREN);
      setState(172);
      expression();
      setState(173);
      match(CSubsetParser::RPAREN);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorConstIntContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(175);
      match(CSubsetParser::CONST_INT);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorConstFloatContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(176);
      match(CSubsetParser::CONST_FLOAT);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorIncopContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(177);
      variable();
      setState(178);
      match(CSubsetParser::INCOP);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CSubsetParser::FactorDecopContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(180);
      variable();
      setState(181);
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

bool CSubsetParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 7: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 8: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 15: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 16: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);

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

bool CSubsetParser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

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
