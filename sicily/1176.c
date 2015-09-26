#include <cstdio>
#include <cstring>
#define max(a, b) (a > b) ? a : b

int main() {
    short n, count = 1;
    int i, sum, j;
    while (scanf("%hd", &n) && n != 0) {
        sum  = 0;
        short arr[n];
        int dp[n][n];
        for (i = 0; i < n; i++)
            scanf("%hd", arr + i), sum += arr[i];
        for (i = 0; i < n - 1; i++)
            dp[i][i + 1] = max(arr[i], arr[i + 1]);
        if (n > 2)
            for (i = 4; i <= n; i += 2)
                for (j = 0; j + i - 1 < n; j++)
                    dp[j][j + i - 1] = max(arr[j] + (arr[j + 1] >= arr[j + i - 1] ? dp[j + 2][j + i - 1] : dp[j + 1][j + i - 2]),
                            arr[j + i - 1] + (arr[j] >= arr[j + i - 2] ? dp[j + 1][j + i - 2] : dp[j][j + i - 3]));
        printf("In game %hd, the greedy strategy might lose by as many as %d points.\n", count++, 2 * dp[0][n - 1] - sum);
    }
    return 0;
}

