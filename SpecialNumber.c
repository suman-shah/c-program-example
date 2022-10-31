#include <stdio.h>
int fact(int x){
  if(x == 0 || x == 1){
    return 1;
    
  }
  return x*(fact(x-1));
}
int main(){
  int x, num, digit, sum = 0;
  printf("Enter the number: ");
  scanf("%d", &x);
  num = x;
  while(num > 0){
    digit = num%10;
    sum += fact(digit);
    num = num/10;
  }
  if(sum == x){
    printf("%d is a Special number.", x);
  }else{
    printf("%d is not a Special number.", x);
  }
  
  return 0;
}
