#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int queue[SIZE];
int f = -1, r = -1;

void insert_r(int x){
    if(f==(r+1)%SIZE)
        printf("Queue overflow");
    else if(r == -1){
        r = f = 0;
        queue[r] = x;
    }


    else{
        r = (r+1)%SIZE;
        queue[r] = x;
    }
}

void insert_f(int x){
    if(f == (r+1)%SIZE)
        printf("Queue overflow");
    else if(r == -1){
        r = f = 0;
        queue[r] = x;
    }
    
    
    else{
        f = (f+ SIZE-1)%SIZE;
        queue[f] = x;
    }
}

int delete_r(){
    int elem;
    if(f == -1)
        printf("Queue underflow");
    else if(f == r){
        elem = queue[f];
        f = -1;
        r = -1;
    }
    
    else{
        elem = queue[r];
        r = (r+ SIZE-1)%SIZE;
    }
    return elem;
}

int delete_f(){
    int elem;
    if(f == -1)
        printf("queue underflow");
    if(f == r){
        elem = queue[f];
        f = r = -1;
    }
    else{
        elem = queue[f];
        f = (f+1) % SIZE;
    }
    return elem;
}

void display(){
    int i;
    if ( f == -1)   
        printf("Empty queue");
    else{
        printf("\n");
        printf("Front [%d] -> ", f);
        for(i=f; i!=r; i = (i+1)%SIZE)
            printf("%d ", queue[i]);
        printf("%d ", queue[i]);
        printf("<- [%d] Rear", r);
    }
}


int main(){

    insert_f(2);
    insert_f(5);
    insert_f(7);
    insert_r(3);
    insert_r(8);
    insert_r(1);
    display();
    delete_f();
    delete_r();
    display();


    return 0;    
}