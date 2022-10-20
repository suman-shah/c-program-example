#include<stdio.h>
#include<stdlib.h>
struct Array{
	int capacity; 
	int lastIndex;
	int *ptr;
};

struct Array* createArray(int cap){
	struct Array *arr;
	arr=(struct Array*)malloc(sizeof(struct Array));
	arr->capacity=cap;
	arr->lastIndex=-1;
	arr->ptr=(int*)malloc(sizeof(int)*cap);
	return arr;
}

void doubleArray(struct Array *arr)
{
  int *temp,i;
  temp=(int*)malloc(sizeof(int)*(arr->capacity)*2);
  for(i=0;i<=arr->lastIndex;i++)
      temp[i]=arr->ptr[i];
	 free(arr->ptr);
	 arr->ptr=temp;
	 arr->capacity*=2;
}

void halfArray(struct Array *arr)
{
	realloc(arr->ptr,2);
}

void append(struct Array *arr,int data)
{
	if(arr->capacity-1==arr->lastIndex)
	     doubleArray(arr);                              //printf("overflow");
	 arr->lastIndex+=1;
    arr->ptr[arr->lastIndex]=data;
	
}
void setValue(struct Array *arr,int index,int data)
{
	int i;
	   if(index<0 || index > arr->lastIndex+1)
	        printf("invalid index");
	   else if(arr->capacity-1==arr->lastIndex)
	   	    doubleArray(arr);                           //printf("overflow");
	   	    for(i=arr->lastIndex;i>=index;i--)
	   	        arr->ptr[i+1]=arr->ptr[i];
	   	    arr->ptr[index]=data;
	   	    arr->lastIndex+=1;	     
}

void editValue(struct Array *arr,int index,int data)
{
	if(index<0||index>arr->lastIndex)
	   printf("invalid index");
	else
	   arr->ptr[index]=data;
}

int get(struct Array *arr,int index)
{
	if(index<0 || index>arr->lastIndex)
	   printf("invalid index");
	else
	   return arr->ptr[index];
}

int count(struct Array *arr)
{
	return arr->lastIndex+1;
}

void deleteValue(struct Array *arr,int index)
{
	int i;
	if(arr->lastIndex==-1)
	   printf("underflow");
	else if(index<0 || index> arr->lastIndex)
	   printf("invalid index");
	else{
		for(i=index;i<arr->lastIndex;i++)
			arr->ptr[i]=arr->ptr[i+1];
		arr->lastIndex-=1;
	}
}

int menu()
{
	int ch;
	printf("\n 1. insert an item ");
	printf("\n 2. append an item ");
	printf("\n 3. print Array value");
	printf("\n 4. delete value");
	printf("\n 5. count total items present ");
	printf("\n 6. edit values");
	printf("\n 7. array capacity ");
	printf("\n 8. exit");
	printf("\n\n Enter your choice: ");
	scanf("%d",&ch);
	return ch;
}

void main(){
	int index,data,i;
	struct Array *arr;
	arr=createArray(10);
	while(1)
	{
		switch(menu())
		{
	    case 1:
	    	printf("enter index and data to insert ");
	    	scanf("%d%d",&index,&data);
	    	setValue(arr,index,data);
	    	break;
	    case 2:
	    	printf("enter data to append ");
	    	scanf("%d",&data);
	    	append(arr,data);
	    	break;
	    case 3:
		printf("\n ");
	    	for(i=0;i<count(arr);i++)
	    	printf(" %d",get(arr,i));
	    	break;
	    case 4:
	    	printf("enter index to delete value ");
	    	scanf("%d",&index);
	    	deleteValue(arr,index);
	    	break;	
	    case 5:
	    	printf("Total Values = %d",count(arr));
	    	break;
	    case 6:
	    	printf("enter index and new data to edit ");
	    	scanf("%d%d",&index,&data);
	    	editValue(arr,index,data);
	    	break;
	    case 7:
	    	 printf("current capacity of dynamic array is %d",arr->capacity);
	    	 break;
	    case 8:
	    	printf("Thankyou %c % c %c, press any key to exit....",2,2,2);
	    	getch();
	    	exit(0);
	    default:
	    	printf("Invalid Choice");
		}
		getch();
		system("cls");
	}
}
