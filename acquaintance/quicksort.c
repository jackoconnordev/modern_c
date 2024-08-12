#include "err.h"
#include "stdio.h"
#include "stdlib.h"

#define SIZE_NUMBERS 10

void printarray(int size, int array[]) {
  printf("%s", "[ ");
  for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("%s", "]\n");
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/* Returns the index `i` of the pivot value from quicksort's partition
 * step. Every value with a lower index than `i` will be smaller than the
 * pivot value, and every value with a greater index than `i` will be larger
 * than the pivot value.
 */
int partition(int left, int right, int array[]) {
  int i = left - 1, j = left;
  int pivot = array[right];

  while (j < right) {
    if (array[j] < pivot) {
      ++i;
      swap(&array[i], &array[j]);
    }
    ++j;
  }

  // `i` can never be as big as `j` / `right` or this swap will
  // swap the last element in the partition with garbage.
  swap(&array[i + 1], &array[right]);

  return i + 1;
}

/* Sorts `array` in-place. */
void quicksort(int left, int right, int array[]) {
  // Only sort arrays of size 2 or greater
  if (left < right) {
    int pivot_idx = partition(left, right, array);
    quicksort(left, pivot_idx - 1, array);
    quicksort(pivot_idx + 1, right, array);
  }
}

int main(int argc, char *argv[argc + 1]) {
  int numbers[SIZE_NUMBERS];

  // ensure numbers populated with zeros
  for (int i = 0; i < SIZE_NUMBERS; ++i) {
    numbers[i] = 0;
  }

  if (argc - 1 > SIZE_NUMBERS) {
    errx(1, "Sorting more than %d numbers is not possible right now",
         SIZE_NUMBERS);
  }

  // read in command line arguments
  const char *errstr;
  for (int i = 1; i < argc; ++i) {
    numbers[i] = strtonum(argv[i], INT32_MIN, INT32_MAX, &errstr);
    if (errstr != NULL) {
      errx(EXIT_FAILURE, "%s", errstr);
    }
  }

  // quicksort time
  quicksort(0, SIZE_NUMBERS - 1, numbers);

  // print sorted array
  printarray(SIZE_NUMBERS, numbers);

  return EXIT_SUCCESS;
}
