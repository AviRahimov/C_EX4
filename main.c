#include <stdio.h>
#include <stdlib.h>
#include "edges.h"
#include "nodes.h"
#include "algo.h"

int main() {
    char input;
    int num_of_nodes = 0;
    pnode *pgraph = NULL;
    printf("starting to scan:\n");
    while (scanf("%c", &input) != EOF) {
        switch (input) {
            case 'A': { // Creating a new graph
                if (pgraph != NULL) {
                    free_graph(pgraph);
                }
                scanf("%d", &num_of_nodes);
                build_graph_cmd((pnode *) &pgraph, num_of_nodes);
                printf("finish input A\n");
                break;
            }
            case 'n': { // Creating a new node
            printf("starting n input:\n");
                int start_node = -1;
                int weight = -1;
                int node_to_link = -1;
                int num = -1;
                // after the 'n' sign the number of the source node will come, we set it as the start node.
                scanf("%d", &start_node);
                // run over all the nodes after the first node to connect the necessary nodes to the source
                // node and put the right weight for each edge.
                while (scanf("%d", &num)) {
                   // node_to_link = num;
                   // scanf("%d", &weight);
                   // make_edge((pnode *) &pgraph, start_node, node_to_link, weight);
                   if(start_node != -1 && node_to_link == -1 && weight == -1){
                    node_to_link = num;
                   }
                   else if(start_node != -1 && node_to_link != -1 && weight == -1){
                    weight = num;
                   }
                   if(start_node != -1 && node_to_link == -1 && weight != -1){
                    make_edge(&pgraph, start_node, node_to_link, weight);
                    node_to_link = -1;
                    weight = -1;
                   }
                }
                break;
            }
            printf("finish n input\n");
            case 'B': { // Adding a new node if not already exist in the graph
                int node_to_insert;
                scanf("%d", &node_to_insert);
                insert_node_cmd(&pgraph, node_to_insert);
                break;
            }
            case 'D': { // Removing a node
                int node_to_delete;
                scanf("%d", &node_to_delete);
                delete_node_cmd((pnode *) &pgraph, node_to_delete);
                break;
            }
            case 'S': { // Returning the shortest path between two number
                int source_node;
                int destination_node;
                scanf("%d", &source_node);
                scanf("%d", &destination_node);
                int ans = dijkstra((pnode *) &pgraph, num_of_nodes, source_node, destination_node);
                printf("Dijsktra shortest path %d\n", ans);
                break;
            }
           // case 'T': { // Calculate the shortest path between several vertices(nodes)
           //     int num_of_nodes;
           //     scanf("%d", &num_of_nodes);
           //    break;
           // }

            default:{
                break;
            }
        }
    }
    printf("finished all functions\n");
    return 0;
}   