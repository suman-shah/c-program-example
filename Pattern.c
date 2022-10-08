#include <stdio.h>
int main()
{
    int n,i,j;
    printf("Enter number of lines ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<2*(n-i);j++)
        printf(" ");
        for(j=0;j<2*i-1;j++)
        printf("* ");
        printf("\n");
    }
}
