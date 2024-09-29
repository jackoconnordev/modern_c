#include "la.h"
#include <stdbool.h>

bool eq_vector(int va[], int vb[], int size) {
  for (int i = 0; i < size; ++i) {
    if (va[i] != vb[i]) {
      return false;
    }
  }
  return true;
};

bool eq_matrix(int ma[], int mb[], int nrow, int ncol) {
  for (int i = 0; i < nrow; ++i) {
    for (int j = 0; j < ncol; ++j) {
      int idx = i * ncol + j;
      if (ma[idx] != mb[idx]) {
        return false;
      }
    }
  }
  return true;
};

void add_vector(int vres[], int va[], int vb[], int size) {
  for (int i = 0; i < size; ++i) {
    vres[i] = va[i] + vb[i];
  }
};

int dot_vector(int va[], int vb[], int size) {
  int res = 0;
  for (int i = 0; i < size; ++i) {
    res += va[i] + vb[i];
  }
  return res;
}

void hadamard_vector(int vres[], int va[], int vb[], int size) {
  for (int i = 0; i < size; ++i) {
    vres[i] = va[i] * vb[i];
  }
}

/* vres must be all zeros */
void matrix_by_vector(int vres[], int m[], int nrow, int ncol, int v[]) {
  for (int i = 0; i < nrow; ++i) {
    for (int j = 0; j < ncol; ++j) {
      vres[i] += v[j] * m[i * ncol + j];
    }
  }
}

void add_matrix(int mres[], int ma[], int mb[], int nrow, int ncol) {
  for (int i = 0; i < nrow; ++i) {
    for (int j = 0; j < ncol; ++j) {
      int idx = i * ncol + j;
      mres[idx] = ma[idx] + mb[idx];
    }
  }
}

void hadamard_matrix(int mres[], int ma[], int mb[], int nrow, int ncol) {
  for (int i = 0; i < nrow; ++i) {
    for (int j = 0; j < ncol; ++j) {
      int idx = i * ncol + j;
      mres[idx] = ma[idx] * mb[idx];
    }
  }
}
