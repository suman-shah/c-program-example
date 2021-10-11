// write a program having a variable i , print the address of i .pass this variable
// to a function and print its address. Are these addresses same? why?
#include<stdio.h>
void addrs(int);
int main(){
     int i;
     printf("address is %u\n",&i);
    //  c=addrs(i);
    //  printf("the address for fn :%u");
    addrs(i);
    return 0;
}

void addrs(int a)
{
    printf("the aredd in fn is %u",&a);
}