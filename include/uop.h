#pragma once

#include <cmath>

namespace rpn {

    template <typename D>
    class uop {
    public:
        virtual D eval(const D d) const = 0;
    };

    template <typename D>
    class absop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return ::abs(d);
        }
    };

    template <typename D>
    class sqrtop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return ::sqrt(d);
        }
    };

    template <typename D>
    class cbrtop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return ::cbrt(d);
        }
    };

    template <typename D>
    class sqop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return d*d;
        }
    };

    template <typename D>
    class expop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return ::exp(d);
        }
    };

    template <typename D>
    class lnop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return ::log(d);
        }
    };

    template <typename D>
    class logop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return ::log10(d);
        }
    };

    template <typename D>
    class alogop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return ::pow(10.0, d);
        }
    };

    template <typename D>
    class invop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return 1.0/d;
        }
    };

    template <typename D>
    class sinop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return ::sin(d);
        }
    };

    template <typename D>
    class asinop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return ::asin(d);
        }
    };

    template <typename D>
    class cosop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return ::cos(d);
        }
    };

    template <typename D>
    class acosop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return ::acos(d);
        }
    };

    template <typename D>
    class tanop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return ::tan(d);
        }
    };

    template <typename D>
    class atanop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return ::atan(d);
        }
    };

    template <typename D>
    class negop : public uop<D> {
    public:
        virtual D eval(const D d) const {
            return -d;
        }
    };

}
