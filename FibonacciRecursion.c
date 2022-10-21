#include<stdio.h>
void fibo(int a,int b,int n);
void fibo(int a,int b,int n){
  if(n>0){
    int c=a+b;
    printf("%d\n",c);
    fibo(b,c,n-1);
  }
}
int main(){
  int n,a=-1,b=1;
  printf("ENTER NUMBER OF TERMS\n");
  scanf("%d",&n);
  fibo(a,b,n);
  return 0;
}
