#include<stdio.h>
#include<stdlib.h>

#define size 7

typedef struct node{               // PRAVIMO STRUKTUR NA NODE
    int data;
    struct node *next;
}NODE;

NODE *niz[size];   // IMAMO NIZ NODEOVA

//void INICNIZA(), void INSERT(value), int SEARCH(value), void PRINT()

void inicNiza()
{
    int i;
    for(i = 0; i < size; i++)  //INICIJALIZUJEMO GA DA BUDU NULL
        niz[i] = NULL;  // napravljen niz koji je prazan
}

void insert(int value)   
{
    //create a newnode with value
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;                      // napravimo newNode
    newNode->next = NULL;

    //calculate hash key
    int key = value % size;             //nabavimo key

    //check if chain[key] is empty
    if(niz[key] == NULL)        // ako nema niko na tom indexu TURI
        niz[key] = newNode;
    //collision
    else
    {
        //add the node at the end of chain[key].
        NODE *temp = niz[key];              // ako ima napravi temp
        while(temp->next)
        {
            temp = temp->next;      //pomeri temp           
        }

        temp->next = newNode;        //i TURI
    }
}


int search(int value)
{
    int key = value % size;         //parvimo key
    NODE *temp = niz[key];          //pravimo temp = niz[key]
    while(temp)
    {
        if(temp->data == value)             //ako je temp->data = value vrati 1
            return 1;
        temp = temp->next;
    }
    return 0;
}


void print()
{
    int i;

    for(i = 0; i < size; i++)
    {
        NODE *temp = niz[i];
        printf("NIZ [%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    //init array of list to NULL
    inicNiza();

    insert(13);
    insert(5);
    insert(32);
    insert(27);
    insert(15);
    insert(8);
    insert(3);
    insert(11);

    print();

    printf("Searching element 10\n");

    if(search(10))
        printf("Search Found\n");
    else
        printf("Search Not Found\n");

    return 0;
}