#include <stdio.h>
#include <stdlib.h>

int N, M;

void createAdjMatrix(int Adj[][N+1], int Arr[][2]){
    int i, j;
    for(i=0; i<N; i++)
        for(j=0; j<N+1; j++)
            Adj[i][j]=0;

    for(i=0; i<M; i++){
        int x = Arr[i][0];
        int y = Arr[i][1];

        Adj[x][y] = 1;
        Adj[y][x] = 1;
    }
}

void printAdjMatrix(int Adj[][N+1]){
    int i, j;
    for (i=0; i<N; i++) {
        for(j=0; j<N+1; j++)
            printf(" %d ", Adj[i][j]);
        printf("\n");
    }
        
}

int main(){
    N=5;
    int Arr[][2] = {   {1,2}, {2,3}, {4,5}, {4, 3}, {1, 4}, {3, 5}, {5, 1}  };
    M = sizeof(Arr)/sizeof(Arr[0]);
    int Adj[N+1][N+1];
    createAdjMatrix(Adj, Arr);
    printAdjMatrix(Adj);
}