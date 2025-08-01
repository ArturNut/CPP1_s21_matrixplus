#include "s21_matrix_oop.h"

#include <cstring>
#include <iostream>

namespace {
constexpr double EPSILON = 1e-5;
}

// default constructor
S21Matrix::S21Matrix() {
  rows_ = 1;
  cols_ = 1;
  matrix_ = new double[rows_ * cols_]();
}

// parameterized constructor
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::out_of_range(
        "Invalid input, rows and columns must be greater than zero");
  }
  matrix_ = new double[rows_ * cols_]();
}

// copy constructor
S21Matrix::S21Matrix(const S21Matrix& o) : rows_(o.rows_), cols_(o.cols_) {
  matrix_ = new double[o.rows_ * o.cols_]();
  std::memcpy(matrix_, o.matrix_, o.rows_ * o.cols_ * sizeof(double));
}

// move constructor
S21Matrix::S21Matrix(S21Matrix&& o) : rows_(o.rows_), cols_(o.cols_) {
  matrix_ = o.matrix_;
  o.matrix_ = nullptr;
  o.rows_ = 0;
  o.cols_ = 0;
}

// destructor
S21Matrix::~S21Matrix() {
  if (matrix_) {
    delete[] matrix_;
  }
}

// accessor
int S21Matrix::getRows() const { return rows_; }

int S21Matrix::getCols() const { return cols_; }

// double* S21Matrix::getMatrix() const { return matrix_; }

// mutator
void S21Matrix::setRows(int newRows) { resize(newRows, cols_); }

void S21Matrix::setCols(int newCols) { resize(rows_, newCols); }

void S21Matrix::resize(int newRows, int newCols) {
  if (newRows <= 0 || newCols <= 0) {
    throw std::out_of_range(
        "Invalid input, rows and columns must be greater than zero");
  }

  int min_rows = (newRows > rows_ ? rows_ : newRows);
  int min_cols = (newCols > cols_ ? cols_ : newCols);

  double* matrix_temp = new double[newRows * newCols]();

  for (int i = 0; i < min_rows; i++) {
    for (int j = 0; j < min_cols; j++) {
      matrix_temp[i * newCols + j] = matrix_[i * cols_ + j];
    }
  }

  rows_ = newRows;
  cols_ = newCols;
  delete[] matrix_;
  matrix_ = matrix_temp;
  matrix_temp = nullptr;
}

// Проверяет матрицы на равенство между собой
bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (std::abs((*this)(i, j) - other(i, j)) > EPSILON) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }

  for (auto i = 0; i < rows_; i++) {
    for (auto j = 0; j < cols_; j++) {
      (*this)(i, j) = (*this)(i, j) + other(i, j);
    }
  }
}

// Вычитает из текущей матрицы другую
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }

  for (auto i = 0; i < rows_; i++) {
    for (auto j = 0; j < cols_; j++) {
      (*this)(i, j) = (*this)(i, j) - other(i, j);
    }
  }
}

// Умножает текущую матрицу на число.
void S21Matrix::MulNumber(const double num) {
  for (auto i = 0; i < rows_; i++) {
    for (auto j = 0; j < cols_; j++) {
      (*this)(i, j) = (*this)(i, j) * num;
    }
  }
}

// Умножает текущую матрицу на вторую.
void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::out_of_range(
        "Количество столбцов в матрице 'A' должно быть равно количеству строк "
        "в матрице 'B'");
  }

  S21Matrix res(rows_, other.cols_);
  double sum = 0.0;

  for (auto i = 0; i < rows_; i++) {
    for (auto j = 0; j < other.cols_; j++) {
      for (int k = 0; k < other.rows_; k++) {
        sum = sum + (*this)(i, k) * other(k, j);
      }
      res(i, j) = sum;
      sum = 0.0;
    }
  }
  *this = std::move(res);
}

// Создает новую транспонированную матрицу из текущей и возвращает ее.
S21Matrix S21Matrix::Transpose() {
  S21Matrix res(cols_, rows_);

  for (auto i = 0; i < cols_; i++) {
    for (auto j = 0; j < rows_; j++) {
      res(i, j) = (*this)(j, i);
    }
  }
  return res;
}

// Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее.
S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::out_of_range("Матрица не является квадратной");
  }

  if (rows_ == 1 && cols_ == 1) {
    return *this;
  }

  double sub_det = 0.0;
  S21Matrix calc(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix sub_matrix = (*this).minor_of_the_element(i, j);
      sub_det = sub_matrix.Determinant();
      calc(i, j) = plus_or_minus_pattern(i, j) * sub_det;
    }
  }
  return calc;
}

int S21Matrix::plus_or_minus_pattern(int i, int j) {
  int result = 1;
  if (i % 2 == 0) {
    result = (j % 2 == 0 ? 1 : -1);
  } else {
    result = (j % 2 == 0 ? -1 : 1);
  }
  return result;
}

// Вычисляет и возвращает определитель текущей матрицы.
double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::out_of_range("Матрица не является квадратной");
  }

  if (rows_ == 1 && cols_ == 1) {
    return (*this)(0, 0);
  }
  if (rows_ == 2 && cols_ == 2) {
    return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
  }

  double result = 0.0;
  double sub_det = 0.0;

  for (int k = 0; k < cols_; k++) {
    S21Matrix sub_matrix = (*this).minor_of_the_element(0, k);
    sub_det = sub_matrix.Determinant();
    result += (k % 2 == 0 ? 1 : -1) * (*this)(0, k) * sub_det;
  }

  return result;
}

// получение матрицы вычеркиванием заданной строки g и столбца k
S21Matrix S21Matrix::minor_of_the_element(int g, int k) {
  S21Matrix res(rows_ - 1, cols_ - 1);
  int sub_i = 0;
  int sub_j = 0;

  for (auto i = 0; i < rows_; i++) {
    if (i == g) {
      continue;
    }

    for (auto j = 0; j < cols_; j++) {
      if (j == k) {
        continue;
      }

      res(sub_i, sub_j) = (*this)(i, j);
      sub_j++;
    }
    sub_i++;
    sub_j = 0;
  }
  return res;
}

// Вычисляет и возвращает обратную матрицу.
S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::out_of_range("Матрица не является квадратной");
  }

  double det = Determinant();

  if (det == 0) {
    throw std::out_of_range(
        "Определитель равен 0, обратной матрицы не существует");
  }

  S21Matrix res = (*this).CalcComplements();
  res = res.Transpose();
  res.MulNumber(rows_ > 1 ? 1 / det : 1 / (det * det));

  return res;
}

// operator overload example
S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix res(*this);
  res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix res(*this);
  res.SubMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  if (this == &other) {
    return true;
  }
  return EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    delete[] matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = new double[other.rows_ * other.cols_]();
    std::memcpy(matrix_, other.matrix_,
                other.rows_ * other.cols_ * sizeof(double));
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  (*this).SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  (*this).SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  (*this).MulMatrix(other);
  return *this;
}

// Для чтения и записи
double& S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row * cols_ + col];
}

// Для чтения (константная версия)
double S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row * cols_ + col];
}