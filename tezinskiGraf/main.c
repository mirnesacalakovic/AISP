#include <stdio.h>
#include <stdlib.h>

#define N 6

typedef struct Graph{
    struct Node *head[N];
}GRAPH;

typedef struct Node{
    int dest, weight;
    struct node *next;
}NODE;

typedef struct Edge{
    int src, dest, weight;
}EDGE;

GRAPH *createGraph(EDGE edge[], int n){
    int i;

    GRAPH *graph =(GRAPH*)malloc(sizeof(GRAPH));
    for(i=0; i<N; i++)
        graph->head[i] = NULL;

    for (i=0; i<n; i++){
        int src = edge[i].src;
        int dest = edge[i].dest;
        int weight = edge[i].weight;

        NODE *newNode = (NODE*)malloc(sizeof(NODE));
        newNode->dest = dest;
        newNode->weight = weight;
        newNode->next = graph->head[src];
        graph->head[src] = newNode;
    }
    return graph;
}


void printGraph(GRAPH *graph){
    int i;
    for(i=0; i<N; i++){
        NODE *ptr = graph->head[i];
        while(ptr != NULL){
            printf(" %d -> %d (%d)", i, ptr->dest, ptr->weight);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main(){
    EDGE edge[] = { {1,2,5}, {2, 3, 8}, {1, 3, 7}, {3, 4, 13}};

    int n = sizeof(edge)/sizeof(edge[0]);

    GRAPH *graph = createGraph(edge, n);

    printGraph(graph);




}