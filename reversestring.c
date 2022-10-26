#include<stdio.h>
#include<string.h>

// Reversing a given string with C Language
 
int main() 
{
    char string[100], temp;
    
    printf("Enter any string: ");
    gets(string);

    int beg = 0, end = strlen(string) - 1;
    while(beg < end)
    {
        temp = string[beg];
        string[beg] = string[end];
        string[end] = temp;

        beg++;
        end--;
    }

    printf("The reversed string is: %s", string);
    return 0;
}
