#include <stdio.h>

int provera(int broj){
    int temp = broj, broj2=0;// 456 6

    while(temp != 0){
        broj2 = broj2 * 10 + temp % 10;
        temp /= 10;
    }
    if(broj2 == broj) return 1;
    return 0;
}

int main(){

    int broj, temp; 
    printf("Unesite broj ");

    while(1){
        scanf("%d", &broj);
        if(provera(broj)) 
            break;
    }

    return 0;
}