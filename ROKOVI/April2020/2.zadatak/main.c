/* Sadrzi funkcije za rad sa dekom velicine 12. U glavnoj fun omoguciti unos niza, pa potom, parne brojeve dodati
na pocetak a neparne br na kraj deka. Obrisati poslednja 2 uneta elementa */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 12



int queue[SIZE];
int F = -1;
int R = -1;



void insert_r(int x) {
    if(F == (R+1) % SIZE)  
        printf("Queue overflow");
    else if (R == -1) {
        F = 0;
        R = 0;
        queue[R] = x;
    } else {
        R = (R + 1) % SIZE;
        queue[R] = x;
    }
}

void insert_f(int x) {
    if (F == (R + 1) % SIZE) {
        printf("Queue overflow!!");
    } else if (R == -1) {
        F = 0;
        R = 0;
        queue[R] = x;
    } else {
        F = (F + SIZE-1) % SIZE;
        queue[F] = x;
    }
}

int delete_r () {
    int x;
    if (F == -1)
        printf("Queue overflow!!!");
    else if(F == R) {
        x = queue[F];
        F = -1;
        R = -1;
    } else {
        x = queue[R];
        R = (R + SIZE-1)%SIZE;
    }
    return x;
}

int delete_f() {
    int x;
    if(F == -1) 
        printf("Queue underflow!!!!");

    else if(F == R){
        x = queue[F];
        F = -1;
        R = -1;
    } else {
        x = queue[F];
        F = (F+1)%SIZE;
    }
    return x;
}


void display() {
    int i;
    if (F==-1)
        printf("Empty Queue\n");
    else {
        printf("Front[%d] ->", F);
        for (i = F; i!=R; i = (i+1)%SIZE)
            printf("%d", queue[i]);
        printf("%d", queue[i]);
        printf("<- [%d] REAR", R);
    }
    printf("\n");
}

int main() {

    int i, x[SIZE], brF=0, brR=0;
    
    printf("Unesite brojeve u niz\n");
    for(i = 0; i<SIZE; i++) {
        scanf("%d", &x[i]);
        if (x[i] % 2 == 0){
            insert_f(x[i]);
            if (i >= (SIZE - 2))
                brF++;
        }
        else {
            insert_r(x[i]);
            if (i >= (SIZE - 2))
                brR++;
        }
    }
    
    display();
    for (i=0;i<brF;i++)
        delete_f();
    for (i=0;i<brR;i++)
        delete_r();
    display();

    return 0;
}