#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

class S21Matrix {
 private:
  int rows_, cols_;  // rows and columns attributes
  double* matrix_;   // pointer to the memory where the matrix will be allocated
  void resize(int newRows, int newCols);
  int plus_or_minus_pattern(int i, int j) const;

 public:
  S21Matrix();                        // default constructor
  S21Matrix(int rows, int cols);      // parameterized constructor
  S21Matrix(const S21Matrix& other);  // copy constructor
  S21Matrix(S21Matrix&& other);       // move constructor
  ~S21Matrix();                       // destructor

  int getRows() const;  // accessor
  int getCols() const;  // accessor
  //   double* getMatrix() const;
  void setRows(int newRows);  // mutator
  void setCols(int newCols);

  // some operators overloads
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  bool operator==(const S21Matrix& other) const;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  // Для чтения и записи
  double& operator()(int row, int col);  // assignment operator overload
  // Для чтения (константная версия)
  double operator()(int row, int col) const;  // index operator overload

  // some public methods

  // Проверяет матрицы на равенство между собой
  bool EqMatrix(const S21Matrix& other) const;

  // Прибавляет вторую матрицу к текущей
  void SumMatrix(const S21Matrix& other);

  // Вычитает из текущей матрицы другую
  void SubMatrix(const S21Matrix& other);

  // Умножает текущую матрицу на число.
  void MulNumber(const double num);

  // Умножает текущую матрицу на вторую.
  void MulMatrix(const S21Matrix& other);

  // Создает новую транспонированную матрицу из текущей и возвращает ее.
  S21Matrix Transpose() const;

  // Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает
  // ее.
  S21Matrix CalcComplements() const;

  // Вычисляет и возвращает определитель текущей матрицы.
  double Determinant() const;

  // Вычисляет и возвращает обратную матрицу.
  S21Matrix InverseMatrix() const;

  // получение матрицы вычеркиванием заданной строки g и столбца k
  S21Matrix minor_of_the_element(int g, int k) const;
};

#endif
