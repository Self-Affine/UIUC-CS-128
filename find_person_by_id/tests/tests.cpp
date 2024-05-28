#include <catch2/catch_test_macros.hpp>

#include "../src/utilities.hpp"

std::vector<Person> people {{"Bob", "A", 1}, {"Charlie", "B", 2}, {"Kathy", "C", 200}};

TEST_CASE("FindPersonById happy path tests", "[normal]" ) {
    REQUIRE(FindPersonById(people, 1).first_name == "Bob");
    REQUIRE(FindPersonById(people, 200).last_name == "C");
    REQUIRE(FindPersonById(people, 2).first_name == "Charlie");
}

TEST_CASE("FindPersonById exception tests", "[exception]"){
    REQUIRE_THROWS_AS(FindPersonById(people, 0), std::runtime_error);
    REQUIRE_THROWS_AS(FindPersonById(people, 3), std::runtime_error);
    REQUIRE_THROWS_AS(FindPersonById(people, 100), std::runtime_error);
}