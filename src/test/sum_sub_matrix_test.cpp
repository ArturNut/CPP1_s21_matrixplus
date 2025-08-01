#include <gtest/gtest.h>

#include "support_matrix_test.h"

TEST(SumSubMatrix, CorrectSumSubMatrix) {
  for (int rows = 1; rows <= 10; rows++) {
    for (int columns = 1; columns <= 10; columns++) {
      S21Matrix A(rows, columns);
      S21Matrix B(rows, columns);
      S21Matrix C;
      S21Matrix D;

      fill_matrix_rand(A);
      fill_matrix_rand(B);

      C = A + B;
      D = C - B;

      EXPECT_TRUE(A == D);
    }
  }
}

TEST(SumSubMatrix, CorrectSumMatrix) {
  for (int rows = 1; rows <= 10; rows++) {
    for (int columns = 1; columns <= 10; columns++) {
      S21Matrix A(rows, columns);
      S21Matrix C;
      S21Matrix D;

      fill_matrix_rand(A);

      C = A + A;
      D = A;
      D.MulNumber(2);

      EXPECT_TRUE(C == D);
    }
  }
}

TEST(SumSubMatrix, ThrowsOutOfRange_WhenMatrixDiffSize) {
  for (int rows = 1; rows <= 10; rows++) {
    for (int columns = 1; columns <= 10; columns++) {
      S21Matrix A(rows, columns);
      S21Matrix B(rows + 1, columns + 1);

      fill_matrix_rand(A);
      fill_matrix_rand(B);

      EXPECT_THROW(A + B, std::out_of_range);
      EXPECT_THROW(B + A, std::out_of_range);
      EXPECT_THROW(A - B, std::out_of_range);
      EXPECT_THROW(B - A, std::out_of_range);
    }
  }
}