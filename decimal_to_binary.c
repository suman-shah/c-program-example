// program to convert a decimal no. to its binary equivalent

//hacktoberfest2021
#include<stdio.h>
#include<conio.h>

void main()
{

    int n,rem,arr[20],i=0;

    printf("Enter a decimal number");
    scanf("%d",&n);

    while(n>0){

        rem=n%2;
        n=n/2;
        arr[i]=rem;

        i++;


    }
    for(int j=i-1;j>=0;j--)
    {
        printf("%d\t",arr[j]);
    }
    getch();

}
