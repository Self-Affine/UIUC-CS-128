#include "matrix_int.hpp"

#include "utility.hpp"

MatrixInt::MatrixInt(unsigned int rows, unsigned int cols)
    : rows_{rows}, cols_{cols}, matrix_{nullptr} 
{
    if(rows_ <= 0 || cols_ <= 0){
        throw std::invalid_argument("Invalid argument!");
    }
    AllocateMatrix();
    InitMatrix();
}
MatrixInt::~MatrixInt() {
    DeallocateMatrix();
}
void MatrixInt::Resize(unsigned int new_rows, unsigned int new_cols) {
    if(new_rows <= 0 || new_cols <= 0){
        throw std::invalid_argument("Invalid argument!");
    }

    if(new_rows == rows_){
        ResizeEqualRows(new_cols);
    } else {
        ResizeUnequalRows(new_rows, new_cols);
    }
    rows_ = new_rows;
    cols_ = new_cols;
}

// PROVIDED - DO NOT MODIFY
int MatrixInt::Get(unsigned int row, unsigned int col) {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::invalid_argument("Invalid idx");
  }
  return matrix_[row][col];
}
void MatrixInt::Set(unsigned int row, unsigned int col, int new_val) {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::invalid_argument("Invalid idx");
  }
  matrix_[row][col] = new_val;
}
std::ostream& operator<<(std::ostream& os, const MatrixInt& matrix) {
  for (unsigned int i = 0; i < matrix.rows_; ++i) {
    for (unsigned int j = 0; j < matrix.cols_; ++j) {
      os << matrix.matrix_[i][j] << "\t";
    }
    os << std::endl;
  }
  return os;
}

void MatrixInt::AllocateMatrix(){
    matrix_ = new int*[rows_];
    for(size_t i = 0; i < rows_; ++i){
        matrix_[i] = new int[cols_];
    }
}

void MatrixInt::InitMatrix(){
    for(unsigned int i = 0; i < rows_; ++i){
        SetRow(matrix_, cols_, i, 0);
    }
}

void MatrixInt::DeallocateMatrix(){
    for(size_t i = 0; i < rows_; ++i){
        delete[] matrix_[i];
    }
    delete[] matrix_;
}

void MatrixInt::ResizeEqualRows(unsigned int new_cols){
    for(size_t i = 0; i < rows_; i++){
        ResizeRow(i, new_cols);
    }
}

void MatrixInt::ResizeUnequalRows(unsigned int new_rows, unsigned int new_cols){
    int** new_matrix = new int*[new_rows];
    unsigned int num_rows_to_copy = new_rows > rows_ ? rows_ : new_rows;
    if(new_rows < rows_){
        //Deallocate the old rows that will not be copied
        for(unsigned int i = new_rows; i < rows_; i++){
            delete[] matrix_[i];
            matrix_[i] = nullptr;
        }
    }

    if(new_cols == cols_){
        //Shallow copy rows
        for(size_t i = 0; i < num_rows_to_copy; ++i){
            new_matrix[i] = matrix_[i];
        }
    } else {
        //Deep copy rows and deallocate old row arrays
        for(size_t i = 0; i < num_rows_to_copy; i++){
            ReplaceRow(new_matrix, i, new_cols);
        }
    }

    for(size_t i = num_rows_to_copy; i < new_rows; ++i){
        new_matrix[i] = new int[new_cols];
        SetRow(new_matrix, new_cols, i, 0);
    }

    delete[] matrix_;
    matrix_ = new_matrix;
}

void MatrixInt::ResizeRow(unsigned int row_index, unsigned int new_cols){
    if(new_cols == cols_)
        return;
    int * new_row = new int[new_cols];
    unsigned int num_to_copy = new_cols > cols_ ? cols_ : new_cols;
    for(size_t i = 0; i < num_to_copy; ++i){
        new_row[i] = matrix_[row_index][i];
    }
    for(size_t i = num_to_copy; i < new_cols; i++){
        new_row[i] = 0;
    }
    delete[] matrix_[row_index];
    matrix_[row_index] = new_row;
}

void MatrixInt::ReplaceRow(int** new_matrix, unsigned int row_index, unsigned int new_cols){
    new_matrix[row_index] = new int[new_cols];
    unsigned int num_to_copy = new_cols > cols_ ? cols_ : new_cols;
    for(size_t i = 0; i < num_to_copy; ++i){
        new_matrix[row_index][i] = matrix_[row_index][i];
    }
    for(size_t i = num_to_copy; i < new_cols; i++){
        new_matrix[row_index][i] = 0;
    }
    delete[] matrix_[row_index];
}