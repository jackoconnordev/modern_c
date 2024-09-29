#ifndef GRAPH
#include "stdlib.h"
#include <stdbool.h>

typedef struct graph graph_t;

// Exercise 7

graph_t *graph_init(size_t num_vertices);

void deallocate_graph(graph_t *graph);

size_t num_vertices(graph_t *graph);

bool edge_between(graph_t *graph, size_t source, size_t target);

void add_edge(graph_t *graph, size_t source, size_t target);

void print_bfs(graph_t *graph);

size_t count_connected_components(graph_t *graph);

// Exercise 8
size_t shortest_path(graph_t *graph, size_t source, size_t target);

#endif // !GRAPH
