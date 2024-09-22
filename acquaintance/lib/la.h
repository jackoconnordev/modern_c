#ifndef LA_H
#define LA_H

#include <stdbool.h>

// Yes, opaque pointers for vec_t and mat_t would mean I don't need size params
bool eq_vector(int va[], int vb[], int size);

void add_vector(int vres[], int va[], int vb[], int size);

int dot_vector(int va[], int vb[], int size);

void hadamard_vector(int vres[], int va[], int vb[], int size);

void matrix_by_vector(int vres[], int m[], int v[], int size);

#endif // !LA_H
