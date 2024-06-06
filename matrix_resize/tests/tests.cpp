#include <catch2/catch_test_macros.hpp>

#include "../src/matrix_int.hpp"

TEST_CASE("Activity prompt test case", "[prompt]"){
    MatrixInt matrix(3, 3);

    for(size_t i = 0; i < 3; i++){
        for(size_t j = 0; j < 3; j++){
            REQUIRE(matrix.Get(i, j) == 0);
        }
    }
    
    REQUIRE_NOTHROW(matrix.Set(0,0,1));
    REQUIRE_NOTHROW(matrix.Set(0,1,2));
    REQUIRE_NOTHROW(matrix.Set(0,2,3));
    REQUIRE_NOTHROW(matrix.Set(1,0,4));
    REQUIRE_NOTHROW(matrix.Set(1,1,5));
    REQUIRE_NOTHROW(matrix.Set(1,2,6));
    REQUIRE_NOTHROW(matrix.Set(2,0,7));
    REQUIRE_NOTHROW(matrix.Set(2,1,8));
    REQUIRE_NOTHROW(matrix.Set(2,2,9));

    matrix.Resize(2,4);
    REQUIRE(matrix.Get(0, 0) == 1);
    REQUIRE(matrix.Get(0, 1) == 2);
    REQUIRE(matrix.Get(0, 2) == 3);
    REQUIRE(matrix.Get(0, 3) == 0);
    REQUIRE_THROWS_AS(matrix.Get(0, 4), std::invalid_argument);
    REQUIRE(matrix.Get(1, 0) == 4);
    REQUIRE(matrix.Get(1, 1) == 5);
    REQUIRE(matrix.Get(1, 2) == 6);
    REQUIRE(matrix.Get(1, 3) == 0);
    REQUIRE_THROWS_AS(matrix.Get(1, 4), std::invalid_argument);
    REQUIRE_THROWS_AS(matrix.Get(3, 0), std::invalid_argument);
}

TEST_CASE("Equal rows and equal cols resize", "[equal rows and cols]"){
    MatrixInt matrix(2, 3);
    matrix.Set(0, 0, 1);
    matrix.Set(0, 1, 2);
    matrix.Set(0, 2, 3);
    matrix.Set(1, 0, 4);
    matrix.Set(1, 1, 5);
    matrix.Set(1, 2, 6);

    matrix.Resize(2, 3);
    REQUIRE(matrix.Get(0, 0) == 1);
    REQUIRE(matrix.Get(0, 1) == 2);
    REQUIRE(matrix.Get(0, 2) == 3);
    REQUIRE(matrix.Get(1, 0) == 4);
    REQUIRE(matrix.Get(1, 1) == 5);
    REQUIRE(matrix.Get(1, 2) == 6);
}

TEST_CASE("Equal rows and nonequal column resizes", "[equal rows and nonequal cols]"){
    MatrixInt matrix(2, 3);
    matrix.Set(0, 0, 1);
    matrix.Set(0, 1, 2);
    matrix.Set(0, 2, 3);
    matrix.Set(1, 0, 4);
    matrix.Set(1, 1, 5);
    matrix.Set(1, 2, 6);

    matrix.Resize(2, 4);
    REQUIRE(matrix.Get(0, 0) == 1);
    REQUIRE(matrix.Get(0, 1) == 2);
    REQUIRE(matrix.Get(0, 2) == 3);
    REQUIRE(matrix.Get(0, 3) == 0);
    REQUIRE(matrix.Get(1, 0) == 4);
    REQUIRE(matrix.Get(1, 1) == 5);
    REQUIRE(matrix.Get(1, 2) == 6);
    REQUIRE(matrix.Get(1, 3) == 0);

    matrix.Resize(2, 2);
    REQUIRE(matrix.Get(0, 0) == 1);
    REQUIRE(matrix.Get(0, 1) == 2);
    REQUIRE_THROWS_AS(matrix.Get(0, 2), std::invalid_argument);
    REQUIRE(matrix.Get(1, 0) == 4);
    REQUIRE(matrix.Get(1, 1) == 5);
    REQUIRE_THROWS_AS(matrix.Get(1, 2), std::invalid_argument);
}

