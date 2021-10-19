#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct queue{
    int front ,rear, size;
    unsigned capacity;
    int* arr;
};

struct queue * createQueue(unsigned capacity){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear= q->capacity - 1;
    q->arr = (int *)malloc(q->capacity*sizeof(int));
    return q; 
}

int isFull(struct queue* q){
    return(q->size == q->capacity);
}

int isEmpty(struct queue* q){
    return (q->size == 0);
}

void enqueue(struct queue* q,int data){
    if(isFull(q)) return;
    q->rear = (q->rear+1)%q->capacity; //for circular queue
    q->arr[q->rear] = data;
    q->size = q->size+1;
}

int dequeue(struct queue* q){
    if(isEmpty(q))
        return INT_MIN;
    int item = q->arr[q->front];
    q->front = (q->front+1)%q->capacity;
    q->size--;
    return item;
}

int front(struct queue* q){
    if(isEmpty(q)) return INT_MIN;
    return q->arr[q->front];
}

int rear(struct queue* q){
    if(isEmpty(q)) return INT_MIN;
    return q->arr[q->rear];
}

int main(){
    printf("Enter capacity of queue: ");
    int val;
    scanf("%d",&val);
    struct queue* new=createQueue(val);
    for(int i=0;i<val;i++){
        printf("\nEnter value to be enqueued: ");
        int data;
        scanf("%d",&data);
        enqueue(new,data);
    }
    if(isFull(new)) printf("\nQueue is full now");
    printf("\n Dequeuing %d",dequeue(new));
    printf("\n Dequeuing %d",dequeue(new));
    printf("\n Dequeuing %d",dequeue(new));
    printf("\n Dequeuing %d",dequeue(new));
    if(isEmpty(new)) printf("\nQueue is empty now");

}