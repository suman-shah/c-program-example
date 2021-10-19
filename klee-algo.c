// Klee's Algorithm by Roshin N. October 2021. @GetPsyched6

/* 
    Klee’s rule finds a union of line segments lying horizontally.
    Example: If we have 3 line segments with co-ords (2,6) (5,8) and (9,12) 
    we can find the total length combined of these segments and the largest continuous segment
    by using Klee's Algorithm. Lines (2,6) and (5,8) are continuous hence it's length is 6.
    The total length of all three line segments is 9; From 2 to 8 >> [6] (continuous segment)
    and From 9 to 12 >> [3] we add these and get 6 + 3 = 9.
    You can verify by running the program. Enter 3 line segments, co-ords 2,6 | 5,8 | 9,12
    and the results should be 9 for union and 6 for continuous max length.
    You can test it out with different inputs too.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
void sort(int b[20][20], int n)
{
    int i, x[2][2];
    for (i = 1; i < 2 * n; i++)
    {
        int j;
        x[0][0] = b[i][0];
        x[0][1] = b[i][1];
        j = i - 1;
        while (j >= 0 && b[j][0] > x[0][0])
        {
            b[j + 1][0] = b[j][0];
            b[j + 1][1] = b[j][1];
            j = j - 1;
        }
        b[j + 1][0] = x[0][0];
        b[j + 1][1] = x[0][1];
    }
    int c[10][10];
    for (i = 0; i < 2 * n; i++)
    {
        if (b[i][0] == b[i + 1][0] && (char)b[i][1] == 'T')
        {
            c[i][0] = b[i][0];
            c[i][1] = b[i][1];
            b[i][0] = b[i + 1][0];
            b[i][1] = b[i + 1][1];
            b[i + 1][0] = c[i][0];
            b[i + 1][1] = c[i][1];
        }
    }
}
void main()
{
    int result = 0, max_length = 0, counter = 0, n = 0, x, y = 0, unions = 0;
    int a[20][20], b[20][20], c[20][20];
    printf("Enter number of line segments: \n");
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter segment %d's x and y co-ordinate (input as:x y): \n", i + 1);
        scanf(" %d", &a[i][0]);
        scanf(" %d", &a[i][1]);
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            x = i;
        else
            x = x + 1;
        b[x][0] = a[i][0];
        b[x][1] = 'F';
        b[++x][0] = a[i][1];
        b[x][1] = 'T';
    }
    sort(b, n);
    for (int i = 0; i < 2 * n; i++)
    {
        if (counter > 0)
        {
            result += b[i][0] - b[i - 1][0];
        }
        if ((char)b[i][1] == 'F')
        {
            counter++;
        }
        else if ((char)b[i][1] == 'T')
        {
            counter--;
        }
        if (counter == 0 && y == 0)
        {
            max_length = result;
            result = 0;
            y++;
        }
    }
    unions = max_length + result;
    printf("Length of union of segments of a line is %d\n", unions);
    printf("Maximum Length of continuous segments of line is %d", max_length);
}
