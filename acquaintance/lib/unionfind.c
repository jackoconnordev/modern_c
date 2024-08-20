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
    fprintf(stderr, "Process memory exceeded.\n");
  }

  // initialise correct values for elements and sizes
  for (size_t i = 0; i < size; ++i) {
    elements[i] = i;
    sizes[i] = 1;
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
  if (ufset->elements == NULL || ufset->sizes == NULL) {
    fprintf(stderr, "UnionFindSet has been deallocated.\n");
    return;
  }
  printf("Elements: ");
  printarray_ptr(ufset->size, ufset->elements);
  printf("   Sizes: ");
  printarray_ptr(ufset->size, ufset->sizes);
}

/**
 * Returns the index of the root of element's set. If element is not in the
 * UnionFindSet returns SIZE_MAX.
 * If root_size is not NULL, set the size of the tree element is a part of
 * there.
 */
size_t ufset_find(struct UnionFindSet *ufset, size_t element,
                  size_t *root_size) {
  if (element >= ufset->size) {
    fprintf(stdout,
            "Aborting attempt to perform find replace as element (%zu) is "
            "not an elmement.\n",
            element);
    return SIZE_MAX;
  }

  size_t parent = ufset->elements[element];
  while (parent != element) {
    element = parent;
    parent = ufset->elements[element];
  }

  if (root_size != NULL) {
    *root_size = ufset->sizes[parent];
  }

  return parent;
}

/**
 * Returns the size of the set which element is a part of. Only the sizes of
 * root elements are maintained and up to date so you really should use this
 * function if you want the size of an element's tree, rather than checking
 * ufset->sizes[element].
 */
size_t ufset_get_size(struct UnionFindSet *ufset, size_t element) {
  size_t root = ufset_find(ufset, element, NULL);
  return ufset->sizes[root];
}

/**
 * Naive union, doesn't attempt to keep the tree depths small at all.
 * The root of element1 will be set to point to the root of element2.
 * If root_size is not NULL, set the size of the tree element is a part of
 * there.
 */
size_t ufset_union(struct UnionFindSet *ufset, size_t element1, size_t element2,
                   size_t *root_size) {
  if (element1 >= ufset->size) {
    fprintf(stdout,
            "Aborting attempt to perform union as element1 (%zu) is "
            "not an elmement.\n",
            element1);
    return SIZE_MAX;
  }
  if (element2 >= ufset->size) {
    fprintf(stdout,
            "Aborting attempt to perform union as element2 (%zu) is "
            "not an elmement.\n",
            element2);
    return SIZE_MAX;
  }

  // Get elements' roots.
  size_t parent_element1 = ufset->elements[element1];
  while (parent_element1 != element1) {
    element1 = parent_element1;
    parent_element1 = ufset->elements[element1];
  }
  size_t size_element1 = ufset->sizes[parent_element1];

  size_t parent_element2 = ufset->elements[element2];
  while (parent_element2 != element2) {
    element2 = parent_element2;
    parent_element2 = ufset->elements[element2];
  }
  size_t size_element2 = ufset->sizes[parent_element2];

  ufset->elements[parent_element1] = parent_element2;

  // Adjust sizes
  ufset->sizes[parent_element2] = size_element1 + size_element2;

  if (root_size != NULL) {
    *root_size = ufset->sizes[parent_element2];
  }

  return parent_element2;
}

/**
 * Set all parent entries on a path to element's root to value. This is only
 * really useful if value is equal to a member of a set that is being merged
 * into.
 * This is a one-pass algorithm. Call this after ufset_find_compress which is
 * a two pass algorithm and set value equal to the root element of
 * find_compress.
 * I'm not maintaining size here, I don't like this function since it's "loose",
 * but I'll put it here since int's in the Modern C exercise asks.
 * If root_size is not NULL then put the size of element's tree (not factoring
 * in if new parent values) in it.
 */
size_t ufset_find_replace(struct UnionFindSet *ufset, size_t element,
                          size_t value, size_t *root_size) {
  if (element >= ufset->size) {
    fprintf(stdout,
            "Aborting attempt to perform find replace as element (%zu) is "
            "not an elmement.\n",
            element);
    return SIZE_MAX;
  }
  if (value >= ufset->size) {
    fprintf(stdout,
            "Aborting attempt to perform find replace as value (%zu) is "
            "not an elmement.\n",
            element);
    return SIZE_MAX;
  }

  size_t parent = ufset->elements[element];
  while (parent != element) {
    ufset->elements[element] = value;
    parent = ufset->elements[parent];
    element = parent;
  }
  ufset->elements[parent] = value;

  if (root_size != NULL) {
    *root_size = ufset->sizes[parent];
  }

  return value;
}

