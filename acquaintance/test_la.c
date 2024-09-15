/* Tests for standard linear algebra functions. */

#include <assert.h>
#include <stdlib.h>

void test_vector_addition() {}

void test_vector_dot_product() {}

void test_vector_hadamard_product() {}

void test_matrix_by_vector() {}

void test_matrix_by_matrix() {}

void test_matrix_by_vector_dimension_error_message() {}

void test_matrix_by_matrix_dimension_error_message() {}

void test_matrix_transpose() {}

void test_matrix_to_echelon_form() {}

void test_matrix_to_reduced_row_echelon_form() {}

void test_matrix_inverse() {}

void test_matrix_inverse_dimension_error_message() {}

int main(int argc, char *argv[]) {
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
