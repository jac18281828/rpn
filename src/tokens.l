%{
using namespace std;
extern "C" int yylex(void);
#include "rpn.hpp"
%}

%%
[ \t] ;     /* ignore */

[0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)     { 
  yylval.value = atof(yytext); 
  return NUMBER; 
};

\"[^"]+\" { yylval.str = yytext; return STRING; };

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

"$"     { return 0; /* EOF */ }

\n         |
.          return yytext[0];
%%
