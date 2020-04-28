%{
  extern "C" {
    int yylex(void);
    int yyparse(void);
    int yywrap(void);
  }

  using namespace std;

#include "machine.h"

  extern Machine* machine;

  void yyerror(const char *s) { cerr << "Error: " << s << endl; }
%}

%union {
  double value;
  const char* str;
  int    token;
}

%token <str>   STRING;
%token <value> NUMBER;
%token <token> DROP DEPTH SWAP CLEAR ACOS ABS ALOG;
%type  <value> exp;
%type  <str>   lit;

%%
multi_ops: operation
| multi_ops operation
;

operation: 
exp '+' '\n' {
  machine->push($1);
  machine->add();
  machine->print();
}
| exp '-' '\n' {
  machine->push($1);
  machine->sub();
  machine->print();
}
| exp '*' '\n' {
  machine->push($1);
  machine->mul();
  machine->print();
}
| exp '/' '\n' {
  machine->push($1);
  machine->div();
  machine->print();
}
| exp '\n' {
  machine->push($1);
  machine->print();
}
| lit '\n' {
  machine->push($1);
  machine->print();
}
| cmd '\n' {
  machine->print();
}
;

exp:     
NUMBER
;

lit:
STRING
;

cmd:
| '+'     { machine->add(); }
| '-'     { machine->sub(); }
| '*'     { machine->mul(); }
| '/'     { machine->div(); }
| ACOS    { machine->acos(); }
| ABS     { machine->abs(); }
| ALOG    { machine->alog(); }
| DROP    { machine->drop(); }
| SWAP    { machine->swap(); }
| CLEAR   { machine->clear(); }
| DEPTH   { machine->depth(); }
;
