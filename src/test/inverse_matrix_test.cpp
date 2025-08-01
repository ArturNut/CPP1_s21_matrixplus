#include <gtest/gtest.h>

#include "support_matrix_test.h"

TEST(InverseMatrix, InverseMatrixCorrect) {
  S21Matrix A(3, 3);
  S21Matrix result(3, 3);
  double det_res = 1.0;

  A(0, 0) = 2.0;
  A(0, 1) = 5.0;
  A(0, 2) = 7.0;
  A(1, 0) = 6.0;
  A(1, 1) = 3.0;
  A(1, 2) = 4.0;
  A(2, 0) = 5.0;
  A(2, 1) = -2.0;
  A(2, 2) = -3.0;

  result(0, 0) = 1.0;
  result(0, 1) = 0.0;
  result(0, 2) = 0.0;
  result(1, 0) = 0.0;
  result(1, 1) = 1.0;
  result(1, 2) = 0.0;
  result(2, 0) = 0.0;
  result(2, 1) = 0.0;
  result(2, 2) = 1.0;

  S21Matrix B = A.InverseMatrix();
  S21Matrix C = A * B;
  double res = C.Determinant();

  EXPECT_EQ(C, result);
  EXPECT_FLOAT_EQ(res, det_res);
}

TEST(InverseMatrix, InverseMatrixCorrect_1) {
  double det_res = 1.0;

  for (int rows = 1; rows <= 8; rows++) {
    S21Matrix A(rows, rows);
    fill_matrix_rand(A);
    double det = A.Determinant();

    if (det != 0) {
      S21Matrix B = A.InverseMatrix();
      S21Matrix C = A * B;
      double res = C.Determinant();
      EXPECT_FLOAT_EQ(res, det_res);
    }
  }
}

TEST(InverseMatrix, ThrowsOutOfRange_WhenMatrixNotSquare) {
  S21Matrix A(3, 4);
  EXPECT_THROW(A.InverseMatrix(), std::out_of_range);
}

TEST(InverseMatrix, ThrowsOutOfRange_WhenInverseMatrixNotExist) {
  S21Matrix A(3, 3);

  A(0, 0) = 2.0;
  A(0, 1) = 5.0;
  A(0, 2) = 7.0;
  A(1, 0) = 6.0;
  A(1, 1) = 3.0;
  A(1, 2) = 4.0;
  A(2, 0) = 10.0;
  A(2, 1) = 25.0;
  A(2, 2) = 35.0;

  EXPECT_THROW(A.InverseMatrix(), std::out_of_range);
}