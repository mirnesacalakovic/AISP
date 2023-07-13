#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

typedef struct DataItem{
    int data;
    int key;
    struct DataItem *next;
}ITEM;

ITEM *hashArray[SIZE];
ITEM *dummyItem;
ITEM *item;

int hashCode1(int key){
    return key % SIZE;
}
int hashCode2(int key){
    return 4 + (key % 2);
}

void insert (int key, int data){
    ITEM *item = (ITEM*)malloc(sizeof(ITEM));
    item->key = key;
    item->data = data;

    int hashIndex = hashCode1(key); 
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){
        hashIndex = hashCode2(key);
        
    }
    hashArray[hashIndex] = item;
}

ITEM *search(int key){
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


ITEM *delete(ITEM *item){
    int key = item->key;

    int hashIndex = hashCode1(key);

    
    if(hashArray[hashIndex]->key == key){
        ITEM *temp = hashArray[hashIndex];
        hashArray[hashIndex] = dummyItem;
        return temp;
    }
    else{
        hashIndex = hashCode2(key);
        if(hashArray[hashIndex]->key == key){
        ITEM *temp = hashArray[hashIndex];
        hashArray[hashIndex] = dummyItem;
        return temp;
        }
    }
    return NULL;
}

void display(){
    int i;
    for (i=0; i<SIZE; i++){
        if (hashArray[i] != NULL)
            printf("%d %d\n", hashArray[i]->key, hashArray[i]->data);
        else 
            printf("~~\n");
        
    }
    printf("\n");
}

int main(){

    dummyItem = (ITEM*)malloc(sizeof(ITEM));
    dummyItem->data = -1;
    dummyItem->key = -1;

    insert(1, 5);
    insert(2, 7);
    insert(3, 8);
    insert(0, 2);
    insert(2, 5);
    insert(8, 1);
    
    
    
    display();

    item = search(3);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }

    delete(item);
    item = search(3);

    if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }
    return 0;
}