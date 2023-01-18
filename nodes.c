#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "edges.h"
#include <limits.h>

void insert_node_cmd(pnode * head, pnode item){
    if (*head == NULL){
        *head = item;
        return;
    }
    
    /* insert node item via node_id order 
    3 scenrios:
        1- item should be added as the new head of the list
        2- item should be added somewhere in the middle of the list
        3- item should be added as the last item of the list
         */
    // case 1:
    if ((*head)->node_num > item->node_num){
        item->next = *head;
        *head = item;
        return;
    }
    if ((*head)->node_num == item->node_num){
        return;
    }
    
    // init vars
    pnode* p = head;
    pnode next = (*p)->next;
    
    // case 2:
    while(next){
    // loop over all the node "linked list"
        if(next->node_num== item->node_num){
            return;
        }
        if(next->node_num > item->node_num){
            (*p)->next = item;
            item->next = next;
            return;
        }
        next = next->next;
        p = &((*p)->next);
    }
    
    // case 3:
    (*p)->next = item;
    item->next = NULL;
    return;
}

void delete_node_cmd(pnode *head, int node_to_delete)
{
    pnode delete_node = (*head), temp = (*head);
    pedge temp_edge;
    while (delete_node->node_num != node_to_delete){
        delete_node = delete_node->next;
    }
    // Traveling over the whole graph
    while (temp != NULL){
        temp_edge = temp->edges;
        while (temp_edge->endpoint != delete_node && temp_edge->endpoint != NULL){
            temp_edge = temp_edge->next;
        }
        free(temp_edge);
        temp = temp->next;
    }
    pedge pnode_to_delete = delete_node->edges;
    while(delete_node->edges != NULL){
        free(pnode_to_delete);
        pnode_to_delete = delete_node->edges->next;
        delete_node->edges = delete_node->edges->next;
    }
    free(delete_node);
    return;
}
pnode get_node(pnode * head, int node_id){
    /* if node_id is not exists: create new node and add it with insert function to the graph */
    if (node_id < 0){
        // invalid node_id number
        return NULL;
    }

    pnode p = *head;
    while (p){
        if (p->node_num == node_id){
            return p;
        }
        p = p->next;
    }
    p = (node*)malloc(sizeof(node));
    if (p == NULL){
        free_graph(head);
        return NULL;
    }
    p->node_num = node_id;
    insert_node_cmd(head, p);
    return p;
}
void free_edges(pedge * eHead){
    /* loop over all the edges of specific node and delete them -> means, free those edges */
    pedge toFreeEdge;
    while (*eHead){
        toFreeEdge = *eHead;
        eHead = &((*eHead)->next);
        free(toFreeEdge);
    }
    if (*eHead != NULL){
        free(*eHead);
    }
}

void free_graph(pnode* head){
    /* delete the whole graph, shall free every node and edge structs*/
    if (*head == NULL){
        return;
    }
    // init vars
    pnode* p = head;
    pedge e;
    pnode toFreeNode;
    // pedge toFreeEdge;

    while(*p)
        // loop over all the node "linked list"
    {
        toFreeNode = *p;
        e = toFreeNode->edges;
        if (e != NULL) {
            free_edges(&e);
        }

        p = &((*p)->next);
        free(toFreeNode);
    }
    return;
}
void build_graph_cmd(pnode *head){
    if(*head){
        free_graph(&head[0]);
    }
    return;
}
void printGraph_cmd(pnode head){
    /*print graph, loop over the whole list of nodes, and print node_id then all its edges details*/
    // init vars
    pnode p = head;
    pedge e;
    while(p){
        // loop over all the node "linked list"
        e = p->edges;
        printf("node id: %d out_edges: ",p->node_num);
        //printf("node id: %d weight: ",p->.);
        while(e){
            // loop over all the edges of specific node
            printf("(to %d, weight %d) ",e->endpoint->node_num, e->weight);
            e = e->next;
        }
        p = p->next;
        printf("\n");
    }
}