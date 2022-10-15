#include<stdio.h>
#include<math.h>

struct poly
{
    float coeff;
    int exp;
};
struct poly a[50];

int pCalc(struct poly poly[], int n, int x)
{
    int i, sum = 0;
    for (i = 0; i <= n; i++)
    {
        sum += poly[i].coeff * pow(x, poly[i].exp);
    }
    return sum;
}
int main()
{
    int i=0,deg1,t,x,k=0,sum=0;
    printf("Enter the highest degree of polynomial : ");
    scanf("%d",&deg1);
    printf("\nEnter number of terms : ");
    scanf("%d",&t);
    for(i=t;i>0;i--)
    {
        printf("\n\nEnter the power of x : ");
        scanf("%d",&a[k].exp);
        printf("Enter the coefficient of x^%d : ",a[k].exp);
        scanf("%f",&a[k].coeff);
        k++;
    }
    printf("\n\nEnter the VALUE of x : ");
    scanf("%d",&x);
    printf("\nExpression = ");
    k=0;
    for(i=deg1;i>=0;i--)
    {
        printf("+ %.1fx^%d",a[k].coeff,a[k].exp);
        k++;
    }    
    sum = pCalc(a,deg1,x);
    printf("\n\nThe value after evavluation  = %d",sum);
    return 0;
}