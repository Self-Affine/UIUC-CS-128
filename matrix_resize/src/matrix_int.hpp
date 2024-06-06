#ifndef MATRIX_INT_HPP
#define MATRIX_INT_HPP

#include <iostream>
#include <stdexcept>

class MatrixInt {
 public:
  MatrixInt(unsigned int rows, unsigned int cols);
  ~MatrixInt();
  void Resize(unsigned int new_rows, unsigned int new_cols);
  int Get(unsigned int row, unsigned int col);
  void Set(unsigned int row, unsigned int col, int new_val);
  friend std::ostream& operator<<(std::ostream& os, const MatrixInt& matrix);

 private:
  int** matrix_;
  unsigned int rows_;
  unsigned int cols_;
  void AllocateMatrix();
  void DeallocateMatrix();

  void InitMatrix();

  void ResizeEqualRows(unsigned int new_cols);
  void ResizeUnequalRows(unsigned int new_rows, unsigned int new_cols);

  void ResizeRow(unsigned int row_index, unsigned int new_cols);
  void ReplaceRow(int** new_matrix, unsigned int row_index, unsigned int new_cols);
};

std::ostream& operator<<(std::ostream& os, const MatrixInt& matrix);

#endif