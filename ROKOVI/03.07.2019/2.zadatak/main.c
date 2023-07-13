/*Napisati program u C-u kojim se stek predstavlja preko niza, i to takav da se uvek vrsi dodavanje po 3 elementa,
a brisanje po 2 elementa istovremeno. U glavnom programu prikazati rad sa takvim stekom

definisanje velicine niza, globalno def niza, top=-1, fun: PUSH (sFull)i POP(sEmpty) sa for petljom koliko
puta se sta izvrsava*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int s[SIZE], top=-1;

int sFull(){
    if(top >= SIZE-1)
        return 1;
    return 0;
}

int sEmpty() {
    if(top <= -1)
        return 1;
    return 0;
}
int i, elem;
int Push() {
    for(i=1;i<=3;i++) {
        printf("Dodajte %d. element \n", i);
        scanf("%d", &elem);
        if(sFull())  
            printf("Overflow!!!");
        else {
            top++;
            s[top] = elem;
        }
    }
    
    
}

int Pop () {
    
    for(i=1;i<=2;i++) {
        
       // int elem;
        if(sEmpty()) {
            printf("Ovreflow!");
            return -1;
        }
        else {
           elem = s[top];
            top--;
           // printf("Brisete element: ");
            printf("%d \n", elem);
            //printf("\n Izbrisani element je: %d",s[top]);
            //top--;
        }
    }
    
}


void Display() {
    if(sEmpty())
        printf("Empty stack");
    else {
        for(i=0;i<=top; i++) 
            printf(" %d ", s[i]);
        printf("\n");
    }
}


int main() {

    int i, n;
    
    Push();
    Push();
    Display();
    Pop();
    Display();
    


    

    return 0;
}