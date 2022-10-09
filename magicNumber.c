#include <stdio.h>
int main() 
{
    int m, n,s;
    printf("Enter Number:");
    scanf("%d",&m);
    n=m;
    while(n>9)
    {
        s=0;
        while(n>0)
        {
        int d=n%10;
        s=s+d;
        n=n/10;
        }
        n=s;
    }
    if(n==1)
    printf("%d is a Magic Number.",m);
    else
    printf("%d is not a Magic Number.",m);
}
