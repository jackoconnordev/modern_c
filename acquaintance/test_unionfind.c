/**
 * Yes I am testing using print debugging. The order of the tests matters.
 */
#include "unionfind.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  puts("Initialise UnionFindSet with size 10. All sizes should be 1 and "
       "elements count from 0 to 9.");
  struct UnionFindSet ufset = ufset_init(10);
  struct UnionFindSet *ufset_ptr = &ufset;
  ufset_print(ufset_ptr);

  puts("");
  puts("Union element 1 and element 2. Elements[0] should be 1 and sizes[1] "
       "should be 2.");
  ufset_union(ufset_ptr, 0, 1, NULL);
  ufset_print(ufset_ptr);

  puts("");
  puts("Union element 1 and element 4. Elements[1] should be 3 and sizes[3] "
       "should be 3.");
  ufset_union(ufset_ptr, 0, 3, NULL);
  ufset_print(ufset_ptr);

  puts("");
  puts("Find the root of element 1 and its tree's size. Element should be 4 "
       "and size should be 3.");
  size_t *root_size;
  size_t element = ufset_find(ufset_ptr, 0, root_size);
  printf("Element=%zu\tSize=%zu\n", element + 1, *root_size);

  puts("");
  puts("Compress the UnionFindSet. Elements[0 && 1 && 3] should be 3.");
  ufset_compress(ufset_ptr);
  ufset_print(ufset_ptr);

  puts("");
  puts("Weighted union element 10 and element 2. Elements[9] should be 3 "
       "because Elements[9] tree is smaller.\nSizes[3] should be 4.");
  ufset_weighted_union(ufset_ptr, 1, 9, NULL);
  ufset_print(ufset_ptr);

  puts("");
  puts("Funky union find works. Union element 7 and element 9. Elements[6] "
       "should be 3 and Sizes[3] should be 5.");
  ufset_funky_union(ufset_ptr, 6, 9, NULL);
  ufset_print(ufset_ptr);

  puts("");
  puts(
      "Deallocate UnionFindSet and call print to see the print error message.");
  ufset_dealloc(ufset_ptr);
  ufset_print(ufset_ptr);

  ufset_ptr = NULL; // No need to free non-manually allocated memory.

  return EXIT_SUCCESS;
}
