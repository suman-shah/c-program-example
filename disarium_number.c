//Program to check a number is Disarium or not
#include <stdio.h>
//CalculateLength() will count the digits present in a number
int calculateLength(int n)
{
int length = 0;
while(n != 0)
{
length = length + 1;
n = n/10;
}
return length;
}
int main()
{
int num , sum = 0, rem = 0, n;
printf( "\n Enter any positive number : ");
scanf("%d",&num);
int len = calculateLength(num);
//Makes a copy of the original number num
n = num;
//Calculates the sum of digits powered with their respective position
while(num > 0)
{
rem = num%10;
sum = sum + (int)pow(rem,len);
num = num/10;
len--;
}
//Checks whether the sum is equal to the number itself
if(sum == n)
printf("\n %d is a disarium number", n);
else
printf( "\n %d is not a disarium number", n);
return 0;
}
