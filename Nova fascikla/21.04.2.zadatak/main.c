 #include <stdio.h>
 #include <stdlib.h>

#define SIZE 7

int N[SIZE]; 
int top = -1, f = -1, r = -1;

void enqueue(int x){
    if(f == (r+1)%SIZE) 
        printf("queue overflow");
    if(r == -1){
        r = f = 0;
        N[r] = x;
    }else{
        r = (r+1)%SIZE;
        N[r] = x;
    }
}

int dequeue(){  
    int elem;
    if(f==-1)
        printf("Queue overflow");
    else if(f == r){
        elem = N[r];
        r = f = -1;
    }else{
        elem = N[r];
        r = (r + SIZE-1)% SIZE;
    }
    return elem;
}


 void Push(int x){
    if(top != SIZE-1){
        top++;
        enqueue(x);
    }
 }

 int Pop(){
    int elem;
    if(top != -1){
       elem = dequeue();
        top--;
        return elem; 
    }
    printf("Stack is empty"); 
 }

void Print(){
    int i;

    for(i=0; i<=top; i++){
        printf("%d ", N[i]);
    }
    printf("\n");
}


 int main(){

    Push(5);
    Push(12);
    Push(6);
    Push(2);
    Print();
    Pop();
    Pop();
    Print();


    return 0;
 }