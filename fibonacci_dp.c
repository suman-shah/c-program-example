#include <stdio.h>

// 1D DP example

int main(){
    int n = 4;

    int fib_dp[n+1];
    fib_dp[0] = fib_dp[1] = 1;

    for (int i = 2; i<=n; i++){
        fib_dp[i] = fib_dp[i-1] + fib_dp[i-2];
    }

    printf("%d\n", fib_dp[n]);

    return 0;
}