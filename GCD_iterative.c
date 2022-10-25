#include <stdio.h>

int gcd(int a, int b)
{
    int min = (a > b) ? b : a;
    while (min > 0)
    {
        if (a % min == 0 && b % min == 0)
            break;
        --min;
    }
    return min;
}

int main(void)
{
    int a, b;
    printf("Enter two numbers : ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d", a, b, gcd(a, b));
    return 0;
}