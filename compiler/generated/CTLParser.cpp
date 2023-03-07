
// Generated from D:/4_project/CTL/compiler/CTLParser.g4 by ANTLR 4.12.0


#include "CTLParserListener.h"
#include "CTLParserVisitor.h"

#include "CTLParser.h"


using namespace antlrcpp;
using namespace ctlFront;

using namespace antlr4;

namespace {

struct CTLParserStaticData final {
  CTLParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CTLParserStaticData(const CTLParserStaticData&) = delete;
  CTLParserStaticData(CTLParserStaticData&&) = delete;
  CTLParserStaticData& operator=(const CTLParserStaticData&) = delete;
  CTLParserStaticData& operator=(CTLParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ctlparserParserOnceFlag;
CTLParserStaticData *ctlparserParserStaticData = nullptr;

void ctlparserParserInitialize() {
  assert(ctlparserParserStaticData == nullptr);
  auto staticData = std::make_unique<CTLParserStaticData>(
    std::vector<std::string>{
      "main"
    },
    std::vector<std::string>{
    },
    std::vector<std::string>{
      "", "INDENT", "DEDENT", "Identifier"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,3,5,2,0,7,0,1,0,1,0,1,0,0,0,1,0,0,0,3,0,2,1,0,0,0,2,3,5,3,0,0,3,1,
  	1,0,0,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ctlparserParserStaticData = staticData.release();
}

}

CTLParser::CTLParser(TokenStream *input) : CTLParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CTLParser::CTLParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CTLParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *ctlparserParserStaticData->atn, ctlparserParserStaticData->decisionToDFA, ctlparserParserStaticData->sharedContextCache, options);
}

CTLParser::~CTLParser() {
  delete _interpreter;
}

const atn::ATN& CTLParser::getATN() const {
  return *ctlparserParserStaticData->atn;
}

std::string CTLParser::getGrammarFileName() const {
  return "CTLParser.g4";
}

const std::vector<std::string>& CTLParser::getRuleNames() const {
  return ctlparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& CTLParser::getVocabulary() const {
  return ctlparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CTLParser::getSerializedATN() const {
  return ctlparserParserStaticData->serializedATN;
}


//----------------- MainContext ------------------------------------------------------------------

CTLParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CTLParser::MainContext::Identifier() {
  return getToken(CTLParser::Identifier, 0);
}


size_t CTLParser::MainContext::getRuleIndex() const {
  return CTLParser::RuleMain;
}

void CTLParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CTLParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void CTLParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CTLParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}


std::any CTLParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CTLParserVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

CTLParser::MainContext* CTLParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, CTLParser::RuleMain);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2);
    match(CTLParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void CTLParser::initialize() {
  ::antlr4::internal::call_once(ctlparserParserOnceFlag, ctlparserParserInitialize);
}
