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
