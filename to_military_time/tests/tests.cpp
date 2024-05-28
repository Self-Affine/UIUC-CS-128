#include <catch2/catch_test_macros.hpp>

#include "../src/military_time.hpp"

TEST_CASE("Compute military time from minutes", "[minutes]"){
    REQUIRE(ToMilitaryTime(389u) == "06:29");
    REQUIRE(ToMilitaryTime(844u) == "14:04");
    REQUIRE(ToMilitaryTime(1440u) == "00:00");
}

TEST_CASE("Compute military time from hours", "[hours]"){
    REQUIRE(ToMilitaryTime(8.4) == "08:24");
    REQUIRE(ToMilitaryTime(14.4432) == "14:27");
    REQUIRE(ToMilitaryTime(24.0) == "00:00");
}

TEST_CASE("Exceptions are thrown", "[exceptions]"){
    REQUIRE_THROWS_AS(ToMilitaryTime(1441u), std::invalid_argument);
    REQUIRE_THROWS_AS(ToMilitaryTime(-0.1), std::invalid_argument);
    REQUIRE_THROWS_AS(ToMilitaryTime(24.001), std::invalid_argument);
}