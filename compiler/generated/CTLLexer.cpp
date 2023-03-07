
#include "CTLParser.h"


// Generated from D:/4_project/CTL/compiler/CTLLexer.g4 by ANTLR 4.12.0


#include "CTLLexer.h"


#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif


using namespace antlr4;

using namespace ctlFront;


using namespace antlr4;

namespace {

struct CTLLexerStaticData final {
  CTLLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CTLLexerStaticData(const CTLLexerStaticData&) = delete;
  CTLLexerStaticData(CTLLexerStaticData&&) = delete;
  CTLLexerStaticData& operator=(const CTLLexerStaticData&) = delete;
  CTLLexerStaticData& operator=(CTLLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag ctllexerLexerOnceFlag;
CTLLexerStaticData *ctllexerLexerStaticData = nullptr;

void ctllexerLexerInitialize() {
  assert(ctllexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<CTLLexerStaticData>(
    std::vector<std::string>{
      "CrowdTask", "Constraints", "Class", "LPAREN", "RPAREN", "LBRACE", 
      "RBRACE", "LBRACK", "RBRACK", "COMMA", "DOT", "COLON", "ASSIGN", "GT", 
      "LT", "EQUAL", "GE", "LE", "NOTEQUAL", "AND", "OR", "ADD", "SUB", 
      "MUL", "DIV", "MOD", "ARROW", "IntegerLiteral", "DecimalLiteral", 
      "HexLiteral", "OctLiteral", "FloatLiteral", "HexFLoatLiteral", "StringLiteral", 
      "BoolLiteral", "Identifier", "NEWLINE", "SKIP_", "SPACES", "StringElement", 
      "CharEscapeSeq", "HexDigits", "HexDigit", "ExponetPart", "Digits", 
      "LetterOrDigit", "Letter"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'CrowdTask'", "'Constraints'", "'class'", "'('", "')'", "'{'", 
      "'}'", "'['", "']'", "','", "'.'", "':'", "'='", "'>'", "'<'", "'=='", 
      "'>='", "'<='", "'!='", "'&&'", "'||'", "'+'", "'-'", "'*'", "'/'", 
      "'%'", "'->'"
    },
    std::vector<std::string>{
      "", "CrowdTask", "Constraints", "Class", "LPAREN", "RPAREN", "LBRACE", 
      "RBRACE", "LBRACK", "RBRACK", "COMMA", "DOT", "COLON", "ASSIGN", "GT", 
      "LT", "EQUAL", "GE", "LE", "NOTEQUAL", "AND", "OR", "ADD", "SUB", 
      "MUL", "DIV", "MOD", "ARROW", "IntegerLiteral", "DecimalLiteral", 
      "HexLiteral", "OctLiteral", "FloatLiteral", "HexFLoatLiteral", "StringLiteral", 
      "BoolLiteral", "Identifier", "NEWLINE", "SKIP_"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,38,378,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,1,0,1,0,1,0,1,0,1,0,1,0,
  	1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,7,
  	1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,
  	14,1,14,1,15,1,15,1,15,1,16,1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,18,1,
  	19,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,
  	25,1,25,1,26,1,26,1,26,1,27,1,27,1,27,3,27,188,8,27,1,28,1,28,1,28,3,
  	28,193,8,28,1,28,4,28,196,8,28,11,28,12,28,197,1,28,3,28,201,8,28,3,28,
  	203,8,28,1,28,3,28,206,8,28,1,29,1,29,1,29,1,29,5,29,212,8,29,10,29,12,
  	29,215,9,29,1,29,3,29,218,8,29,1,29,3,29,221,8,29,1,30,1,30,5,30,225,
  	8,30,10,30,12,30,228,9,30,1,30,1,30,5,30,232,8,30,10,30,12,30,235,9,30,
  	1,30,3,30,238,8,30,1,30,3,30,241,8,30,1,31,1,31,1,31,3,31,246,8,31,1,
  	31,1,31,3,31,250,8,31,1,31,3,31,253,8,31,1,31,3,31,256,8,31,1,31,1,31,
  	1,31,3,31,261,8,31,1,31,3,31,264,8,31,3,31,266,8,31,1,32,1,32,1,32,1,
  	32,3,32,272,8,32,1,32,3,32,275,8,32,1,32,1,32,3,32,279,8,32,1,32,1,32,
  	3,32,283,8,32,1,32,1,32,3,32,287,8,32,1,33,1,33,5,33,291,8,33,10,33,12,
  	33,294,9,33,1,33,1,33,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,3,
  	34,307,8,34,1,35,1,35,5,35,311,8,35,10,35,12,35,314,9,35,1,36,3,36,317,
  	8,36,1,36,1,36,3,36,321,8,36,1,36,3,36,324,8,36,1,36,1,36,1,37,1,37,1,
  	37,1,37,1,38,4,38,333,8,38,11,38,12,38,334,1,39,1,39,3,39,339,8,39,1,
  	40,1,40,1,40,1,41,1,41,1,41,5,41,347,8,41,10,41,12,41,350,9,41,1,41,3,
  	41,353,8,41,1,42,1,42,1,43,1,43,3,43,359,8,43,1,43,1,43,1,44,1,44,5,44,
  	365,8,44,10,44,12,44,368,9,44,1,44,3,44,371,8,44,1,45,1,45,3,45,375,8,
  	45,1,46,1,46,0,0,47,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,
  	11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,
  	45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,
  	34,69,35,71,36,73,37,75,38,77,0,79,0,81,0,83,0,85,0,87,0,89,0,91,0,93,
  	0,1,0,17,1,0,49,57,2,0,76,76,108,108,2,0,88,88,120,120,3,0,48,57,65,70,
  	97,102,4,0,48,57,65,70,95,95,97,102,1,0,48,55,2,0,48,55,95,95,4,0,68,
  	68,70,70,100,100,102,102,2,0,80,80,112,112,2,0,43,43,45,45,2,0,9,9,32,
  	32,2,0,32,33,35,127,8,0,34,34,39,39,92,92,98,98,102,102,110,110,114,114,
  	116,116,2,0,69,69,101,101,1,0,48,57,2,0,48,57,95,95,3,0,65,90,95,95,97,
  	122,409,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,
  	11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,
  	0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,
  	0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,
  	43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,
  	0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,
  	0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,
  	75,1,0,0,0,1,95,1,0,0,0,3,105,1,0,0,0,5,117,1,0,0,0,7,123,1,0,0,0,9,126,
  	1,0,0,0,11,129,1,0,0,0,13,132,1,0,0,0,15,135,1,0,0,0,17,138,1,0,0,0,19,
  	141,1,0,0,0,21,143,1,0,0,0,23,145,1,0,0,0,25,147,1,0,0,0,27,149,1,0,0,
  	0,29,151,1,0,0,0,31,153,1,0,0,0,33,156,1,0,0,0,35,159,1,0,0,0,37,162,
  	1,0,0,0,39,165,1,0,0,0,41,168,1,0,0,0,43,171,1,0,0,0,45,173,1,0,0,0,47,
  	175,1,0,0,0,49,177,1,0,0,0,51,179,1,0,0,0,53,181,1,0,0,0,55,187,1,0,0,
  	0,57,202,1,0,0,0,59,207,1,0,0,0,61,222,1,0,0,0,63,265,1,0,0,0,65,267,
  	1,0,0,0,67,288,1,0,0,0,69,306,1,0,0,0,71,308,1,0,0,0,73,320,1,0,0,0,75,
  	327,1,0,0,0,77,332,1,0,0,0,79,338,1,0,0,0,81,340,1,0,0,0,83,343,1,0,0,
  	0,85,354,1,0,0,0,87,356,1,0,0,0,89,362,1,0,0,0,91,374,1,0,0,0,93,376,
  	1,0,0,0,95,96,5,67,0,0,96,97,5,114,0,0,97,98,5,111,0,0,98,99,5,119,0,
  	0,99,100,5,100,0,0,100,101,5,84,0,0,101,102,5,97,0,0,102,103,5,115,0,
  	0,103,104,5,107,0,0,104,2,1,0,0,0,105,106,5,67,0,0,106,107,5,111,0,0,
  	107,108,5,110,0,0,108,109,5,115,0,0,109,110,5,116,0,0,110,111,5,114,0,
  	0,111,112,5,97,0,0,112,113,5,105,0,0,113,114,5,110,0,0,114,115,5,116,
  	0,0,115,116,5,115,0,0,116,4,1,0,0,0,117,118,5,99,0,0,118,119,5,108,0,
  	0,119,120,5,97,0,0,120,121,5,115,0,0,121,122,5,115,0,0,122,6,1,0,0,0,
  	123,124,5,40,0,0,124,125,6,3,0,0,125,8,1,0,0,0,126,127,5,41,0,0,127,128,
  	6,4,1,0,128,10,1,0,0,0,129,130,5,123,0,0,130,131,6,5,2,0,131,12,1,0,0,
  	0,132,133,5,125,0,0,133,134,6,6,3,0,134,14,1,0,0,0,135,136,5,91,0,0,136,
  	137,6,7,4,0,137,16,1,0,0,0,138,139,5,93,0,0,139,140,6,8,5,0,140,18,1,
  	0,0,0,141,142,5,44,0,0,142,20,1,0,0,0,143,144,5,46,0,0,144,22,1,0,0,0,
  	145,146,5,58,0,0,146,24,1,0,0,0,147,148,5,61,0,0,148,26,1,0,0,0,149,150,
  	5,62,0,0,150,28,1,0,0,0,151,152,5,60,0,0,152,30,1,0,0,0,153,154,5,61,
  	0,0,154,155,5,61,0,0,155,32,1,0,0,0,156,157,5,62,0,0,157,158,5,61,0,0,
  	158,34,1,0,0,0,159,160,5,60,0,0,160,161,5,61,0,0,161,36,1,0,0,0,162,163,
  	5,33,0,0,163,164,5,61,0,0,164,38,1,0,0,0,165,166,5,38,0,0,166,167,5,38,
  	0,0,167,40,1,0,0,0,168,169,5,124,0,0,169,170,5,124,0,0,170,42,1,0,0,0,
  	171,172,5,43,0,0,172,44,1,0,0,0,173,174,5,45,0,0,174,46,1,0,0,0,175,176,
  	5,42,0,0,176,48,1,0,0,0,177,178,5,47,0,0,178,50,1,0,0,0,179,180,5,37,
  	0,0,180,52,1,0,0,0,181,182,5,45,0,0,182,183,5,62,0,0,183,54,1,0,0,0,184,
  	188,3,57,28,0,185,188,3,59,29,0,186,188,3,61,30,0,187,184,1,0,0,0,187,
  	185,1,0,0,0,187,186,1,0,0,0,188,56,1,0,0,0,189,203,5,48,0,0,190,200,7,
  	0,0,0,191,193,3,89,44,0,192,191,1,0,0,0,192,193,1,0,0,0,193,201,1,0,0,
  	0,194,196,5,95,0,0,195,194,1,0,0,0,196,197,1,0,0,0,197,195,1,0,0,0,197,
  	198,1,0,0,0,198,199,1,0,0,0,199,201,3,89,44,0,200,192,1,0,0,0,200,195,
  	1,0,0,0,201,203,1,0,0,0,202,189,1,0,0,0,202,190,1,0,0,0,203,205,1,0,0,
  	0,204,206,7,1,0,0,205,204,1,0,0,0,205,206,1,0,0,0,206,58,1,0,0,0,207,
  	208,5,48,0,0,208,209,7,2,0,0,209,217,7,3,0,0,210,212,7,4,0,0,211,210,
  	1,0,0,0,212,215,1,0,0,0,213,211,1,0,0,0,213,214,1,0,0,0,214,216,1,0,0,
  	0,215,213,1,0,0,0,216,218,7,3,0,0,217,213,1,0,0,0,217,218,1,0,0,0,218,
  	220,1,0,0,0,219,221,7,1,0,0,220,219,1,0,0,0,220,221,1,0,0,0,221,60,1,
  	0,0,0,222,226,5,48,0,0,223,225,5,95,0,0,224,223,1,0,0,0,225,228,1,0,0,
  	0,226,224,1,0,0,0,226,227,1,0,0,0,227,229,1,0,0,0,228,226,1,0,0,0,229,
  	237,7,5,0,0,230,232,7,6,0,0,231,230,1,0,0,0,232,235,1,0,0,0,233,231,1,
  	0,0,0,233,234,1,0,0,0,234,236,1,0,0,0,235,233,1,0,0,0,236,238,7,5,0,0,
  	237,233,1,0,0,0,237,238,1,0,0,0,238,240,1,0,0,0,239,241,7,1,0,0,240,239,
  	1,0,0,0,240,241,1,0,0,0,241,62,1,0,0,0,242,243,3,89,44,0,243,245,5,46,
  	0,0,244,246,3,89,44,0,245,244,1,0,0,0,245,246,1,0,0,0,246,250,1,0,0,0,
  	247,248,5,46,0,0,248,250,3,89,44,0,249,242,1,0,0,0,249,247,1,0,0,0,250,
  	252,1,0,0,0,251,253,3,87,43,0,252,251,1,0,0,0,252,253,1,0,0,0,253,255,
  	1,0,0,0,254,256,7,7,0,0,255,254,1,0,0,0,255,256,1,0,0,0,256,266,1,0,0,
  	0,257,263,3,89,44,0,258,260,3,87,43,0,259,261,7,7,0,0,260,259,1,0,0,0,
  	260,261,1,0,0,0,261,264,1,0,0,0,262,264,7,7,0,0,263,258,1,0,0,0,263,262,
  	1,0,0,0,264,266,1,0,0,0,265,249,1,0,0,0,265,257,1,0,0,0,266,64,1,0,0,
  	0,267,268,5,48,0,0,268,278,7,2,0,0,269,271,3,83,41,0,270,272,5,46,0,0,
  	271,270,1,0,0,0,271,272,1,0,0,0,272,279,1,0,0,0,273,275,3,83,41,0,274,
  	273,1,0,0,0,274,275,1,0,0,0,275,276,1,0,0,0,276,277,5,46,0,0,277,279,
  	3,83,41,0,278,269,1,0,0,0,278,274,1,0,0,0,279,280,1,0,0,0,280,282,7,8,
  	0,0,281,283,7,9,0,0,282,281,1,0,0,0,282,283,1,0,0,0,283,284,1,0,0,0,284,
  	286,3,89,44,0,285,287,7,7,0,0,286,285,1,0,0,0,286,287,1,0,0,0,287,66,
  	1,0,0,0,288,292,5,34,0,0,289,291,3,79,39,0,290,289,1,0,0,0,291,294,1,
  	0,0,0,292,290,1,0,0,0,292,293,1,0,0,0,293,295,1,0,0,0,294,292,1,0,0,0,
  	295,296,5,34,0,0,296,68,1,0,0,0,297,298,5,116,0,0,298,299,5,114,0,0,299,
  	300,5,117,0,0,300,307,5,101,0,0,301,302,5,102,0,0,302,303,5,97,0,0,303,
  	304,5,108,0,0,304,305,5,115,0,0,305,307,5,101,0,0,306,297,1,0,0,0,306,
  	301,1,0,0,0,307,70,1,0,0,0,308,312,3,93,46,0,309,311,3,91,45,0,310,309,
  	1,0,0,0,311,314,1,0,0,0,312,310,1,0,0,0,312,313,1,0,0,0,313,72,1,0,0,
  	0,314,312,1,0,0,0,315,317,5,13,0,0,316,315,1,0,0,0,316,317,1,0,0,0,317,
  	318,1,0,0,0,318,321,5,10,0,0,319,321,2,12,13,0,320,316,1,0,0,0,320,319,
  	1,0,0,0,321,323,1,0,0,0,322,324,3,77,38,0,323,322,1,0,0,0,323,324,1,0,
  	0,0,324,325,1,0,0,0,325,326,6,36,6,0,326,74,1,0,0,0,327,328,3,77,38,0,
  	328,329,1,0,0,0,329,330,6,37,7,0,330,76,1,0,0,0,331,333,7,10,0,0,332,
  	331,1,0,0,0,333,334,1,0,0,0,334,332,1,0,0,0,334,335,1,0,0,0,335,78,1,
  	0,0,0,336,339,7,11,0,0,337,339,3,81,40,0,338,336,1,0,0,0,338,337,1,0,
  	0,0,339,80,1,0,0,0,340,341,5,92,0,0,341,342,7,12,0,0,342,82,1,0,0,0,343,
  	352,3,85,42,0,344,347,3,85,42,0,345,347,5,95,0,0,346,344,1,0,0,0,346,
  	345,1,0,0,0,347,350,1,0,0,0,348,346,1,0,0,0,348,349,1,0,0,0,349,351,1,
  	0,0,0,350,348,1,0,0,0,351,353,3,85,42,0,352,348,1,0,0,0,352,353,1,0,0,
  	0,353,84,1,0,0,0,354,355,7,3,0,0,355,86,1,0,0,0,356,358,7,13,0,0,357,
  	359,7,9,0,0,358,357,1,0,0,0,358,359,1,0,0,0,359,360,1,0,0,0,360,361,3,
  	89,44,0,361,88,1,0,0,0,362,370,7,14,0,0,363,365,7,15,0,0,364,363,1,0,
  	0,0,365,368,1,0,0,0,366,364,1,0,0,0,366,367,1,0,0,0,367,369,1,0,0,0,368,
  	366,1,0,0,0,369,371,7,14,0,0,370,366,1,0,0,0,370,371,1,0,0,0,371,90,1,
  	0,0,0,372,375,3,93,46,0,373,375,7,14,0,0,374,372,1,0,0,0,374,373,1,0,
  	0,0,375,92,1,0,0,0,376,377,7,16,0,0,377,94,1,0,0,0,41,0,187,192,197,200,
  	202,205,213,217,220,226,233,237,240,245,249,252,255,260,263,265,271,274,
  	278,282,286,292,306,312,316,320,323,334,338,346,348,352,358,366,370,374,
  	8,1,3,0,1,4,1,1,5,2,1,6,3,1,7,4,1,8,5,1,36,6,0,1,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ctllexerLexerStaticData = staticData.release();
}

}

CTLLexer::CTLLexer(CharStream *input) : Lexer(input) {
  CTLLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *ctllexerLexerStaticData->atn, ctllexerLexerStaticData->decisionToDFA, ctllexerLexerStaticData->sharedContextCache);
}

CTLLexer::~CTLLexer() {
  delete _interpreter;
}

std::string CTLLexer::getGrammarFileName() const {
  return "CTLLexer.g4";
}

const std::vector<std::string>& CTLLexer::getRuleNames() const {
  return ctllexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CTLLexer::getChannelNames() const {
  return ctllexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CTLLexer::getModeNames() const {
  return ctllexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CTLLexer::getVocabulary() const {
  return ctllexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CTLLexer::getSerializedATN() const {
  return ctllexerLexerStaticData->serializedATN;
}

const atn::ATN& CTLLexer::getATN() const {
  return *ctllexerLexerStaticData->atn;
}


void CTLLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 3: LPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 4: RPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 5: LBRACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 6: RBRACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: LBRACKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: RBRACKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 36: NEWLINEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void CTLLexer::LPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0: m_opened++; break;

  default:
    break;
  }
}

void CTLLexer::RPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1: m_opened--; break;

  default:
    break;
  }
}

void CTLLexer::LBRACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2: /*m_opened++;*/ break;

  default:
    break;
  }
}

void CTLLexer::RBRACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3: /*m_opened--;*/ break;

