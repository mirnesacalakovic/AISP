#include <stdio.h>
#include <stdlib.h>

#define N 6

typedef struct Graph{
    struct Node *head[N];
}GRAPH;

typedef struct node{
    int dest;
    struct node *next;
}NODE;

typedef struct Edge{
    int src, dest;
}EDGE;

GRAPH *createGraph(EDGE edges[], int n){
    int i;

    GRAPH *graph = (GRAPH*)malloc(sizeof(GRAPH));
    for(i=0; i<N; i++)
        graph->head[i] = NULL;

    for(i=0; i<n; i++){

        int src = edges[i].src;
        int dest = edges[i].dest;

        NODE *newNode = (NODE*)malloc(sizeof(NODE));
        newNode->dest = dest;
        newNode->next = graph->head[src];
        graph->head[src] = newNode;

        newNode = (NODE*)malloc(sizeof(NODE));
        newNode->dest = src;
        newNode->next = graph->head[dest];
        graph->head[dest] = newNode;
    }
    return graph;
}

void printGraph(GRAPH *graph){
    int i;
    for(i=0; i<N; i++){
        NODE *ptr = graph->head[i];
        while(ptr != NULL){
            printf(" %d -> %d", i, ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main(){

    EDGE edge[] = { {0,1}, {1,2}, {2,0}, {2,1}};

    int n = sizeof(edge)/sizeof(edge[0]);

    GRAPH *graph = createGraph(edge, n);

    return 0;
}

