/*Kreirati hash tabelu u Cu sa 7 uaza koja koristi ulancano hesiranje. U mainu uneti niz 13, 5, 32, 27, 1, 8, 2, 11 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *niz[SIZE];

void inicNiza(){
    int i;
    for(i = 0; i<SIZE; i++){
        niz[i] = NULL;
    }
}

void insert(int value){
    NODE *newNode = malloc(sizeof(NODE));
    newNode->data = value;
    newNode->next = NULL;

    int key = value % SIZE;

    if(niz[key] == NULL)
        niz[key] = newNode;
    else{
        NODE *temp = niz[key];
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }

}

int search(int value){
    int key = value % SIZE;
    NODE *temp = niz[key];

    while(temp){
        if(temp->data == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void print(){
    int i;
    for(i=0; i<SIZE; i++){
        NODE *temp = niz[i];
        printf("NIZ [%d] -->", i);
        while(temp){
            printf("%d -->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    //init array of list to NULL
    inicNiza();

    insert(13);
    insert(5);
    insert(32);
    insert(27);
    insert(15);
    insert(8);
    insert(3);
    insert(11);

    print();

    printf("Searching element 10\n");

    if(search(10))
        printf("Search Found\n");
    else
        printf("Search Not Found\n");

    return 0;
}