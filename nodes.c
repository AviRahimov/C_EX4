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