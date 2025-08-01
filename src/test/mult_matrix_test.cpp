#include <gtest/gtest.h>

#include "support_matrix_test.h"

TEST(Mult_Matrix, AssociativityMatrix) {
  for (int rows = 1; rows <= 10; rows++) {
    S21Matrix A(rows, rows);
    S21Matrix B(rows, rows);
    S21Matrix C(rows, rows);

    fill_matrix_rand(A);
    fill_matrix_rand(B);
    fill_matrix_rand(C);

    // ассоциативность (A*B)*C=A*(B*C)
    EXPECT_TRUE((A * B) * C == A * (B * C));
  }
}

TEST(Mult_Matrix, AssociativityMatrix_1) {
  for (int rows = 1; rows <= 10; rows++) {
    for (int cols = 2; cols <= 11; cols++) {
      S21Matrix A(rows, cols);
      S21Matrix B(cols, rows);
      S21Matrix C(rows, rows);

      fill_matrix_rand(A);
      fill_matrix_rand(B);
      fill_matrix_rand(C);

      // ассоциативность (A*B)*C=A*(B*C)
      EXPECT_TRUE((A * B) * C == A * (B * C));
    }
  }
}

TEST(Mult_Matrix, NonCommutativityMatrix) {
  for (int rows = 1; rows <= 10; rows++) {
    for (int cols = 2; cols <= 11; cols++) {
      S21Matrix A(rows, cols);
      S21Matrix B(cols, rows);

      fill_matrix_rand(A);
      fill_matrix_rand(B);

      // некоммутативность A*B != B*A
      EXPECT_FALSE(A * B == B * A);
    }
  }
}

TEST(Mult_Matrix, DistributivityMatrix) {
  for (int rows = 1; rows <= 10; rows++) {
    for (int cols = 2; cols <= 11; cols++) {
      S21Matrix A(rows, cols);
      S21Matrix B(rows, cols);
      S21Matrix C(cols, rows);

      fill_matrix_rand(A);
      fill_matrix_rand(B);
      fill_matrix_rand(C);

      // дистрибутивность (A+B)*C = A*C + B*C
      EXPECT_TRUE((A + B) * C == A * C + B * C);
    }
  }
}

TEST(Mult_Matrix, ThrowsOutOfRange_WhenRowsNotEqualColumns) {
  for (int rows = 1; rows <= 10; rows++) {
    for (int cols = 2; cols <= 11 && cols != rows; cols++) {
      S21Matrix A(rows, cols);
      S21Matrix B(rows, cols);

      fill_matrix_rand(A);
      fill_matrix_rand(B);

      EXPECT_THROW(A * B, std::out_of_range);
    }
  }
}