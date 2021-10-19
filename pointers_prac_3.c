// write a program to change the value of a variable
//to 10 times ,use call by ref.
#include<stdio.h>
int ptr(int*);
int main(){
     int a=6;

printf("enter a number: \n");
scanf("%d",&a);
a=ptr(&a);
printf("the new value is %d",a);
    return 0;
}
int ptr(int *i)
{
  int p=*i*10;
return(p);                           // this concept is helpful also if we want to return more then one things 
    

}