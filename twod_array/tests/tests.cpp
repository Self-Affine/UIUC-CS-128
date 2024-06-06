#include <catch2/catch_test_macros.hpp>

#include "../src/twodarray.hpp"

#include <sstream>

TEST_CASE("Prompt test case", "[prompt]"){
    const int x = 4, y = 5;
    int **arr = Empty2dArray(x,y);
    for(size_t i = 0; i < x; i++){
        for(size_t j = 0; j < y; j++){
            REQUIRE(arr[i][j] == 0);
        }
    }
    int onedarray[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
    std::ostringstream* oss  = new std::ostringstream{};
    Print2dArray(arr, x, y, *oss);
    REQUIRE(oss->str() == "0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0");
    Init2dArray(onedarray, arr, x, y);
    REQUIRE(arr[0][0] == 2);
    REQUIRE(arr[0][1] == 3);
    REQUIRE(arr[0][2] == 4);
    REQUIRE(arr[0][3] == 5);
    REQUIRE(arr[0][4] == 6);
    REQUIRE(arr[3][0] == 17);
    REQUIRE(arr[3][1] == 18);
    REQUIRE(arr[3][2] == 19);
    REQUIRE(arr[3][3] == 20);
    REQUIRE(arr[3][4] == 21);
    std::ostringstream().swap(*oss); //swaps oss with default constructed ostringstream, effectively clearing it
    Print2dArray(arr, x, y, *oss);
    REQUIRE(oss->str() == "2 3 4 5 6\n7 8 9 10 11\n12 13 14 15 16\n17 18 19 20 21");

    //Cleanup
    for(size_t i = 0; i  < x; i++){
        delete[] arr[i];
    }
    delete[] arr;
}