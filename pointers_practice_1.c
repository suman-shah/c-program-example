// write a program to print the address of a variable. use this address to get the value of this variable
#include<stdio.h>

int main(){
     int a;
     printf("the address of a is%u\n",&a);
     scanf("%d",&a);
     printf("%d\n",a);
    return 0;
}