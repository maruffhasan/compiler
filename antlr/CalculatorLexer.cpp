
// Generated from Calculator.g4 by ANTLR 4.13.2


#include "CalculatorLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct CalculatorLexerStaticData final {
  CalculatorLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CalculatorLexerStaticData(const CalculatorLexerStaticData&) = delete;
  CalculatorLexerStaticData(CalculatorLexerStaticData&&) = delete;
  CalculatorLexerStaticData& operator=(const CalculatorLexerStaticData&) = delete;
  CalculatorLexerStaticData& operator=(CalculatorLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag calculatorlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CalculatorLexerStaticData> calculatorlexerLexerStaticData = nullptr;

void calculatorlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (calculatorlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(calculatorlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CalculatorLexerStaticData>(
    std::vector<std::string>{
      "INT", "PLUS", "TIMES", "LPAREN", "RPAREN", "WHITESPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "'+'", "'*'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "INT", "PLUS", "TIMES", "LPAREN", "RPAREN", "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,6,33,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,4,0,
  	15,8,0,11,0,12,0,16,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,4,5,28,8,5,11,
  	5,12,5,29,1,5,1,5,0,0,6,1,1,3,2,5,3,7,4,9,5,11,6,1,0,2,1,0,48,57,3,0,
  	10,10,13,13,32,32,34,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,
  	0,9,1,0,0,0,0,11,1,0,0,0,1,14,1,0,0,0,3,18,1,0,0,0,5,20,1,0,0,0,7,22,
  	1,0,0,0,9,24,1,0,0,0,11,27,1,0,0,0,13,15,7,0,0,0,14,13,1,0,0,0,15,16,
  	1,0,0,0,16,14,1,0,0,0,16,17,1,0,0,0,17,2,1,0,0,0,18,19,5,43,0,0,19,4,
  	1,0,0,0,20,21,5,42,0,0,21,6,1,0,0,0,22,23,5,40,0,0,23,8,1,0,0,0,24,25,
  	5,41,0,0,25,10,1,0,0,0,26,28,7,1,0,0,27,26,1,0,0,0,28,29,1,0,0,0,29,27,
  	1,0,0,0,29,30,1,0,0,0,30,31,1,0,0,0,31,32,6,5,0,0,32,12,1,0,0,0,3,0,16,
  	29,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  calculatorlexerLexerStaticData = std::move(staticData);
}

}

CalculatorLexer::CalculatorLexer(CharStream *input) : Lexer(input) {
  CalculatorLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *calculatorlexerLexerStaticData->atn, calculatorlexerLexerStaticData->decisionToDFA, calculatorlexerLexerStaticData->sharedContextCache);
}

CalculatorLexer::~CalculatorLexer() {
  delete _interpreter;
}

std::string CalculatorLexer::getGrammarFileName() const {
  return "Calculator.g4";
}

const std::vector<std::string>& CalculatorLexer::getRuleNames() const {
  return calculatorlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CalculatorLexer::getChannelNames() const {
  return calculatorlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CalculatorLexer::getModeNames() const {
  return calculatorlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CalculatorLexer::getVocabulary() const {
  return calculatorlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CalculatorLexer::getSerializedATN() const {
  return calculatorlexerLexerStaticData->serializedATN;
}

const atn::ATN& CalculatorLexer::getATN() const {
  return *calculatorlexerLexerStaticData->atn;
}




void CalculatorLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  calculatorlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(calculatorlexerLexerOnceFlag, calculatorlexerLexerInitialize);
#endif
}
