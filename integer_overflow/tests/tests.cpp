#include <catch2/catch_test_macros.hpp>

#include "../src/solution.hpp"

TEST_CASE("ExponentToOverflow tests", "[ExponentToOverflow]"){
    REQUIRE(ExponentToOverflow(1048, 2) == std::pair<unsigned int, int>(21, -2097152000));
    REQUIRE(ExponentToOverflow(-2000, 2) == std::pair<unsigned int, int>(21, 100663296));
    REQUIRE(ExponentToOverflow(-20000, 4) == std::pair<unsigned int, int>(9, -947912704));
}