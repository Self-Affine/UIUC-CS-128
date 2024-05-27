#include "largest_digit.hpp"

#include <cassert>

int LargestDigit(int number){
    assert(number >= 0);

    int largestDigit = 0;

    while(number != 0){
        int lastDigit = number % 10;
        if(lastDigit > largestDigit){
            largestDigit = lastDigit;
        }
        number = number / 10;
    }
    return largestDigit;
}