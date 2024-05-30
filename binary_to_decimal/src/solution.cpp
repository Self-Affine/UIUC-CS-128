#include <sstream>
#include <stdexcept>
#include <cmath>

#include "solution.hpp"



int Base2ToBase10(const std::string &binary){
    validateArgument(binary);

    int tmp = 0;
    for(int i = 2; i < 10; i++){
        tmp += CharIntToInt(binary.at(i)) * pow(2, 9 - i);
    }
    return tmp;
}

//Note: format of input `binary` must be "0bXXXXXXXX" where each X is either 0 or 1
static void validateArgument(const std::string &binary){
    if(binary.size() != 10)
        throw std::invalid_argument("Invalid argument");
    if(binary.at(0) != '0')
        throw std::invalid_argument("Invalid argument");
    if(binary.at(1) != 'b')
        throw std::invalid_argument("Invalid argument");
    for(size_t i = 2; i < 10; i++){
        if(binary.at(i) != '0' && binary.at(i) != '1'){
            throw std::invalid_argument("Invalid argument");
        }
    }
}

// provided functions
int CharIntToInt(char c) {
  std::stringstream ss;
  ss << c;
  int value = 0;
  ss >> value;
  return value;
}

