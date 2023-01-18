#include "edges.h"
#include "nodes.h"
#include <stdlib.h>

pedge make_edge(int weight, pnode end) {
    pedge a = (pedge) malloc(sizeof(edge));
    if (!a) {
        return NULL;
    }
    a->weight = weight;
    a->endpoint = end;
    a->next = NULL;
    return a;
}

//when do we want to do remove edge? when removing a node we want to remove every single edge from that node. for that we can know the node src and dest
void remove_edge(pedge *edge_to_rm, int dest) {
    if (!(*edge_to_rm)) {
        return;
    }
    if ((*edge_to_rm)->endpoint->node_num == dest) {
        pedge temp = *edge_to_rm;
        *edge_to_rm = (*edge_to_rm)->next;
        free(temp);
    }
    if (*edge_to_rm) {
        pedge temp = *edge_to_rm;
        while (temp->next) {//why not run on temp itself?
            if (temp->next->endpoint->node_num == dest) {
                pedge temp2 = temp->next;
                temp->next = temp->next->next;
                free(temp2);
                break;
            }
            temp = temp->next;
        }
    }
}

void remove_all_edges(pnode target, pnode *head) {
    if ((target->edges)) { //only if there is an edge
        pedge temp = target->edges;
        while (temp->next) {
            remove_edge(&(temp->next), temp->next->endpoint->node_num);
        }
        remove_edge(&temp, temp->endpoint->node_num);
        target->edges = NULL;
    }
    //until now, we removed all edges going out of the node. now we need to remove all edges which goes in to the node,
    // meaning we need to iterate over all the graph and search for mentions of the node
    int node_target_id = target->node_num;
    pnode node_iter = *head;
    while (node_iter) {
        pedge temp = node_iter->edges;
        if (temp) {//if this is false this means no edges for the current node therefore we move on to check the next node
            //not sure about the following if code at all. need to deal with if removing first edge not sure how.
            if (temp->endpoint->node_num == node_target_id) {
                pedge temp2 = temp;
                temp = temp->next;
                if (!(temp)) { //this is the case for which there is only one edge in the linked list and I want to remove it.
                    remove_edge(&temp2, node_target_id);
                    node_iter->edges = NULL;
                    continue;
                }
                node_iter->edges = temp;
                remove_edge(&temp2, node_target_id);
            }
            //until here not sure
            while (temp->next) {
                if (temp->next->endpoint->node_num ==
                    node_target_id) {//this means I found an edge coming in to the node I want to remove edges for
                    remove_edge(&(temp->next), node_target_id);
                }
                temp = temp->next;//move on to the next edge
                if (!(temp)) {
                    break;
                }
            }
        }
        node_iter = node_iter->next;//move on to the next node
    }
}