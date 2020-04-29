#pragma once

#include <string>

#include "errorhandler.h"

namespace rpn {
    class printerrorhandler : public errorhandler {
    public:
        void error(std::string const &message) const;

        void underflow(void) const;
    };
}


