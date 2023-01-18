#ifndef GRAPH_ALGO
#define GRAPH_ALGO
#include "nodes.h"

// Algorithms:
int dijkstra(pnode* head , int src , int dest , int bool);
void TSP(pnode *head);
void swap(int *x, int *y);
int min(const int arr[],int n);
int factorial(int size);
int arrayc(pnode * head,int values[], int size);
void per(pnode *head, int *values, int right, int left, int *permute, int *n);
#endif