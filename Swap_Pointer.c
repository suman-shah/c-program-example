#include<stdio.h>
int main()
{
  int x,y,t;
  int * a;
  int * b;
  printf("Enter first number\n");
  scanf("%d",&x);
  printf("Enter second number\n");
  scanf("%d",&y);
  a=&x;
  b=&y;
  t=*a;
  *a=*b;
  *b=t;
  printf("%d",*a);
  printf("%d",*b);
  return 0;
}
