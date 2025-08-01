#include <gtest/gtest.h>

#include "support_matrix_test.h"

TEST(OperatorIndexMatrix, ThrowsOutOfRange) {
  S21Matrix A(7, 7);

  EXPECT_THROW(A(8, 8) = 7, std::out_of_range);
  EXPECT_THROW(A(7, 7) = 7, std::out_of_range);
  EXPECT_NO_THROW(A(0, 0) = 7);
  EXPECT_THROW(A(-1, -1) = 7, std::out_of_range);

  const S21Matrix B(7, 7);

  EXPECT_THROW(B(8, 8), std::out_of_range);
  EXPECT_THROW(B(7, 7), std::out_of_range);
  EXPECT_NO_THROW(B(0, 0));
  EXPECT_THROW(B(-1, -1), std::out_of_range);
}