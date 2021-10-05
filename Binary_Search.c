#include<stdio.h>
int binary_search(int arr[],int n,int x){
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==x)    
            return mid;
        else if(arr[mid]<x)    
            start = mid + 1;
        else    
            end = mid - 1;
    }
    return -1;
}
int main()
{        
       int n, arr[n],i;
       scanf("%d",&n);
       for (i=0;i<n;i++){
           scanf("%d",&arr[i]);
       }
       int x;      
       printf("Enter element you want to search: ");
       scanf("%d",&x);
       
       int index = binary_search(arr,n,x);
       
       if(index!=-1){
               printf("%d%s%d",x," is present at index ",index);
       }
       else{
               printf("%d%s",x," is not present in the given array\n");
       }
       return 0;
}