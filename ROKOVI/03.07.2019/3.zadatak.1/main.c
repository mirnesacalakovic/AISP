/*Napisati program u Cu kojim se red sa dva kraja implementira preko dvostruko ulancane liste*/
/* struktura za dvostruku listu, globalni pokazivac za kraj i pocetak, funkcije: createNode(), insertAtFront(), insertAtBack(), 
deleteAtBack(), deleteAtFront(), print()*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *front = NULL, *rear = NULL;

Node *GetNewNode(int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtFront(int x) {
    Node *newNode = GetNewNode(x);
    if(front == NULL) {
        front = rear = newNode;
        return;
    }
    front->prev = newNode;
    newNode->next = front;
    front = newNode;
}

void InsertAtRear(int x) {
    Node *newNode = GetNewNode(x);
    if(rear == NULL) {
        front = rear = newNode;
        return;
    }
    newNode->prev = rear;
    rear->next = newNode;
    rear = newNode;
}

int DeleteAtFront() {
    int data;
    Node *temp = front;
    if(front == NULL)
        printf("RED PRAZAN!");
    else {
        if(front == rear) {
            data = front->data;
            front = rear = NULL;
            return data;
        }
        else {
            data = front->data;
            front = front->next;
        }
    }
    free(temp);
    return data;
}

int DeleteAtRear() {
    int data;
    Node *temp = rear;
    if(front == NULL)
        printf("RED PRAZAN!");
    else {
        if(front == rear) {
            data = rear->data;
            front = rear = NULL;
            return data;
        }
        else {
            data = rear->data;
            rear = rear->prev;
        }
    }
    free(temp);
    return data;
}

void Print() {
    Node *temp = front;

    while(temp != rear) {
        printf("  %d  ", temp->data);
        temp = temp->next;
    }
    printf("  %d  ", temp->data);
    printf("\n");
}
int main() {

    InsertAtFront(5);
    InsertAtFront(8);
    InsertAtRear(90);
    InsertAtFront(3);
    InsertAtRear(5);
    InsertAtRear(58);
    InsertAtFront(1);
    Print();
    DeleteAtFront();
    DeleteAtFront();
    DeleteAtRear();
    Print();

    return 0;
}