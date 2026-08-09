
// Generated from Calculator.g4 by ANTLR 4.13.2


#include "CalculatorVisitor.h"

#include "CalculatorParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CalculatorParserStaticData final {
  CalculatorParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CalculatorParserStaticData(const CalculatorParserStaticData&) = delete;
  CalculatorParserStaticData(CalculatorParserStaticData&&) = delete;
  CalculatorParserStaticData& operator=(const CalculatorParserStaticData&) = delete;
  CalculatorParserStaticData& operator=(CalculatorParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag calculatorParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CalculatorParserStaticData> calculatorParserStaticData = nullptr;

void calculatorParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (calculatorParserStaticData != nullptr) {
    return;
  }
#else
  assert(calculatorParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CalculatorParserStaticData>(
    std::vector<std::string>{
      "start", "expression", "term", "factor"
    },
    std::vector<std::string>{
      "", "", "'+'", "'*'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "INT", "PLUS", "TIMES", "LPAREN", "RPAREN", "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,6,40,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,1,1,1,1,1,1,1,1,1,1,
  	1,1,5,1,17,8,1,10,1,12,1,20,9,1,1,2,1,2,1,2,1,2,1,2,1,2,5,2,28,8,2,10,
  	2,12,2,31,9,2,1,3,1,3,1,3,1,3,1,3,3,3,38,8,3,1,3,0,2,2,4,4,0,2,4,6,0,
  	0,38,0,8,1,0,0,0,2,10,1,0,0,0,4,21,1,0,0,0,6,37,1,0,0,0,8,9,3,2,1,0,9,
  	1,1,0,0,0,10,11,6,1,-1,0,11,12,3,4,2,0,12,18,1,0,0,0,13,14,10,2,0,0,14,
  	15,5,2,0,0,15,17,3,4,2,0,16,13,1,0,0,0,17,20,1,0,0,0,18,16,1,0,0,0,18,
  	19,1,0,0,0,19,3,1,0,0,0,20,18,1,0,0,0,21,22,6,2,-1,0,22,23,3,6,3,0,23,
  	29,1,0,0,0,24,25,10,2,0,0,25,26,5,3,0,0,26,28,3,6,3,0,27,24,1,0,0,0,28,
  	31,1,0,0,0,29,27,1,0,0,0,29,30,1,0,0,0,30,5,1,0,0,0,31,29,1,0,0,0,32,
  	33,5,4,0,0,33,34,3,2,1,0,34,35,5,5,0,0,35,38,1,0,0,0,36,38,5,1,0,0,37,
  	32,1,0,0,0,37,36,1,0,0,0,38,7,1,0,0,0,3,18,29,37
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  calculatorParserStaticData = std::move(staticData);
}

}

CalculatorParser::CalculatorParser(TokenStream *input) : CalculatorParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CalculatorParser::CalculatorParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CalculatorParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *calculatorParserStaticData->atn, calculatorParserStaticData->decisionToDFA, calculatorParserStaticData->sharedContextCache, options);
}

CalculatorParser::~CalculatorParser() {
  delete _interpreter;
}

const atn::ATN& CalculatorParser::getATN() const {
  return *calculatorParserStaticData->atn;
}

std::string CalculatorParser::getGrammarFileName() const {
  return "Calculator.g4";
}

const std::vector<std::string>& CalculatorParser::getRuleNames() const {
  return calculatorParserStaticData->ruleNames;
}

const dfa::Vocabulary& CalculatorParser::getVocabulary() const {
  return calculatorParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CalculatorParser::getSerializedATN() const {
  return calculatorParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

CalculatorParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CalculatorParser::ExpressionContext* CalculatorParser::StartContext::expression() {
  return getRuleContext<CalculatorParser::ExpressionContext>(0);
}


size_t CalculatorParser::StartContext::getRuleIndex() const {
  return CalculatorParser::RuleStart;
}


std::any CalculatorParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

CalculatorParser::StartContext* CalculatorParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, CalculatorParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(8);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CalculatorParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalculatorParser::ExpressionContext::getRuleIndex() const {
  return CalculatorParser::RuleExpression;
}

void CalculatorParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprTermContext ------------------------------------------------------------------

CalculatorParser::TermContext* CalculatorParser::ExprTermContext::term() {
  return getRuleContext<CalculatorParser::TermContext>(0);
}

CalculatorParser::ExprTermContext::ExprTermContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any CalculatorParser::ExprTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitExprTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusContext ------------------------------------------------------------------

CalculatorParser::ExpressionContext* CalculatorParser::PlusContext::expression() {
  return getRuleContext<CalculatorParser::ExpressionContext>(0);
}

tree::TerminalNode* CalculatorParser::PlusContext::PLUS() {
  return getToken(CalculatorParser::PLUS, 0);
}

CalculatorParser::TermContext* CalculatorParser::PlusContext::term() {
  return getRuleContext<CalculatorParser::TermContext>(0);
}

CalculatorParser::PlusContext::PlusContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any CalculatorParser::PlusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitPlus(this);
  else
    return visitor->visitChildren(this);
}

CalculatorParser::ExpressionContext* CalculatorParser::expression() {
   return expression(0);
}

CalculatorParser::ExpressionContext* CalculatorParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CalculatorParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  CalculatorParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, CalculatorParser::RuleExpression, precedence);

    

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
    _localctx = _tracker.createInstance<ExprTermContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(11);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(18);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<PlusContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleExpression);
        setState(13);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(14);
        match(CalculatorParser::PLUS);
        setState(15);
        term(0); 
      }
      setState(20);
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

