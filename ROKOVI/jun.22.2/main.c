#include <stdio.h>
#define MAX 100

void zamena (int x[MAX][MAX], int m, int n) {
    int max=0, min=0, maxIndexI, maxIndexJ, minIndexI, minIndexJ, i, j, pom;
    max = x[1][n-1]; maxIndexI = 1; maxIndexJ = n-1;
    min = x[1][n-1]; minIndexI = 1; minIndexJ = n-1;
    for(i=1;i<m; i++)
        for(j=n-1; j<(n-1-i); j--) {
            if(min > x[i][j]){
                min = x[i][j];
                minIndexI = i;
                minIndexJ = j;
            }
            if(max < x[i][j]){
                max = x[i][j];
                maxIndexI = i;
                maxIndexJ = j;
            }
        }

    x[minIndexI][minIndexJ] = max;
    x[maxIndexI][maxIndexJ] = min;



}


int main() {
          
    int m, n, j, i, X[MAX][MAX];

    printf("Unesite dimenziju m ");
    scanf("%d", &m);
    printf("Unesite dimenziju n ");
    scanf("%d", &n);
    
    for(i=0; i<m; i++)
        for(j=0;j<n;j++)
            scanf("%d", &X[i][j]);


    zamena(X, m, n);

    printf("\n");
    for(i=0; i<m; i++){
        for(j=0;j<n;j++) 
            printf("%d ", X[i][j]);
        printf("\n");
    }
        

    return 0;
}