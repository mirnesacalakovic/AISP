#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

typedef struct DataItem{
    int data;
    int key;
    struct DataItem *next;
}DataItem;

DataItem *hashArray[SIZE];
DataItem *dummyItem;
DataItem *item;

int hashCode1(int key){
    return key % SIZE;
}
int hashCode2(int key){
    return (4 + (key % 2))% SIZE;
}

void insert (int key, int data){
    DataItem *item = (DataItem*)malloc(sizeof(DataItem));
    item->data = data;
    item->key = key;

    int hashIndex = hashCode1(key);
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex] != -1)
        hashIndex = hashCode2(key);
    
    hashArray[hashIndex] = item;    
}

DataItem *search(int key){
    int hashIndex = hashCode1(key);

    if(hashArray[hashIndex]->key == key)
        return hashArray[hashIndex];
    else{
        while(hashArray[hashIndex]->key != key)
            hashIndex = hashCode2(key);
        return hashArray[hashIndex];
    }
    return NULL;
}

DataItem *delete(DataItem *item){
    int key = item->key;

    int hashIndex = hashCode1(key);

    if(hashArray[hashIndex]->key == key){
        DataItem *temp = hashArray[hashIndex];
        hashArray[hashIndex] = dummyItem;
        return temp;
    }
    else{
        while(hashArray[hashIndex]->key != key)
            hashIndex = hashCode2(key);
        DataItem *temp = hashArray[hashIndex];
        hashArray[hashIndex] = dummyItem;
        return temp;
    }
    return NULL;
}

void display(){
    int i;
    for (i=0; i<SIZE; i++){
        if(hashArray[i] != NULL)
            printf("%d, %d\n", hashArray[i]->key, hashArray[i]->data);
        else 
            printf("~~\n");
    }
    printf("\n");
}


int main(){

    dummyItem = (DataItem*)malloc(sizeof(DataItem));
    dummyItem->data = -1;
    dummyItem->key = -1;
    dummyItem->next = NULL;
    DataItem *item = (DataItem*)malloc(sizeof(DataItem));
    item->data = 4;
    item->key = 1;  

    insert(1, 4);
    insert(3, 6);
    insert(4, 8);
    insert(6, 8); 
    insert(2, 5);
    insert(5, 12);
    insert(8, 3);
    insert(7, 1);
    display();
    delete(item);
    display();

    DataItem *stavka;

    stavka = search(3);
    if (stavka != NULL)
        printf("Element %d found", stavka->data);
    else
        printf("Element not found");
    



    return 0;
}