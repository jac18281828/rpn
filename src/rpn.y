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
    along with RPN.  If not, see <https://www.gnu.org/licenses/>.

*/
%{
  extern "C" {
    int yylex(void);
    int yyparse(void);
    int yywrap(void);
  }

  using namespace std;

#include <memory>

#include "errorhandler.h"
#include "machine.h"
#include "bifun.h"
#include "biop.h"
#include "ufun.h"
#include "uop.h"
#include "rpn.h"

  using machine_t = rpn::machine_t;

  extern rpn::machine<machine_t> machine;

  extern std::unique_ptr<rpn::errorhandler> errorhandler;
    
  static void yyerror(const char *s) {
      errorhandler.get()->error(s);
  }

  static void bieval(rpn::biop<machine_t> const &op) {
      try {
          const rpn::bifun<machine_t, rpn::biop<machine_t>> bifun_eval;
          bifun_eval.eval(machine, op);
      } catch(rpn::underflow const &ex) {
          errorhandler.get()->underflow();
      } catch(std::exception const &ex) {
          errorhandler.get()->error("unexpected error.");
      }
      
  }

  static void ueval(rpn::uop<machine_t> const &op) {
      try {      
          const rpn::ufun<machine_t, rpn::uop<machine_t>> ufun_eval;
          ufun_eval.eval(machine, op);
      } catch(rpn::underflow const &ex) {
          errorhandler.get()->underflow();
      } catch(std::exception const &ex) {
          errorhandler.get()->error("unexpected error.");
      }
      
  }

%}

%union {
    double value;
    const char* str;
    int    token;
}

%token <sp>    SPACE;
%token <str>   STRING;
%token <value> NUMBER;
%type  <value> val;
%type  <str>   lit;
%token <token> DROP DEPTH SWAP CLEAR ABS SQRT CBRT SQ EXP LN LOG ALOG ROOTX POW INV RAND SIN ASIN COS ACOS TAN ATAN NEG PRINT COSH SINH TANH ACOSH ASINH ATANH MOD CEIL FLOOR TRUNC ROUND MIN MAX DIGITS;

%%
multi_ops: operation
| multi_ops operation
;

operation:
val sp {
    machine.push($1);
}
| val '+' '\n' {
    machine.push($1);
    bieval(rpn::addop<machine_t>());
    machine.print();
}
| val '-' '\n' {
    machine.push($1);
    bieval(rpn::subop<machine_t>());
    machine.print();
}
| val '*' '\n' {
    machine.push($1);
    bieval(rpn::mulop<machine_t>());
    machine.print();
}
| val '/' '\n' {
    machine.push($1);    
    bieval(rpn::divop<machine_t>());
    machine.print();    
}
| val '\n' {
    machine.push($1);
    machine.print();
}
| lit '\n' {
    machine.push($1);
    machine.print();    
}
| cmd sp { }
| cmd '\n' {
    machine.print();
}
;

val:     
NUMBER
;

lit:
STRING
;

sp:
SPACE
;

cmd:
| '+' { bieval(rpn::addop<machine_t>()); }
| '-' { bieval(rpn::subop<machine_t>()); }
| '*' { bieval(rpn::mulop<machine_t>()); }
| '/' { bieval(rpn::divop<machine_t>()); }
| ROOTX { bieval(rpn::rootxop<machine_t>()); }
| POW   { bieval(rpn::powop<machine_t>()); }
| ABS   { ueval(rpn::absop<machine_t>()); }
| SQRT  { ueval(rpn::sqrtop<machine_t>()); }
| CBRT  { ueval(rpn::cbrtop<machine_t>()); }
| SQ    { ueval(rpn::sqop<machine_t>()); }
| EXP   { ueval(rpn::expop<machine_t>()); }
| LN    { ueval(rpn::lnop<machine_t>()); }
| LOG   { ueval(rpn::logop<machine_t>()); }
| ALOG  { ueval(rpn::alogop<machine_t>()); }
| INV   { ueval(rpn::invop<machine_t>()); }
| SIN   { ueval(rpn::sinop<machine_t>()); }
| ASIN  { ueval(rpn::asinop<machine_t>()); }
| COS   { ueval(rpn::cosop<machine_t>()); }
| ACOS  { ueval(rpn::acosop<machine_t>()); }
| TAN   { ueval(rpn::tanop<machine_t>()); }
| ATAN  { ueval(rpn::atanop<machine_t>()); }
| NEG   { ueval(rpn::negop<machine_t>()); }
| COSH   { ueval(rpn::coshop<machine_t>()); }
| ACOSH   { ueval(rpn::acoshop<machine_t>()); }
| SINH   { ueval(rpn::sinhop<machine_t>()); }
| ASINH   { ueval(rpn::asinhop<machine_t>()); }
| TANH   { ueval(rpn::tanhop<machine_t>()); }
| ATANH   { ueval(rpn::atanhop<machine_t>()); }
| CEIL   { ueval(rpn::ceilop<machine_t>()); }
| FLOOR   { ueval(rpn::floorop<machine_t>()); }
| TRUNC   { ueval(rpn::truncop<machine_t>()); }
| ROUND   { ueval(rpn::roundop<machine_t>()); }
| MOD   { bieval(rpn::modop<machine_t>()); }
| MIN   { bieval(rpn::minop<machine_t>()); }
| MAX   { bieval(rpn::maxop<machine_t>()); }
| DROP    { machine.drop(); }
| SWAP    { machine.swap(); }
| CLEAR   { machine.clear(); }
| DEPTH   { machine.depth(); }
| RAND    { machine.rand(); }
| DIGITS    { machine.digits(); }
| PRINT    { }
;
