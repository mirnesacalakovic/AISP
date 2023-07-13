#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *first = NULL, *last = NULL, *temp = NULL;

void create(int elem){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = elem;
    newNode->next = NULL;
    if(first == NULL)
        first = last = newNode;
    else{
        last->next = newNode;
        last = newNode;
    }
}

void print(){
    NODE *temp = first;
    if(first == NULL)
        printf("Lista je prazna");

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

NODE *middle ( NODE *start, NODE* last){
    if(start == NULL)
        return NULL;
    NODE *slow = start;
    NODE *fast = start->next;

    while(fast != last){
        fast = fast->next;
        if(fast != last){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

NODE *binarySearch(NODE *first, int value){
    NODE *start = first;
    NODE *last = NULL;

    NODE *mid = middle(start, last);
    do{
        
        if (mid == NULL)
            return NULL;
        if(mid->data == value)
            return mid;
        else if(mid->data < value)
            start = mid->next;
        else
            last = mid;
    }while(last == NULL || last != start);

    return NULL;
}

int main(){


    create(2);
    create(3);
    create(5);
    create(6);
    create(7);
    create(9);
    print();
   
    if(binarySearch(first, 7) != NULL)
        printf("Elemnt found");
    else 
        printf("Element not found");


    return 0;
}
