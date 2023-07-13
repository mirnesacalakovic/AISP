/*Kreirati program za rad sa kruzno ulancanom listom. Napisati funkciju za nalazenje maximalnog elementa liste. U glavnom programu demonstrirati rad funkcija
struktura, globalni ptr front=NULL rear=NULL temp, fun create(), delete(), display() */

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE *front = NULL, *rear = NULL, *temp;

void create(int x) {
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = x;
    newNode->next = NULL;
    if(rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
    rear->next = front;

}

void delete() {
    temp = front;
    if (front == NULL)
        printf("Overflow!");
    else {
        if(front == rear) {
            printf("%d", front->data);
            front = rear = NULL;
        }else {
            printf("%d\n", front->data);
            front = front->next;
            rear->next = front;
        }
        temp->next = NULL;
        free(temp);
    }

}

void display() {
    temp = front;

    if(front == NULL)
        printf("Empty!!!");
    else { 
        printf("\n");
        for(; temp!= rear; temp=temp->next) 
            printf("%d ", temp->data);
        printf("%d ", temp->data);
    }      
            
}

NODE* maxElement() {
    NODE *max = front;
    temp = front;
    while (temp != rear) {
        if(max->data < temp->data)
            max->data = temp->data;
        else    
            temp = temp->next;
    }
    if(max->data < temp->data)
        max->data = temp->data;
          
    return max;
}

int main() {


    create(3);
    create(2);
    create(99);
    delete();
    create(8);
    create(19);
    create(21);
    display();
    printf("Najveci element je: %d", maxElement()->data);

    return 0;

}