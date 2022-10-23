#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    // Array B contains the coefficients of the n 'n degree' equations long with constant term.
    // Array A is used to implement the Gaussian Elimination method to solve linear equations.
    // Array Y contains final generated output ans
    double B[n + 1][n];
    double A[n][n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &B[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = B[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        A[i][n] = B[n][i];
    }

    for (int b = 0; b < n - 1; b++)
    {
        for (int i = b + 1; i < n; i++)
        {
            double z = (A[i][b] / A[b][b]);
            for (int j = 0; j < n + 1; j++)
            {
                A[i][j] = A[i][j] - (z * A[b][j]);
            }
        }
    }
    double Y[n];
    Y[n - 1] = (A[n - 1][n] / A[n - 1][n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += A[i][j] * Y[j];
        }
        Y[i] = (A[i][n] - sum) / A[i][i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%.7lf\n", Y[i]);
    }
}
