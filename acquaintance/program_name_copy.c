#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <string.h>

int main(int argc, char *argv[]) {
  size_t const len = strlen(argv[0]);
  char name[len + 1];

  memcpy(name, argv[0], len);
  name[len] = 0;

  if (!strcmp(name, argv[0])) {
    printf("The name string \"%s\" is the same as the argv[0] string \"%s\".",
           name, argv[0]);
  } else {
    printf(
        "The name string \"%s\" is not the same as the argv[0] string \"%s\".",
        name, argv[0]);
  }
  return EXIT_SUCCESS;
}
