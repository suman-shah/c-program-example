#include <stdio.h>
void main()
{
    int a[100], b[100], com[100];
    int n1, n2;

    printf("Enter the no of elements in A:\n");
    scanf("%d", &n1);
    printf("Enter the elements in A:\n");
    for (int i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    printf("Enter the no of elements in B:\n");
    scanf("%d", &n2);
    printf("Enter the elements in B:\n");
    for (int i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    int i,j,m,k = 0,flag=0;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            flag=0;
            if (a[i] == b[j])
            {
                for(m=0;m<n1;m++)
                {
                    if(com[m]==a[i])
                    {
                        flag=1;
                    }
                }
                if (flag==0)
                {
                    com[k] = a[i];
                    k++;
                }
            }
        }
    }

    printf("Intersection of two sets is : ");
    for (int i = 0; i < k; i++)
        printf("%d ", com[i]);

    printf("\n");
}