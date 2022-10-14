#include<stdio.h>

int main()
{
    int num1,num2,sum = 0;

    printf("Enter the 2 integers of your choice : \n");

    scanf("%d%d",&num1,&num2);

    sum = num1+num2;

    printf("The sum of the 2 integers is : %d",sum);

    return 0;
}