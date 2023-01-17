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

pnode get_node(pnode * head, int node_id);
void free_graph(pnode *head);
void free_edges(pnode *n);
void build_graph_cmd(pnode *head, int num_of_nodes);
void insert_node_cmd(pnode *head, int n);
void delete_node_cmd(pnode *head, int node_to_delete);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);
void free_edges(pnode *n);

#endif