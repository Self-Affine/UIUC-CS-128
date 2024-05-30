#include "solution.hpp"

#include <stdexcept>
#include <cmath>
#include <sstream>

double BinaryToDouble(const std::string &binary_string){
    //validate argument
    if(binary_string.size() != 9)
        throw std::invalid_argument("Invalid argument");
    if(binary_string.at(0) != '0')
        throw std::invalid_argument("Invalid argument");
    if(binary_string.at(1) != 'b')
        throw std::invalid_argument("Invalid argument");
    for(size_t i = 2; i < 9; i++){
        if(binary_string.at(i) != '0' && binary_string.at(i) != '1'){
            throw std::invalid_argument("Invalid argument");
        }
    }
    //special encoding
    if(binary_string == "0b0000000")
        return 0.0;
    if(binary_string == "0b1000000")
        return -0.0;
    //regular encoding
    double sign = binary_string.at(2) == '0' ? 1.0 : -1.0;
    double exponent = ComputeExponent(binary_string);
    double mantissa = ComputeMantissa(binary_string);
    return sign * pow(2.0, exponent - 1.0) * (1.0 + mantissa);
}

double ComputeExponent(const std::string &binary_string){
    return CharIntToInt(binary_string.at(3)) * 2.0 + CharIntToInt(binary_string.at(4));
}

double ComputeMantissa(const std::string &binary_string){
    double tmp = 0.0;
    for(size_t i = 5; i < 9; i++){
        tmp += CharIntToInt(binary_string.at(i)) / pow(2, i - 4);
    }
    return tmp;
}

int CharIntToInt(char c) {
  std::stringstream ss;
  ss << c;
  int value = 0;
  ss >> value;
  return value;
}