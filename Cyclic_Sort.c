// Cyclic Sort:
// ------------

// Cyclic sort is a sorting technique which performs sorting in O(n) i.e., in liner time complexity.
// Thus making it one of the most efficient sorting alogrithm and one which you're going to use during
// interview exams.

// Q) Where can we apply cyclic sort?
// Sol) We can apply this sorting technique only when the given array of elements is range within 0 to n
//      elements (or) 1 to n-1 elements.

// Q) What is cyclic sort ?
// Sol) Since the array of elements are range from 0 to n elements ( it can 1 to n-1 elements too ),
//      the resultant/sorted array will satisfy the condition:

//                                 array[ element-1 ] = element

//      So, by using the same principal we can sort the whole array in Linear Time complexity and Constant
//      Space complexity.

// Say what if the condition for an element in "Unsorted Array" fails ? We just swap the element into its
// rightful place using the same principal.

#include <stdio.h>

// Cyclic Sort logic
void cyclic_sort(int arr[])
{
    int i = 0, ele, temp;
    while (arr[i] != '\0')
    {
        ele = arr[i];

        // if the condition is satisfied then
        // this element is sorted in its place
        // So we check for next element
        if (arr[ele - 1] == ele)
        {
            ++i;
            continue;
        }

        // else we will swap 'ele' into
        // its place
        temp = arr[ele - 1];
        arr[ele - 1] = arr[i];
        arr[i] = temp;
    }
    return;
}

// Display function prototyping
void display_arr(int arr[]);

// Driver Program
int main(void)
{
    int arr[6] = {1, 5, 3, 4, 2};

    printf("\nUnsorted Array: ");
    display_arr(arr);

    printf("\nAfter applying Cyclic Sort: ");
    cyclic_sort(arr);
    display_arr(arr);

    printf("\n");

    return 0;
}

// Display function definition
// Inspired by Arrays.toString() method in Java
void display_arr(int arr[])
{
    int i;

    printf("[ ");

    for (i = 0; arr[i + 1] != '\0'; ++i)
    {
        printf("%d, ", arr[i]);
    }

    printf("%d ]\n", arr[i]);

    return;
}

// Output :
// -------
//
// Unsorted Array : [ 1, 5, 3, 4, 2 ]
//
// After applying Cyclic Sort : [ 1, 2, 3, 4, 5 ]