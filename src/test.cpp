#include <gtest/gtest.h>

#include <iostream>

#include "s21_matrix_oop.h"

using std::cout;
using std::endl;

const double array[] = {
    4.12512,      1.32345,      5.3434,  9.123,   3.423,
    -7,           -21.26,       6,       1,       0.4157,
    0.5006,       0.1884,       0.2344,  0.8225,  0.4371,
    0.0808,       0.013,        0.8204,  0.5015,  0.7873,
    0.1538,       0.9806,       0.9468,  0.078,   0.4977,
    0.743,        -0.0434,      0.9209,  0.749,   0.6829,
    0.739,        0.1384,       0.8109,  0.5913,  0.6107,
    0.2687,       -0.3779,      0.7682,  0.2943,  0.8724,
    0.3116,       0.1198,       0.2749,  0.0641,  0.5021,
    -0.8657,      0.4406,       0.6234,  0.171,   0.0579,
    0.086,        0.55,         0.8024,  0.5736,  -0.1404,
    0.1462,       0.6172,       0.4292,  0.058,   0.2317,
    0.5967,       0.4873,       0.1726,  -0.5706, 0.6767,
    0.3622,       0.3775,       0.643,   0.2117,  0.1683,
    0.703,        0.2448,       -0.5261, 0.6291,  0.4757,
    0.0339,       0.7057,       0.8827,  0.5759,  0.6319,
    0.3025,       -0.42,        0.7499,  0.6911,  0.5967,
    0.1891,       0.336,        0.2373,  0.4509,  0.4646,
    -0.6515,      0.9486,       0.7103,  0.0626,  0.2757,
    0.8244,       0.9472,       0.7044,  -0.3874, 0.1399,
    0.4882,       0.7975,       0.4117,  0.0027,  0.3549,
    0.8414,       0.0239,       -0.1733, 0.098,   0.1065,
    0.4405,       0.7345,       0.8534,  0.426,   0.9292,
    0.1767,       -0.7374,      0.4815,  0.9739,  0.4876,
    0.0262,       0.1403,       0.1921,  0.7472,  -0.5169,
    0.7543,       0.5345,       0.4635,  0.3534,  0.6513,
    0.0867,       0.0013,       0.4953,  -0.4359, 0.1437,
    0.5049,       0.0084,       0.7472,  0.3362,  0.7553,
    0.1652,       0.1627,       -0.1393, 0.3445,  0.024,
    0.9169,       0.0952,       0.2843,  0.1334,  0.099,
    0.087,        -0.4658,      0.7305,  0.8998,  0.1138,
    0.3479,       0.6054,       0.6645,  0.4858,  -0.6006,
    0.3069,       0.5604,       0.8199,  0.4466,  0.0198,
    0.4392,       0.2393,       0.4175,  -0.2823, 0.4243,
    0.1683,       0.9902,       0.1453,  0.2186,  0.3224,
    0.8634,       0.001,        -0.8476, 0.7231,  0.5999,
    0.6591,       0.2503,       0.3301,  0.2544,  0.5644,
    0.6209,       0.2708,       0.5955,  0.3221,  0.7958,
    0.8995,       0.3439,       0.2614,  0.7356,  0.4484,
    -0.6048,      0.3428,       0.6927,  0.3247,  0.5848,
    0.6776,       0.6777,       0.002,   0.7091,  0.9307,
    -0.0968,      0.3205,       0.5119,  0.5774,  124234.4353,
    2342424.6435, -235234.6433, 7654,    124,     1,
    0.0,          -0.0,         2341.314};

// Other foo

void fill_matrixArray(const double array[], S21Matrix* matrix);
void fillIdentity(S21Matrix* matrix);
void fill_matrix(S21Matrix* matrix);
std::ostream& print_matrix(std::ostream& os, const S21Matrix& matrix);
std::ostream& operator<<(std::ostream& os, const S21Matrix& m);

// EXCEPTION TEST
// TEST CONSTRUCTORS

#ifndef __APPLE__
TEST(test_constructor, test1) {
  EXPECT_THROW(S21Matrix A(-1, 2), std::out_of_range);
}

