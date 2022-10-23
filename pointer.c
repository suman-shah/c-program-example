//program to find power of one number to another and factorial value of a number using pointer
void pow_fact(float x,int y,int num,float *power,int *fact)
{
  float res=1;
  int i;
  for(i=1;i<=y;i++)
    res=res*x;
  *power=res;
  res=1;
  for(i=1;i<=num;i++)
    res=res*i;
  *fact=res;
}
void main()
{
  float a;
  int b,num,fac;
  float pow;
  printf("enter a and b for calculating a raised to b: ");
  scanf("%f%d",&a,&b);
  printf("Enter number whose factorial is to be calculated:");
  scanf("%d",&num);
  pow_fact(a,b,num,&pow,&fac);
  printf("power=%f factorial=%d",pow,fac);
}
  
