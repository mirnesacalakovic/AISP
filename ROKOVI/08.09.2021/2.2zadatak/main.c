//isEmpty(), isFull(), push(), pop(), display();  isMinimum()-je brisemo dva elementa istovremeno
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20


int s[SIZE], top = -1;

int isFull(){
    if(top >= SIZE-2)
        return 1;
    return 0;
}

int isEmpty(){
    if(top == -1)
        return 1;
    return 0;
}

int isMinimum(){
    if(top < 1)
        return 1;
    return 0;
}

void Push(){
    int i, niz[2];
    for(i=0; i<2; i++){
        printf("Unesite %d. element  ", i+1);
        scanf("%d", &niz[i]);
    }

    if (isFull()) {
        printf("Stack is full ");
        return;
    }

    for(i=0; i<2; i++){
        top++;
        s[top] = niz[i]; 
    }

}

int* Pop(){
    int niz[2], i;
    if(isMinimum())
        perror("Nemamo dovoljno elemenata za brisanje.");
    
    
    for (i=0; i<2; i++){
        niz[i] = s[top];
        top--;
    }

    return niz;
}

void display(){
    int i;
    if(isEmpty()){
        printf("Stek je prazan.");
        return;
    }
    for(i=0; i<=top; i++)
        printf("%d ", s[i]);
    printf("Top^");
}



int main(){

    Push();
    Push();
    
    Pop();

    display();

    return 0;
}