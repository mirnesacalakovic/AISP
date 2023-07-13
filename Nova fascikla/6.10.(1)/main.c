#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int Stack[SIZE], top =-1;

int isEmpty(){
    if(top==-1)
        return 1;
    return 0;
}

int isFull(){
    if(top == SIZE-1)
        return 1;
    return 0;
}
void Push(int x){
    if (isFull())
        printf("Stack is full");
    else{
        top++;
        Stack[top] = x;
    }
}

int Pop(){
    int elem;
    if(isEmpty())
        printf("There is nothing to pop");
    else{
        elem = Stack[top];
        top--;
        return elem;
    }
}
void display(){
    int i;
    for(i=0; i<=top; i++)
        printf("%d ", Stack[i]);
}


typedef struct node{
    int data;
    struct node *link;
}NODE;

NODE *front, *rear;

void Insert(int x){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    if(newNode == NULL)
        printf("Out of memory");
    else{
        newNode->data = x;
        newNode->link = NULL;
        if(front == NULL)
            front = rear = newNode;
        else{
            rear->link = newNode;
            rear = newNode;
        }
    }
    
}

void Print(){
    NODE *temp = front;
    if(front == NULL)
        printf("Empty Queue");
    else{
        printf("\n");
        while(temp){
            printf(" %d ", temp->data);
            temp = temp->link;
        }
    }
}

int isPrime(int x){
    int i, flag = 0;

    if(x == 0 || x == 1)
        flag = 1;
    for(i=2; i<=x/2; i++)
        if(x%i == 0){
            flag = 1;
            break;
        }
    if(flag == 0)
        return x;
}


int main(){
    int i;
    Push(4);
    Push(5);
    Push(2);
    Push(8);
    Push(7);
    display();

    for(i=0; i<=top; i++)
        if(isPrime(Stack[i]))
            Insert(Stack[i]);
    
    Print();

    return 0;
}