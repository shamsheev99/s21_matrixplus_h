#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <math.h>

#include <exception>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

// Constant EPSILON for Equal
constexpr double EPS = 1e-7;

class S21Matrix {
 public:
  // A basic constructor that initialises a matrix of some predefined dimension
  S21Matrix();
  // Parametrized constructor with number of rows and columns
  S21Matrix(int rows, int cols);
  // Parametrized constructor with number of rows = columns
  explicit S21Matrix(int rows);
  // Copy constructor
  S21Matrix(const S21Matrix& other);
  // Move constructor
  S21Matrix(S21Matrix&& other);

  // Accessors
  int get_rows() const;
  int get_cols() const;
  double get_matrix(int row, int col) const;
  // Mutators
  void set_rows(int rows);
  void set_cols(int cols);
  void set_matrix(int row, int col, double num);

  // Destructor
  ~S21Matrix();
  //  Checks matrices for equality with each other
  bool eq_matrix(const S21Matrix& other);
  // Adds the second matrix to the current one
  void sum_matrix(const S21Matrix& other);
  // Subtracts another matrix from the current one
  void sub_matrix(const S21Matrix& other);
  // Multiplies the current matrix by a number
  void mul_number(const double num);
  // Multiplies the current matrix by the second matrix
  void mul_matrix(const S21Matrix& other);
  //  Creates a new transposed matrix from the current one and returns it
  S21Matrix transpose();
  // Calculates the algebraic addition matrix of the current one and returns it
  S21Matrix calc_complements();
  // Calculates and returns the determinant of the current matrix
  double determinant();
  // Calculates and returns the inverse matrix
  S21Matrix inverse_matrix();
  // Addition of two matrices
  S21Matrix operator+(const S21Matrix& other);
  // Subtraction of one matrix from another
  S21Matrix operator-(const S21Matrix& other);
  // Matrix multiplication and matrix multiplication by a number
  S21Matrix operator*(const double num);
  S21Matrix operator*(const S21Matrix& other);
  friend S21Matrix operator*(const double left, const S21Matrix& right);

  // Checks for matrices equality (eq_matrix)
  bool operator==(const S21Matrix& other);
  // Assignment of values from one matrix to another one
  S21Matrix& operator=(const S21Matrix& other);
  // Addition assignment (sum_matrix)
  S21Matrix& operator+=(const S21Matrix& other);
  // Difference assignment (sub_matrix)
  S21Matrix& operator-=(const S21Matrix& other);
  // Difference assignment (mul_matrix)
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*=(const double num);
  // Indexation by matrix elements (row, column)
  double operator()(int row, int col);

  // Other private functions
 private:
  void get_minor(int row, int column);
  bool check_matrix() const;
  bool checkSize_matrix(const S21Matrix& other) const;
  bool checkSquare_matrix() const;
  void create_matrix();
  void remove_matrix();
  void resize_matrix(int rows, int cols);
  void copy_matrix(const S21Matrix& other);

 public:
  friend std::ostream& operator<<(std::ostream& os, const S21Matrix& m);

 private:
  // Attributes
  // Rows and columns
  int _rows, _cols;
  // Pointer to the memory where the matrix is allocated
  double** _matrix;
};

#endif  // SRC_S21_MATRIX_OOP_H_