TEST_CASE("Nonequal rows and equal columns resizes", "[nonequal rows and equal columns]"){
    MatrixInt matrix(2, 3);
    matrix.Set(0, 0, 1);
    matrix.Set(0, 1, 2);
    matrix.Set(0, 2, 3);
    matrix.Set(1, 0, 4);
    matrix.Set(1, 1, 5);
    matrix.Set(1, 2, 6);

    matrix.Resize(3, 3);
    REQUIRE(matrix.Get(0, 0) == 1);
    REQUIRE(matrix.Get(0, 1) == 2);
    REQUIRE(matrix.Get(0, 2) == 3);
    REQUIRE(matrix.Get(1, 0) == 4);
    REQUIRE(matrix.Get(1, 1) == 5);
    REQUIRE(matrix.Get(1, 2) == 6);
    REQUIRE(matrix.Get(2, 0) == 0);
    REQUIRE(matrix.Get(2, 1) == 0);
    REQUIRE(matrix.Get(2, 2) == 0);

    matrix.Resize(1, 3);
    REQUIRE(matrix.Get(0, 0) == 1);
    REQUIRE(matrix.Get(0, 1) == 2);
    REQUIRE(matrix.Get(0, 2) == 3);
    REQUIRE_THROWS_AS(matrix.Get(1, 2), std::invalid_argument);
}

TEST_CASE("Nonequal rows and nonequal columns resizes", "[nonequal rows and nonequal columns]"){
    MatrixInt matrix(2, 3);
    matrix.Set(0, 0, 1);
    matrix.Set(0, 1, 2);
    matrix.Set(0, 2, 3);
    matrix.Set(1, 0, 4);
    matrix.Set(1, 1, 5);
    matrix.Set(1, 2, 6);

    matrix.Resize(3, 4);
    REQUIRE(matrix.Get(0, 0) == 1);
    REQUIRE(matrix.Get(0, 1) == 2);
    REQUIRE(matrix.Get(0, 2) == 3);
    REQUIRE(matrix.Get(0, 3) == 0);
    REQUIRE(matrix.Get(1, 0) == 4);
    REQUIRE(matrix.Get(1, 1) == 5);
    REQUIRE(matrix.Get(1, 2) == 6);
    REQUIRE(matrix.Get(1, 3) == 0);
    REQUIRE(matrix.Get(2, 0) == 0);
    REQUIRE(matrix.Get(2, 1) == 0);
    REQUIRE(matrix.Get(2, 2) == 0);
    REQUIRE(matrix.Get(2, 3) == 0);

    matrix.Resize(2, 3);
    REQUIRE(matrix.Get(0, 0) == 1);
    REQUIRE(matrix.Get(0, 1) == 2);
    REQUIRE(matrix.Get(0, 2) == 3);
    REQUIRE(matrix.Get(1, 0) == 4);
    REQUIRE(matrix.Get(1, 1) == 5);
    REQUIRE(matrix.Get(1, 2) == 6);

    matrix.Resize(3, 2);
    REQUIRE(matrix.Get(0, 0) == 1);
    REQUIRE(matrix.Get(0, 1) == 2);
    REQUIRE(matrix.Get(1, 0) == 4);
    REQUIRE(matrix.Get(1, 1) == 5);
    REQUIRE(matrix.Get(2, 0) == 0);
    REQUIRE(matrix.Get(2, 1) == 0);

    matrix.Resize(2, 3);
    REQUIRE(matrix.Get(0, 0) == 1);
    REQUIRE(matrix.Get(0, 1) == 2);
    REQUIRE(matrix.Get(0, 2) == 0);
    REQUIRE(matrix.Get(1, 0) == 4);
    REQUIRE(matrix.Get(1, 1) == 5);
    REQUIRE(matrix.Get(1, 2) == 0);
}

