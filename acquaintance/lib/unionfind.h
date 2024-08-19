#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <stddef.h>

struct UnionFindSet {
  size_t *elements;
  size_t *sizes;
  size_t size;
};

struct UnionFindSet ufset_init(size_t num_elements);

void ufset_dealloc(struct UnionFindSet ufset);

void ufset_print(struct UnionFindSet ufset);

void ufset_find(struct UnionFindSet ufset, size_t element);

void ufset_find_replace(struct UnionFindSet ufset, size_t element,
                        size_t value);

void ufset_find_compress(struct UnionFindSet ufset, size_t element);

void ufset_union(struct UnionFindSet ufset, size_t element_1, size_t element_2);

#endif // !UNIONFIND_H
