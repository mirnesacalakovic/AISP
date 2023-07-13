#include <stdio.h>
#include <stdlib.h>
/*Inicijaliczacaija, dodavanje elemenata u kruzno ulancanu listu i njihov prikaz. Elemeti su tipa int. Napisati funkciju kojom se kruzna 
lista siftuje za m mesta udesno. u glavnom programu prikazati rad funkcija*/

/*Struktura kruzne liste, globalni pokazivaci koji pokazuju na null, fun: print(), create(), shiftRight(m)*/

typedef struct Node{
    int info;
    struct Node *next;

} NODE;


NODE *front = NULL, *rear = NULL, *temp;


void Print() {
    
    temp = front;

    if(front == NULL)
        printf("Lista je prazna;");
    else {
        printf("\n");
        for(; temp != rear; temp = temp->next)         
            printf("\n %d adress = %u \t  next = %u \t", temp->info, temp, temp->next);
        printf("\n %d adress = %u \t next = %u", temp->info, temp, temp->next);
        
    }
}


void Create() {

    NODE *newnode = (NODE*)malloc(sizeof(NODE));

    printf("Enter the node value: ");
    scanf("%d", &newnode->info);

    newnode->next = NULL;

    if(rear == NULL)
        rear = front = newnode;
    else{
        rear->next = newnode;
        rear = newnode;
    }

    rear->next = front;
}


void ShiftRight(int m) {
    int i; 
    for(i=0; i<m; i++) {
        int prev = rear->info;
        int temp1;
        temp = front;

        while(temp != rear) {
            temp1 = temp->info;
            temp->info = prev;
            prev = temp1;

            temp = temp->next;
        }
        rear->info = prev;
    }
}


int main() {

    int i;

    for(i=0; i<6; i++)
        Create();

    Print();

    int m;

    printf("\nZa koliko mesta se pomera lista? \n");
    scanf("%d", &m);

    ShiftRight(m);

    Print();

    return 0;
}