/*Program za rad sa jednostrukom ulancanom listom. Kreirati funkcije prviParan(NODE* I) koja od date liste vraca prvi element ako je paran
u suprotnom vraca null i listaParnih(NODE *I) koja od date liste pravi novu, tako sto dodaje parne elemente liste na kraj nove liste
a brise ga iz stare liste*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *first1=NULL, *first2 = NULL, *last1 = NULL, *last2 = NULL;

void create(NODE **first, NODE **last, int data){
    NODE *newElement = (NODE*)malloc(sizeof(NODE));
    newElement->data = data;
    newElement->next = NULL;
    if (*first == NULL)
        *first = *last = newElement; 
    else{
        (*last)->next = newElement;
        (*last)=newElement;
    }
}

void delete_actual(NODE **first, NODE **last, NODE *pom){
    NODE *temp;
    if((pom == *first) && (*first == *last)) {
        *first = *last = NULL;
        free(pom);
    }
    temp = pom->next;
    pom->next = temp->next;
    pom->data = temp->data;
    free(temp);
}

void display(NODE *first){
    NODE *temp = first;
    if(first==NULL){
        printf("Empty list\n");
        return;
    }
    while(temp != NULL){
        printf("|%d| ", temp->data);
        temp = temp->next;
    }
    printf("\tNULL");
}

NODE* prviParan(NODE *I){
    if(I->data%2 == 0)
        return I;
    return NULL;
}

NODE *listaParnih(NODE *I){
    NODE *temp = I;

    while(temp!=NULL){
        if(temp->data % 2 == 0){
            create(&first2, &last2, temp->data);
            delete_actual(&first1, &last1, temp);
        }
        temp = temp->next;
    }
    return first2;
}


int main() {

    create(&first1, &last1, 4);
    create(&first1, &last1, 2);
    create(&first1, &last1, 6);
    create(&first1, &last1, 7);
    create(&first1, &last1,8);

    display(first1);
    printf("\nPrvi element je: %d\n",prviParan(first1)->data);

    listaParnih(first1);
    display(first2);
    printf("\nPrvi element je: %d\n");
    display(first1);
    
    return 0;

}