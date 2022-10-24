#include <stdio.h>

// @returns base * base * base ... (exponent times) modulo modulus
// (base ^ exponent)%modulus
long long recursive_exponentiation(long long base, long long exponent, long long modulus){
    // a number power 0 is 1
    if (exponent == 0){
        return 1;
    }

    long long result = recursive_exponentiation(base, exponent / 2, modulus);

    if (exponent % 2){ // if the exponent is not divisible by 2
        result = (result * result * base) % modulus;
    } else {
        result = (result * result) % modulus;
    }

    return result;
}

// @returns base * base * base ... (exponent times) modulo modulus
// (base ^ exponent)%modulus
long long iterative_exponentiation(long long base, long long exponent, long long modulus){
    long long result = 1;

    while (exponent > 0){
        if (exponent & 1){ // if exponent not divisible by 2
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }

    return result;
}

int main(){
    printf("%lld\n", recursive_exponentiation(2, 6, __INT_MAX__));
    printf("%lld\n", recursive_exponentiation(5, 4, __INT_MAX__));
}