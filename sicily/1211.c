#include <cstdio>
#include <cstring>
#include <queue>

struct Node {
    int location, step;
    Node(int location, int step) {
        this->location = location;
        this->step = step;
    }
};

int main() {
    int n, m, l, i, from, to, query, a, b, k, j, x;
    scanf("%d %d %d", &n, &m, &l);
    bool road[n + 1][n + 1];
    int dp[n + 1][n + 1][l + 1];
    memset(road, 0, sizeof(road));
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < m; i++)
        scanf("%d %d", &from, &to), road[from][to] = true, dp[from][to][1] = 1;
    for (k = 2; k <= l; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                for (x = 1; x <= n; x++)
                    if (road[i][x])
                        dp[i][j][k] += dp[x][j][k - 1];
    scanf("%d", &query);
    while (query--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[a][b][l]);
    }
}

