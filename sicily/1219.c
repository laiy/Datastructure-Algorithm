#include <cstdio>
#include <cstring>

#define MAXN 21
#define INF 0x3f3f3f3f
#define max(x, y) x ^ ((x ^ y) & -(x < y))
#define min(x, y) y ^ ((x ^ y) & -(x < y))

int n;
int color[MAXN][MAXN];
int weight[MAXN][MAXN];
bool visited[MAXN];
int relations[MAXN];
int pre[MAXN];
int dp[1 << MAXN][2];

void create_relation(int index) {
    visited[index] = true;
    relations[index] |= 1 << (index - 1);
    for (int i = 1; i <= n; i++)
        if (!visited[i] && weight[i][index])
            create_relation(i), relations[index] |= relations[i], pre[i] = index;
}

inline void init() {
    memset(color, 0, sizeof(color));
    memset(weight, 0, sizeof(weight));
    memset(visited, 0, sizeof(visited));
    memset(relations, 0, sizeof(relations));
    memset(dp, INF, sizeof(dp));
}

int dfs(int index, int player) {
    if (!index)
        return 0;
    if (dp[index][(player + 1) / 2] != INF)
        return dp[index][(player + 1) / 2];
    int temp_index, temp, maxx = -INF, minx = INF;
    for (int i = 1; i <= n; i++)
        if ((index & (1 << (i - 1))) && color[i][pre[i]] == player) {
            temp_index = index & ~(relations[i]);
            temp = dfs(temp_index, player * -1);
            maxx = max(maxx, weight[pre[i]][i] + temp);
            minx = min(minx, weight[pre[i]][i] + temp);
        }
    if (player == 1) {
        if (maxx == -INF)
            maxx = dfs(index, player * -1);
        dp[index][(player + 1) / 2] = maxx;
    } else {
        if (minx == INF)
            minx = dfs(index, player * -1);
        dp[index][(player + 1) / 2] = minx;
    }
    return dp[index][(player + 1) / 2];
}

int main() {
    init();
    scanf("%d", &n);
    int a, b, c, w;
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d %d", &a, &b, &c, &w), color[a][b] = color[b][a] = c, weight[a][b] = weight[b][a] = w * c;
    create_relation(0);
    printf("%d\n", dfs((1 << n) - 1, 1));
    return 0;
}

