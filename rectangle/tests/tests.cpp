#include <catch2/catch_test_macros.hpp>

#include "../src/rectangle.hpp"


TEST_CASE("Testing invalid arguments", "[invalid]"){
    Rectangle r {2, 3};
    REQUIRE_THROWS_AS(Rectangle(-1, 1), std::invalid_argument);
    REQUIRE_THROWS_AS(Rectangle(1, 0), std::invalid_argument);
    REQUIRE_THROWS_AS(r.Height(0), std::invalid_argument);
    REQUIRE_THROWS_AS(r.Width(-1), std::invalid_argument);
}

TEST_CASE("Testing setters and getters", "[setters and getters]"){
    Rectangle r {2.0, 3.0};
    REQUIRE(r.Width() == 2.0);
    REQUIRE(r.Height() == 3.0);
    r.Height(1.0);
    r.Width(1.0);
    REQUIRE(r.Height() == 1.0);
    REQUIRE(r.Width() == 1.0);
}

TEST_CASE("Testing area", "[area]"){
    constexpr double EPSILON = 0.00001;
    Rectangle r1 {2.0, 3.0};
    Rectangle r2 {10.0, 5.0};
    Rectangle r3 {7.5, 2.5};
    REQUIRE(abs(r1.Area() - 6.0) < EPSILON);
    REQUIRE(abs(r2.Area() - 50.0) < EPSILON);
    REQUIRE(abs(r3.Area() - 18.75) < EPSILON);
}