#include <memory>

#include "catch.hpp"

#include "machine.h"
#include "bifun.h"
#include "biop.h"

TEST_CASE("bifun op test", "[addop]") {

    rpn::machine<long> machine;

    rpn::addop<long> addop;

    rpn::bifun<long, rpn::biop<long>> fun;

    machine.push(100L);

    machine.push(200L);

    fun.eval(machine, addop);

    const auto stacktype = machine.pop();

    REQUIRE(std::get<long>(stacktype) == 300L);

}
