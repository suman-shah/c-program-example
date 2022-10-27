// this program will find LSB, MSB and nth bit

#include<stdio.h>

// since one byte has 8 bits 
#define BITS 8 * sizeof(int)

int findLSB(int num);
int findMSB(int num);
int findNthBit(int num, int pos);
void showBit(int num);


int main(){
    int num = 0, pos = 0;
    printf("Enter number: ");
    scanf("%d",&num);
    printf("Enter nth pos to find bit: ");
    scanf(" %d",&pos);
    
    // showing output
    showBit(num);
    printf("lsb is %d",findLSB(num));
    printf("\nmsb is %d",findMSB(num));
    printf("\n4th bit is %d",findNthBit(num,2));
    printf("\n");
    return 0;
}

// this function will find LSB of number
int findLSB(int num){
    return num & 1;
}

// this function will find MSB of number
int findMSB(int num){
    int temp = num >> BITS - 1;
    return temp & 1;
}

// this function will return nth bit 
int findNthBit(int num, int pos){
    int temp = num >> pos;
    return temp & 1;
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