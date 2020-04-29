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
