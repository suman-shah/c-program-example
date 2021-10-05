#include<stdio.h>
#include<stdlib.h>
// constructor
struct node{
int data;
struct node*next;
struct node*prev;}*head;

//finction for creating doubly linked list
void createlist(int n)
{
    struct node*newnode,*temp;
    int data,i=1;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==0)
       {printf("empty");}
    else
       {printf("enter data");
       scanf("%d",&head->data);
       head->next=0;
       head->prev=0;
       temp=head;
       for(i=2;i<=n;i++)
       {
           newnode=(struct node*)malloc(sizeof(struct node));
           printf("enter data");
           scanf("%d",&newnode->data);
           newnode->next=0;
           temp->next=newnode;
           newnode->prev=temp;
           temp=newnode;
       }
       }

}

// display a list
void displaylist(){struct node*temp;
int count=0;
temp=head;
while(temp!=0)
{
    printf("%d\n",temp->data);
    temp=temp->next;
    count++;
}
printf("count is :%d\n",count);
}

// insert at beginning
struct node*insertatbeg(){
int data;
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter data u want to insert");
scanf("%d",&newnode->data);
newnode->next=head;
newnode->prev=0;
head=newnode;
return head;
}



// search an element in linked list
void searchelement(int item){
struct node*temp;
temp=head;
int pos=1;
while(temp!=0)
    {
        if(temp->data==item)
            {printf("position is:%d",pos);
            return;
            }
            pos++;
            temp=temp->next;

    }
}


// feletion of node at beginning
struct node*deleteatbeg()
{struct node*temp;
temp=head;
head=head->next;
free(temp);
return head;
}

// deletion at end

struct node*deleteatend(){
    struct node*temp,*prevnode;
    temp=head;
    while(temp->next!=0)
    {
        prevnode=temp;
        temp=temp->next;
    }
   prevnode->next=0;
   free(temp) ;
   return head;
}


int main(){
  
int n,item;
printf("enter no of nodes");
scanf("%d",&n);
createlist(n);
printf("list is:\n");
displaylist();
printf("after insertion");
head=insertatbeg();
displaylist();

printf("enter element to be searched");
scanf("%d",&item);
searchelement(item);

head=deleteatbeg();
displaylist();
head=deleteatend();
displaylist();
return 0;
}

