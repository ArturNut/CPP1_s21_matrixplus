#include <gtest/gtest.h>

#include "support_matrix_test.h"

TEST(CalcComplementsMatrix, CalculatesMatrixAlgebraicComplements) {
  S21Matrix A(3, 3);
  S21Matrix result(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 2;
  A(2, 0) = 5;
  A(2, 1) = 2;
  A(2, 2) = 1;

  result(0, 0) = 0;
  result(0, 1) = 10;
  result(0, 2) = -20;
  result(1, 0) = 4;
  result(1, 1) = -14;
  result(1, 2) = 8;
  result(2, 0) = -8;
  result(2, 1) = -2;
  result(2, 2) = 4;

  EXPECT_EQ(A.CalcComplements(), result);
}

TEST(CalcComplementsMatrix,
     CalculatesMatrixAlgebraicComplements_WhenMatrix_1x1) {
  S21Matrix A(1, 1);

  A(0, 0) = 10;

  EXPECT_EQ(A.CalcComplements(), A);
}

TEST(CalcComplementsMatrix,
     CalculatesMatrixAlgebraicComplements_WhenMatrix_2x2) {
  S21Matrix A(2, 2);
  S21Matrix result(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  result(0, 0) = 4;
  result(0, 1) = -3;
  result(1, 0) = -2;
  result(1, 1) = 1;

  EXPECT_EQ(A.CalcComplements(), result);
}

TEST(CalcComplementsMatrix, ThrowsOutOfRange_WhenMatrixNonSquare) {
  S21Matrix A(4, 5);
  EXPECT_THROW(A.CalcComplements(), std::out_of_range);
}