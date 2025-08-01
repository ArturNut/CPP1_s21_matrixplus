#include <gtest/gtest.h>

#include "support_matrix_test.h"

TEST(TransposeMatrix, CorrectTransposeSquareMatrix) {
  for (int rows = 2; rows <= 10; rows++) {
    S21Matrix A(rows, rows);
    fill_matrix_rand(A);

    EXPECT_EQ(A.Transpose().Transpose(), A);
  }
}

TEST(TransposeMatrix, CorrectTransposeNotSquareMatrix) {
  for (int rows = 1; rows <= 10; rows++) {
    for (int cols = 2; cols <= 10 && cols != rows; cols++) {
      S21Matrix A(rows, cols);
      fill_matrix_rand(A);

      EXPECT_EQ(A.Transpose().Transpose(), A);
    }
  }
}

TEST(TransposeMatrix, NotCorrectTransposeMatrix) {
  for (int rows = 2; rows <= 10; rows++) {
    S21Matrix A(rows, rows);
    fill_matrix_rand(A);

    EXPECT_NE(A.Transpose(), A);
  }
}