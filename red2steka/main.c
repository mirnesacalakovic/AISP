#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int S1[SIZE], S2[SIZE], top1 = -1, top2 = -1;
int i, count = 0;

int isFull(){
    if(top1 == SIZE-1)
        return 1;
    return 0;
}
void Push1(int elem){
    if(isFull())
        printf("Stack is full");
    else{
        top1++;
        S1[top1] = elem;
    }
}
int Pop1(){
    int elem;
    if(top1 ==-1 && top2 == -1)
        return 1;
    else{
        elem = S1[top1];
        top1--;
        return elem;
    }
}

void Push2(int elem){
    if(isFull())
        printf("Stack is full");
    else{
        top2++;
        S2[top2] = elem;
    }
}

int Pop2(){
    int elem;
    if(top2 == -1)
        return 1;
    else{
        elem = S2[top2];
        top2--;
        return elem;
    }
}
void enqueue(int x){
    Push1(x);
    count++;
}

int dequeue(){
    int i, elem, b;
    for(i=0; i<count; i++)
        Push2(Pop1());
    b = Pop2();
    printf("Popped element is %d ", b);
    count--;
    for(i=0; i<count; i++)
        Push1(Pop2());
}

void display(){
    int i;
    printf("\n");
    for(i=0; i<=top1; i++)
        printf(" %d ", S1[i]);
    
}

int main(){

    enqueue(5);
    enqueue(2);
    enqueue(-1);
    dequeue();
    display();

}