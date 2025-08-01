#include <gtest/gtest.h>

#include "support_matrix_test.h"

TEST(MinorOfTheElementMatrix, MinorMatrixCorrect) {
  S21Matrix A(4, 4);

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(0, 3) = 4.0;
  A(1, 0) = 5.0;
  A(1, 1) = 6.0;
  A(1, 2) = 7.0;
  A(1, 3) = 8.0;
  A(2, 0) = 9.0;
  A(2, 1) = 10.0;
  A(2, 2) = 11.0;
  A(2, 3) = 12.0;
  A(3, 0) = 13.0;
  A(3, 1) = 14.0;
  A(3, 2) = 15.0;
  A(3, 3) = 16.0;

  S21Matrix B = A.minor_of_the_element(0, 0);

  EXPECT_EQ(B(0, 0), 6.0);
  EXPECT_EQ(B(0, 1), 7.0);
  EXPECT_EQ(B(0, 2), 8.0);
  EXPECT_EQ(B(1, 0), 10.0);
  EXPECT_EQ(B(1, 1), 11.0);
  EXPECT_EQ(B(1, 2), 12.0);
  EXPECT_EQ(B(2, 0), 14.0);
  EXPECT_EQ(B(2, 1), 15.0);
  EXPECT_EQ(B(2, 2), 16.0);
}

TEST(MinorOfTheElementMatrix, MinorMatrixCorrect_1) {
  S21Matrix A(4, 4);

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(0, 3) = 4.0;
  A(1, 0) = 5.0;
  A(1, 1) = 6.0;
  A(1, 2) = 7.0;
  A(1, 3) = 8.0;
  A(2, 0) = 9.0;
  A(2, 1) = 10.0;
  A(2, 2) = 11.0;
  A(2, 3) = 12.0;
  A(3, 0) = 13.0;
  A(3, 1) = 14.0;
  A(3, 2) = 15.0;
  A(3, 3) = 16.0;

  S21Matrix B = A.minor_of_the_element(1, 1);

  EXPECT_EQ(B(0, 0), 1.0);
  EXPECT_EQ(B(0, 1), 3.0);
  EXPECT_EQ(B(0, 2), 4.0);
  EXPECT_EQ(B(1, 0), 9.0);
  EXPECT_EQ(B(1, 1), 11.0);
  EXPECT_EQ(B(1, 2), 12.0);
  EXPECT_EQ(B(2, 0), 13.0);
  EXPECT_EQ(B(2, 1), 15.0);
  EXPECT_EQ(B(2, 2), 16.0);
}