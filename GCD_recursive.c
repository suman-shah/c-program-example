#include <stdio.h>

int gcd(int a, int b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(void)
{
    int a, b;
    printf("Enter two numbers : ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d", a, b, gcd(a, b));
    return 0;
}