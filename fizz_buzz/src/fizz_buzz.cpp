#include "fizz_buzz.hpp"

std::string FizzBuzz(int n) {
    if(n % 15 == 0){
        return "FizzBuzz";
    } else if(n % 3 == 0){
        return "Fizz";
    } else if(n % 5 == 0){
        return "Buzz";
    } else {
        return std::to_string(n);
    }
    // write your solution here!
    
}