TEST(test_constructor, test2) {
  EXPECT_THROW(S21Matrix A(0, 0), std::out_of_range);
}

TEST(test_constructor, test4) {
  S21Matrix A;
  EXPECT_THROW(A.get_matrix(3, 0), std::out_of_range);
}

// TEST MUTATORS

TEST(test_mutator, test1) {
  S21Matrix A(1, 1);
  EXPECT_THROW(A.set_rows(-3), std::out_of_range);
}

TEST(test_mutator, test2) {
  S21Matrix A(1, 1);
  EXPECT_THROW(A.set_cols(-3), std::out_of_range);
}

TEST(test_mutator, test3) {
  S21Matrix A(1, 1);
  EXPECT_THROW(A.set_matrix(-1, 1, 0.5), std::out_of_range);
}

// TEST ACCESSORS

TEST(test_accessor, test4) {
  S21Matrix A(2, 2);
  EXPECT_THROW((A.get_matrix(2, 1)), std::out_of_range);
}

// TEST SUM MATRIX

TEST(test_sum_matrix, test1) {
  S21Matrix A;
  S21Matrix B(1, 5);
  EXPECT_THROW(A.sum_matrix(B), std::invalid_argument);
}

// TEST SUB MATRIX

TEST(test_sub_matrix, test1) {
  S21Matrix A;
  S21Matrix B(1, 5);
  EXPECT_THROW(A.sub_matrix(B), std::invalid_argument);
}

// TEST MUL MATRIX

TEST(test_mult_matrix, test2) {
  S21Matrix A(3, 1);
  fill_matrix(&A);
  S21Matrix B(5, 1);
  fill_matrix(&B);
  EXPECT_ANY_THROW(A.mul_matrix(B));
}

TEST(test_mult_matrix, test3) {
  S21Matrix A(3, 3);
  fill_matrix(&A);
  S21Matrix B(std::move(A));
  EXPECT_ANY_THROW(B.mul_matrix(A));
}

// TEST TRANSPOSE

TEST(test_transpose_matrix, test3) {
  S21Matrix A(5, 1);
  fill_matrixArray(array, &A);
  S21Matrix B(std::move(A));
  EXPECT_ANY_THROW(A.transpose());
}

// TEST DETERM

TEST(test_determ, test4) {
  S21Matrix A(5, 1);
  fill_matrixArray(array, &A);
  EXPECT_ANY_THROW(A.determinant());
}

// TEST CALC COMPLEMENTS

TEST(test_complements, test3) {
  S21Matrix A(3, 2);
  fill_matrix(&A);
  EXPECT_ANY_THROW(S21Matrix B = A.calc_complements());
}

// TEST INVERSE

TEST(test_inverse, test2) {
  S21Matrix A(5, 1);
  fill_matrixArray(array, &A);
  EXPECT_ANY_THROW(A.inverse_matrix());
}

TEST(test_inverse, test3) {
  S21Matrix A(5, 5);
  fill_matrixArray(array, &A);
  S21Matrix B(std::move(A));
  EXPECT_ANY_THROW(A.inverse_matrix());
}

TEST(test_inverse, test4) {
  S21Matrix A(5, 5);
  fill_matrix(&A);
  EXPECT_ANY_THROW(A.inverse_matrix());
}

// TEST OPERATOR +

TEST(test_operator_plus, test1) {
  S21Matrix A(5, 5);
  S21Matrix B;
  fill_matrixArray(array, &A);
  EXPECT_ANY_THROW(B + A);
}

// TEST OPERATOR -

TEST(test_operator_minus, test1) {
  S21Matrix A(5, 5);
  S21Matrix B;
  fill_matrixArray(array, &A);
  EXPECT_ANY_THROW(B - A);
}

// TEST OPERATOR *

TEST(test_operator_mul, test1) {
  S21Matrix A(3);
  S21Matrix B(4);
  fill_matrixArray(array, &A);
  fill_matrixArray(array, &B);
  EXPECT_ANY_THROW(B * A);
}
// CPPCHECK FIND ERROR OF MOVE BUT IS OK
/*
TEST(test_operator_mul, test4) {
  S21Matrix A(3, 3);
  S21Matrix C(std::move(A));
  double B = 0.5;
  EXPECT_ANY_THROW(A * B);
}
*/
// TEST OPERATOR +=

