#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int item;
	struct node *next;
};

void insertTail(struct node **h,struct node **t,int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->item=data;
	temp->next=NULL;
	temp->prev=NULL;
	if((*h)==NULL&&(*t)==NULL)
	{
		*h=temp;
		*t=temp;
	}
	else
	{
		temp->prev=*t;
		(*t)->next=temp;
		(*t)=temp;
	}
}

void insertHead(struct node **h,struct node **t,int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	temp->item=data;
	
	if((*h)==NULL&&(*t)==NULL)
	{
		*h=temp;
		*t=temp;
	}
	else
	{
		temp->next=*h;
		(*h)->prev=temp;
		*h=temp;
	}
}

void deletionHead(struct node **h,struct node **t)
{
	struct node *r;
	r=*h;
	if((*h)==NULL&&(*t)==NULL)
	{
		printf("Queue is Empty\n");
	}
	else if(*h==*t)
		{
			free(*h);
			free(*t);
			*h=NULL;
			*t=NULL;
		}
		else
		{
			(*h)=(*h)->next;
			(*h)->prev=NULL;
			free(r);
			
		}
}

void deletionTail(struct node **h,struct node **t)
{
	struct node *r;
	r=*t;
	if((*h)==NULL&&(*t)==NULL)
		printf("Queue is Empty\n");
	else if(*h==*t)
		{
			free(*h);
			free(*t);
			*h=NULL;
			*t=NULL;
		}
	else
	{
		(*t)=(*t)->prev;
		(*t)->next=NULL;
		free(r);	
	}
}

struct node* search(struct node *h,int data)  
{                                           
	while(h){
	if(h->item==data)
		  return h;
		 h=h->next;
			}
	return NULL;
}

void viewFirst(struct node *h,struct node *t)
{
	while(h)
	{
		printf("%d \t",h->item);
		h=h->next;
	}
}

void viewLast(struct node *h,struct node *t)
{
	while(t)
	{
		printf("%d \t",t->item);
		t=t->prev;
	}
}
int menu()
{
	int ch;
	printf("\n\n 1. insert an item at Head ");
	printf("\n 2. insert an item at Tail  ");
	printf("\n 3. delete node at Tail ");
	printf("\n 4. delete node at Head ");
	printf("\n 5. view at Head to Tail ");
	printf("\n 6. view at Tail to Head ");
	printf("\n 7. search node");
	printf("\n 8. exit");
	printf("\n\n Enter your choice: ");
	scanf("%d",&ch);
	return ch;
}


void main()
{
	struct node *head=NULL;
	struct node *tail=NULL;
	struct node *temp;
	while(1)
	{ 
	switch(menu())
	{  int data;
		case 1:  {
		    int i,n;
			printf("How many element you want to insert = ");
			scanf("%d",&n);
		    printf("\n enter data to be inserted at head \n ");
		    for(i=1;i<=n;i++){
		    scanf("%d",&data);
		    insertHead(&head,&tail,data);
		}
		break;
	       }
		
		case 2: {
		    int i,n;
			printf("How many element you want to insert = ");
			scanf("%d",&n);
		    printf(" enter data to be inserted at Tail \n ");
		    for(i=1;i<=n;i++){ 
		    scanf("%d",&data);
		    insertTail(&head,&tail,data);
		}
		break;}
		
		case 3:	
			deletionTail(&head,&tail);
		break;
		
		case 4:
			deletionHead(&head,&tail);
		break;
		
		case 5:
			viewFirst(head,tail);
			break;
		case 6:
		viewLast(head,tail);
		break;
			
		case 7:
		{
			struct node *temp;
		    printf(" enter data you want to search \n ");
		    scanf("%d",&data);
		    temp=search(head,data);
		    if(temp==NULL)
		    {
		    	printf(" no such node found %c %c \n",2,2);
			}
			else 
			printf(" data %d is found ",temp->item);
			break;
		}
			
		case 8:
			exit(0);
     }
}
}
