#pragma once

#include <string>

namespace rpn {

    class errorhandler {
    public:
        
        virtual void error(std::string const &message) const = 0;
        
        virtual void underflow(void) const = 0;

    };
    
}


