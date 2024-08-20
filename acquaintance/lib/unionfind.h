/**
 * I have combined interface and implementation doc comments in the
 * implementation file because I am lazy.
 */
#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <stddef.h>

struct UnionFindSet {
  size_t *elements;
  size_t *sizes;
  size_t size;
};

struct UnionFindSet ufset_init(size_t num_elements);

void ufset_dealloc(struct UnionFindSet *ufset);

void ufset_print(struct UnionFindSet *ufset);

size_t ufset_find(struct UnionFindSet *ufset, size_t element,
                  size_t *root_size);

size_t ufset_get_size(struct UnionFindSet *ufset, size_t element);

size_t ufset_union(struct UnionFindSet *ufset, size_t element1, size_t element2,
                   size_t *root_size);

size_t ufset_find_compress(struct UnionFindSet *ufset, size_t element,
                           size_t *root_size);

size_t ufset_funky_union(struct UnionFindSet *ufset, size_t element1,
                         size_t element2, size_t *root_size);

size_t ufset_weighted_union(struct UnionFindSet *ufset, size_t element1,
                            size_t element2, size_t *root_size);

void ufset_compress(struct UnionFindSet *ufset);

#endif // !UNIONFIND_H
