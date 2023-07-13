#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int CQ[SIZE], f =-1, r =-1;

int CQfull(){
    if ((f == -1) || (f==0 && r ==SIZE-1))
        return 1;
    return 0;
}

int CQempty(){
    if (f == -1)
        return 1;
    return 0;
}

void insert(int x){
    if (CQFull())
        printf("queue is full");
    else{
        if (f==-1)
            f = 0;
        r = (r+1)%SIZE;
        CQ[r] = x; 
    }
}

int delete(){
    int elem;
    if (CQempty()){ 
        printf("Queue is empty");
        return -1;
    } else{
        elem = CQ[f];
        if(f == r)
            r = f = -1;
        f = (f+1)%SIZE;
        return elem;
    }
}

typedef struct node{
    int data;
    struct node *next;
}NODE;
NODE *front, *rear;

void insert(int x){
    NODE *newNode =(NODE*)malloc(sizeof(NODE));
    newNode->data = x;
    newNode->next = NULL;
    if(front == NULL)
        front = rear = newNode;
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

void display(){
    NODE *t;
    if (front == NULL)
        printf("Queue is empty");
    else{
        t = front;
        while(t){
            printf("%d ", t->data);
            t = t->next;
        }
    }

}