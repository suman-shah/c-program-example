#include<stdio.h>
#include <math.h>
 
int main() 
{
   float PAmount, ROI, Time_Period, CIFuture, CI;
 
   printf("\nPlease enter the Principal Amount : \n");
   scanf("%f", &PAmount);
 
   printf("Please Enter Rate Of Interest : \n");
   scanf("%f", &ROI);
 
   printf("Please Enter the Time Period in Years : \n");
   scanf("%f", &Time_Period);
 
   CIFuture = PAmount * (pow(( 1 + ROI/100), Time_Period));
   CI = CIFuture - PAmount;
   
   printf("\nFuture Compound Interest for Principal Amount %.2f is = %.2f", PAmount, CIFuture);
   printf("\nCompound Interest for Principal Amount %.2f is = %.2f", PAmount, CI);
 
   return 0;
}
