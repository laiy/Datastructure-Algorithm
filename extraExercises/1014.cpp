#include <stdio.h>
#define N 10000000
#define min(a, b) (a < b ? a : b)

int dis[200], map[200][200];
bool visited[200];
int n;

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = N;
        }
        dis[i] = N;
        visited[i] = false;
    }
}

int Dijkstra(int s, int t) {
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        int min = N, index;
        for (int j = 0; j < n; j++)
            if (!visited[j] && dis[j] < min) min = dis[j], index = j;
        visited[index] = true;
        for (int j = 0; j < n; j++)
            if (!visited[j]) dis[j] = min(dis[j], dis[index] + map[index][j]);
    }
    return visited[t] ? dis[t] : -1;
}

int main() {
    int s, t, x, m, a, b;
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        while (m--) {
            scanf("%d%d%d", &a, &b, &x);
            if (x < map[a][b]) {
                map[a][b] = map[b][a] = x;
            }
        }
        scanf("%d%d", &s, &t);
        printf("%d\n", Dijkstra(s, t));
    }
    return 0;
}

