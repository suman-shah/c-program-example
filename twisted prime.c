#include <stdio.h>  
int main()  
{  
  int n, reverse,sum=0 , flag;  
  printf("Enter the prime number?");  
  scanf("%d",&n);  
while(n!=0)  
    {  
        reverse = n%10;  
        sum = sum*10 + reverse;  
        n= n/10;  
    }  
       
        printf("\n");  
    flag = 0;  
    for (int j = 2; j <= sum / 2; j++)  
    {  
        if ((sum % j) == 0)  
        {  
            flag = 1;  
            break;  
        }  
    }  
    if (flag == 0)  
            printf("Twisted Prime");  
     else  
            printf("Not Twisted Prime");  
  
}  
