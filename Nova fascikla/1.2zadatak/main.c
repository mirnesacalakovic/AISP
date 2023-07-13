#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 7

int Stack[SIZE], top = -1;

int isFull(){
    if(top == SIZE-1)  
        return 1;
    return 0;
}
int isEmpty(){
    if(top == -1)  
        return 1;
    return 0;
}

void Push(int x){
    if(isFull())    
        printf("stack is full");
    else{
        top++;
        Stack[top] = x;
    }
}

int Pop(){
    int elem;
    if(isEmpty())
        printf("Stack is empty");
    else{
        elem = Stack[top];
        top--;
        return elem;
    }
}

void display(){
    int i;
    if(isEmpty())
        printf("Stack is empty.");
    else { 
        for(i=0; i<=top; i++)
            printf(" %d ", Stack[i]);
    }
}


typedef struct node{
    int data;
    struct  node *link;
}NODE;

NODE *front, *rear;

void Insert(int elem){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = elem;
    newNode->link = NULL;
    if(front == NULL)
        front = rear = newNode;
    else{
        rear->link = newNode;
        rear = newNode;
    }
}

int delete(){
    int elem;
    NODE *t;
    if(front == NULL)
        printf("Red je prazan");
    else{
        t = front;
        elem = front->data;
        if(front == rear)
            rear = NULL;
        front = front->link;
        t->link = NULL;
        free(t);
        return elem;
    }
}

void Qprint(){
    NODE *t = front;
    if(front == NULL)
        printf("Queue is empty");
    else{
        printf("\n");
        while(t){
            printf(" %d ", t->data);
            t = t->link;
        }
    }
}

int isPrime(int x){
    int i, flag = 0;
    if (x==0 || x==1)
        flag = 1;
    for(i=2; i<= x/2; i++)
        if(x%i == 0){
            flag = 1;
            break;
        } 
    if(flag == 0)
        return x;
}

int main(){

    Push(3);
    Push(6);
    Push(9);
    Push(7);
    Push(5);
    display();

    int i;

    for(i=0; i<=top; i++) { 
        if(isPrime(Stack[i]))
            Insert(Stack[i]);
    }
    Qprint();

    return 0;
}