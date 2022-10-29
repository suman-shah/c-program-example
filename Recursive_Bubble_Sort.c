#include <stdio.h>

void swap ( int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
	return ; 
}

void bubble_sort_recursion (int arr[], int r, int n)
{
  // Base case
	if ( r == n )
		return ;
  
	for ( int i = 0; i < n-r-1; ++i)
		if( arr[i] > arr[1+i] )
			swap( &arr[i], &arr[i+1]);
  
	return bubble_sort_recursion (arr, r+1, n);
}

int main()
{
	int n;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
  
	int arr[n];
	puts("\nEnter the element : ");
	for(int i = 0; i < n; ++i)
		scanf("%d",&arr[i]);
  
	bubble_sort_recursion( arr, 0, n );
  
	printf("The sorted elements are as follows : \n");
	for(int i = 0; i < n; ++i)
		printf("%d ",arr[i]);
  
	return 0;
}