TEST(test_operator_plusEq, test2) {
  S21Matrix A;
  S21Matrix B(1, 7);
  fill_matrix(&A);
  EXPECT_ANY_THROW(A += B);
}

// TEST OPERATOR -=

TEST(test_operator_minusEq, test2) {
  S21Matrix A;
  S21Matrix B(1, 7);
  fill_matrix(&A);
  EXPECT_ANY_THROW(A -= B);
}

// TEST OPERATOR *=

TEST(test_operator_mulEq, test1) {
  S21Matrix A(3);
  S21Matrix B(4);
  fill_matrixArray(array, &A);
  fill_matrixArray(array, &B);
  EXPECT_ANY_THROW(B * A);
}

TEST(test_operator_brace, test2) {
  S21Matrix A(3, 3);
  fill_matrixArray(array, &A);
  EXPECT_ANY_THROW(A(5, 2));
}

#endif

// NORMAL TESTS
// TEST CONSTRUCTORS

TEST(test_constructor, test3) {
  S21Matrix A(1, 1);
  A.set_matrix(0, 0, 0.234);
  ASSERT_DOUBLE_EQ(A.get_matrix(0, 0), 0.234);
}

TEST(test_constructor, test5) {
  S21Matrix A(3, 2);
  A.set_matrix(2, 1, 0.234);
  S21Matrix B(A);
  ASSERT_DOUBLE_EQ(B.get_matrix(2, 1), 0.234);
}

TEST(test_constructor, test6) {
  S21Matrix A(3, 2);
  A.set_matrix(2, 1, 0.234);
  S21Matrix B(std::move(A));
  ASSERT_DOUBLE_EQ(B.get_matrix(2, 1), 0.234);
}

// TEST MUTATORS

TEST(test_mutator, test4) {
  S21Matrix A(1, 1);
  A.set_cols(3);
  ASSERT_DOUBLE_EQ(A.get_matrix(0, 2), 0.0);
}

TEST(test_mutator, test5) {
  S21Matrix A(1, 1);
  A.set_rows(5);
  ASSERT_DOUBLE_EQ(A.get_matrix(4, 0), 0.0);
}

TEST(test_mutator, test6) {
  S21Matrix A(3, 3);
  A.set_matrix(2, 2, 0.1231);
  ASSERT_DOUBLE_EQ(A.get_matrix(2, 2), 0.1231);
}

// TEST ACCESSORS

TEST(test_accessor, test1) {
  S21Matrix A(2, 2);
  double num = A.get_matrix(1, 1);
  ASSERT_DOUBLE_EQ(num, 0.0);
}

TEST(test_accessor, test2) {
  S21Matrix A(2, 2);
  int num = A.get_rows();
  ASSERT_EQ(num, 2);
}

TEST(test_accessor, test3) {
  S21Matrix A(2, 2);
  int num = A.get_cols();
  ASSERT_EQ(num, 2);
}

// TEST EQ MATRIX

TEST(test_eq_matrix, test1) {
  S21Matrix A;
  fill_matrix(&A);
  S21Matrix B(A);
  ASSERT_TRUE(A.eq_matrix(B));
}

TEST(test_eq_matrix, test2) {
  S21Matrix A;
  fill_matrix(&A);
  S21Matrix B;
  fill_matrixArray(array, &B);
  ASSERT_FALSE(A.eq_matrix(B));
}

TEST(test_eq_matrix, test3) {
  S21Matrix A;
  fill_matrix(&A);
  S21Matrix B(2, 3);
  fill_matrixArray(array, &B);
  ASSERT_FALSE(A.eq_matrix(B));
}

TEST(test_eq_matrix, test4) {
  S21Matrix A;
  fill_matrix(&A);
  S21Matrix B(3, 3);
  fill_matrixArray(array, &B);
  ASSERT_FALSE(A.eq_matrix(B));
}

