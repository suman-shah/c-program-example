#include <stdio.h>
#include <string.h>

void main()
{
    char str[100];
    int i, j, count = 0;
    printf("Enter the string: ");
    gets(str);
    for (i = 0; i < strlen(str); i++)
    {
        count = 1;
        for (j = i + 1; j < strlen(str); j++)
        {
            if (str[i] == str[j])
            {
                count++;
                str[j] = '0';
            }
        }

        if (str[i] != '0')
            printf("%c-%d ", str[i], count);
    }
    printf("\n");
}