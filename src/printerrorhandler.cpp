#include <cstdlib>
#include <iostream>
#include "printerrorhandler.h"

using namespace rpn;

void printerrorhandler::error(std::string const &message) const {
    std::cerr << "Error: " << message << std::endl;
    ::abort();
}

void printerrorhandler::underflow(void) const {
    std::cerr << "underflow." << std::endl;
}

