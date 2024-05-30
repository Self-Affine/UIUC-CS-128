#include <catch2/catch_test_macros.hpp>

#include "../src/solution.hpp"

TEST_CASE("Invalid arguments", "[invalid]"){
    REQUIRE_THROWS_AS(Base2ToBase10("0b11112111"), std::invalid_argument);
    REQUIRE_THROWS_AS(Base2ToBase10("1b11111111"), std::invalid_argument);
    REQUIRE_THROWS_AS(Base2ToBase10("1x11111111"), std::invalid_argument);
    REQUIRE_THROWS_AS(Base2ToBase10("0b11100011111"), std::invalid_argument);
}

TEST_CASE("Valid arguments", "[valid]"){
    REQUIRE(Base2ToBase10("0b00000011") == 3);
    REQUIRE(Base2ToBase10("0b00000000") == 0);
    REQUIRE(Base2ToBase10("0b11111111") == 255);
}