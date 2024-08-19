#include "unionfind.h"
#include <stdbool.h>
#include <stdlib.h>

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

void ufset_dealloc(struct UnionFindSet ufset) {
  free(ufset.elements);
  free(ufset.sizes);
  ufset.elements = NULL;
  ufset.sizes = NULL;
}
