#include <gtest/gtest.h>

#include "support_matrix_test.h"

TEST(MultiplicationAssignment, CorrectMulMatrix) {
  for (int rows = 1; rows <= 2; rows++) {
    S21Matrix A(rows, rows);
    S21Matrix C;

    fill_matrix_rand(A);

    C = A * A * A * A;
    A *= A;
    A *= A;

    EXPECT_TRUE(A == C);
  }
}

TEST(MultiplicationAssignment, ThrowsOutOfRange_WhenRowsNotEqualColumns) {
  for (int rows = 1; rows <= 10; rows++) {
    for (int cols = 2; cols <= 11 && cols != rows; cols++) {
      S21Matrix A(rows, cols);
      S21Matrix B(rows, cols);

      fill_matrix_rand(A);
      fill_matrix_rand(B);

      EXPECT_THROW(A *= B, std::out_of_range);
    }
  }
}