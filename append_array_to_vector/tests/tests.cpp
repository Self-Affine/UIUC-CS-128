#include <catch2/catch_test_macros.hpp>

#include "../src/solution.hpp"

int array1[] = {0};
int array2[] = {0, 1};
int array3[] = {0, 1, 0};

std::vector<int> vec1 = {};
std::vector<int> vec2 = {0, 1, 2, 3, 4};

TEST_CASE("Append to empty vector", "[empty]"){
    AppendArrayToVector(array1, sizeof(array1)/sizeof(array1[0]), vec1);
    REQUIRE(vec1 == std::vector<int>{0});
    vec1 = {};
    AppendArrayToVector(array2, sizeof(array2)/sizeof(array2[0]), vec1);
    REQUIRE(vec1 == std::vector<int>{0, 1});
    vec1 = {};
    AppendArrayToVector(array3, sizeof(array3)/sizeof(array3[0]), vec1);
    REQUIRE(vec1 == std::vector<int>{0, 1, 0});
}

TEST_CASE("Append to nonempty vector", "[nonempty]"){
    AppendArrayToVector(array1, sizeof(array1)/sizeof(array1[0]), vec2);
    REQUIRE(vec2 == std::vector<int>{0, 1, 2, 3, 4, 0});
    vec2 = {0, 1, 2, 3, 4};
    AppendArrayToVector(array2, sizeof(array2)/sizeof(array2[0]), vec2);
    REQUIRE(vec2 == std::vector<int>{0, 1, 2, 3, 4, 0, 1});
    vec2 = {0, 1, 2, 3, 4};
    AppendArrayToVector(array3, sizeof(array3)/sizeof(array3[0]), vec2);
    REQUIRE(vec2 == std::vector<int>{0, 1, 2, 3, 4, 0, 1, 0});
    vec2 = {0, 1, 2, 3, 4};
}