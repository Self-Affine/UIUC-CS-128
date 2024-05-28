#include <catch2/catch_test_macros.hpp>

#include "../src/solution.hpp"

//should return false
int array1[] = {0, 1, 2, 3};
int array2[] = {-5};
int array3[] = {9, 12, 3, -3, 4, 19};
//should return true
int array4[] = {0, 0};
int array5[] = {0, 1, 2, 0, 5};
int array6[] = {7, -15, 7};

TEST_CASE("Does not contain duplicate", "[no duplicate]"){
    REQUIRE(!ContainsDuplicate(array1, sizeof(array1)/ sizeof(array1[0])));
    REQUIRE(!ContainsDuplicate(array2, sizeof(array2)/ sizeof(array2[0])));
    REQUIRE(!ContainsDuplicate(array3, sizeof(array3)/ sizeof(array3[0])));
}

TEST_CASE("Contains duplicate", "[duplicate]"){
    REQUIRE(ContainsDuplicate(array4, sizeof(array4)/ sizeof(array4[0])));
    REQUIRE(ContainsDuplicate(array5, sizeof(array5)/ sizeof(array5[0])));
    REQUIRE(ContainsDuplicate(array6, sizeof(array6)/ sizeof(array6[0])));
}