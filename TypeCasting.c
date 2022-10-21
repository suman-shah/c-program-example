#include<stdio.h>
int main(){
  //IMPLICIT TYPE CASTING
  char c= 'A';
  int i = c;
  //i stores ASCII value of character 'A' which is 65
  printf("%d\n",i);
  //EXPLICIT TYPE CASTING
  c=(char)(i+2); //65+2=67
  //c='C' whose ASCII value is 67
  printf("%c\n",c);
  return 0;
}
