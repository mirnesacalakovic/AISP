/*Program za rad sa jednostruko ulancanom listom. Fun za pretragu sortirane liste. U glavnom programu demon. rad fun*/
/*struktura, globalne, fun: display(), insertAfter(), insertBefore(), deleteAfter(), Pretraga()*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;

}NODE;

NODE *first = NULL, *last = NULL, *temp = NULL;

void create(int elem) {
    temp = (NODE*)malloc(sizeof(NODE));
    temp->data = elem;
    temp->next = NULL;
    if(first == NULL)
        first = last = temp;
    else {
        last->next = temp;
        last = temp;
    }
}

void insert_after(NODE *pom, int elem) {
    temp = (NODE*)malloc(sizeof(NODE));
    temp->data = elem;
    temp->next = pom->next;
    pom->next = temp;
    if(pom==last) 
        last = temp;
    
}

void insert_before(NODE *pom, int elem) {
    temp=(NODE*)malloc(sizeof(NODE));
    temp->next = pom->next;
    temp->data = pom->data;
    pom->data = elem;
    pom->next = temp;
    if(pom==last)
        temp = last;
}

void delete_after(NODE *pom) {
    temp = pom->next;
    pom->next = temp->next;
    temp->next = NULL;
    free(temp);
}

void display() {
    temp = first;
    while(temp!=NULL){
        printf(" %d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

NODE* Pretrazivanje(NODE *pom, int elem) {
    temp = pom;
    if (first == NULL) {
        printf("Prazna");
        return NULL;
    } 
    
    if(temp->data == elem){ 
        printf("Element nadjen");
        return temp;
    }
    else {
        temp=temp->next;
        Pretrazivanje(pom->next, elem);
    }
         

}

int main() {

    create(3);
    create(5);
    create(7);
    create(1);
    create(5);
    display();
    Pretrazivanje(first, 1);
    printf("\n%d\n", Pretrazivanje(first, 1)->data);

    return 0;
}