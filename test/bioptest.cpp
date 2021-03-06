#include "catch.hpp"

#include "biop.h"

TEST_CASE("add test", "[addop]") {

    rpn::addop<long> adder;

    REQUIRE(adder.eval(1L, 1L) == 2L);

}

TEST_CASE("sub test", "[subop]") {

    rpn::subop<long> subber;

    REQUIRE(subber.eval(600L, 1L) == 599L);

}

TEST_CASE("mul test", "[mulop]") {

    rpn::mulop<long> mult;

    // Feynman could do it in his head
    REQUIRE(mult.eval(49L, 49L) == 2401L);

}

TEST_CASE("div test", "[divop]") {

    rpn::divop<long> div;

    REQUIRE(div.eval(9L, 7L) == 1L);

}

TEST_CASE("rootx test", "[rootxop]") {

    rpn::rootxop<double> rootx;

    const auto result = Approx(3.0).epsilon(1e-8);
    
    REQUIRE(rootx.eval(9.0, 2.0) == result);

}


TEST_CASE("pow test", "[powop]") {

    rpn::powop<double> pow;

    const auto result = Approx(2304.0).epsilon(1e-8);
    
    REQUIRE(pow.eval(48.0, 2.0) == result);

}

TEST_CASE("mod test", "[modop]") {

    rpn::modop<double> mod;

    REQUIRE(mod.eval(9.0, 7.0) == Approx(2.0F).epsilon(1e-8F));

}

TEST_CASE("min test", "[minop]") {

    rpn::minop<double> min;

    REQUIRE(min.eval(8.0, 100.0) == Approx(8.0F).epsilon(1e-8F));

}

TEST_CASE("max test", "[maxop]") {

    rpn::maxop<double> max;

    REQUIRE(max.eval(8.0, 100.0) == Approx(100.0F).epsilon(1e-8F));

}

