#include "number_utilities.hpp"

int NumberOddDigitsInInt(int number){
    if(number == 0){
        return 0;
    } else if(number < 0){
        number = -number;
    }
    int count = 0;
    while(number != 0){
        int lastDigit = number % 10;
        if((lastDigit % 2) == 1){
            count++;
        }
        number = number / 10;
    }
    return count;
}