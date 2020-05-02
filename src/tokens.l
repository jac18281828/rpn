%{
using namespace std;
extern "C" int yylex(void);
#include "rpn.hpp"
%}

%%
[ \t] { return SPACE; };

[0-9]+|([0-9]*\.[0-9]+)?([eE][-+]?[0-9]+)     { 
  yylval.value = atof(yytext); 
  return NUMBER; 
};

\"[^"]+\" { yylval.str = yytext; return STRING; };

"e"  { 
    yylval.value = 2.71828182845904523536;
    return yylval.token = NUMBER; 
}

"pi"  { 
    yylval.value = 3.1415926535897932384;
    return yylval.token = NUMBER; 
}

"drop"  { return yylval.token = DROP; }
"depth" { return yylval.token = DEPTH; }
"swap"  { return yylval.token = SWAP; }
"clear"  { return yylval.token = CLEAR; }
"abs"  { return yylval.token = ABS; }
"sqrt" { return yylval.token = SQRT; }
"cbrt" { return yylval.token = CBRT; }
"sq" { return yylval.token = SQ; }
"exp" { return yylval.token = EXP; }
"ln" { return yylval.token = LN; }
"log" { return yylval.token = LOG; }
"alog" { return yylval.token = ALOG; }
"rootx" { return yylval.token = ROOTX; }
"pow" { return yylval.token = POW; }
"inv" { return yylval.token = INV; }
"rand" { return yylval.token = RAND; }
"sin" { return yylval.token = SIN; }
"asin" { return yylval.token = ASIN; }
"cos" { return yylval.token = COS; }
"acos" { return yylval.token = ACOS; }
"tan" { return yylval.token = TAN; }
"atan" { return yylval.token = ATAN; }
"neg" { return yylval.token = NEG; }
"print" { return yylval.token = PRINT; }

"$"     { return 0; /* EOF */ }

\n         |
.          return yytext[0];

%%
