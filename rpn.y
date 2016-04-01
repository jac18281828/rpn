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
  int    token;
}

%token <value> NUMBER;
%token <token> DROP SWAP CLEAR ACOS ABS;
%type  <value> exp;

%%
multi_ops: operation
| multi_ops operation
;

operation: 
exp '\n' {
  machine->push($1);
  machine->print();
}
| cmd '\n' {
  machine->print();
}
;

exp:     
NUMBER
| exp '+' {  $$ = machine->add($1); }
| exp '-' {  $$ = machine->sub($1); }
| exp '*' {  $$ = machine->mul($1); }
| exp '/' {  $$ = machine->div($1); }
| '+'     {  $$ = machine->add(); }
| '-'     {  $$ = machine->sub(); }
| '*'     {  $$ = machine->mul(); }
| '/'     {  $$ = machine->div(); }
| ACOS    {  $$ = machine->acos(); }
| ABS     {  $$ = machine->abs(); }
;

cmd:
DROP { machine->drop(); }
| SWAP {  machine->swap();  }
| CLEAR { machine->clear(); }
;
