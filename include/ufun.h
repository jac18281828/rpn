#pragma once

#include <memory>

#include "machine.h"

namespace rpn {

    template <typename D, class uop>
    class ufun {
    public:
        void eval(rpn::machine<D> &m, uop const &u) const {
            const auto stele = m.pop();
            const auto val   = std::get<D>(stele);
            m.push(u.eval(val));
        }
    };
    
}
