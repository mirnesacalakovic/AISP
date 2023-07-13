#include <stdio.h>
#define MAX 100
typedef struct {
    int sifra;
    float povPlastika;
    float povDrvo;
    float povStaklo;
    float cena;
}VRATA;


int main() {

    VRATA vrata[MAX];
    int cenaPlastika, cenaDrvo, cenaStaklo, i=0, brVrataDrvo=0, brVrata=0; //metra kvadratnog
    float min;
    FILE *dato1, *dato2;

    printf("Unesite cenu kvadratnog metra plastike ");
    scanf("%d", &cenaPlastika);

    printf("Unesite cenu kvadratnog metra drveta ");
    scanf("%d", &cenaDrvo);

    printf("Unesite cenu kvadratnog metra stakla ");
    scanf("%d", &cenaStaklo);



    if((dato1=fopen("Vrata.dat", "r")) == NULL) {
        printf("Greska!");
        return 1;
    }
    if((dato2=fopen("Cene.dat", "w")) == NULL) {
        printf("Greska!!");
        return 1;
    }


    while (fscanf(dato1, "%d %f %f %f", &vrata[i].sifra, &vrata[i].povPlastika, &vrata[i].povDrvo, &vrata[i].povStaklo) != EOF){
        if(vrata[i].povPlastika == 0 && vrata[i].povStaklo==0)
            brVrataDrvo++;
        vrata[i].cena = (vrata[i].povPlastika * cenaPlastika) + (vrata[i].povDrvo * cenaDrvo) + (vrata[i].povStaklo * cenaStaklo); 

        i++;
        brVrata++;
    }

    min = vrata[0].cena ;
    for(i=0; i<brVrata; i++) { 
        fprintf(dato2, "%d %f \n", vrata[i].sifra, vrata[i].cena );
        if(vrata[i].cena < min)
            min = vrata[i].cena;
    }

    
    printf("Broj vrata koja su 100 posto od drveta je %d\n", brVrataDrvo);
    printf("Najeftinija vrata su: %2.f ", min);

    fclose(dato1);
    fclose(dato2);

    return 0;

}