/*Napisato rad sa jednostrukom i dvostrukom ulancanom listom. Napisati fun koja prebacuje elemente sa neparnih pozicija iz 
dvostruke liste u jednostruko ulancanu listu. U gl programu demonstrirati rad liste*/
//Strukture za obe liste, fun: Print() za obe liste, create() za obe liste, insert() na pocetak i kraj za dvostruku,
// 
#include <stdio.h>
#include <stdlib.h>

typedef struct dnode{
    int data;
    struct dnode *next;
    struct dnode *prev;
}DNODE;

DNODE *head = NULL; DNODE *tempD = NULL;

DNODE *GetNewNode(int x) {
    DNODE *newNode = (DNODE*)malloc(sizeof(DNODE));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int x) {
    DNODE* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(int x) {
    tempD = head;
    DNODE *newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    while(tempD->next != NULL)
        tempD = tempD->next;
    
    tempD->next = newNode;
    newNode->prev = tempD;
}

void DisplayD() {
    tempD = head;
    while(tempD != NULL) {
        printf(" %d ", tempD->data);
        tempD = tempD->next;
    }
    printf("\n");
}







typedef struct nodeJ {
    int info;
    struct nodeJ *next;

} NODEJ;

NODEJ *first = NULL, *last = NULL, *tempJ = NULL;

void CreateJ(int elem) {
    tempJ = (NODEJ*)malloc(sizeof(NODEJ));
    tempJ->info = elem;
    tempJ->next = NULL;
    if (first == NULL) {
        first = tempJ;
        last = tempJ;
    } else {
        last->next = tempJ;
        last = tempJ;
    }
}

void DisplayJ() {
    tempJ = first;
    while(tempJ != NULL) {
        printf(" %d ", tempJ->info);
        tempJ = tempJ->next;
    }
}

void Prebacivanje() {
    tempD = head;
    while (tempD != NULL){
        CreateJ(tempD->data);
        tempD = tempD->next;
        tempD = tempD->next;
    }
}



int main() {

    InsertAtTail(2);
    InsertAtHead(6);
    InsertAtTail(2);
    InsertAtHead(6);
    InsertAtTail(2);
    InsertAtHead(6);
    DisplayD();
    Prebacivanje();
    DisplayJ();

    return 0;
}