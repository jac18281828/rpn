/*

    Copyright © John A Cairns <john@2ad.com> 2016-2020

    This file is part of RPN.

    RPN is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RPN is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <https://www.gnu.org/licenses/>.

*/

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
