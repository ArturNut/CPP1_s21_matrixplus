#include <gtest/gtest.h>

#include "support_matrix_test.h"

TEST(AdditionAssignmentMatrix, CorrectSumMatrix) {
  for (int rows = 1; rows <= 10; rows++) {
    S21Matrix A(rows, rows);
    S21Matrix B;

    fill_matrix_rand(A);

    B = A + A + A + A;
    A += A;
    A += A;

    EXPECT_TRUE(A == B);
  }
}

TEST(AdditionAssignmentMatrix, OperatorThrowsOutOfRange_WhenMatrixDiffSize) {
  for (int rows = 1; rows <= 10; rows++) {
    S21Matrix A(rows, rows);
    S21Matrix B(rows + 1, rows + 1);

    fill_matrix_rand(A);
    fill_matrix_rand(B);

    EXPECT_THROW(A += B, std::out_of_range);
  }
}
