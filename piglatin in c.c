#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void convert_to_pig_latin (char str[]);

int main()
{
    char str[100]; //defining to store input.

    printf("Enter a string :\n");
    scanf("%s",&str); //takes input.

    convert_to_pig_latin (str); //calls function.
    return 0;
}

void convert_to_pig_latin (char str[])
{
    char nstr[100]; //defining to store answer.
    int l1=strlen(str); //strlen(str) will return length of string "str".

    for ( int j=0;j<l1;j++ )
    {
        nstr[j]=str[j+1];
    }
    nstr[l1-1]=str[0];
    nstr[l1]='l';
    nstr[l1+1]='y';

    for( int k=0;k<=l1+1;k++ )
    {
        printf("%c",nstr[k]); //prints answer char by char.
    }
}
