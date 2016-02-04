#include <cstdio>
#define min(a, b) a < b ? a : b

int main() {
    int n, a[101], r, i, j; 
    double b, v, e, f, cost[10001], dp[101];
    while (scanf("%d", &n) && n) {
        for (i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        scanf("%lf", &b);
        scanf("%d %lf %lf %lf", &r, &v, &e, &f);
        cost[0] = 0;
        for (i = 1; i <= a[n]; i++)
            cost[i] = cost[i - 1] + (((i - 1) >= r) ? (1 / (v - e * ((i - 1) - r))) : (1 / (v - f * (r - (i - 1)))));
        for (i = 1; i <= n; i++) {
            dp[i] = cost[a[i]];
            for (j = 1; j < i; j++)
                dp[i] = min(dp[i], dp[j] + cost[a[i] - a[j]] + b);
        }
        printf("%.4lf\n", dp[n]);
    }
    return 0;
}
