#include "utility.hpp"

void SetRow(int **matrix_int, unsigned int num_cols, unsigned int row_index, int value)
{
    for(unsigned int i = 0; i < num_cols; ++i){
        matrix_int[row_index][i] = value;
    }
}