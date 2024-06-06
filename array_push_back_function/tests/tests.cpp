#include <catch2/catch_test_macros.hpp>

#include "../src/solution.hpp"

TEST_CASE("Prompt test case 1", "[case1]"){
    unsigned int capacity = 10;
    unsigned int size = 3;
    int* array = new int[capacity];
    array[0] = 11;
    array[1] = 29;
    array[2] = 34;
    PushBackToIntArray(array, size, capacity, 14);
    REQUIRE(capacity == 10);
    REQUIRE(size == 4);
    REQUIRE(array[0] == 11);
    REQUIRE(array[1] == 29);
    REQUIRE(array[2] == 34);
    REQUIRE(array[3] == 14); 
    delete[] array;
}

TEST_CASE("Prompt test case 2", "[case2]"){
    unsigned int capacity = 3;
    unsigned int size = 3;
    int *array = new int[capacity];
    array[0] = 1;
    array[1] = 4;
    array[2] = 9;
    PushBackToIntArray(array, size, capacity, 12);
    REQUIRE(capacity == 6);
    REQUIRE(size == 4);
    REQUIRE(array[0] == 1);
    REQUIRE(array[1] == 4);
    REQUIRE(array[2] == 9);
    REQUIRE(array[3] == 12);
    delete[] array;
}

TEST_CASE("Null array case", "[null]"){
    unsigned int capacity = 0;
    unsigned int size = 0;
    int *array = nullptr;
    PushBackToIntArray(array, size, capacity, 1);
    REQUIRE(capacity == 1);
    REQUIRE(size == 1);
    REQUIRE(array[0] == 1);
    delete[] array;
}