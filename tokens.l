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

"depth" { return yylval.token = DEPTH; }
"drop"  { return yylval.token = DROP; }
"swap"  { return yylval.token = SWAP; }
"clear"  { return yylval.token = CLEAR; }
"acos"  { return yylval.token = ACOS; }
"abs"  { return yylval.token = ABS; }
"alog" { return yylval.token = ALOG; }

"$"     { return 0; /* EOF */ }

\n         |
.          return yytext[0];
%%
