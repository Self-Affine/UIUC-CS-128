#include "solution.hpp"

#include <cassert>

LargestSumPair LargestVectorSum(const std::vector<std::vector<int>> &input){
    assert(input.size() > 0);
    unsigned int indexOfMaxSum = 0;
    int maxSum = computeSum(input.at(0));

    for(size_t i = 1; i < input.size(); i++){
        int sum {computeSum(input.at(i))};
        if(sum > maxSum){
            indexOfMaxSum = i;
            maxSum = sum;
        }
    }
    return LargestSumPair{.index = indexOfMaxSum, .sum = maxSum};
}

int computeSum(const std::vector<int> &v){
    assert(v.size() > 0);
    int tmp = 0;
    for(size_t i = 0; i < v.size(); i++){
        tmp += v.at(i);
    }
    return tmp;
}