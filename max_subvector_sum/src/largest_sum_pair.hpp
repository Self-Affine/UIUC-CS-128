#ifndef LARGEST_SUM_PAIR_HPP
#define LARGEST_SUM_PAIR_HPP

#include <limits>

struct LargestSumPair {
  unsigned int index = 0;
  int sum = std::numeric_limits<int>::min();
};

#endif