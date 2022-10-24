#include <stdio.h>
#include<stdbool.h>

bool isprime(int n)
{
    int c=0,i;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        c++;
        if(c==0)
        return true;
        else
        return false;
    }
}

bool ispalin(int n)
{
    int temp,orig,sum=0,r;
    orig=n;
    while(n>0)
    {
        r=n%10;
        sum=sum+10*r;
        n=n/10;
    }
    if(sum==orig)
    return true;
    else
    return false;
}

void main()
{
    int num;
    bool pa,pr;
    printf("Enter the number \n");
    scanf("%d",&num);
    pr=isprime(num);
    pa=ispalin(num);
    if(pa==true&&pr==true)
    printf("the number %d is prime-palindrome",num);
    else if(pa==true&&pr==false)
    printf("the number %d is palindrome but not prime",num);
    else if(pa==false&&pr==true)
    printf("the number %d is not palindrome but it is prime",num);
    else
    printf("the number %d is not prime-palindrome",num);
}
