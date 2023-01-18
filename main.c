#include "nodes.h"
#include "edges.h"
#include "algo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int vertex = 0;
    int FLAG = 1;
    node *head = NULL;
    int c =0;
    int first = 1;
    while (FLAG) {
        if(first) {
            c = getchar();
        }
        switch (c) {
            case 'A':
                getchar();
                pnode removi = head;
                while(removi!=NULL){
                    remove_node(&head , removi->node_num);
                    removi = head;
                }
                scanf("%d", &vertex); // vertex graph.
                //char n;
                //scanf("%s", &n);
                for (int i = 0; i < vertex; ++i) {
                    int src_id = 0;
                    scanf("%d", &src_id);
                    pnode node_data;//maybe not good declaration.
                    if (i == 0) {
                        head = make_node(src_id);
                        node_data = head;
                    }
                    pnode checker = head;
                    while (checker) {
                        if (checker->node_num == src_id) {
                            break;
                        }
                        checker = checker->next;
                    }
                    if (!checker) {
                        node_data = make_node(src_id);
                        if (!node_data) {
                            exit(0);
                        }
                        pnode temp = head;
                        while (temp->next) {
                            temp = temp->next;
                        }
                        temp->next = node_data;
                    } else {
                        node_data = checker;
                    }
                    int dest = 0;
                    while (scanf("%d", &dest)) {
                        
                        pedge edge_data = NULL;
                        int weight = 0;
                        scanf("%d", &weight);
                        pnode destination = head;
                        while (destination) { // creating dest node if doesn't exist
                            if (destination->node_num == dest) {
                                break;
                            }
                            destination = destination->next;
                        }
                        if (destination) {
                            edge_data = make_edge(weight, destination);
                            if (!edge_data) {
                                exit(0);
                            }
                        } else {
                            //need to create the endpoint node and create the edge with it
                            destination = make_node(dest);
                            if (!destination) {
                                exit(0);
                            } else {
                                pnode temp = head;
                                while (temp->next) {
                                    temp = temp->next;
                                }
                                temp->next = destination;
                            }
                            edge_data = make_edge(weight, destination);
                            if (!edge_data) {
                                exit(0);
                            }
                        }
                        //need to add edge to node->edges and need to see where to add it
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
                    c = getchar();
                    if (c != 'n') {
                        first=0;
                        break;
                    }
                }
                getchar();
                getchar();
                break;
        
            case 'B':
                getchar();//for the space
                int to_add;
                scanf("%d", &to_add);
                insert_node_cmd(&head, to_add);
                first=1;
                break;
            
            case 'D':
                getchar();
                int node_to_remove;
                scanf("%d", &node_to_remove);
                remove_node(&head, node_to_remove);
                first=1;
                break;
            
            case 'S':
                getchar();
                int dest, src;
                scanf("%d %d", &src, &dest);
                printf("Dijsktra shortest path: ");
                dijkstra(&head, src, dest, 1);//maybe send without head since in debugger it shows 2 heads
                first=1;
                break;
            
            case 'T':
                getchar();
                TSP(&head);
                first=1;
                break;
            
            case ' ':
                break;
            default:
                FLAG = 0;
                break;
            
        }
    }
    pnode removie = head;
    while(removie!=NULL){
        remove_node(&head , removie->node_num);
        removie = head;
    }
}