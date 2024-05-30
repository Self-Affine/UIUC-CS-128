#include <catch2/catch_test_macros.hpp>

#include "../src/solution.hpp"

const std::string pathToFolder {"D://Programming//Courses//UIUC//CS 128//file_streams_retrieve_ints//data//"};

TEST_CASE("Retrieve ints from data.dat","[data.dat]"){
    std::vector<int> ints {};
    REQUIRE_NOTHROW(ints = get_ints_from_file(pathToFolder + "data.dat"));
    REQUIRE(ints.size() == 4);
    REQUIRE(ints.at(0) == 1);
    REQUIRE(ints.at(1) == 2);   
    REQUIRE(ints.at(2) == 9);  
    REQUIRE(ints.at(3) == 8);  
}