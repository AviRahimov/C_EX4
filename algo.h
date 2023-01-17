#ifndef GRAPH_ALGO
#define GRAPH_ALGO
#include <stdbool.h>
#include "nodes.h"

// Algorithms:
int shortest_path(pnode head, int src, int dest);
int TSP(pnode head, int * tspArr, int size);
#endif