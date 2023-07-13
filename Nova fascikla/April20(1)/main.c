#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;

NODE *first=NULL, *last=NULL;

void insert(int x){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = x;
    newNode->next = NULL;
    if(first == NULL)
        first = last = newNode;
    else{
        last->next = newNode;
        last = newNode;
    }
}

void display(){
    NODE *temp = first;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

typedef struct DvosNode{
    int data;
    struct DvosNode *prev;
    struct DvosNode *next;
}DVOSNODE;

DVOSNODE *head;

DVOSNODE *create(int x){
    DVOSNODE *new = (DVOSNODE*)malloc(sizeof(DVOSNODE));
    new->data = x;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void insertAtTail(int x){
 
    DVOSNODE *temp = head;  
    DVOSNODE *newNode = create(x);
    if(head == NULL){
        head = newNode;
        return;
    } 
    
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
void DisplayD() {
    DVOSNODE *tempD = head;
    while(tempD != NULL) {
        printf(" %d ", tempD->data);
        tempD = tempD->next;
    }
    printf("\n");
}

void prebacivanje(){
    DVOSNODE *temp = head;
    while(temp!=NULL){
        insert(temp->data);
        temp = temp->next;
        temp = temp->next;
    }
      
}

int main(){
    int i;

    insertAtTail(4);
    insertAtTail(7);
    insertAtTail(9);
    insertAtTail(2);
    insertAtTail(1);
    DisplayD();

    prebacivanje();

    display();

    return 0;
}