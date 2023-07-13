/*Napisati program za rad sa stekom implementiranim preko niza od 10 elemenata i za rad sa redom impl preko lancane liste. 
 U glavnom programu napuniti stek random brojevima, a iz steka prebaciti proste brojeve u red*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10

int N[SIZE], top = -1;

int isEmpty(){
    if(top == -1)
        return 1;
    else 
        return 0;
}

int isFull(){
    if(top == SIZE-1)
        return 1;
    else 
        return 0;
}

void Push(int x){
    if(isFull()){
        printf("Stack is full.");
    }else{   
        top++;
        N[top] = x;
    }
}

int Pop(){
    int elem;
    if(isEmpty()){
        printf("There is nothing to pop.");
        return 1;
    }else{
        elem = N[top];
        top--;
        return elem;
    }
}

void Display(){
    int i;
    if(isEmpty())
        printf("There is nothing to print.");
    else{
        for(i=0; i<=top; i++)
            printf(" %d ", N[i]);  
    }   printf("\n");
}


typedef struct node{
    int data;
    struct node *link;
}NODE;

NODE *front, *rear;

void insert(int x){
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    if(temp == NULL)
        printf("Out of memory");
    else{
        temp->data = x;
        temp->link = NULL;
        if(front == NULL)
            front = rear = temp;
        else{
            rear->link = temp;
            rear = temp;
        }
    }
}

void Qprint(){
    NODE *t;
    if(front == NULL)
        printf("Empty queue");
    else{
        t = front;
        while(t){
            printf("\n %d ", t->data);
            t = t->link;
        }
    }
}


int isPrime(int n){
    int i, flag = 0;
  // 0 and 1 are not prime numbers
  // change flag to 1 for non-prime number
    if (n == 0 || n == 1)
        flag = 1;
    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0)    
        return n;
}


int main(){

    Push(2);
    Push(3);
    Push(1);
    Push(7);
    Push(5);
    Push(9);
    Display();

    int i; 
    for(i=0; i<=top; i++){
        if(isPrime(N[i]))
            insert(N[i]);
    }
    Qprint();


}