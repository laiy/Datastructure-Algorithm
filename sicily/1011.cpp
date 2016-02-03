#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int t, n, m, i, j, k, count;
    long long dp[11][2001];
    long long ans;
    scanf("%d", &t);
    memset(dp, 0, sizeof(dp));
    n = 10, m = 2000;
    for (i = 1; i <= m; i++)
        dp[1][i] = 1;
    for (i = 2; i <= n; i++)
        for (j = pow(2, i - 1); j <= m; j++)
            for (k = pow(2, i - 2); k <= j / 2; k++)
                dp[i][j] += dp[i - 1][k];
    for (count = 1; count <= t; count++) {
        scanf("%d %d", &n, &m);
        ans = 0;
        for (i = pow(2, n - 1); i <= m; i++)
            ans += dp[n][i];
        printf("Case %d: n = %d, m = %d, # lists = %lld\n", count, n, m, ans);
    }
    return 0;
}

