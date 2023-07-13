#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

typedef struct DataItem{
    int data;
    int key;
    struct DataItem *next;
}ITEM;

ITEM *hashArray[SIZE];
ITEM *item;

int hashCode1(int key){
    return key % SIZE;
}
int hashCode2(int key){
    return (4+(key % SIZE))%SIZE;
}

void insert(int key, int data){
    ITEM *item = (ITEM*)malloc(sizeof(ITEM));
    item->data = data;
    item->key = key;

    int hashIndex = hashCode1(key);
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
        hashIndex = hashCode2(key);

    hashArray[hashIndex] = item;
}

ITEM *search(int key){
    int hashIndex = hashCode1(key);

    if(hashArray[hashIndex]->key == key)
        return hashArray[hashIndex];
    else{
        while(hashArray[hashIndex] != NULL)
            hashIndex = hashCode2(key);
        return hashArray[hashIndex];
    }
    return NULL;
}

void Print(){
    int i;
    for(i=0; i<SIZE; i++){
        printf("\n");
        if(hashArray[i] != NULL)
            printf("%d %d",hashArray[i]->key, hashArray[i]->data);
        else    
            printf("~~");
    }
    printf("\n");
}


int main(){

    insert(1, 4);
    insert(2, 9);
    insert(5, 92);
    insert(6, 64);
    insert(8, 91);
    Print();

    item = search(5);
    if(item != NULL)
        printf("Element %d found", item->data);
    else
        printf("Element not find");

    return 0;
}