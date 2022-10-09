#include <stdio.h>
int main() {
    int i, j, s, n, c;
    printf("Enter the number of rows");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        for(s=1; s<n-i; s++)
            printf(" ");
        for(j=0; j<=i; j++)
        {
            if(i==0 || j==0)
                c = 1;
            else
                c = (c*(i-j+1))/j;
            printf("%d ", c);
        }
        printf("\n");
    }
    return 0;
}
