#include "catch.hpp"

#include "uop.h"

TEST_CASE("abs test", "[absop]") {

    rpn::absop<long> abs;

    REQUIRE(abs.eval(1L) == 1L);

    REQUIRE(abs.eval(-1L) == 1L);

    REQUIRE(abs.eval(0L) == 0L);

}

TEST_CASE("sqrt test", "[sqrtop]") {

    rpn::sqrtop<long> sqrt;

    REQUIRE(sqrt.eval(4L) == 2L);

    rpn::sqrtop<double> sqrtd;

    const auto result = Approx(1.4142136D).epsilon(1e-5);

    REQUIRE(sqrtd.eval(2.0D) == result);

}

TEST_CASE("cbrt test", "[cbrtop]") {

    rpn::cbrtop<double> cbrt;

    const auto result = Approx(1.4142136D).epsilon(1e-5);

    REQUIRE(cbrt.eval(2.828427D) == result);

}

TEST_CASE("sq test", "[sqop]") {

    rpn::sqop<unsigned char> sq;

    REQUIRE(sq.eval(4u) == 16);

}

TEST_CASE("exp test", "[expop]") {

    rpn::expop<float> exp;

    const auto result = Approx(2.718281828F).epsilon(1e-7);

    REQUIRE(exp.eval(1.0f) == result);

}

TEST_CASE("ln test", "[lnop]") {

    rpn::lnop<float> ln;

    const auto result = Approx(1.0f).epsilon(1e-7);

    REQUIRE(ln.eval(2.718281828F) == result);

}

TEST_CASE("log test", "[logop]") {

    rpn::logop<float> log;

    const auto result = Approx(2.0f).epsilon(1e-3);

    REQUIRE(log.eval(100.0f) == result);

}


TEST_CASE("alog test", "[alogop]") {

    rpn::alogop<float> alog;

    const auto result = Approx(1000.0f).epsilon(1e-3);

    REQUIRE(alog.eval(3.0f) == result);

}

TEST_CASE("invop test", "[invop]") {

    rpn::invop<float> inv;

    const auto result = Approx(0.3333f).epsilon(1e-3);

    REQUIRE(inv.eval(3.0f) == result);

}

TEST_CASE("sinop test", "[sinop]") {

    rpn::sinop<float> sin;

    const auto result0 = Approx(0.0f).epsilon(1e-6);

    const auto result1 = Approx(1.0f).epsilon(1e-6);

    REQUIRE(sin.eval(3.141592F/2.0F) == result1);

    REQUIRE(sin.eval(0.0F) == result0);

}

TEST_CASE("asinop test", "[asinop]") {

    rpn::asinop<float> asin;

    const auto result = Approx(3.1415926535F/2.0F).epsilon(1e-7);

    REQUIRE(asin.eval(1.0F) == result);

}

TEST_CASE("cosop test", "[cosop]") {

    rpn::cosop<float> cos;
    
    const auto result1 = Approx(1.0f).epsilon(1e-6);

    REQUIRE(cos.eval(0.0F) == result1);

}

TEST_CASE("acosop test", "[acosop]") {

    rpn::acosop<float> acos;

    const auto result = Approx(1.5707963705F).epsilon(1e-6);

    REQUIRE(acos.eval(0.0) == result);

}

TEST_CASE("tanop test", "[tanop]") {

    rpn::tanop<float> tan;

    const auto result = Approx(1.55740772465F).epsilon(1e-6);

    REQUIRE(tan.eval(1.0) == result);

}

TEST_CASE("atanop test", "[atanop]") {

    rpn::atanop<float> atan;

    const auto result = Approx(3.1415926535897932385/4.0).epsilon(1e-4);

    REQUIRE(atan.eval(1.0) == result);

}


TEST_CASE("negop test", "[negop]") {

    rpn::negop<long> neg;

    REQUIRE(neg.eval(1) == -1L);

    REQUIRE(neg.eval(-1) == 1L);
    
    REQUIRE(neg.eval(0L) == 0L);    

}


