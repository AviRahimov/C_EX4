#include <stdio.h>
#include <stdlib.h>
#include "edges.h"
#include "nodes.h"
#include "algo.h"

int main() {
    char input;
    int num_of_nodes, index, node_id;
    int weight, dest_node;
    pnode pgraph = NULL;
    pnode n = NULL;
    int num = 0;
    while (scanf("%c", &input) != EOF) {
        switch (input) {
            case 'A': { // Creating a new graph
                if (pgraph != NULL){
                    free_graph(&pgraph);
                    pgraph = NULL;
                }
                scanf("%d ",&num_of_nodes);
                index = 0;
                while(index < num_of_nodes){
                scanf("%c ",&input);
                scanf("%d ",&node_id); // start of new node
                n = (pnode)malloc(sizeof(node));
                if (n == NULL){
                    free_graph(&pgraph);
                    return -1;
                }
                n->node_num = node_id;
                insert_node_cmd(&pgraph, n); // add node to the linked list of nodes 
                // e = n->edges; // add the edges now.
                while (scanf("%d ",&dest_node) == 1){
                    scanf("%d ",&weight);
                    make_edge(&pgraph, n->node_num, dest_node, weight);
                }
                index++;
                n = NULL;
            }
            break;
            }
            case 'B': { // Adding a new node if not already exist in the graph
                int node_to_insert;
                scanf("%d", &node_to_insert);
                insert_node_cmd(&pgraph, node_to_insert);
                break;
            }
            case 'D': { // Removing a node
                int node_to_delete;
                scanf("%d", &node_to_delete);
                delete_node_cmd(&pgraph, node_to_delete);
                break;
            }
            case 'S': { // Returning the shortest path between two number
                int source_node;
                int destination_node;
                scanf("%d", &source_node);
                scanf("%d", &destination_node);
                int ans = shortest_path(pgraph, source_node, destination_node);
                printf("Dijkstra shortest path %d\n", ans);
                break;
            }
            case 'T': { // Calculate the shortest path between several vertices(nodes)
                int size;
                scanf("%d ",&size);
                int * arr = (int*)malloc(size*sizeof(int));
                if (arr == NULL){
                    free_graph(&pgraph);
                    return -1;
                }
                int i = 0;
                while (i < size){
                    scanf("%d ",&num);
                    arr[i] = num;
                    i++;
                }
                printf("TSP shortest path: %d \n",TSP(pgraph, &arr[0], i));
                free(arr);
               break;
            }

            default:{
                break;
            }
        }
    }
    return 0;
}   