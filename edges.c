#include "edges.h"
#include "nodes.h"
#include "stdlib.h"
#include <stdio.h>

void make_edge(pnode *head, int src, int to_link, int weight){
    // I need to run over the graph with a pointer to head that I will make and find the src node and save it to different
    // node, the same for to_link node(make a pointer...) then, i need to check if the edges of the pointer to the
    // src node is null or maybe there are some edges and every case to itself
    pnode psrc = (*head), pto_link = (*head);
    while (psrc != NULL && psrc->node_num !=src){
        psrc = psrc->next;
    }
    while (pto_link != NULL && pto_link->node_num != to_link){
        pto_link = pto_link->next;
    }
    if(psrc->edges == NULL){
        pedge new_edge = (pedge) malloc(sizeof(edge));
        if(new_edge == NULL)
        {
            printf("The allocation was not succeed");
            exit(0);
        }
        new_edge->next = NULL;
        new_edge->endpoint = pto_link;
        new_edge->weight = weight;
        psrc->edges = new_edge;
        psrc->next = pto_link;
    } else{
        pedge exist_edge = psrc->edges;
        pedge new_edge = (pedge) malloc(sizeof(edge));
        if(new_edge == NULL)
        {
            printf("The allocation was not succeed");
            exit(0);
        }
        exist_edge->next = new_edge;
        new_edge->next = NULL;
        new_edge->weight = weight;
        new_edge->endpoint = pto_link;
        psrc->next = pto_link;
    }
    return;
}
