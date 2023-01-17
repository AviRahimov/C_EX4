#include "algo.h"
#include "nodes.h"
#include "stdlib.h"
#include <limits.h>

pqueue createQueue() {
    pqueue queue = (pqueue)malloc(sizeof(queue));
    queue->next = NULL;
    return queue;
}

void enqueue(pqueue *curr_queue, pnode vertex, int dist) {
    pqueue newNode = (pqueue)malloc(sizeof(queue));
    newNode->vertex = vertex;
    newNode->shortest_dist = dist;
    newNode->visited = 0;
    newNode->next = NULL;

    if (*curr_queue == NULL) {
        *curr_queue = newNode;
    } else {
        pqueue temp = *curr_queue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

pqueue dequeue(pqueue* queue) {
    if (*queue == NULL) {
        return NULL;
    }
    pqueue temp = *queue;
    *queue = (*queue)->next;
    return temp;
}

void freeQueue(pqueue queue) {
    while (queue != NULL) {
        pqueue temp = queue;
        queue = queue->next;
        free(temp);
    }
}

int dijkstra(pnode *graph, int numNodes, int start, int end) {
    // Create a priority queue to store vertices that
    // are being preprocessed
    pqueue queue1 = createQueue();

    // Create an array to store the shortest distances
    // from the start vertex
    int* distances = (int*)malloc(numNodes * sizeof(int));

    // Initialize all distances as infinite and the start vertex as 0
    for (int i = 0; i < numNodes; i++) {
        distances[i] = INT_MAX;
    }
    distances[start] = 0;

    // Insert the start vertex into the queue
    enqueue(queue1, &graph[start], 0);

    while (queue1 != NULL) {
        // Extract the vertex with the minimum distance
        pqueue min = dequeue(&queue1);
        pnode u = min->vertex;
        u->visited = 1;

        // Stop the algorithm if the end vertex is extracted
        if (u->node_num == end) {
            break;
        }

        // Traverse through all adjacent vertices of extracted vertex u
        pedge pCrawl = u->edges;
        while (pCrawl != NULL) {
            pnode v = pCrawl->endpoint;
            int weight = pCrawl->weight;

            // If the distance of v from start is greater than
            // the distance of u (extracted vertex) plus weight
            // of edge u-v, update the distance and enqueue v
            if (distances[u->node_num] != INT_MAX && distances[u->node_num] + weight < distances[v->node_num]) {
                distances[v->node_num] = distances[u->node_num] + weight;

                // Enqueue the vertex v if it's not visited yet
                if (!v->visited) {
                    enqueue(queue1, v, distances[v->node_num]);
                }
            }
            pCrawl = pCrawl->next;
        }
    }
    int shortest_distance = distances[end];
    // release memory
   // free(distances);
   // freeQueue(queue1);
    return shortest_distance;
}
