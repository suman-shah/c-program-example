#include <stdio.h>

// function for Binary Addition
int binAddition(int a, int b)
{
    int c; //carry
    while (b != 0) {
        //find carry and shift it left
        c = (a & b) << 1;
        //find the sum
        a = a ^ b;
        b = c;
    }
    return a;
}

// function for Binary Subtraction
int binSubtracton(int a, int b)
{
    int carry;
    //get 2's compliment of b and add in a
    b = binAddition(~b, 1);

    while (b != 0) {
        //find carry and shift it left
        carry = (a & b) << 1;
        //find the sum
        a = a ^ b;
        b = carry;
    }
    return a;
}

int main()
{
    int number1, number2, binAdd, binSub;

    printf("Input first integer value: ");
    scanf("%d", &number1);

    printf("Input second integer value: ");
    scanf("%d", &number2);

    binAdd = binAddition(number1, number2);
    binSub = binSubtracton(number1, number2);

    printf("Binary Addition: %d\n", binAdd);
    printf("Binary Subtraction: %d\n", binSub);

    return 0;
}
