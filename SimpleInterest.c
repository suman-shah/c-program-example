// 1. A program to calculate simple interest 
#include<stdio.h>
#include<string.h>

int main(){
     int p ,r,t,si;
     char name[20];
     printf("please enter your Name \n");
     gets(name);
     printf("Hello Mr.%s please enter Principle , rate of interet and time:\n",name);
     scanf("%d%d%d",&p,&r,&t);
    
    si=p+((p*r*t)/100);

    printf("the Simple interest on %d amount for %d years As per %d rate is: %d",p,r,t,si);
    fflush(stdin);


    return 0;
}