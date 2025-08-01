#include <gtest/gtest.h>

#include "support_matrix_test.h"

class S21MatrixTest : public ::testing::Test {
 protected:
  S21Matrix A;
  S21Matrix B;
};

TEST_F(S21MatrixTest, CreatedObjectClass_WhenDefaultConstructor) {
  EXPECT_EQ(A.getRows(), 1);
  EXPECT_EQ(A.getCols(), 1);
  EXPECT_EQ(B.getRows(), 1);
  EXPECT_EQ(B.getCols(), 1);
}

TEST(ParameterizedConstructorMatrix, CreatedObjectClass_WhenRowsAndColsValid) {
  S21Matrix C(10, 10);

  EXPECT_EQ(C.getRows(), 10);
  EXPECT_EQ(C.getCols(), 10);
}

TEST(ParameterizedConstructorMatrix,
     ThrowsOutOfRange_WhenRowsAndColsLessOrEqualZerro) {
  EXPECT_THROW(S21Matrix C(0, 0), std::out_of_range);
  EXPECT_THROW(S21Matrix C(1, 0), std::out_of_range);
  EXPECT_THROW(S21Matrix C(0, 1), std::out_of_range);
  EXPECT_THROW(S21Matrix C(-1, -1), std::out_of_range);
  EXPECT_THROW(S21Matrix C(-1, 1), std::out_of_range);
  EXPECT_NO_THROW(S21Matrix C(10, 10));
}

TEST(CopyConstructorMatrix, CreatedCopyObjectClass) {
  S21Matrix original(2, 2);

  original(0, 0) = 1.0;
  original(0, 1) = 2.0;
  original(1, 0) = 3.0;
  original(1, 1) = 4.0;

  S21Matrix copy(original);

  EXPECT_EQ(copy(0, 0), 1.0);
  EXPECT_EQ(copy(0, 1), 2.0);
  EXPECT_EQ(copy(1, 0), 3.0);
  EXPECT_EQ(copy(1, 1), 4.0);

  original(0, 0) = 5;
  EXPECT_EQ(copy(0, 0), 1.0);
}

TEST(CopyConstructorMatrix, MemoryIndependence) {
  S21Matrix original(5, 5);
  original(0, 0) = 10.0;

  S21Matrix copy(original);

  // EXPECT_NE(original.getMatrix(), copy.getMatrix());

  copy(0, 0) = 5;
  EXPECT_EQ(original(0, 0), 10.0);
}

TEST(MovedConstructorMatrix, CreatedMovedObjectClass) {
  S21Matrix original(2, 2);

  original(0, 0) = 1.0;
  original(0, 1) = 2.0;
  original(1, 0) = 3.0;
  original(1, 1) = 4.0;

  // double* original_pointer = original.getMatrix();

  S21Matrix moved(std::move(original));

  EXPECT_EQ(moved(0, 0), 1.0);
  EXPECT_EQ(moved(0, 1), 2.0);
  EXPECT_EQ(moved(1, 0), 3.0);
  EXPECT_EQ(moved(1, 1), 4.0);

  // EXPECT_EQ(original_pointer, moved.getMatrix());

  EXPECT_EQ(original.getRows(), 0.0);
  EXPECT_EQ(original.getCols(), 0.0);
  // EXPECT_EQ(original.getMatrix(), nullptr);
}

TEST(MovedConstructorMatrix, SourceObjectIsValidAfterMove) {
  S21Matrix original(3, 3);
  original(1, 1) = 5.0;

  S21Matrix moved(std::move(original));

  EXPECT_EQ(original.getRows(), 0.0);
  EXPECT_EQ(original.getCols(), 0.0);
  // EXPECT_EQ(original.getMatrix(), nullptr);

  original = S21Matrix(2, 2);
  EXPECT_EQ(original.getRows(), 2);
  EXPECT_EQ(original.getCols(), 2);
}

TEST(MovedConstructorMatrix, MovesFromTemporary) {
  S21Matrix moved = S21Matrix(2, 2);

  EXPECT_EQ(moved.getRows(), 2);
  EXPECT_EQ(moved.getCols(), 2);
}

TEST(ConstructorMatrix, WorksWithStdContainers) {
  std::vector<S21Matrix> matrices;
  matrices.push_back(S21Matrix(2, 2));

  EXPECT_EQ(matrices[0].getRows(), 2);
  EXPECT_EQ(matrices[0].getCols(), 2);
}