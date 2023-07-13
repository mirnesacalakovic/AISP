//Presek dve liste
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

void insert();
void display();
//int getIntesectionNode(int d, NODE *first1, NODE *first2);


typedef struct node
{
    int data;
    struct node *next;
}NODE;




NODE *temp=NULL;
NODE *first[3]={NULL,NULL,NULL};
NODE *last[3]={NULL,NULL,NULL};




NODE *search(NODE *list,int val)
{
NODE *ptr;
for(ptr=list;ptr!=NULL && ptr->data!=val;ptr=ptr->next);
return(ptr);
}





int isPresent (NODE *head, int data)
{
struct node *t = head;
while (t != NULL)
{
if (t->data == data)
return 1;
t = t->next;
}
return 0;
}




NODE *getIntersection (NODE *head1, NODE *head2)
{

NODE *t1 = head1;

// Traverse list1 and search each element of it in list2. If the element
// is present in list 2, then insert the element to result
while (t1 != NULL)
{
    if (isPresent(head2, t1->data))
        insert(t1->data, 0);
    t1 = t1->next;
}
// pokazivac first[0] je koriscen kao pokazivac na rezultat 
return first[0];
}





void insert(int elem, int listNo)
{
	temp=(struct node*)malloc(sizeof(struct node));
    temp->data=elem;
    temp->next=NULL;
    if(first[listNo]==NULL)
    {
        first[listNo]=temp;
        last[listNo]=temp;
    }
    else
    {
        last[listNo]->next=temp;
        last[listNo]=temp;
    }
	
}





void display(NODE *first)
{
    temp=first;
    printf("First->");
    while(temp!=NULL)
    {
    //printf("|%d|%d| --> ",temp->data,temp->next);
    printf("|%d| --> ",temp->data);
    temp=temp->next;
    }
      printf("NULL");
}




main()
{

	NODE *pom;
printf("Jednostruko ulancana lista list1 \n");
insert(5,1);
insert(20,1);
insert(100,1);
display(first[1]);
insert(100,2);
insert(5,2);
insert(300,2);
printf("\n Jednostruko ulancana lista list2 \n");
display(first[2]);
pom=getIntersection(first[1],first[2]);
printf("\n The intersection list is: ");
display(pom);
} 