// TEST SUM MATRIX

TEST(test_sum_matrix, test2) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  A.set_matrix(3, 3, 0.5);
  B.set_matrix(3, 3, 0.5);
  A.sum_matrix(B);
  ASSERT_DOUBLE_EQ(A.get_matrix(3, 3), 1.0);
}

// TEST SUB MATRIX

TEST(test_sub_matrix, test2) {
  S21Matrix A(5, 5);
  S21Matrix B(5, 5);
  A.set_matrix(3, 3, 0.5);
  B.set_matrix(3, 3, 0.5);
  A.sub_matrix(B);
  ASSERT_DOUBLE_EQ(A.get_matrix(3, 3), 0.0);
}

// TEST MUL NUMBER

TEST(test_mul_matrix, test1) {
  S21Matrix A;
  double number = 2;
  fill_matrix(&A);
  A.mul_number(number);
  ASSERT_DOUBLE_EQ(A.get_matrix(1, 1), 8.0);
}

// TEST MUL MATRIX

TEST(test_mult_matrix, test1) {
  S21Matrix A(5, 1);
  fill_matrix(&A);
  S21Matrix B(1);
  fill_matrix(&B);
  A.mul_matrix(B);
  ASSERT_DOUBLE_EQ(A.get_matrix(0, 0), 0.0);
}

// TEST TRANSPOSE

TEST(test_transpose_matrix, test1) {
  S21Matrix A(5, 2);
  int row, col;
  row = A.get_rows();
  col = A.get_cols();
  A.transpose();
  ASSERT_TRUE((row == A.get_cols() && col == A.get_rows()));
}

TEST(test_transpose_matrix, test2) {
  S21Matrix A(1, 2);
  A.set_matrix(0, 1, 15);
  A.transpose();
  ASSERT_DOUBLE_EQ(A.get_matrix(1, 0), 15);
}

// TEST DETERMINANT

TEST(test_determ, test1) {
  S21Matrix A;
  fill_matrixArray(array, &A);
  double determ = A.determinant();
  ASSERT_DOUBLE_EQ(determ, 1053.599490942001);
}

TEST(test_determ, test2) {
  S21Matrix A;
  fill_matrix(&A);
  double determ = A.determinant();
  ASSERT_DOUBLE_EQ(determ, 0.0);
}

TEST(test_determ, test3) {
  S21Matrix A(1, 1);
  fill_matrixArray(array, &A);
  double determ = A.determinant();
  ASSERT_DOUBLE_EQ(determ, 4.12512);
}

// TEST CALC COMPL

TEST(test_complements, test1) {
  S21Matrix A;
  fill_matrix(&A);
  S21Matrix B = A.calc_complements();
  ASSERT_DOUBLE_EQ(B.get_matrix(1, 1), -12);
}

TEST(test_complements, test2) {
  S21Matrix A(1, 1);
  fill_matrix(&A);
  S21Matrix B = A.calc_complements();
  ASSERT_DOUBLE_EQ(B.get_matrix(0, 0), 1);
}

// TEST INVERSE MATR

TEST(test_inverse, test1) {
  S21Matrix A;
  S21Matrix B;
  S21Matrix Identity;
  fillIdentity(&Identity);
  fillIdentity(&B);
  fill_matrixArray(array, &A);
  S21Matrix C = A.inverse_matrix();
  A.mul_matrix(C);
  ASSERT_EQ(A.eq_matrix(Identity), true);
}

// TEST OPERATORS

// TEST OPERATOR "="

TEST(test_operator_eq, test1) {
  S21Matrix A(5, 5);
  S21Matrix B;
  fill_matrixArray(array, &A);
  B = A;
  ASSERT_DOUBLE_EQ(B.get_matrix(4, 4), 0.4977);
}

// TEST OPERATOR "+"

TEST(test_operator_plus, test2) {
  S21Matrix A(3);
  S21Matrix B(3);
  fill_matrixArray(array, &A);
  fill_matrixArray(array, &B);
  B.mul_number(-1);
  A + B;
  ASSERT_DOUBLE_EQ(A.get_matrix(2, 2), 0.0);
}

