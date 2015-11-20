#include <cstdio>
#include <cstring>

int main() {
    int n, m, l, i, from, to, query, a, b, k, j, x, time;
    scanf("%d %d %d", &n, &m, &l);
    int road[n + 1][n + 1];
    int copy[n + 1][n + 1];
    int temp_result[n + 1][n + 1];
    memset(road, 0, sizeof(road));
    for (i = 0; i < m; i++)
        scanf("%d %d", &from, &to), road[from][to]++;
    memcpy(copy, road, sizeof(road));
    time = 1;
    while (time * 2 <= l) {
        for (k = 1; k <= n; k++)
            for (i = 1; i <= n; i++) {
                temp_result[i][k] = 0;
                for (j = 1; j <= n; j++)
                    temp_result[i][k] += road[i][j] * road[j][k];
            }
        memcpy(road, temp_result, sizeof(temp_result));
        time *= 2;
    }
    for (x = 1; x <= l - time; x++) {
        for (k = 1; k <= n; k++)
            for (i = 1; i <= n; i++) {
                temp_result[i][k] = 0;
                for (j = 1; j <= n; j++)
                    temp_result[i][k] += road[i][j] * copy[j][k];
            }
        memcpy(road, temp_result, sizeof(temp_result));
    }
    scanf("%d", &query);
    while (query--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", road[a][b]);
    }
}

