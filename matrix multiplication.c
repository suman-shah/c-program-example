#include <stdio.h>
int main()
{
     int arr[2][3], total[2];
     for(int i = 0; i < 2; i++) {
         for(int j = 0; j < 3; j++){
              scanf("%d", &arr[i][j]);
         }  
     }
     for(int i = 0; i < 2; i++) {
         int sum = 0;
         for(int j = 0; j < 3; j++){
              sum += arr[i][j];
         }
         total[i] = sum;
     }
     for(int i = 0; i < 2; i++)
         printf("%d : %d\n", i + 1, total[i]);

     return 0;
}
