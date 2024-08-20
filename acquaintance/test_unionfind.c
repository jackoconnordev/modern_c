#include "unionfind.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  struct UnionFindSet ufset = ufset_init(10);
  struct UnionFindSet *ufset_ptr = &ufset;

  puts("Initialise UnionFindSet with size 10. All sizes should be 1 and "
       "elements count from "
       "0 to 10.");
  ufset_print(ufset_ptr);

  return EXIT_SUCCESS;
}
