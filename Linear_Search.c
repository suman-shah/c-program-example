//  Linear search is a search that finds an element in the list by searching the element sequentially until the element is found in the list.


//This program is for an element occuring once in a list.

#include <stdio.h>
void main()
{
    int m, i, n, count = 0;

    //Entering number of elements in the array
    printf("Enter the no. of elements: ");
    scanf("%d", &m);
    int a[m];

    //Entering the elements
    printf("Enter the elements: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }

    //Linear search begins
    printf("Enter the number you want to search for: ");
    scanf("%d", &n);
    for (i = 0; i < m; i++)
    {
        if (a[i] == n)
        {
            printf("Your number %d is at location %d", n, i);
            count++;
            break;
        }
    }
    if (count == 0)
    {
        printf("Your Number %d is not found", n);
    }
}