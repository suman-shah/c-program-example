#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void enqueue();
void dequeue();
void display();

int queue[MAX];
int rear = - 1, front = - 1;

int main(){
    int choice;

    printf("1.Insert element to queue \n");
    printf("2.Delete element from queue \n");
    printf("3.Display all elements of Circular queue \n");
    printf("4.Quit \n");

    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid choice \n");
        }
    }
}
void enqueue()
{
    int item;
    if((rear == MAX - 1 && front == 0) || (front == rear+1))
    {
    printf("Queue Overflow \n");
    }
    else
    {
        if(front == - 1) front = 0;
        printf("\nInsert the element in queue : ");
        scanf("%d", &item);
        
        if(rear == MAX -1) rear = 0;
        else rear = rear + 1;
        
        queue[rear] = item;
    }
}
void dequeue()
{
    if(front == - 1)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("\nElement deleted from queue is : %d\n", queue[front]);

        if(front == rear){
            //queue[front] = NULL;
            front = -1;
            rear = -1;

        }
        else if (front == MAX -1)
        {
            //queue[front] = NULL;
            front = 0;
        }
        else
        {
            //queue[front] = NULL;
            front = front + 1;
        }
    }
}
void display()
{
    int i;
    if(front == - 1)
    {
        printf("Queue is empty \n");
    }
    else if(front > rear)
    {

        printf("\nQueue is : \n");
        for(i = front; i <= MAX-1; i++)
        {
            printf("%d ", queue[i]);
            printf("\n");
        }
        for(i = 0; i <= rear; i++)
        {
            printf("%d ", queue[i]);
            printf("\n");
        }
    }
    else{
        printf("\nQueue is : \n\t");
        for(i = front; i <= MAX-1; i++){
            printf("%d ", queue[i]);
            printf("\n");
        }
    }

}
