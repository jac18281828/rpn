#include <memory>
#include <cstdlib>

#include "printerrorhandler.h"
#include "errorhandler.h"
#include "machine.h"
#include "rpn.h"

extern "C" int yyparse(void);

rpn::machine<rpn::machine_t> machine;

std::unique_ptr<rpn::errorhandler> errorhandler;

int main(int argc, char* argv[]) {

    errorhandler = std::make_unique<rpn::printerrorhandler>();

    while(yyparse() != 0);

    ::exit(EXIT_SUCCESS);
}
