#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

void free_graph(pnode *head)
{

}
/**
 * Building a new graph by taking the head of the graph and the number of nodes in the graph that we
 * can allocate the exact memory that are needed to this nodes by their size.
 * @param head the pointer to the first node of the graph
 * @param num_of_nodes the number of nodes in the graph
 */
void build_graph_cmd(pnode *head, int num_of_nodes)
{
    int i;
    pnode ptrnode;
    pnode temp = *head;
    for (i = 0; i < num_of_nodes; ++i) {
        ptrnode = (pnode) malloc(sizeof(node));

        if(ptrnode == NULL)
        {
            printf("The allocation was not succeed");
            exit(0);
        }
        ptrnode->next = NULL;
        ptrnode->node_num = i;
        ptrnode->edges = NULL;
        if (i == 0) {
            *head = ptrnode;
        }
        else
        {
            temp->next = ptrnode;
            temp = ptrnode;
        }
        return;
    }

}

void insert_node_cmd(pnode *head)
{

}

void delete_node_cmd(pnode *head)
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

void printGraph_cmd(pnode head)//for self debug
{

} 

void deleteGraph_cmd(pnode *head)
{

}

void shortsPath_cmd(pnode head)
{

}

void TSP_cmd(pnode head)
{

}