//----------------- TermContext ------------------------------------------------------------------

CalculatorParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalculatorParser::TermContext::getRuleIndex() const {
  return CalculatorParser::RuleTerm;
}

void CalculatorParser::TermContext::copyFrom(TermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TimesContext ------------------------------------------------------------------

CalculatorParser::TermContext* CalculatorParser::TimesContext::term() {
  return getRuleContext<CalculatorParser::TermContext>(0);
}

tree::TerminalNode* CalculatorParser::TimesContext::TIMES() {
  return getToken(CalculatorParser::TIMES, 0);
}

CalculatorParser::FactorContext* CalculatorParser::TimesContext::factor() {
  return getRuleContext<CalculatorParser::FactorContext>(0);
}

CalculatorParser::TimesContext::TimesContext(TermContext *ctx) { copyFrom(ctx); }


std::any CalculatorParser::TimesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitTimes(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TermFactContext ------------------------------------------------------------------

CalculatorParser::FactorContext* CalculatorParser::TermFactContext::factor() {
  return getRuleContext<CalculatorParser::FactorContext>(0);
}

CalculatorParser::TermFactContext::TermFactContext(TermContext *ctx) { copyFrom(ctx); }


std::any CalculatorParser::TermFactContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitTermFact(this);
  else
    return visitor->visitChildren(this);
}

CalculatorParser::TermContext* CalculatorParser::term() {
   return term(0);
}

CalculatorParser::TermContext* CalculatorParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CalculatorParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  CalculatorParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, CalculatorParser::RuleTerm, precedence);

    

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
    _localctx = _tracker.createInstance<TermFactContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(22);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(29);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<TimesContext>(_tracker.createInstance<TermContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleTerm);
        setState(24);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(25);
        match(CalculatorParser::TIMES);
        setState(26);
        antlrcpp::downCast<TimesContext *>(_localctx)->f = factor(); 
      }
      setState(31);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
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

CalculatorParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalculatorParser::FactorContext::getRuleIndex() const {
  return CalculatorParser::RuleFactor;
}

void CalculatorParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FactorIntContext ------------------------------------------------------------------

tree::TerminalNode* CalculatorParser::FactorIntContext::INT() {
  return getToken(CalculatorParser::INT, 0);
}

CalculatorParser::FactorIntContext::FactorIntContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CalculatorParser::FactorIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitFactorInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenContext ------------------------------------------------------------------

tree::TerminalNode* CalculatorParser::ParenContext::LPAREN() {
  return getToken(CalculatorParser::LPAREN, 0);
}

CalculatorParser::ExpressionContext* CalculatorParser::ParenContext::expression() {
  return getRuleContext<CalculatorParser::ExpressionContext>(0);
}

tree::TerminalNode* CalculatorParser::ParenContext::RPAREN() {
  return getToken(CalculatorParser::RPAREN, 0);
}

CalculatorParser::ParenContext::ParenContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CalculatorParser::ParenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalculatorVisitor*>(visitor))
    return parserVisitor->visitParen(this);
  else
    return visitor->visitChildren(this);
}
CalculatorParser::FactorContext* CalculatorParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 6, CalculatorParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(37);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CalculatorParser::LPAREN: {
        _localctx = _tracker.createInstance<CalculatorParser::ParenContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(32);
        match(CalculatorParser::LPAREN);
        setState(33);
        expression(0);
        setState(34);
        match(CalculatorParser::RPAREN);
        break;
      }

      case CalculatorParser::INT: {
        _localctx = _tracker.createInstance<CalculatorParser::FactorIntContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(36);
        match(CalculatorParser::INT);
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

bool CalculatorParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);
    case 2: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CalculatorParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CalculatorParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void CalculatorParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  calculatorParserInitialize();
#else
  ::antlr4::internal::call_once(calculatorParserOnceFlag, calculatorParserInitialize);
#endif
}
