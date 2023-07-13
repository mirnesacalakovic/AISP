#include <stdio.h>
#include <stdlib.h> //insert-r() insert-f()  delete-r() delete-f()  display()


#define SIZE 7

int QQ[SIZE], f =-1, r =-1;

void insert_r(int x){
    if(f = (r+1)%SIZE)
        printf("Queue is full");
    else if(r == -1){
            f = r = 0;
            QQ[r] = x;
    }else{
        r = (r+1)%SIZE;
        QQ[r] = x;
    }
}

void insert_r(int value){
    if(f == (r+1)%SIZE)
        printf("Queue is full");
    else if(r == -1){
        f = r = 0;
        QQ[r] = value;
    }else{
        r = (r+1)%SIZE;
        QQ[r] = value;
    }
}

void insert_r(int value){
    if(f == (r+1)%SIZE)
        printf("Queue overflow");
    else if(r == -1){
        f = r = 0;
        QQ[r] = value;
    }else{
        r = (r+1)%SIZE;
        QQ[r] = value;
    }
}

void insert_r (int value){
    if(f = (r+1)%SIZE)
        printf("Queue overflow");
    else if(r == -1){
        r = f = 0;
        QQ[r] = value;
    }else{
        r = (r+1)%SIZE;
        QQ[r] = value;
    }
}

void insert_r(int value){
    if(f == (f+1)%SIZE)
        printf("Queue full");
    else if(r == -1){
        f= r = 0;
        QQ[r] = value;
    }else{
        r = (r+1)%SIZE;
        QQ[r] = value;
    }
}

void insert_f(int value){
    if(f == (r+1)%SIZE)
        printf("Queue is full");
    else if(r == -1){
        r = f = 0;
        QQ[r] = value;
    }else{
        f = (f + SIZE-1)%SIZE;
        QQ[f] = value;
    }
}

void insert_f(int value){
    if(f == (r+1)%SIZE)
        printf("");
    else if(r == -1){
        f = r = 0;
        QQ[r] = value;
    }else{
        f = (f+ SIZE-1)% SIZE;
        QQ[f] = value;
    }
}

void insert_r(int value){
    if(f == (r+1)%SIZE)
        printf("");
    else if(r == -1){
        r = f = 0;
        QQ[r] = value;
    }else{
        r =(r+1)%SIZE;
        QQ[r]=value;
    }
}

void insert_f(int x){
    if(f == (r+1)%SIZE)
        printf("");
    else if(r == -1){
        f = r = 0;
        QQ[r] = x;
    }else{
        f = (f + SIZE-1)%SIZE;
        QQ[f]= x;
    }
}

int delete_r(){
    int elem;
    if(f==-1)
        printf("");
    else if(f == r){
        elem = QQ[f];
        f = r = -1;
    }else{
        elem = QQ[r];
        r = (r + SIZE-1)%SIZE;
    }
    return elem;
}

int delete_r(){
    int x;
    if(f == -1)
        printf("");
    else if(f == r){
        x = QQ[r];
        r = f = -1;
    }else{
        x = QQ[r];
        r = (r+ SIZE-1)%SIZE; 
    }
    return x;
}

int delete_f(){
    int x;
    if(f == -1)
        printf("Empty queue");
    else if(r = f){
        x = QQ[r];
        f = r = -1;
    }else{
        x =QQ[f];
        f = (f+SIZE-1)%SIZE;
    }
    return x;
}

int delete_r(){
    int x;
    if(f == -1)
        printf("empty queue");
    else if(f = r){
        x = QQ[r];
        f = r = -1; 
    }else{
        x = QQ[r];
        r = (r + SIZE-1)%SIZE;
    }
    return x;
}

void insert_r(int x){
    if (f == (r+1)%SIZE)
        printf("Queue is fiull");
    else if(r == -1){
        f = r = 0;
        QQ[r] = x;
    }else{
        r = (r+1)%SIZE;
        QQ[r] = x;
    }
}

int delete_f(){
    int x;
    if(f == -1)
        printf("Empty");
    else if(f = r){
        x = QQ[r];
        r = f = -1;
    }else{
        x = QQ[f];
        f = (f+1)%SIZE;
    }
    return x;
}


void insert_f(int x){
    if (f == (r+1)%SIZE)
        printf("full queue");
    else if(r = -1){
        r = f = 0;
        QQ[r] = x;
    }else{
        f = (f + SIZE-1)%SIZE;
        QQ[f] = x;
    }
}




int delete_r(){
    int x;
    if (f == -1)
        printf("emtpty queue");
    else if(f == r){
        x = QQ[r];
        f = r = -1;
    }else{
        x = QQ[r];
        r = (r+ SIZE-1)%SIZE;
    }
    return x;
}



void insert_r(int x){
    if(f == (r+1)%SIZE)
        printf("Full");
    else if(r == -1){
        f = r = 0;
        QQ[r] = x;
    }else{
        r = (r+1)%SIZE;
        QQ[r] = x;
    }
}


int delete_f(){
    int x;
    if(f == -1)
        printf("");
    else if (r = f){
        x = QQ[r];
        r = f =-1;
    }else{
        x = QQ[f];
        f = (f+1)%SIZE;
    }

}


void insert_f(int x){
    if(f == (r+1)%SIZE)
        printf("Dek je pun");
    else if(r == -1){
        r = f = 0;
        QQ[r] = x;
    }else{
        f = (f + SIZE-1)%SIZE;
        QQ[f] = x;
    }
}

int delete_r(){
    int x;
    if(f == -1)
        printf("dek je prazan");
    else if(r = f){
        x = QQ[r];
        f = r = -1;
    }else{
        x = QQ[r];
        r = (r + SIZE-1)%SIZE;
    }
    return x;
}