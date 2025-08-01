#include "support_matrix_test.h"

#include <iostream>
#include <random>

namespace {
constexpr double MIN = 1;
constexpr double MAX = 100;
}  // namespace

double rand_in_range() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(MIN, MAX);
  return dist(gen);
}

void fill_matrix_rand(S21Matrix& mat) {
  for (int i = 0; i < mat.getRows(); ++i) {
    for (int j = 0; j < mat.getCols(); ++j) {
      mat(i, j) = rand_in_range();
    }
  }
}

void fill_matrix(S21Matrix& mat) {
  double count = 0.0;
  for (int i = 0; i < mat.getRows(); ++i) {
    for (int j = 0; j < mat.getCols(); ++j) {
      mat(i, j) = count++;
    }
  }
}

// void print_matrix(S21Matrix& mat) {
//   for (int i = 0; i < mat.getRows(); ++i) {
//     for (int j = 0; j < mat.getCols(); ++j) {
//       std::cout << mat.getMatrix()[i * mat.getCols() + j] << " ";
//     }
//     std::cout << '\n';
//   }
// }