#include <vector>
#include <cassert>

#include "solution.hpp"

int main() {
    std::vector<std::vector<int>> vect1 {{1, 2, 3, 4, 5},
                                      {84},
                                      {9, 10, 11, 12, 13, 14, 15}};
    LargestSumPair result = LargestVectorSum(vect1);
    assert(result.index == 1 && result.sum == 84);

    std::vector<std::vector<int>> vect2 {{-21, -34},
                                      {7, 2, 3},
                                      {500, 12}};
    result = LargestVectorSum(vect2);
    assert(result.index == 2 && result.sum == 512);
}
