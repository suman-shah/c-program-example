// this program will change nth bit in number

#include<stdio.h>

// since one byte has 8 bits 
#define BITS 8 * sizeof(int)

void showBit(int num);
int setNthBit(int num, int pos, int bit);


int main(){
    // getting from user
    int num, pos, bit;
    printf("\nEnter number: ");
    scanf(" %d",&num);
    printf("\nEnter nth pos: ");
    scanf(" %d",&pos);
    printf("\nEnter bit to be changed: ");
    scanf(" %d",&bit);

    // output
    showBit(num);
    num = setNthBit(num, pos, bit);
    showBit(num);
    return 0;
}

// change nth bit of number
int setNthBit(int num, int pos, int bit){
    // getting bits before nth pos
    int p1 = num >> pos + 1;
    p1 <<= pos + 1;

    // getting bits after nth pos
    int temp = num - p1;
    int temp2 = temp >> pos;
    temp2 <<= pos;
    int p2 = temp - temp2;

    // setting bit's position
    bit <<= pos;
    // adding all three parts to get new number
    return p1+bit+p2;
}

// this function will show bits
void showBit(int num){
    int bit = 0;
    printf("\n%d => ",num);
    for(int i = BITS - 1; i >= 0; i--){
        bit = num >> i;
        bit = bit & 1;
        printf("%d",bit);
    }
    printf("\n");
}