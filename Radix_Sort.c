#include <stdio.h>
#include <stdlib.h>
#define range 10

int getmax(int a[],int n)
{
  int i;
  int mx = a[0];

  for( i = 1; i < n; i++)
    if( a[i] > mx )
      mx = a[i];
      
  return mx;
}

void countsort(int arr[],int n,int place)
{
  int output[n];
  int i, freq[range]={0};
  
  for( i = 0 ; i < n; i++)
    freq[ (arr[i]/place)%range ]++;

  for(i= 1; i < range; i++)
    freq[i] += freq[i-1];

  for( i = n-1; i >= 0; i--)
  {
    output[ freq[ (arr[i]/place)%range ] - 1 ] = arr[i];
    freq[ (arr[i]/place)%range ]--;
  }
  
  for( i = 0; i < n; i++)
    arr[i]=output[i];
    
	return ;
}

void radixsort(int arr[],int n,int maxx)
{
  int mul=1;
  
  while(maxx)
  {
    countsort( arr, n, mul);
    mul *= 10;
    maxx /= 10;
  }
  
	return ;
}

int main()
{
    int n,i;
    
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    
    int a[n];
    
    printf("\nEnter the values into the array : ");
    for( i = 0; i < n; ++i)
	    scanf("%d",&a[i]);
      
    radixsort(a,n,getmax(a,n));
    
    printf("\nThe Sorted Array :\n");
    for( i = 0; i < n; i++)
        printf("%d ",a[i]);
        
    return 0;
}
