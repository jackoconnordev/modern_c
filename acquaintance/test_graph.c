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
  deallocate_graph(graph);
  free(graph);
  graph = NULL;
  puts("passed\n");
}

/* Graph I'm testing w/ 7 connected components
 *
 * 0 <-> 1 <-> 2 <-> 3 <-> 0
 * 4 <-> 5, 9 <-> 5
 * 6 <-> 7
 * 13 <-> 14 <-> 11 <-> 13
 * 8
 * 10
 * 12
 */
void test_count_connected_components() {
  puts("test_count_connected_components:");
  graph_t *graph = graph_init(15);
  add_edge(graph, 0, 1);
  add_edge(graph, 1, 2);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 0);

  add_edge(graph, 4, 5);
  add_edge(graph, 5, 9);

  add_edge(graph, 6, 7);

  add_edge(graph, 13, 14);
  add_edge(graph, 14, 11);
  add_edge(graph, 11, 13);

  size_t connected_component_count = count_connected_components(graph);
  assert(connected_component_count == 7);
  deallocate_graph(graph);

  free(graph);
  graph = NULL;
  puts("passed\n");
}

void test_bfs() {
  puts("test_bfs:");
  graph_t *graph = graph_init(5);

  add_edge(graph, 0, 1);
  add_edge(graph, 1, 2);
  add_edge(graph, 0, 4);
  add_edge(graph, 4, 3);

  print_bfs(graph, 1);

  deallocate_graph(graph);
  free(graph);
  graph = NULL;
}

/*
 * There should be 9 edges. Eyeball the rest if it looks okay.
 */
void test_spanning_tree() {
  puts("\ntest_spanning_tree");
  puts("Expecting 9 edges to be printed");
  graph_t *graph = graph_init(10);

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      add_edge(graph, i, j);
    }
  }

  print_spanning_tree(graph);
}

int main(int argc, char *argv[]) {
  test_add_edge();
  test_count_connected_components();
  test_bfs();
  test_spanning_tree();

  return EXIT_SUCCESS;
}
