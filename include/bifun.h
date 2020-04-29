#pragma once

#include <memory>

#include "machine.h"

namespace rpn {

    template <typename D, class biop>
    class bifun {
    public:

        void eval(rpn::machine<D> &m, biop const &bop) const {

            auto el1 = m.pop();
            auto el2 = m.pop();

            auto val1 = std::get<D>(el2);
            auto val2 = std::get<D>(el1);

            m.push(bop.eval(val1, val2));
        }
        
    };
    
}
