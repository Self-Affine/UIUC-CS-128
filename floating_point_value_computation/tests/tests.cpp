#include <catch2/catch_test_macros.hpp>

#include "../src/solution.hpp"

TEST_CASE("Valid argument tests", "[valid]"){
    REQUIRE(BinaryToDouble("0b0101100") == 3.5);
    REQUIRE(BinaryToDouble("0b0000000") == 0.0);
    REQUIRE(BinaryToDouble("0b1000000") == -0.0);
}

TEST_CASE("Invalid argument tests", "[invalid]"){
    REQUIRE_THROWS_AS(BinaryToDouble("1b0101100"), std::invalid_argument);
    REQUIRE_THROWS_AS(BinaryToDouble("0b010110000"), std::invalid_argument);
    REQUIRE_THROWS_AS(BinaryToDouble("0b0102100"), std::invalid_argument);
    REQUIRE_THROWS_AS(BinaryToDouble("0x0101100"), std::invalid_argument);
}