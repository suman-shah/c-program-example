#include<stdio.h>
#include<math.h>

struct poly
{
    float coeff;
    int exp;
};
struct poly a[50],b[50],c[50];
int main()
{
    int i;
    int deg1,deg2;      
    int k=0,l=0,m=0;
    printf("Enter the highest degree of poly1:");
    scanf("%d",&deg1);
    for(i=0;i<=deg1;i++)
    {
        printf("\nEnter the coeff of x^%d :",i);
        scanf("%f",&a[i].coeff);
        
        a[k++].exp = i;
    }
    printf("\nEnter the highest degree of poly2:");
    scanf("%d",&deg2);
    
    for(i=0;i<=deg2;i++)
    { 
        printf("\nEnter the coeff of x^%d :",i);
        scanf("%f",&b[i].coeff);
        
        b[l++].exp = i;
    }

    printf("\nExpression 1 = %.1f",a[0].coeff);
    for(i=1;i<=deg1;i++)
    {
        printf("+ %.1fx^%d",a[i].coeff,a[i].exp);
    }    
    
    printf("\nExpression 2 = %.1f",b[0].coeff);
    for(i=1;i<=deg2;i++)
        {
        printf("+ %.1fx^%d",b[i].coeff,b[i].exp);
        }

    if(deg1>deg2)
        {
            for(i=0;i<=deg2;i++)
            {
                c[m].coeff = a[i].coeff + b[i].coeff;
                c[m].exp = a[i].exp;
                m++;
            }
            
            for(i=deg2+1;i<=deg1;i++)
            {
                c[m].coeff = a[i].coeff;
                c[m].exp = a[i].exp;
                m++;
            }
        }
    else
    {
        for(i=0;i<=deg1;i++)
        {
        c[m].coeff = a[i].coeff + b[i].coeff;
        c[m].exp = a[i].exp;
        m++;
        }
        
        for(i=deg1+1;i<=deg2;i++)
        {
        c[m].coeff = b[i].coeff;
        c[m].exp = b[i].exp;
        m++;
        }
    }
    
    printf("\nExpression after additon  = %.1f",c[0].coeff);
    for(i=1;i<m;i++)
    {
        printf("+ %.1fx^%d",c[i].coeff,c[i].exp);
    }	 
    
    return 0;

}

