/*Implementrirati stek preko niza duzine 20, u koji se ubacuju i brisu po dva elementa istovremeno*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int s[SIZE], top=-1;

int isEmpty() {
    if(top == -1)
        return 1;
    return 0;
}
int isFull() {
    if(top >= SIZE-2)
        return 1;
    return 0;
}
int isMinimum(){
    if(top<1)
        return 1;
    return 0;
}

/*void Push(int elem[2]){
    if(isFull()) {
        printf ("Overflow");
        return;
    }
        
    int i;
    for(i=0; i<2; i++) {
        top++;
        s[top] = elem[i];
    }
    
}
*/

void Push(){
    int niz[2], i;
    for(i=0; i<2; i++){
        printf("Unesite %d. element.", i+1);
        scanf("%d", &niz[i]);
    }

    if(isFull()) {
        printf ("Overflow");
        return;
    }
    for(i=0; i<2; i++) {
        top++;
        s[top] = niz[i];
    }


}



int* Pop(){
    int elem[2];
    if (isMinimum()){ 
        perror("Stek nema dovoljno elemenata za brisanje");
    }
    int i;
    for(i=0;i<2;i++) {
        elem[i] = s[top];
        top--;
            
    }
    return elem;  
}

void display(){
    int i;
    if(isEmpty()){
        printf("Stek je prazan");
        return;
    }
    for(i=0; i<=top; i++)
        printf("%d ", s[i]);
    printf("Top^\n");
}



int main(){

   /* int elem[2], i;
    for(i=0; i<2; i++){
        printf("Unesite %d. element.", i+1);
        scanf("%d", &elem[i]);
    }
    //for(i=0; i<2; i++)
      //  printf("%d ", elem[i]);
*/
    Push();
    Push();
    Pop();

    

    display();
   

    return 0;
}