#include <gtest/gtest.h>

#include "support_matrix_test.h"

class S21MatrixTest : public ::testing::Test {
 protected:
  S21Matrix A;
  S21Matrix B;
};

TEST_F(S21MatrixTest, EqualMatrixs_WhenRowsAndColsEqual) {
  S21Matrix original(10, 10);
  fill_matrix_rand(original);
  A = original;

  EXPECT_TRUE(A == original);
  EXPECT_TRUE(A == A);
  EXPECT_TRUE(original == original);
}

TEST_F(S21MatrixTest, NotEqualMatrixs_WhenDiffSize) {
  S21Matrix original(10, 10);
  fill_matrix(original);
  A = original;

  original.setCols(5);
  original.setRows(5);

  B = original;

  EXPECT_FALSE(A == B);
}

TEST_F(S21MatrixTest, NotEqualMatrixs_WhenDifferentsElements) {
  S21Matrix original(10, 10);
  fill_matrix_rand(original);
  A = original;

  fill_matrix(original);

  B = original;

  EXPECT_FALSE(A == B);
}

TEST_F(S21MatrixTest, EqualMatrixs_WhenZeroMatrix) { EXPECT_TRUE(A == B); }

TEST_F(S21MatrixTest, EqualMatrixs_WhenNearEqualWithEpsilon) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A(1, 1) = 0.0000000188;
  B(1, 1) = 0.0000000199;

  EXPECT_TRUE(A == B);
}