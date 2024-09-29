#ifndef LA_H
#define LA_H

#include <stdbool.h>

// Yes, opaque pointers for vec_t and mat_t would mean I don't need size params
bool eq_vector(int va[], int vb[], int size);

bool eq_matrix(int ma[], int mb[], int nrow, int ncol);

void add_vector(int vres[], int va[], int vb[], int size);

int dot_vector(int va[], int vb[], int size);

void hadamard_vector(int vres[], int va[], int vb[], int size);

void matrix_by_vector(int vres[], int m[], int nrow, int ncol, int v[]);

void add_matrix(int mres[], int ma[], int mb[], int nrow, int ncol);

void hadamard_matrix(int mres[], int ma[], int mb[], int nrow, int ncol);

#endif // !LA_H
