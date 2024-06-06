#include "matrix_int.hpp"

int main(){
    //checking for memory leaks
    MatrixInt matrix(2, 3);
    matrix.Set(0, 0, 1);
    matrix.Set(0, 1, 2);
    matrix.Set(0, 2, 3);
    matrix.Set(1, 0, 4);
    matrix.Set(1, 1, 5);
    matrix.Set(1, 2, 6);

    //Nonequal rows, equal columns
    matrix.Resize(3, 3);
    matrix.Resize(2, 3);
    //Nonequal rows, nonequal columns
    matrix.Resize(3, 4); //rows increase, columns increase
    matrix.Resize(2, 3); //rows decrease, columns decrease
    matrix.Resize(3, 2); //rows increase, columns decrease
    matrix.Resize(2, 3); //rows decrease, columns increase
    //Equal rows
    matrix.Resize(2, 3);
    matrix.Resize(2, 2);
    matrix.Resize(2, 4);
}