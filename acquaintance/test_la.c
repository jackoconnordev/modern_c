/* Tests for standard linear algebra functions. */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "la.h"

void test_vector_equals() {
  puts("test_vector_equals:");
  int a[3] = {1, 2, 3};
  int b[3] = {1, 2, 3};
  assert(eq_vector(a, b, 3));

  int c[3] = {1, 2, 4};
  assert(!eq_vector(a, c, 3));
  puts("passed");
}

void test_vector_addition() {
  puts("test_vector_addition:");
  int a[3] = {1, 3, 6};
  int b[3] = {2, 4, 6};
  int c[3] = {0};
  int d[3] = {3, 7, 12};

  add_vector(c, a, b, 3);
  assert(eq_vector(c, d, 3));
  puts("passed");
}

void test_vector_dot_product() {
  puts("test_vector_dot_product:");
  int a[3] = {1, 2, 3};
  int b[3] = {2, 4, 6};
  assert(dot_vector(a, b, 3) - 28);

  int c[3] = {-1, -2, -3};
  assert(dot_vector(a, c, 3) + 14);
  puts("passed");
}

void test_vector_hadamard_product() {
  puts("test_vector_hadamard_product:");
  int a[3] = {2, 3, 4};
  int b[3] = {4, 3, 2};
  int c[3] = {0};
  int d[3] = {8, 9, 8};

  hadamard_vector(c, a, b, 3);
  assert(eq_vector(c, d, 3));
  puts("passed");
}

void test_matrix_by_vector() {
  puts("test_matrix_by_vector:");
  int nrow = 2;
  int ncol = 3;
  int m[6] = {9, 7, 4, 8, 7, 9};
  int v[3] = {5, 2, 1};
  int vres[2] = {0};
  int d[2] = {63, 63};

  matrix_by_vector(vres, m, nrow, ncol, v);
  assert(eq_vector(vres, d, nrow));
  puts("passed");
}

void test_matrix_equals() {
  puts("test_matrix_equals:");
  int nrow = 2;
  int ncol = 3;
  int a[6] = {9, 7, 4, 8, 7, 9};
  int b[6] = {9, 7, 4, 8, 7, 9};
  assert(eq_matrix(a, b, nrow, ncol));

  int c[6] = {9, 9, 9, 9, 9, 9};
  assert(!eq_matrix(a, c, nrow, ncol));
  puts("passed");
}

void test_matrix_addition() {
  puts("test_matrix_addition:");
  int nrow = 2;
  int ncol = 2;
  int a[4] = {1, 2, 3, 4};
  int b[4] = {2, 3, 4, 5};
  int c[4] = {0};
  int d[4] = {3, 5, 7, 9};

  add_matrix(c, a, b, nrow, ncol);
  assert(eq_matrix(c, d, nrow, ncol));
  puts("passed");
}

void test_matrix_hadamard_product() {
  puts("test_matrix_hadamard_product");
  int nrow = 2;
  int ncol = 2;
  int a[4] = {1, 2, 3, 4};
  int b[4] = {1, 2, 3, 4};
  int c[4] = {0};
  int d[4] = {1, 4, 9, 16};

  hadamard_matrix(c, a, b, nrow, ncol);
  assert(eq_matrix(c, d, nrow, ncol));
  puts("passed");
}

void test_matrix_by_matrix() {}

void test_matrix_by_vector_dimension_error_message() {}

void test_matrix_by_matrix_dimension_error_message() {}

void test_matrix_transpose() {}

void test_matrix_to_echelon_form() {}

void test_matrix_to_reduced_row_echelon_form() {}

void test_matrix_inverse() {}

void test_matrix_inverse_dimension_error_message() {}

int main(int argc, char *argv[]) {
  test_vector_equals();
  test_vector_addition();
  test_vector_dot_product();
  test_vector_hadamard_product();
  test_matrix_by_vector();
  test_matrix_equals();
  test_matrix_addition();
  test_matrix_hadamard_product();
  test_matrix_by_matrix();
  test_matrix_by_vector_dimension_error_message();
  test_matrix_by_matrix_dimension_error_message();
  test_matrix_transpose();
  test_matrix_to_echelon_form();
  test_matrix_to_reduced_row_echelon_form();
  test_matrix_inverse();
  test_matrix_inverse_dimension_error_message();
  return EXIT_SUCCESS;
}
