#include <catch2/catch_test_macros.hpp>

#include "../src/utilities.hpp"

Student chuck1 {.first_name = "Chuck", .last_name = "Norris", .uin = 0};
Student chuck2 {.first_name = "Chuck", .last_name = "Norris", .uin = 0};
Student chuck3 {.first_name = "Chuck", .last_name = "Norris", .uin = 1};
Student chuck4 {.first_name = "Chucky", .last_name = "Norris", .uin = 0};
Student chuck5 {.first_name = "Chuck", .last_name = "Morris", .uin = 0};

TEST_CASE("Test equality operator", "[equality]"){
    REQUIRE(chuck1 == chuck2);
    REQUIRE_FALSE(chuck1 == chuck3);
    REQUIRE_FALSE(chuck1 == chuck4);
    REQUIRE_FALSE(chuck1 == chuck5);
}