#include <stdio.h>
#include <stdlib.h>
#include "edges.h"
#include "nodes.h"
#include "algo.h"

int main(){
    char input;
    int num_of_nodes = 0;
    int *pgraph = 0;
    while(scanf("%c", &input)!=EOF){
        switch (input)
        {
        case 'A':{ // Creating a new graph
            if(pgraph != NULL)
            {
                free_graph(&pgraph);
            }
            scanf("%d", &num_of_nodes);
            build_graph_cmd(&pgraph, num_of_nodes);
            break;
        }
        case 'n':{ // Creating a new node
            int start_node;
            int weight;
            int node_to_link;
            int num;
            // after the 'n' sign the number of the source node will come, we set it as the start node.
            scanf("%d", &start_node);
            // run over all the nodes after the first node to connect the necessary nodes to the source
            // node and put the right weight for each edge.
            while (scanf("%d", &num))
            {
                node_to_link = num;
                scanf("%d", &weight);
                make_edge(&pgraph, start_node, node_to_link, weight);
            }
            break;
        }
        case 'B':{ // Adding a new node if not allready exist in the graph
            /* code */
            break;
        }
        case 'D':{ // Removing a node
            /* code */
            break;
        }
        case 'S':{ // Returning the shortest path between two number 
            /* code */
            break;
        }
        case 'T':{ // Calculate the shortest path between several vetices(nodes)
            /* code */
            break;
        }

        default:
            break;
        }

    }
    return 0;
}
