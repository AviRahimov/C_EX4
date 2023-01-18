#ifndef GRAPH_EDGE
#define GRAPH_EDGE
#include "nodes.h"

pedge make_edge(int weight, pnode end);
void remove_edge(pedge *edge_to_rm, int dest);
void remove_all_edges(pnode target, pnode *head);

#endif