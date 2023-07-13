/*Napisati program u kom se pomocu odgovarajucih funkcija vrsi inicijalizacija, dodavanje elemenata u
kruzno ulancanu i njihov prikaz. Kreirati fun za pretvaranje kruzne liste u dvostruko ulancanu*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node *front = NULL, *rear = NULL, *temp;

void create(int x){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->info = x;
    newnode->next = NULL;
    if(rear == NULL)  
        front = rear = newnode;
    else{
        rear->next = newnode;
        rear = newnode;
    }
    rear->next = front;
}

void display(){
    temp = front;
    if(front == NULL)
        printf("\nEmpty");
    else{
        printf("\n");
        for(; temp!=rear; temp = temp->next)
            printf("\n%d adress=%u next=%u\t ", temp->info, temp, temp->next);
        printf("\n%d adress=%u next=%u\t ", temp->info, temp, temp->next);
    }

}

struct NodeDvos {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct NodeDvos *head;

struct Node* GetNewNode(int x) {
	struct NodeDvos* newNode = (struct NodeDvos*)malloc(sizeof(struct NodeDvos));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void InsertAtTail(int x) {
	struct NodeDvos* temp1 = head;
	struct NodeDvos* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp1->next != NULL) 
        temp1 = temp1->next; 

	temp1->next = newNode;
	newNode->prev = temp1;
}


void pretvaranje(){
    temp = front;
    while(temp != rear){
        InsertAtTail(temp->info);
        temp = temp->next;
    }
    InsertAtTail(temp->info);
}


void Print() {
	struct NodeDvos* temp1 = head;
	printf("\nForward: ");
	while(temp1 != NULL) {
		printf(" %d %d \t",temp1->prev, temp1->data);
        //printf("\t PREV %d ", temp1->prev);
		temp1 = temp1->next;
	}
	
}


int main(){

    create(3);
    create(8);
    create(4);
    create(2);
    create(9);

    display();

    pretvaranje();

    Print();

    return 0;
}