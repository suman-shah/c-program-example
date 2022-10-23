#include <stdio.h>

int recursive_f(int b, long long int A[b][b])
{
    long int determinant = 0;
    int L = 1, r, c;
    long long int X[b - 1][b - 1];
    long int z = 1000000007;
    if (b == 1)
    {
        return A[0][0];
    }
    else
    {
        for (int i = 0; i < b; i++)
        {
            r = 0, c = 0;
            for (int j = 1; j < b; j++)
            {
                for (int k = 0; k < b; k++)
                {
                    if (k != i)
                    {
                        X[r][c] = A[j][k];
                        if (c <= b - 3)
                        {
                            c = c + 1;
                        }
                        else
                        {
                            r = r + 1;
                            c = 0;
                        }
                    }
                }
            }
            determinant += ((L % z) * (A[0][i] % z) * (recursive_f(b - 1, X) % z)) % z;
            determinant = determinant % z;
            L = (-1) * L;
        }
    }
    return determinant;
}

int main()
{
    int c;
    scanf("%d", &c);
    long long int A[c][c];
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%lld", &A[i][j]);
        }
    }
    long int z = 1000000007;
    long long int r = recursive_f(c, A);
    if (r >= 0)
    {
        printf("%lld\n", r);
    }
    else
    {
        printf("%lld\n", r + z);
    }

    return 0;
}
