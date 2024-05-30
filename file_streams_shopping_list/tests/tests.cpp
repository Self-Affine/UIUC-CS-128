#include <catch2/catch_test_macros.hpp>

#include "../src/shopping_list.hpp"

#include <vector>

const std::string pathToFolder {"D://Programming//Courses//UIUC//CS 128//file_streams_shopping_list//data//"};

TEST_CASE("Testing good data", "[good]"){
    std::vector<Item> items {};
    REQUIRE_NOTHROW(items = LoadItemsToVector(pathToFolder + "good_data.dat"));
    REQUIRE(items.at(0).itemName == "Apples");
    REQUIRE(items.at(0).quantity == 10);
    REQUIRE(items.at(0).price == 5.99);
    REQUIRE(items.at(1).itemName == "Tomatoes");
    REQUIRE(items.at(1).quantity == 5);
    REQUIRE(items.at(1).price == 3.99);
}

TEST_CASE("Testing bad data", "[bad]"){
    REQUIRE_THROWS_AS(LoadItemsToVector(pathToFolder + "bad_data1.dat"), std::runtime_error);
    REQUIRE_THROWS_AS(LoadItemsToVector(pathToFolder + "bad_data2.dat"), std::runtime_error);
}