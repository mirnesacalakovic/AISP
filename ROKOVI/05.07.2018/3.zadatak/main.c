/*Program za rad sa redom preko niza. U glavnoj funkciji kreirati, koristeci fun za red i stek. U prvi red dodati priv 7 brojeva deljivih
sa 2018, a zati iz prvog reda prebaciti u stek samo brojeve deljive sa 5*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int red[SIZE], f=-1, r=-1;
int stek[SIZE], top=-1;

int isFull() {
    if((f == r+1) || (f == 0 && r == SIZE-1))
        return 1;
    return 0; 
}
int isEmpty() {
    if (f==-1)
        return 1;
    return 0;
}

void insert(int elem) {
    if(isFull())
        printf("overflow ");
    else {
        if(f==-1)
            f = 0;
        r = (r+1)%SIZE;
        red[r] = elem;
    }
}

int delete() {
    int elem;
    if(isEmpty()) {
        printf("overflow!"); 
        return -1;
    }else {
        elem = red[f];
        if(f==r) {
            f=-1; 
            r=-1;
        }else  
            f =(f+1)%SIZE;
        return elem;
    }
}

void display(){
    int i;
    if(isEmpty())
        printf("Empty.");
    else {
        printf("Front[%d]->", f);
        for(i=f; i!=r; i=(i+1)%SIZE)
            printf(" %d ", red[i]);
        printf("%d", red[i]);
        printf(" <-[%d]Rear", r);
    }
}

int sFull(){
    if(top==SIZE-1)
        return 1;
    return 0;
}
int sEmpty() {
    if(top==-1)
        return 1;
    return 0;
}
void push(int elem){
    if(sFull())
        printf("Overflowwww");
    else{
        ++top;
        stek[top] = elem;
    }
}
int pop(){
    int elem;
    if(sEmpty()) {
        printf("underflow");
        return -1;
    }else{
        elem = stek[top];
        top--;
        return elem;
    }
}
void stekDisplay(){
    int i;
    if(sEmpty())
        printf("prazan stek");
    else{
        for(i=0; i<top; i++)
            printf("%d\n", stek[i]);
        printf("TOP");
    }
}







int main() {

    int br=4;
    int n = 2018; 
    
    do {
        for (int i=1; i<=2018; i++) {
            if(2018 % i == 0){
                insert(i);
                br--;
            }
            
        }
    }while(br!=0);
    
    display();
    
    for(int i=f;f!=r;i=(f+1)%SIZE)
        if(red[i] % 5 == 0)
            push(i);
    
    stekDisplay();
    return 0;
}