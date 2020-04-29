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
          machine.print();
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
          machine.print();
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

%token <str>   STRING;
%token <value> NUMBER;
%token <token> DROP DEPTH SWAP CLEAR ABS SQRT CBRT SQ EXP LN LOG ALOG ROOTX POW INV RAND SIN ASIN COS ACOS TAN ATAN NEG;
%type  <value> exp;
%type  <str>   lit;

%%
multi_ops: operation
| multi_ops operation
;

operation: 
exp '+' '\n' {
    machine.push($1);
    bieval(rpn::addop<machine_t>());
}
| exp '-' '\n' {
    machine.push($1);
    bieval(rpn::subop<machine_t>());
}
| exp '*' '\n' {
    machine.push($1);
    bieval(rpn::mulop<machine_t>());    
}
| exp '/' '\n' {
    machine.push($1);    
    bieval(rpn::divop<machine_t>());        
}
| exp '\n' {
    machine.push($1);
    machine.print();
}
| lit '\n' {
    machine.push($1);
    machine.print();
}
| cmd '\n' {
    machine.print();
}
;

exp:     
NUMBER
;

lit:
STRING
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
| DROP    { machine.drop(); }
| SWAP    { machine.swap(); }
| CLEAR   { machine.clear(); }
| DEPTH   { machine.depth(); }
| RAND    { machine.rand(); }
;
