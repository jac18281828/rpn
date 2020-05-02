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


TEST_CASE("coshop test", "[coshop]") {

    rpn::coshop<float> cosh;

    const auto result = Approx(1.0F).epsilon(1e-8F);

    REQUIRE(cosh.eval(0.0F) == result);

    const auto result1 = Approx(1.54308063481524377847F).epsilon(1e-7F);

    REQUIRE(cosh.eval(0.0F) == result);

}

TEST_CASE("acoshop test", "[acoshop]") {

    rpn::acoshop<float> acosh;

    const auto result = Approx(0.0F).epsilon(1e-8F);

    REQUIRE(acosh.eval(1.0F) == result);

}

TEST_CASE("sinhop test", "[sinhop]") {

    rpn::sinhop<float> sinh;

    const auto result = Approx(0.0F).epsilon(1e-8F);

    REQUIRE(sinh.eval(0.0F) == result);

    const auto result1 = Approx(1.175201193643801456882381850595600815155717981334095870229F).epsilon(1e-7);

    REQUIRE(sinh.eval(1.0F) == result1);

}


TEST_CASE("asinhop test", "[asinhop]") {

    rpn::asinhop<float> asinh;

    const auto result = Approx(0.0F).epsilon(1e-8F);

    REQUIRE(asinh.eval(0.0F) == result);

    const auto result1 = Approx(1.0F).epsilon(1e-7);

    REQUIRE(asinh.eval(1.175201193643801456882381850595600815155717981334095870229F) == result1);

}

TEST_CASE("tanhop test", "[tanhop]") {

    rpn::tanhop<float> tanh;

    const auto result = Approx(0.0F).epsilon(1e-8F);

    REQUIRE(tanh.eval(0.0F) == result);

    const auto result1 = Approx(0.761594155955764888119458282604793590412768597257936551596F).epsilon(1e-7);

    REQUIRE(tanh.eval(1.0) == result1);

}

TEST_CASE("atanhop test", "[atanhop]") {

    rpn::atanhop<float> atanh;

    const auto result = Approx(0.0F).epsilon(1e-8F);

    REQUIRE(atanh.eval(0.0F) == result);

    const auto result1 = Approx(1.0F).epsilon(1e-7);

    REQUIRE(atanh.eval(0.761594155955764888119458282604793590412768597257936551596F) == result1);

}

TEST_CASE("ceilop test", "[ceilop]") {

    rpn::ceilop<float> ceil;

    REQUIRE(ceil.eval(0.0F) == Approx(0.0F).epsilon(1e-8F));

    REQUIRE(ceil.eval(1.1F) == Approx(2.0F).epsilon(1e-8F));

    REQUIRE(ceil.eval(0.8F) == Approx(1.0F).epsilon(1e-8F));

}

TEST_CASE("floorop test", "[floorop]") {

    rpn::floorop<float> floor;

    REQUIRE(floor.eval(0.0F) == Approx(0.0F).epsilon(1e-8F));

    REQUIRE(floor.eval(1.1F) == Approx(1.0F).epsilon(1e-8F));

    REQUIRE(floor.eval(0.8F) == Approx(0.0F).epsilon(1e-8F));

}

TEST_CASE("truncop test", "[truncop]") {

    rpn::truncop<float> trunc;

    REQUIRE(trunc.eval(0.0F) == Approx(0.0F).epsilon(1e-8F));

    REQUIRE(trunc.eval(-0.1F) == Approx(0.0F).epsilon(1e-8F));

    REQUIRE(trunc.eval(0.8F) == Approx(0.0F).epsilon(1e-8F));

}

TEST_CASE("roundop test", "[roundop]") {

    rpn::roundop<float> round;

    REQUIRE(round.eval(0.5F) == Approx(1.0F).epsilon(1e-8F));

    REQUIRE(round.eval(0.4F) == Approx(0.0F).epsilon(1e-8F));

}



