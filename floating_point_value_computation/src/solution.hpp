#ifndef PARSE_FLOAT_HPP
#define PARSE_FLOAT_HPP

#include <string>

double BinaryToDouble(const std::string &binary_string);

double ComputeExponent(const std::string &binary_string);
double ComputeMantissa(const std::string &binary_string);

int CharIntToInt(char c);

#endif