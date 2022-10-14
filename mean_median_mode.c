#include<stdio.h>
void main()
{
    int a[50],n,i,tmp,j,temp;
    int z,count, mode,mcount;
    int tally[n];
    float tot=0 , mean , median = 0, mid =0;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the element : ");
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++)
    {
        tot = tot+a[i];
    }
    mean = tot / n ;
    printf("The mean value is: %.1f\n",mean);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }

    if(n%2 == 0)
    {
        temp=(n/2)-1;
        for(i=0;i<n;i++)
        {
            if(temp==i || (temp+1)==i)
            {
                mid=mid+a[i];
            }
        }
        mid=mid/2;
        printf("Median value is: %.1f",mid);
    }
    else 
    {
        temp=(n/2);
        for(i=0;i<n;i++)
        {
            if(temp==i)
            {
                int mid=a[i];
                printf("Median value: %d",mid);
            }
        }
    }
    for (i = 0; i < n; ++i) {
        count = 0;
        for (j = 0; j < n; ++j) 
        {
            if (a[j] == a[i])
            ++count;
        }
        
        if (count > mcount) 
        {
            mcount = count;
            mode = a[i];
        }
    }
    printf("\nMode value is : %d", mode);
}