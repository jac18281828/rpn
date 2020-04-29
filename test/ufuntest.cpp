#include <memory>

#include "catch.hpp"

#include "machine.h"
#include "ufun.h"
#include "uop.h"

TEST_CASE("ufun simple op test", "[negop]") {

    rpn::machine<long> machine;

    rpn::negop<long> negop;

    rpn::ufun<long, rpn::uop<long>> fun;

    machine.push(100L);

    fun.eval(machine, negop);

    const auto stacktype = machine.pop();

    REQUIRE(std::get<long>(stacktype) == -100L);

}

