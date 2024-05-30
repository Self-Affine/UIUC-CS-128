#include "solution.hpp"

#include <cmath>
#include <iostream>
#include <limits>

std::pair<unsigned int, int> ExponentToOverflow(int init_value,
unsigned int base) 
{
    unsigned int exponent = 0;
    long long result = 0;
    int resultInt;
    while(true){
        result = init_value * static_cast<long long>(std::pow(base, exponent));
        if(result < std::numeric_limits<int>::min() || result > std::numeric_limits<int>::max()){
            resultInt = init_value * static_cast<int>(std::pow(base, exponent));
            break;
        }
        exponent++;
    }
    return std::pair<unsigned int, int>(exponent, resultInt);
}