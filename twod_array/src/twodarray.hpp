#ifndef TWODARRAY_HPP
#define TWODARRAY_HPP

#include <iostream>

int** Empty2dArray(unsigned int num_rows, unsigned int num_cols);

void Init2dArray(int src[], int** dest, unsigned int num_rows, unsigned int num_cols);

void Print2dArray(int** arr, unsigned num_rows, unsigned num_cols, std::ostream& os = std::cout);

#endif