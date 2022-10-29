#include<stdio.h>
int main() {
 int i,j,n;
 float a[10][10], sum=0.0;

 printf("Enter order of matrix:\n");
 scanf("%d", &n);
 printf("Enter matrix elements:\n");
 for(i=0;i< n;i++) {
  for(j=0;j< n;j++) {
   scanf("%f", &a[i][j]);
  } }

 for(i=0;i< n;i++) {
  for(j=0;j< n;j++) {
   if(i==j || i+j==n-1) {
    sum = sum + a[i][j];
   } } }
 printf("Sum = %f\n", sum);

 return 0;
}
