#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct DataItem {
    int data; 
    int key;
} DataItem;

DataItem* hashArray[SIZE];
DataItem* dummyItem;
DataItem* item;

int hashCode(int key) { //fun za onaj index
    return key % SIZE; // key moduo VELICINA NIZA
}

DataItem* search (int key){
    //nadjemo index za nas key
    int hashIndex = hashCode(key); // saljemo key nasoj funkciji 

    //sve dok ne dodjemo do kraja niza
    while(hashArray[hashIndex] != NULL){ 

        if(hashArray[hashIndex]->key == key) // ako je isti kljuc - mesto zauzeto
            return hashArray[hashIndex];       //vrati mesto i sad spremamo za drugi moduo

        //idi na sledeci index
        ++hashIndex;

        //drugi moduo
        hashIndex %= SIZE;

    }

    return NULL;
}

void insert(int key, int data) {
     
    DataItem* item =(DataItem*)malloc(sizeof(DataItem));
    item->data = data;
    item->key = key;

    //nadjemo index za odredjeni kljuc
    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){
        
        ++hashIndex; //idi na drugo polje

        hashIndex % SIZE; //drugi moduo
    }

    hashArray[hashIndex] = item; //ubacimo taj node na taj index

}


DataItem* delete(DataItem* item){
    int key = item->key;

    int hashIndex = hashCode(key);

    while (hashArray[hashIndex] != NULL){
        if(hashArray[hashIndex]->key = key){//ako je index zauzet
            DataItem* temp = hashArray[hashIndex]; // temp ce da nam pokazuje na taj index

            hashArray[hashIndex] = dummyItem;
            return temp;
        } 
        
        ++hashIndex;

        hashIndex %= SIZE;
    }

    return NULL;
}

void display() {
    int i = 0;

    for (i=0; i<SIZE; i++) {
        if(hashArray[i] != NULL)
            printf("(%d, %d)", hashArray[i]->key, hashArray[i]->data);
        else printf(" ~~ ");
    }

    printf("\n");
}

int main() {
    dummyItem = (DataItem*)malloc(sizeof(DataItem));
    dummyItem->data = -1;
    dummyItem->key = -1;

    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);

    display();

    item = search(37);

    if(item!=NULL)
        printf("ELment fount: %d\n", item->data);
    else
        printf("Elemet not found\n");
    
    delete(item);
    item = search(37);

    if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }


    return 0;
}