  default:
    break;
  }
}

void CTLLexer::LBRACKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4: m_opened++; break;

  default:
    break;
  }
}

void CTLLexer::RBRACKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5: m_opened--; break;

  default:
    break;
  }
}

void CTLLexer::NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6: 
            {
                std::string newline, spaces;
                std::string text = getText();
                for (char c: text){
                    if ((c == '\r') || (c == '\n') || (c == '\f')) {
                        newline.push_back(c);
                    } else {
                        spaces.push_back(c);
                    }
                }
                int next = _input->LA(1);
                int nextnext = _input->LA(2);
                if (m_opened > 0 || (nextnext != -1 && (next == '\r' || next == '\n' ||next == '\f' ||next == '#' ) ) ) {
                    // The part of the block that requires indentation to distinguish code exists
                    // only within the CrowdTask, where m_opened is 1
                    emit(commonToken(SKIP_, newline));
                } else {
                    int indent = getIndentationCount(spaces);
                    int previous = m_indents.empty() ? 0 : m_indents.top();
                    if (indent == previous){
                        emit(commonToken(SKIP_, text));
                    } else if(indent > previous) {
                        emit(commonToken(NEWLINE, ";" + newline));
                        m_indents.push(indent);
                        emit(commonToken(SKIP_, spaces));
                        emit(commonToken(ctlFront::CTLParser::INDENT, "<"+ std::to_string(indent)+"<"));
                    } else {
                        emit(commonToken(NEWLINE, ";" + newline));
                        while (!m_indents.empty() && m_indents.top() > indent) {
                            emit(commonToken(SKIP_, std::string(m_indents.top(), ' ')));
                            emit(createDedent(m_indents.top()));
                            emit(commonToken(SKIP_, "\n"));
                            m_indents.pop();
                        }
                        emit(commonToken(SKIP_, std::string(indent, ' ')));
                    }
                }
            }
         break;

  default:
    break;
  }
}



void CTLLexer::initialize() {
  ::antlr4::internal::call_once(ctllexerLexerOnceFlag, ctllexerLexerInitialize);
}
