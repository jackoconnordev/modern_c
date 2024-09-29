#ifndef GRAPH
#include "stdlib.h"
#include <stdbool.h>

typedef struct graph graph_t;

// Exercise 7

graph_t *graph_init(size_t num_vertices);

bool edge_between(graph_t *graph, size_t source, size_t target);

void add_edge(graph_t *graph, size_t source, size_t target);

void print_bfs(graph_t *graph);

void print_connected_components(graph_t *graph);

// Exercise 8

#endif // !GRAPH
