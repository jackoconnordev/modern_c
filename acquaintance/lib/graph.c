#include "graph.h"
#include "unionfind.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Internal function/struct declarations

struct graph {
  size_t num_vertices;
  bool *adj_matrix;
};

// Public functions

graph_t *graph_init(size_t num_vertices) {
  bool malloc_failed = false;

  struct graph *graph = malloc(sizeof(struct graph));
  if (graph == NULL) {
    malloc_failed = true;
  }

  size_t adj_matrix_size = num_vertices * num_vertices * sizeof(size_t);
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
  if (source >= graph->num_vertices || target >= graph->num_vertices) {
    printf("%zu <-> %zu is not an edge", source, target);
    return;
  }

  graph->adj_matrix[source * graph->num_vertices + target] = true;
  graph->adj_matrix[target * graph->num_vertices + source] = true;
}

void print_bfs(graph_t *graph, size_t source) {
  if (source >= graph->num_vertices) {
    printf("%zu is not a vertex", source);
    puts("");
    return;
  }

  // Setup visited and next_queue
  bool visited[graph->num_vertices];
  memset(visited, false, sizeof(visited));
  visited[source] = true;
  printf("Visited vertex %zu\n", source);

  size_t queue[graph->num_vertices];

  // Max queue length == queue array length so no wrapping around possible.
  queue[0] = source;
  size_t queue_front = 0;
  size_t queue_back = 1;

  while (queue_front <= queue_back) {
    size_t current_vertex = queue[queue_front];
    for (size_t j = 0; j < graph->num_vertices; ++j) {
      if (!visited[j] && edge_between(graph, j, current_vertex)) {
        printf("Visited vertex %zu\n", j);
        visited[j] = true;
        queue[queue_back] = j;
        ++queue_back;
      }
    }
    ++queue_front;
  }
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
