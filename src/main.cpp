#include <cstdlib>
#include "machine.h"

extern "C" int yyparse(void);

Machine *machine;

int main(int argc, char* argv[]) {
  machine = new Machine();

  while(yyparse() != 0);

  delete(machine);

  return EXIT_SUCCESS;
}
