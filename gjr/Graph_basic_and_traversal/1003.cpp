/*************************************************************************
	> File Name: 1003.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Thursday, January 08, 2015 PM08:33:10 CST
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 10000
#define min(a, b) (a < b ? a : b)

int n, m;
int distance[1001][1001];
bool visited[1001];

void bfs(int node) {
    std::queue<int> q;
    q.push(node);
    distance[1][1] = 0;
    while (!q.empty()) {
        int temp = q.front();
        visited[temp] = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                for (int j = 1; j <= n; j++) {
                    distance[temp][i] = distance[i][temp] = min(distance[temp][i], distance[temp][j] + distance[j][i]);
                }
                q.push(i);
            }
        }
        q.pop();
    }
}

void output() {
    for (int i = 1; i <= n; i++)
        printf("%d ", (distance[1][i] >= MAX ? -1 : distance[1][i]));
    printf("\n");
}

int main() {
    int v, y;
    scanf("%d%d", &n, &m);
    memset(visited, false, sizeof(visited));
    memset(distance, MAX, sizeof(distance));
    for (int i = 0; i < m; i++) scanf("%d%d", &v, &y), distance[v][y] = distance[y][v] = 1;
    bfs(1);
    output();
    return 0;
}

