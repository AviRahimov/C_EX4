#include "edges.h"
#include "nodes.h"
#include <stdlib.h>
#include <stdio.h>


void make_edge(pnode * head, int from, int to_link, int weight){
    pedge e = (edge *)malloc(sizeof(edge));
    if (e == NULL){
        printf("failed to allocate memory, edge from %d, weight %d, to %d\n",from, weight, to_link);
        return;
    }
    e->endpoint = get_node(head, to_link);
    e->weight = weight;
    e->next = NULL;
    pnode pn = get_node(head, from);
    pedge *pe = &(pn->edges);
    while(*pe){
        pe = &((*pe)->next);
    }
    *pe = e; //set next to e
    return;
}
