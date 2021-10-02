//Finding the product of 2 matrices

#include <stdio.h>
void main()
{
    int m, n, i, j, p, q, k;

    //Entering matrix elements
    printf("Enter the no. of rows of first matrix:\n");
    scanf("%d", &m);
    printf("Enter the no. of columns of first matrix:\n");
    scanf("%d", &n);
    printf("Enter the no. of rows of second matrix:\n");
    scanf("%d", &p);
    printf("Enter the no. of columns of second matrix:\n");
    scanf("%d", &q);

    //Number of columns of first matrix equal to number of rows of second matrix implies that matrix multiplication is impossible
    if (n != p)
    {
        printf("Matrix multiplication is not possible");
    }
    else
    {
        int a[m][n], b[p][q], c[m][q];
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("Enter the a[%d][%d] element:\n", i, j);
                scanf("%d", &a[i][j]);
            }
        }
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < q; j++)
            {
                printf("Enter the b[%d][%d] element:\n", i, j);
                scanf("%d", &b[i][j]);
            }
        }

        //Displaying first matrix
        printf("The first matrix is:\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("\t%d", a[i][j]);
            }
            printf("\n");
        }

        //Displaying second matrix
        printf("The second matrix is:\n");
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < q; j++)
            {
                printf("\t%d", b[i][j]);
            }
            printf("\n");
        }
        
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                c[i][j] = 0;
                for (k = 0; k < n; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        //Displaying product matrix
        printf("The product matrix is:\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
            {
                printf("\t%d", c[i][j]);
            }
            printf("\n");
        }
    }
}