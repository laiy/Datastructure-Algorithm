#include <cstdio>

int main() {
    int n, i, dp[31], j;
    dp[0] = 1;
    for (i = 2; i <= 30; i += 2) {
        dp[i] = 3 * dp[i - 2];
        for (j = i - 4; j >= 0; j -= 2) {
            dp[i] += 2 * dp[j];
        }
    }
    while (scanf("%d", &n) && n != -1) {
        if (n & 1)
            printf("0\n");
        else
            printf("%d\n", dp[n]);
    }
    return 0;
}
