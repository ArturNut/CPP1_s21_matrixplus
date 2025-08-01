#include <gtest/gtest.h>

#include "support_matrix_test.h"

TEST(DeterminantMatrix, СalculateDeterminant_WhenMatrixSquare) {
  double check_result = 18.0;
  S21Matrix A(4, 4);

  A(0, 0) = 3.0;
  A(0, 1) = -3.0;
  A(0, 2) = -5.0;
  A(0, 3) = 8.0;
  A(1, 0) = -3.0;
  A(1, 1) = 2.0;
  A(1, 2) = 4.0;
  A(1, 3) = -6.0;
  A(2, 0) = 2.0;
  A(2, 1) = -5.0;
  A(2, 2) = -7.0;
  A(2, 3) = 5.0;
  A(3, 0) = -4.0;
  A(3, 1) = 3.0;
  A(3, 2) = 5.0;
  A(3, 3) = -6.0;

  EXPECT_EQ(A.Determinant(), check_result);
}

TEST(DeterminantMatrix, СalculateDeterminant_WhenMatrixSquare_1) {
  double check_result = -60.0;
  S21Matrix A(4, 4);

  A(0, 0) = 5;
  A(0, 1) = 8;
  A(0, 2) = 0;
  A(0, 3) = -4;
  A(1, 0) = 0;
  A(1, 1) = 1;
  A(1, 2) = 10;
  A(1, 3) = 1;
  A(2, 0) = 0;
  A(2, 1) = 0;
  A(2, 2) = -4;
  A(2, 3) = 0;
  A(3, 0) = 0;
  A(3, 1) = 0;
  A(3, 2) = 0;
  A(3, 3) = 3;

  EXPECT_EQ(A.Determinant(), check_result);
}

TEST(DeterminantMatrix, СalculateDeterminant_WhenMatrixSquare_2) {
  double check_result = 24300.0;
  S21Matrix A(7, 7);

  A(0, 0) = 3;
  A(0, 1) = -3;
  A(0, 2) = 10;
  A(0, 3) = 8;
  A(0, 4) = 3;
  A(0, 5) = -3;
  A(0, 6) = -5;
  A(1, 0) = -3;
  A(1, 1) = 2;
  A(1, 2) = 4;
  A(1, 3) = -6;
  A(1, 4) = -3;
  A(1, 5) = 2;
  A(1, 6) = 4;
  A(2, 0) = 2;
  A(2, 1) = -5;
  A(2, 2) = -7;
  A(2, 3) = 5;
  A(2, 4) = 2;
  A(2, 5) = -5;
  A(2, 6) = -7;
  A(3, 0) = -4;
  A(3, 1) = 3;
  A(3, 2) = 5;
  A(3, 3) = -6;
  A(3, 4) = -4;
  A(3, 5) = 3;
  A(3, 6) = 5;
  A(4, 0) = 8;
  A(4, 1) = -3;
  A(4, 2) = -5;
  A(4, 3) = 8;
  A(4, 4) = 3;
  A(4, 5) = -3;
  A(4, 6) = -5;
  A(5, 0) = 7;
  A(5, 1) = 2;
  A(5, 2) = 4;
  A(5, 3) = -6;
  A(5, 4) = -3;
  A(5, 5) = 2;
  A(5, 6) = 4;
  A(6, 0) = 2;
  A(6, 1) = 4;
  A(6, 2) = -7;
  A(6, 3) = 5;
  A(6, 4) = 2;
  A(6, 5) = -5;
  A(6, 6) = -7;

  EXPECT_EQ(A.Determinant(), check_result);
}

TEST(DeterminantMatrix, СalculateDeterminant_WhenMatrix_2x2) {
  S21Matrix A(2, 2);
  double check_result = 26;

  A(0, 0) = 6;
  A(0, 1) = -4;
  A(1, 0) = 2;
  A(1, 1) = 3;

  EXPECT_EQ(A.Determinant(), check_result);
}

TEST(DeterminantMatrix, СalculateDeterminant_WhenMatrix_1x1) {
  S21Matrix A(1, 1);
  double check_result = 55;

  A(0, 0) = 55;

  EXPECT_EQ(A.Determinant(), check_result);
}

TEST(DeterminantMatrix, ThrowsOutOfRange_WhenMatrixNonSquare) {
  S21Matrix A(4, 5);
  EXPECT_THROW(A.Determinant(), std::out_of_range);
}