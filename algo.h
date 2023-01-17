#ifndef GRAPH_ALGO
#define GRAPH_ALGO
#include <stdbool.h>
#include "nodes.h"

typedef struct QUEUE {
    pnode vertex;
    int shortest_dist;
    int visited;
    struct QUEUE *next;
}queue, *pqueue;


void enqueue(pqueue *curr_queue, pnode vertex, int dist);
pqueue createQueue();
pqueue dequeue(pqueue* queue);
int dijkstra(pnode *graph, int numNodes, int start, int end);
#endif