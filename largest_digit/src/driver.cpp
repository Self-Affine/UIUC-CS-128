#include "largest_digit.hpp"

#include <iostream>

int LargestDigit(int number);

int main() {

  std::cout << LargestDigit(787) << std::endl;
  std::cout << LargestDigit(567) << std::endl;
  std::cout << LargestDigit(1) << std::endl;
  std::cout << LargestDigit(98093) << std::endl;
  std::cout << LargestDigit(10) << std::endl;
}