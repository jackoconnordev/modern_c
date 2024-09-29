#include "graph.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct graph {
  size_t num_vertices;
  bool *adj_matrix;
};

graph_t *graph_init(size_t num_vertices) {
  struct graph *graph = malloc(sizeof(struct graph));

  bool adj_matrix_size = num_vertices * num_vertices * sizeof(size_t);
  bool *adj_matrix = malloc(adj_matrix_size);
  memset(adj_matrix, false, adj_matrix_size);

  graph->num_vertices = num_vertices;
  graph->adj_matrix = adj_matrix;
  return graph;
}

bool edge_between(graph_t *graph, size_t source, size_t target) {
  return graph->adj_matrix[source * graph->num_vertices + target] &&
         graph->adj_matrix[target * graph->num_vertices + source];
}

void add_edge(graph_t *graph, size_t source, size_t target) {
  if (source >= graph->num_vertices || source >= graph->num_vertices) {
    printf("%zu <-> %zu is not an edge", source, target);
    return;
  }

  graph->adj_matrix[source * graph->num_vertices + target] = true;
  graph->adj_matrix[target * graph->num_vertices + source] = true;
}
