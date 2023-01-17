#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "edges.h"

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

void insert_node_cmd(pnode *head , int n)
{
    int to_link;
    int weight;
    pnode current = *head; // creating a new pointer and initialize it with the value of the head of the graph
    pnode prev = NULL; // while we traverse the list of nodes, prev will be used to keep track of the previous node we have been

    while (current != NULL) { // traverse the list of nodes
        if (current->node_num == n) { //check if the node we want to insert is already exists
            printf("The Node %d is already exists. Delete all outgoing edges", n);
            pedge e = current->edges;
            while (e != NULL) {
                pedge temp = e->next;
                free(e); // deleting all the edges from the node that exist.
                e = temp;
            }
            make_edge(head, n, to_link, weight);
        } return;
        //if the node does not exist
        prev = current;
        current = current->next;
    }
    //if the node does not exist, create new node and add it to the graph
    pnode newNode = (pnode)malloc(sizeof(node));
    newNode->node_num = n;
    newNode->edges = NULL;
    newNode->next = NULL;
    if(prev == NULL){
        *head = newNode;
    }
    else{
        prev->next = newNode;
    }
    printf("Node %d was inserted successfully.\n",n);
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