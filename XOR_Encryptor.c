#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argv, char *argc[])
{
    FILE *ptr, *out, *open;
    unsigned char ch;
    // ptr is the file to read the Seed to be encrypted
    // out is the file in which encrypted Seed is written
    // open stores the seed using which we will encrypt the input
    // Any person who wants to decrypt this will require the seed using which we have encrypted this file
    // In this repository a XOR_Decyptor.c is also being given to decrypt the generated input
    ptr = fopen(argc[1], "r");
    out = fopen(argc[3], "w");
    open = fopen(argc[2], "w");
    srand(time(0));
    int *C, *A;
    C = malloc(sizeof(int) * 100000000);
    A = malloc(sizeof(int) * 100000000);
    for (int i = 0; i < 127; i++)
    {
        C[i] = rand() % 2;
        fprintf(open, "%d", C[i]);
    }
    int j = 8;
    while (fscanf(ptr, "%c", &ch) != EOF)
    {
        int temp = ch;
        for (int i = j - 1; i >= j - 8; i--)
        {
            A[i] = temp % 2;
            temp /= 2;
        }
        j += 8;
    }
    for (int i = 127; i < 127 + j - 8; i++)
    {
        C[i] = C[i - 1] ^ C[i - 127];
        A[i - 127] = C[i - 1] ^ C[i - 127] ^ A[i - 127];
        fprintf(out, "%d", A[i - 127]);
    }

    fprintf(out, "\n");
    fclose(open);
    fclose(out);
    fclose(ptr);
}
