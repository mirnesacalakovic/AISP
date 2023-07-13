#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *front, *rear;

void insert(int x){
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->data = x;
    temp->next = NULL;
    if(rear == NULL)
        front = rear = temp;
    else{
        rear->next = temp;
        rear = temp;
    }
    rear->next = front;
}

int findMax(){
    NODE *temp = front;
    int max = temp->data;
    while(temp!=rear){
        if(temp->data >= max)
            max = temp->data;
        temp = temp->next;
    }
    if(temp->data >= max)
        max = temp->data;
    return max;
}

void display(){
    NODE *temp = front;
    if(front == NULL)
        printf("empty");
    else{
        printf("\n");
        for(;temp!=rear; temp=temp->next)
            printf("%d ", temp->data);
        printf("%d ", temp->data);
        
    }
    
}


int main(){


    insert(3);
    insert(6);
    insert(4);
    insert(7);
    insert(8);
    insert(1);
    insert(9);

    display();
    printf(" \nMax element je %d ", findMax());


    return 0;
}