// TEST OPERATOR "-"

TEST(test_operator_minus, test2) {
  S21Matrix A(3);
  S21Matrix B(3);
  fill_matrixArray(array, &A);
  fill_matrixArray(array, &B);
  A - B;
  ASSERT_DOUBLE_EQ(A.get_matrix(2, 2), 0.0);
}

// TEST OPERATOR "*"

TEST(test_operator_mul, test2) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  fill_matrix(&A);
  fill_matrix(&B);
  A* B;
  ASSERT_DOUBLE_EQ(A.get_matrix(2, 2), 111);
}

TEST(test_operator_mul, test3) {
  S21Matrix A(3, 3);
  double B = 0.5;
  fill_matrix(&A);
  A* B;
  ASSERT_DOUBLE_EQ(A.get_matrix(2, 2), 8 * 0.5);
}

TEST(test_operator_mul, test5) {
  S21Matrix A(3, 3);
  double B = 0.5;
  fill_matrix(&A);
  S21Matrix C(B * A);
  ASSERT_DOUBLE_EQ(C.get_matrix(2, 2), 8 * 0.5);
}

// TEST OPERATOR "+="

TEST(test_operator_plusEq, test1) {
  S21Matrix A;
  fill_matrix(&A);
  A += A;
  ASSERT_DOUBLE_EQ(A.get_matrix(2, 2), 8 + 8);
}

// TEST OPERATOR "-="

TEST(test_operator_minusEq, test1) {
  S21Matrix A;
  fill_matrix(&A);
  A -= A;
  ASSERT_DOUBLE_EQ(A.get_matrix(2, 2), 0);
}

// TEST OPERATOR "*="

TEST(test_operator_mulEq, test2) {
  S21Matrix A(3, 3);
  fill_matrix(&A);
  S21Matrix B(A);
  A *= B;
  ASSERT_DOUBLE_EQ(A.get_matrix(2, 2), 111);
}

TEST(test_operator_mulEq, test3) {
  S21Matrix A(3, 3);
  fill_matrix(&A);
  double B = 0.5;
  A *= B;
  ASSERT_DOUBLE_EQ(A.get_matrix(2, 2), 8 / 2);
}

// TEST OPERATOR "=="

TEST(test_operator_eqEq, test1) {
  S21Matrix A(3, 3);
  fill_matrix(&A);
  S21Matrix B(A);
  ASSERT_EQ(A == B, true);
}

TEST(test_operator_eqEq, test2) {
  S21Matrix A(3, 3);
  fill_matrix(&A);
  S21Matrix B(4, 4);
  ASSERT_EQ(A == B, false);
}

// TEST OPERATOR "()"

TEST(test_operator_brace, test1) {
  S21Matrix A(3, 3);
  fill_matrixArray(array, &A);
  ASSERT_DOUBLE_EQ(A(2, 2), array[8]);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// Declare other foo

void fill_matrixArray(const double array[], S21Matrix* matrix) {
  int rows = matrix->get_rows();
  int cols = matrix->get_cols();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix->set_matrix(i, j, (array[i * rows + j]));
    }
  }
}

void fillIdentity(S21Matrix* matrix) {
  int rows = matrix->get_rows();
  int cols = matrix->get_cols();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == j)
        matrix->set_matrix(i, j, 1.0);
      else
        matrix->set_matrix(i, j, 0.0);
    }
  }
}

void fill_matrix(S21Matrix* matrix) {
  int rows = matrix->get_rows();
  int cols = matrix->get_cols();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix->set_matrix(i, j, (i * rows + j));
    }
  }
}

#if DEBUG == 1

std::ostream& print_matrix(std::ostream& os, const S21Matrix& matrix) {
  int rows = matrix.get_rows();
  int cols = matrix.get_cols();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      os << matrix.get_matrix(i, j) << "\t";
    }
    os << endl;
  }
  cout << "--------------" << endl;
  return os;
}

std::ostream& operator<<(std::ostream& os, const S21Matrix& m) {
  return print_matrix(os, m);
}

#endif
