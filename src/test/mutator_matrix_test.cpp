#include <gtest/gtest.h>

#include "support_matrix_test.h"

TEST(MutatorMatrix, ThrowsOutOfRange_WhenRowsLessOrEqualZerro) {
  S21Matrix original(3, 3);

  EXPECT_THROW(original.setRows(0), std::out_of_range);
  EXPECT_THROW(original.setRows(-1), std::out_of_range);
  EXPECT_NO_THROW(original.setRows(1));
  EXPECT_NO_THROW(original.setRows(7));
}

TEST(MutatorMatrix, ThrowsOutOfRange_WhenColsLessOrEqualZerro) {
  S21Matrix original(3, 3);

  EXPECT_THROW(original.setCols(0), std::out_of_range);
  EXPECT_THROW(original.setCols(-1), std::out_of_range);
  EXPECT_NO_THROW(original.setCols(1));
  EXPECT_NO_THROW(original.setCols(7));
}

TEST(MutatorMatrix, CorrectMatrix_WhenSetRowsDecreases) {
  S21Matrix original(3, 3);
  fill_matrix(original);

  EXPECT_EQ(original(0, 0), 0.0);
  EXPECT_EQ(original(0, 1), 1.0);
  EXPECT_EQ(original(0, 2), 2.0);
  EXPECT_EQ(original(1, 0), 3.0);
  EXPECT_EQ(original(1, 1), 4.0);
  EXPECT_EQ(original(1, 2), 5.0);
  EXPECT_EQ(original(2, 0), 6.0);
  EXPECT_EQ(original(2, 1), 7.0);
  EXPECT_EQ(original(2, 2), 8.0);

  original.setRows(2);

  EXPECT_EQ(original(0, 0), 0.0);
  EXPECT_EQ(original(0, 1), 1.0);
  EXPECT_EQ(original(0, 2), 2.0);
  EXPECT_EQ(original(1, 0), 3.0);
  EXPECT_EQ(original(1, 1), 4.0);
  EXPECT_EQ(original(1, 2), 5.0);

  original.setRows(1);

  EXPECT_EQ(original(0, 0), 0.0);
  EXPECT_EQ(original(0, 1), 1.0);
  EXPECT_EQ(original(0, 2), 2.0);
}

TEST(MutatorMatrix, CorrectMatrix_WhenSetRowsIncreases) {
  S21Matrix original(2, 2);
  fill_matrix(original);

  EXPECT_EQ(original(0, 0), 0.0);
  EXPECT_EQ(original(0, 1), 1.0);
  EXPECT_EQ(original(1, 0), 2.0);
  EXPECT_EQ(original(1, 1), 3.0);

  original.setRows(3);

  EXPECT_EQ(original(0, 0), 0.0);
  EXPECT_EQ(original(0, 1), 1.0);
  EXPECT_EQ(original(1, 0), 2.0);
  EXPECT_EQ(original(1, 1), 3.0);
  EXPECT_EQ(original(2, 0), 0.0);
  EXPECT_EQ(original(2, 1), 0.0);

  original.setRows(4);

  EXPECT_EQ(original(0, 0), 0.0);
  EXPECT_EQ(original(0, 1), 1.0);
  EXPECT_EQ(original(1, 0), 2.0);
  EXPECT_EQ(original(1, 1), 3.0);
  EXPECT_EQ(original(2, 0), 0.0);
  EXPECT_EQ(original(2, 1), 0.0);
  EXPECT_EQ(original(3, 0), 0.0);
  EXPECT_EQ(original(3, 1), 0.0);
}

TEST(MutatorMatrix, CorrectMatrix_WhenSetColsDecreases) {
  S21Matrix original(3, 3);
  fill_matrix(original);

  EXPECT_EQ(original(0, 0), 0.0);
  EXPECT_EQ(original(0, 1), 1.0);
  EXPECT_EQ(original(0, 2), 2.0);
  EXPECT_EQ(original(1, 0), 3.0);
  EXPECT_EQ(original(1, 1), 4.0);
  EXPECT_EQ(original(1, 2), 5.0);
  EXPECT_EQ(original(2, 0), 6.0);
  EXPECT_EQ(original(2, 1), 7.0);
  EXPECT_EQ(original(2, 2), 8.0);

  original.setCols(2);

  EXPECT_EQ(original(0, 0), 0.0);
  EXPECT_EQ(original(0, 1), 1.0);
  EXPECT_EQ(original(1, 0), 3.0);
  EXPECT_EQ(original(1, 1), 4.0);
  EXPECT_EQ(original(2, 0), 6.0);
  EXPECT_EQ(original(2, 1), 7.0);

  original.setCols(1);

  EXPECT_EQ(original(0, 0), 0.0);
  EXPECT_EQ(original(1, 0), 3.0);
  EXPECT_EQ(original(2, 0), 6.0);
}

TEST(MutatorMatrix, CorrectMatrix_WhenSetColsIncreases) {
  S21Matrix original(2, 2);
  fill_matrix(original);

  EXPECT_EQ(original(0, 0), 0.0);
  EXPECT_EQ(original(0, 1), 1.0);
  EXPECT_EQ(original(1, 0), 2.0);
  EXPECT_EQ(original(1, 1), 3.0);

  original.setCols(3);

  EXPECT_EQ(original(0, 0), 0.0);
  EXPECT_EQ(original(0, 1), 1.0);
  EXPECT_EQ(original(0, 2), 0.0);
  EXPECT_EQ(original(1, 0), 2.0);
  EXPECT_EQ(original(1, 1), 3.0);
  EXPECT_EQ(original(1, 2), 0.0);

  original.setCols(4);

  EXPECT_EQ(original(0, 0), 0.0);
  EXPECT_EQ(original(0, 1), 1.0);
  EXPECT_EQ(original(0, 2), 0.0);
  EXPECT_EQ(original(0, 3), 0.0);
  EXPECT_EQ(original(1, 0), 2.0);
  EXPECT_EQ(original(1, 1), 3.0);
  EXPECT_EQ(original(1, 2), 0.0);
  EXPECT_EQ(original(0, 3), 0.0);
}