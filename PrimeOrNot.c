#include <stdio.h>
int main() {
  int n, i, flag = 1;
  printf("Enter a positive number: ");
  scanf("%d", &n);

  for (i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      flag++;
    }
  }

 /* if (n == 1) {
    printf("1 is neither prime nor composite.");
  } 
  */
 
    if (flag > 1)
      printf("%d is not a prime number.", n);
    if(flag == 0)
      printf("%d is not a prime number.", n);
  }

  return 0;
}
