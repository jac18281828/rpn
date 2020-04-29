#include "catch.hpp"

#include "machine.h"

TEST_CASE("push to machine", "[machine push]") {

    rpn::machine<int> machine;

    machine.push(100);

    REQUIRE(machine.size() == 1);
}

TEST_CASE("pop machine", "[machine pop]") {

    rpn::machine<int> machine;

    machine.push(100);

    const auto stackele = machine.pop();

    const auto val = std::get<int>(stackele);

    REQUIRE(val == 100);

    REQUIRE(machine.size() == 0);
}

TEST_CASE("peek machine", "[machine peek]") {

    rpn::machine<int> machine;

    machine.push(100);

    const auto stackele = machine.peek();

    const auto val = std::get<int>(stackele);

    REQUIRE(val == 100);
}

TEST_CASE("drop machine", "[machine drop]") {

    rpn::machine<int> machine;

    machine.push(100);

    machine.drop();

    REQUIRE(machine.size() == 0);
    
}


TEST_CASE("swap machine", "[machine swap]") {

    rpn::machine<int> machine;

    machine.push(100);

    machine.push(200);

    machine.swap();

    const auto s1 = machine.pop();

    const auto v1 = std::get<int>(s1);

    REQUIRE(v1 == 100); // first off is now first on

    const auto s2 = machine.pop();

    const auto v2 = std::get<int>(s2);

    REQUIRE(v2 == 200);
    
}



TEST_CASE("clear machine", "[machine clear]") {

    rpn::machine<int> machine;


    for(int i=0; i<100; i++) {
        machine.push(i);
    }

    REQUIRE(machine.size() == 100);


    machine.clear();
    

    REQUIRE(machine.size() == 0);
    
}

TEST_CASE("empty machine", "[machine empty]") {

    rpn::machine<int> machine;

    REQUIRE(machine.empty() == true);

    for(int i=0; i<100; i++) {
        machine.push(i);
    }

    REQUIRE(machine.empty() == false);
    
}

TEST_CASE("machine depth", "[machine depth]") {

    rpn::machine<int> machine;

    for(int i=0; i<100; i++) {
        machine.push(i);
    }

    machine.depth();

    REQUIRE(machine.size() == 101);

    const auto depthele = machine.pop();

    const auto depthval = std::get<int>(depthele);

    REQUIRE(depthval == 100);
    
}


