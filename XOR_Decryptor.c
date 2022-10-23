#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argv, char *argc[])
{
    // The file out contains the decrypted output
    // The file en contains the seed using which we will decrypt the input
    // The file ans contains the decrypted output
    FILE *out, *en, *ans;
    int x, y;
    out = fopen(argc[1], "r");
    en = fopen(argc[2], "r");
    ans = fopen(argc[3], "w");
    int *B = malloc(sizeof(int) * 100000000);
    int j = 0;
    for (int i = 0; i < 127; i++)
        fscanf(out, "%1d", &B[i]);
    while (fscanf(en, "%1d", &y) != EOF)
    {
        int sum = 0, temp[8] = {0};
        for (int i = j; i < j + 8; i++)
        {
            if (i % 8 >= 1)
                fscanf(en, "%1d", &y);
            B[i + 127] = B[i] ^ B[i + 126];
            x = B[i] ^ B[i + 126];
            temp[i - j] = (x ^ y) * pow(2, 7 + j - i);
            sum += temp[i - j];
        }
        j += 8;
        unsigned char c = sum;
        fprintf(ans, "%c", c);
    }

    printf("\n");

    fclose(ans);
    fclose(en);
    fclose(out);
}
