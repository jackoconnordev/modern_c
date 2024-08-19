#include "unionfind.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printarray_ptr(size_t size, size_t *array) {
  printf("%s", "[ ");
  for (size_t i = 0; i < size; ++i) {
    printf("%zu ", array[i]);
  }
  printf("%s", "]\n");
}

struct UnionFindSet ufset_init(size_t size) {
  bool malloc_failed = false;
  size_t *elements = malloc(sizeof(size_t) * size);
  if (elements == NULL) {
    malloc_failed = true;
  }

  size_t *sizes = malloc(sizeof(size_t) * size);
  if (sizes == NULL) {
    malloc_failed = true;
  }

  if (malloc_failed) {
    struct UnionFindSet aborted_ufset = {NULL, NULL, 0};
    return aborted_ufset;
  }

  struct UnionFindSet ufset = {elements, sizes, size};

  return ufset;
}

void ufset_dealloc(struct UnionFindSet *ufset) {
  free(ufset->elements);
  free(ufset->sizes);
  ufset->elements = NULL;
  ufset->sizes = NULL;
}

void ufset_print(struct UnionFindSet *ufset) {
  printarray_ptr(ufset->size, ufset->elements);
  printarray_ptr(ufset->size, ufset->sizes);
}

size_t ufset_find(struct UnionFindSet *ufset, size_t element) {
  // TODO: Don't allow element1 or element2 bigger than ufset->size
  size_t parent = ufset->elements[element];
  while (parent != element) {
    element = parent;
    parent = ufset->elements[element];
  }
  return parent;
}

void ufset_union(struct UnionFindSet *ufset, size_t element1, size_t element2) {
  // TODO: Don't allow element1 or element2 bigger than ufset->size
  size_t parent_element1 = ufset->elements[element1];
  size_t parent_element2 = ufset->elements[element2];

  while (parent_element1 != element1) {
    element1 = parent_element1;
    parent_element1 = ufset->elements[element1];
  }

  while (parent_element2 != element2) {
    element2 = parent_element2;
    parent_element2 = ufset->elements[element2];
  }

  ufset->elements[parent_element1] = parent_element2;
}

void ufset_find_replace(struct UnionFindSet *ufset, size_t element,
                        size_t value) {
  // TODO: Don't allow element1 or element2 bigger than ufset->size
}

void ufset_weighted_union(struct UnionFindSet *ufset, size_t element1,
                          size_t element2) {
  // TODO: Don't allow element1 or element2 bigger than ufset->size
  size_t parent_element1 = ufset->elements[element1];
  size_t parent_element2 = ufset->elements[element2];

  while (parent_element1 != element1) {
    element1 = parent_element1;
    parent_element1 = ufset->elements[element1];
  }

  while (parent_element2 != element2) {
    element2 = parent_element2;
    parent_element2 = ufset->elements[element2];
  }

  if (ufset->sizes[parent_element1] < ufset->sizes[parent_element2]) {
    ufset->elements[parent_element1] = parent_element2;
    ufset->sizes[parent_element2] =
        ufset->sizes[parent_element1] + ufset->sizes[parent_element2];
    ufset->sizes[parent_element1] = 0;
  } else {
    ufset->elements[parent_element2] = parent_element1;
    ufset->sizes[parent_element1] =
        ufset->sizes[parent_element2] + ufset->sizes[parent_element1];
    ufset->sizes[parent_element2] = 0;
  }
}
