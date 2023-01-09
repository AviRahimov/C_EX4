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
                free_graph(pgraph);
            }
            scanf("%c", &num_of_nodes);
            build_graph_cmd(pgraph, num_of_nodes);
            break;
        }
        case 'n':{ // Creating a new node
            /* code */
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
