// To find the largest element and the smallest element in the array
#include<stdio.h>
int main()
{
  int n;
  printf("Enter the number of elements you want to enter in this array\n");
  scanf("%d",&n);
  int arr[n],i;
  printf("Enter the %d elements in the array\n",n);
  for(i=0;i<=n-1;i++)
  {
    scanf("%d",&arr[i]);
  }
  int max= arr[n-1];
  int min=arr[0];
  for(i=1;i<=n-1;i++)
  {
    if(min>arr[i])
    {
      min=arr[i];
    }
  }
  for(i=0;i<=n-2;i++)
  {
    if(max<arr[i])
    {
      max=arr[i];
    }
  }
  printf("The largest and the smallest element in the array is %d and %d respectively",max,min);
  return 0;
}
