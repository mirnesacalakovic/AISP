/*Program za rad sa jednostruko ulancanom listom. Fun za pretragu sortirane liste. U glavnom programu demon. rad fun*/
/*struktura, globalne, fun: display(), create(), insertAfter(), insertBefore(), deleteAfter(), Pretraga()*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE *first = NULL, *last = NULL, *temp = NULL;

void create(int elem) {
    temp = (NODE*)malloc(sizeof(NODE));
    temp->data = elem;
    temp->next = NULL;
    if(first==NULL) 
        first = last = temp;
    else {
        last->next = temp;
        last = temp;
    }
}

void insert_after(NODE *pom, int elem) {
    temp = (NODE*)malloc(sizeof(NODE));
    temp->data = elem;
    temp->next = pom->next;
    pom->next = temp;
    if(pom == last)
        last = temp; //temp je sada poslednji
}

void insert_before(NODE *pom, int elem) {
    temp = (NODE*)malloc(sizeof(NODE));
    temp->next = pom->next;
    temp->data = pom->data;
    pom->data = elem;
    pom->next = temp;
    if (pom == last)
        temp = last; //last dodeljujemo tempu
}

void delete_after(NODE *pom) {
    temp = pom->next;
    pom->next = temp->next;
    temp->next = NULL;
    free(temp);
}

void display(){
    temp = first;

    while(temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


NODE *SrednjiElement(NODE *start, NODE *last) { //saljemo od kog pocinjemo i last

    if (start == NULL) //ako nemamo start ne vracamo nista
        return NULL;

    NODE *slow = start;  //postavimo da nam je slow na start
    NODE *fast = start->next;      //postavimo da nam je fast na sledecem elemntu; kad fast bude na last, slow ce biti na sredini

    while(fast != last) {           // sve dok fast nije poslednji
        fast = fast->next;          // fast ce da se pomeri za jedan korak
        if(fast != last) {            // ispitamo ako fast nije poslednji (da bi fast bio u prednosti)
            slow=slow->next;            //slow pomerimo za jedan
            fast = fast->next;  	       //fast pomerimo za jedan
        }
    }                               //POSLE JEDNE ITERACIJE WHILEA FAST JE DVA KORAKA ISPRED 
    return slow;
}

NODE *Pretrazivanje(NODE *first, int value) {
    NODE *start = first;
    NODE *last = NULL;

    NODE *mid = SrednjiElement(start, last);

    do {
        if (mid == NULL)
        return NULL;
    
        if(mid->data == value)
            return mid;
        else if(mid->data < value)
            start = mid->next;
        else 
            last = mid;
    } while (last == NULL || last != start);
    
    return NULL;
}




int main() {

    create(5);
    create(2);
    create(9);
    create(21); 
    create(6);
    create(4);
    create(66);
    create(123); 

    display();

    if(Pretrazivanje(first, 22) != NULL)
        printf("Element nadjen");
    else 
        printf("Element nije nadjen");

    return 0;
}
/*NODE *SrednjiELement(NODE *start, NODE *last) {
    if (start == NULL)
        return NULL;
    
    NODE *slow = start;
    NODE *fast = start->next;

    while(fast!=last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

NODE *Pretrazivanje(NODE *first, int value) {
    NODE *start = first;
    NODE* last = NULL;

    do{
        //find middle
        NODE* mid = SrednjiELement(start, last);
        
        
        if(mid == NULL)
            return NULL;
        
        if(mid->data == value)
            return mid;
        
        else if(mid->data < value)
            start = mid->next;

        else   
            last = mid;
    } while (last == NULL || last!=start);

    
    return NULL;
}*/