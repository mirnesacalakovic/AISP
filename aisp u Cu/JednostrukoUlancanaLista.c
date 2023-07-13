// jednostruko ulancana lista - klasicne operacije
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void insert_after();
void insert_before();
void create();
void delete_after();
void delete_actual();
void delete_on_position();
void delete_by_value();
void display();


typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *first=NULL,*last=NULL,*temp=NULL;


int isEmpty(){
	if (first==NULL) return 1;
	else return 0;
}
void create(int elem)
{
	temp=(struct node*)malloc(sizeof(struct node));
    temp->data=elem;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
        last=temp;
    }
    else
    {
        last->next=temp;
        last=temp;
    }
	
}
void insert_after(NODE *pom, int elem)
{
	
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=elem;
    temp->next=pom->next;
    pom->next=temp; 
    if (pom==last) last=temp;
    
}

void insert_before(NODE *pom, int elem)
{

    temp=(struct node*)malloc(sizeof(struct node));
     temp->next=pom->next;
     temp->data=pom->data;
     pom->data=elem;
     pom->next=temp;
     if (pom==last){
	 temp=last;
     }
}

void delete_after(NODE *pom)
{
//if (isEmpty()) printf("List is empty");		
temp=pom->next;
pom->next=temp->next;
temp->next=NULL;
free(temp);	
}

void delete_actual(NODE *pom){
	if ((pom==first)&(first==last)){
		first=last=NULL;
		free(pom);
	}
	temp=pom->next;
	pom->next=temp->next;
	pom->data=temp->data;
	free(temp);
	
}

void delete_on_position(int pos)
{		
int count=1;
NODE *p, *q;
p=first;
q=NULL;
if (pos==1){
	first=p->next;
	free(p);
	return;
}
while(pos!=count)
{
 q=p;	
 p=p->next;
 count++;
}
delete_after(q);

}

void delete_by_value(int value){
NODE *p,*q;
    
    p=first;
    q=NULL;
    while(p!=NULL)
    {
        if(value==p->data)
        break;
        else
        {
        q=p;	
        p=p->next;
            }
    }
    if((p==first)&(first==last))
    {
        first=last=NULL;
        free(p);
        printf("Lista je sada prazna!");
    }
    else if(p==last)
    {
        q->next=NULL;
        free(p);
        last=q;
    }
    else
    {
        q->next=p->next;
        free(p);
    }	
}


void display()
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
	int ch;
	int element;
	printf("List is empty, add any element: ");scanf("%d",&element);create(element);
    do{ 
    printf("\nSingle Linked List");
    printf("\n------------");
    printf("\n1.Insert at first\n2.Insert at last\n3.Delete first\n4.Delete by Position\n5.Delete by Value\n6.Display\n7.Exit");
    printf("\n\n-->Enter Your Choice:");
    scanf("%d",&ch);
 
        switch(ch)
        {
        	
            case 1: printf("\n-->Enter value:");scanf("%d",&element);insert_before(first,element);break;
            case 2: printf("\n-->Enter value:");scanf("%d",&element);insert_after(last,element);break;
            case 3: delete_actual(first);break;
            case 4:printf("\n-->Enter position to delete:");scanf("%d",&element);delete_on_position(element);break;
            case 5:printf("\n-->Enter value to delete:");scanf("%d",&element);delete_by_value(element);break;
            case 6:display();break;
            case 7:exit(0);
         
            default:printf("\nError-->Enter a valid choice!!"); exit(0);
        }
    }while(1);
	
	
	
/*printf("Jednostruko ulancana lista \n");
create(5);
insert_after(first,10);
insert_after(first,20);
insert_before(last,99);
display();*/
} 