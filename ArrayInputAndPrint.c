#include<stdio.h>
int main(){
  //Array Declaration having size 100
  int a[100];
  //SIZE INPUT
  int n;
  printf("ENTER NUMBER OF ELEMENTS YOU WANT TO INPUT :\n");
  scanf("%d",&n);
  //ARRAY INPUT USING FOR LOOP
  printf("ENTER ARRAY :\n");
  for(int i=0;i<n;i++){
    //Take input at 'ith' index of array
    scanf("%d",&a[i]);
  }
  //PRINT ARRAY
  printf("OUR ARRAY IS :\n");
  for(int i=0;i<n;i++){
    //Print element at 'ith' index of array
    printf("%d\n",a[i]);
  }
  return 0;
}
