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
  int c[3] = {};
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

void test_vector_hadamard_product() {}

void test_matrix_by_vector() {}

void test_matrix_addition() {}

void test_matrix_hadamard_product() {}

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
