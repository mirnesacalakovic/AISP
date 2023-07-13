#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *front=NULL, *rear=NULL;
NODE *front2=NULL, *rear2=NULL;

void insert(int x){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = x;
    newNode->next = NULL;
    
    if(front == NULL)
        front = rear = newNode;
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

void Nova(int x){
  
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = x;
    newNode->next = NULL;

    if(front2 == NULL)
        front2 = rear2 = newNode;
    else{
        rear2->next = newNode;
        rear2 = newNode;
    }
}

void display(NODE *front){
    NODE *t = front;
    if(front == NULL)
        printf("Empty list");
    else{
        while(t){ 
            printf(" %d ", t->data); 
            t = t->next;    
        }
    }
}


void powF(NODE *i, int exp){
    NODE *temp = front;

    if(front == NULL)
        printf("List is empty");
    else{
        while(temp){
            Nova(pow(temp->data, 2));
            temp = temp->next;
        }
    }
}



int main() {

    insert(4);
    insert(2);
    insert(6);
    insert(5);
    insert(8);

    powF(front, 2);

    display(front2);
    
}