/**
 * Set the value for all elements on the path element -> root to the root.
 * No need to adjust size here as no element is added to or removed from
 * element's tree.
 * If root_size is not NULL, set the size of the tree element is a part of
 * there.
 */
size_t ufset_find_compress(struct UnionFindSet *ufset, size_t element,
                           size_t *root_size) {
  if (element >= ufset->size) {
    fprintf(stdout,
            "Aborting attempt to perform find compress as (%zu) is "
            "not an elmement.\n",
            element);
    return SIZE_MAX;
  }

  size_t root = ufset_find(ufset, element, NULL);
  ufset_find_replace(ufset, element, root, NULL);

  if (root_size != NULL) {
    *root_size = ufset->sizes[root];
  }

  return root;
}

/**
 * Do a union using ufset_find_compress (2 pass), ufset_find_replace (1
 * pass) and ufset_get_size (one pass each tree). Merge the smaller tree into
 * the bigger one. If root_size is not NULL, set the size of the tree element is
 * a part of there.
 */
size_t ufset_funky_union(struct UnionFindSet *ufset, size_t element1,
                         size_t element2, size_t *root_size) {
  if (element1 >= ufset->size) {
    fprintf(stdout,
            "Aborting attempt to perform union as element1 (%zu) is "
            "not an elmement.\n",
            element1);
    return SIZE_MAX;
  }
  if (element2 >= ufset->size) {
    fprintf(stdout,
            "Aborting attempt to perform union as element2 (%zu) is "
            "not an elmement.\n",
            element2);
    return SIZE_MAX;
  }

  size_t new_root;
  size_t root_size1 = ufset_get_size(ufset, element1);
  size_t root_size2 = ufset_get_size(ufset, element2);
  if (root_size1 < root_size2) {
    new_root = ufset_find_compress(ufset, element2, NULL);
    ufset_find_replace(ufset, element1, new_root, NULL);
  } else {
    new_root = ufset_find_compress(ufset, element1, NULL);
    ufset_find_replace(ufset, element2, new_root, NULL);
  }
  ufset->sizes[new_root] = root_size1 + root_size2;

  if (root_size != NULL) {
    *root_size = ufset->sizes[new_root];
  }

  return new_root;
}

/**
 * When joining two trees, add the smaller tree to the larger tree. The height
 * of the merged tree is less likely to increase if adding the smaller tree to
 * the larger, as the smaller tree might have height smaller than the height of
 * the larger tree and it points to the larger tree's root.
 */
size_t ufset_weighted_union(struct UnionFindSet *ufset, size_t element1,
                            size_t element2, size_t *root_size) {
  if (element1 >= ufset->size) {
    fprintf(stdout,
            "Aborting attempt to perform weighted union as element1 (%zu) is "
            "not an elmement.\n",
            element1);
    return SIZE_MAX;
  }
  if (element2 >= ufset->size) {
    fprintf(stdout,
            "Aborting attempt to perform weighted union as element2 (%zu) is "
            "not an elmement.\n",
            element2);
    return SIZE_MAX;
  }

  // Get roots of each element's trees.
  size_t root_size1, root_size2;
  size_t parent_element1 = ufset_find(ufset, element1, &root_size1);
  size_t parent_element2 = ufset_find(ufset, element2, &root_size2);

  // Union the trees and update ufset->sizes.
  size_t new_root;
  if (root_size1 < root_size2) {
    ufset->elements[parent_element1] = parent_element2;
    new_root = parent_element2;
  } else {
    ufset->elements[parent_element2] = parent_element1;
    new_root = parent_element1;
  }
  ufset->sizes[new_root] = root_size1 + root_size2;

  if (root_size != NULL) {
    *root_size = ufset->sizes[new_root];
  }

  return new_root;
}

/**
 * Compress all paths of all trees in the UnionFindSet. Not meant to be called
 * often and focus is on correct final result for future performance.
 * Doesn't change sizes as no trees elements are added or removed.
 */
void ufset_compress(struct UnionFindSet *ufset) {
  for (size_t i = 0; i < ufset->size; ++i) {
    ufset_find_compress(ufset, i, NULL);
  }
}
