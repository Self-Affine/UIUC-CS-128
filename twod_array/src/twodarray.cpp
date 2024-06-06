#include "twodarray.hpp"

int** Empty2dArray(unsigned int num_rows, unsigned int num_cols) {
    int** arr = new int*[num_rows];
    for(size_t i = 0; i < num_rows; ++i){
        arr[i] = new int[num_cols];
        for(size_t j = 0; j < num_cols; ++j){
            arr[i][j] = 0;
        }
    }
    return arr;
}

void Init2dArray(int src[], int** dest, unsigned int num_rows, unsigned int num_cols) {
    size_t srcIndex = 0;
    for(size_t i = 0; i < num_rows; ++i){
        for(size_t j = 0; j < num_cols; ++j, ++srcIndex){
            dest[i][j] = src[srcIndex];
        }
    }
}

void Print2dArray(int** arr, unsigned num_rows, unsigned num_cols, std::ostream& os) {
    for(size_t i = 0; i < num_rows; ++i){
        for(size_t j = 0; j < num_cols; ++j){
            os << std::to_string(arr[i][j]);
            if(j != num_cols - 1){
                os << ' ';
            }
        }
        if(i != num_rows - 1){
            os << '\n';
        }
    }
}