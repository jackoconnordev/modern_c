#include "graph.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_add_edge() {
  puts("test_add_edge:");
  graph_t *graph = graph_init(3);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);

  assert(edge_between(graph, 0, 1));
  assert(edge_between(graph, 1, 0));
  assert(edge_between(graph, 2, 0));
  assert(!edge_between(graph, 1, 2));
  assert(!edge_between(graph, 2, 1));
  puts("passed");
}

int main(int argc, char *argv[]) {
  test_add_edge();

  return EXIT_SUCCESS;
}
