#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    int visited;
    int distance;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;


void clean(int **ShortestPath,int size);
pnode make_node(int id);
void remove_node(pnode *head, int node_to_remove);
void insert_node_cmd(pnode *head, int num_of_node);

#endif