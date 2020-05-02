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

#include <cmath>

namespace rpn {

    template <typename D>
    class biop {
    public:
        virtual D eval(const D d1, const D d2) const = 0;
    };

    template <typename D>
    class addop : public biop<D> {
    public:
        virtual D eval(const D d1, const D d2) const {
            return d1 + d2;
        }
    };

    template <typename D>
    class subop : public biop<D> {
    public:
        virtual D eval(const D d1, const D d2) const {
            return d1 - d2;
        }
    };

    template <typename D>
    class mulop : public biop<D> {
    public:
        virtual D eval(const D d1, const D d2) const {
            return d1 * d2;
        }
    };
    
    template <typename D>
    class divop : public biop<D> {
    public:
        virtual D eval(const D d1, const D d2) const {
            return d1 / d2;
        }
    };

    template <typename D>
    class rootxop : public biop<D> {
    public:
        virtual D eval(const D d1, const D d2) const {
            return ::pow(d1, 1.0/d2);
        }
    };

    template <typename D>
    class powop : public biop<D> {
    public:
        virtual D eval(const D d1, const D d2) const {
            return ::pow(d1, d2);
        }
    };
    
}
