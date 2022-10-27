// this program to swap numbers using bitwise operators

#include<stdio.h>

int main(){
    int a = 1;
    int b = 3;

    a = a^b;
    b = a^b;
    a = a^b;
    printf("\na = %d\nb = %d\n",a,b);
}