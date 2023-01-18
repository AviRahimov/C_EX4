#include "nodes.h"
#include "edges.h"
#include <stdlib.h>
#include <stdio.h>

pnode make_node(int id) {
    pnode a = (pnode) malloc(sizeof(node));
    if (!a) {
        return NULL;
    }
    a->node_num = id;
    a->edges = NULL;
    a->next = NULL;
    return a;
}

void remove_node(pnode *head, int node_to_remove) {
    if (!(*head)) {
        return;
    }
    if ((*head)->node_num == node_to_remove) {
        pnode temp = *head;
        if (!(temp->next)) { //this is the case for which there is only one node in the linked list and I wish to remove it.
            remove_all_edges(temp, head);
            *head = (*head)->next; //im only changing the head here so, I can call the remove edge function with the original head
            free(temp);
            *head = NULL;
            return;
        }
        remove_all_edges(temp, head);
        *head = (*head)->next;//im only changing the head here so, I can call the remove edge function with the original head
        free(temp);
        return;
    } else {
        pnode temp = *head;
        while (temp->next) {
            if (temp->next->node_num == node_to_remove) {
                pnode temp2 = temp->next;
                remove_all_edges(temp2, head);
                temp->next = temp->next->next;
                free(temp2);
                return;
            }
            temp = temp->next;
        }
    }
}

//A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 S 2 0

void insert_node_cmd(pnode *head, int id_of_node_to_add) {
    pnode node_data;
    if (!*head) { //need to check here if its *head or head
        *head = make_node(id_of_node_to_add);
    }
    pnode check = *head;
    int flag = 1;
    while (check) { // creating dest node if docent exist
        if (check->node_num == id_of_node_to_add) {
            if ((check->edges)) { //only if there is an edge
                pedge temp = check->edges;
                while (temp->next) {
                    remove_edge(&(temp->next), temp->next->endpoint->node_num);
                }
                remove_edge(&temp,
                           temp->endpoint->node_num);//big problem here for some reason not freeing the edge only freeing inside the function not working out of it
                check->edges = NULL;
            }
            flag = 0;
            break;
        }
        check = check->next;
    }
    if (flag) {
        node_data = make_node(id_of_node_to_add);
        if (!node_data) {
            exit(0);
        }
        pnode temp4 = *head;
        while (temp4->next) {
            temp4 = temp4->next;
        }
        temp4->next = node_data;
    } else {
        node_data = check;
    }
    int dest;
    while (scanf("%d", &dest)) {
        pedge edge_data = NULL;
        int weight;
        scanf("%d", &weight);
        pnode pnod1 = *head;
        int flag2 = 0;
        while (pnod1) { // creating dest node if doesn't exist
            if (pnod1->node_num == dest) {
                flag2 = 1;
                break;
            }
            pnod1 = pnod1->next;
        }
        if (flag2) { // problem here.
            edge_data = make_edge(weight, pnod1);
            if (!edge_data) {
                exit(0);
            }
        } else {
            //need to create the endpoint node and create the edge with it
            pnod1 = make_node(dest);
            if (!pnod1) {
                exit(0);
            } else {
                pnode temp = *head;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = pnod1;
            }
            edge_data = make_edge(weight, pnod1);
            if (!edge_data) {
                exit(0);
            }
        }
        pedge temp = node_data->edges;
        if (!temp) {
            node_data->edges = edge_data;
        } else {
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = edge_data;
        }
    }
}