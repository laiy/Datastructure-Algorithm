#include <stdio.h>
#include <string.h>

#define max(a, b) a > b ? a : b

int main() {
    int n, m, i, j;
    int v[25], p[25];
    while (scanf("%d %d", &n, &m) != EOF) {
        for (i = 0; i < m; i++)
            scanf("%d %d", v + i, p + i);
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (i = 0; i < m; i++)
            for (j = 0; j <= n; j++)
                if (j < v[i])
                    dp[i + 1][j] = dp[i][j];
                else
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - v[i]] + v[i] * p[i]);
        printf("%d\n", dp[m][n]);
    }
    return 0;
}

