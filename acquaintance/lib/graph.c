#include "graph.h"
#include "unionfind.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct graph {
  size_t num_vertices;
  bool *adj_matrix;
};

graph_t *graph_init(size_t num_vertices) {
  bool malloc_failed = false;

  struct graph *graph = malloc(sizeof(struct graph));
  if (graph == NULL) {
    malloc_failed = true;
  }

  bool adj_matrix_size = num_vertices * num_vertices * sizeof(size_t);
  bool *adj_matrix = malloc(adj_matrix_size);
  if (graph->adj_matrix == NULL) {
    malloc_failed = true;
  }
  memset(adj_matrix, false, adj_matrix_size);

  graph->num_vertices = num_vertices;
  graph->adj_matrix = adj_matrix;
  return graph;
}

void deallocate_graph(graph_t *graph) {
  free(graph->adj_matrix);
  graph->adj_matrix = NULL;
}

size_t num_vertices(graph_t *graph) { return graph->num_vertices; }

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

size_t count_connected_components(graph_t *graph) {
  struct UnionFindSet ufset = ufset_init(num_vertices(graph));

  for (int i = 0; i < graph->num_vertices; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (edge_between(graph, i, j)) {
        // Don't care about root_size
        ufset_union(&ufset, i, j, NULL);
      }
    }
  }

  ufset_compress(&ufset);
  size_t count = ufset_compressed_subsets_count(&ufset);

  ufset_dealloc(&ufset);

  return count;
}
