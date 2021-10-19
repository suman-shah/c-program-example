#include<stdio.h>

int main(){
     int a=5;
     int *j,**k;
     j=&a;
     k=&j;
     printf("%d\n",a);
     printf("%u\n",j);
     printf("%u\n",&j);
     printf("%d\n",*&j);
     printf("%d\n",k);

    return 0;
}