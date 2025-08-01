#include <gtest/gtest.h>

#include "support_matrix_test.h"

TEST(DifferenceAssignment, CorrectSubMatrix) {
  for (int rows = 1; rows <= 10; rows++) {
    S21Matrix A(rows, rows);
    S21Matrix B(rows, rows);
    S21Matrix C;

    fill_matrix_rand(A);
    fill_matrix_rand(B);

    C = A - B - B - B;
    A -= B;
    A -= B;
    A -= B;

    EXPECT_TRUE(A == C);
  }
}

TEST(DifferenceAssignment, OperatorThrowsOutOfRange_WhenMatrixDiffSize) {
  for (int rows = 1; rows <= 10; rows++) {
    S21Matrix A(rows, rows);
    S21Matrix B(rows + 1, rows + 1);

    fill_matrix_rand(A);
    fill_matrix_rand(B);

    EXPECT_THROW(A -= B, std::out_of_range);
  }
}