/*

    Copyright © John A Cairns <john@2ad.com> 2016-2020

    This file is part of RPN.

    RPN is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RPN is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <https://www.gnu.org/licenses/>.

*/
%{
using namespace std;
extern "C" int yylex(void);
#include "rpn.hpp"
%}

%option caseless

%%
[ \t] { return SPACE; };

-?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) { 
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
"cosh" { return yylval.token = COSH; }
"acosh" { return yylval.token = ACOSH; }
"sinh" { return yylval.token = SINH; }
"asinh" { return yylval.token = ASINH; }
"tanh" { return yylval.token = TANH; }
"atanh" { return yylval.token = ATANH; }
"ceil" { return yylval.token = CEIL; }
"floor" { return yylval.token = FLOOR; }
"trunc" { return yylval.token = TRUNC; }
"round" { return yylval.token = ROUND; }
"mod" { return yylval.token = MOD; }
"min" { return yylval.token = MIN; }
"max" { return yylval.token = MAX; }
"digits" { return yylval.token = DIGITS; }

"$"     { return 0; /* EOF */ }

\n         |
   [-+/*]          return yytext[0];
   
.       { /* ignore */ }

%%
