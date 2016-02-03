/*************************************************************************
	> File Name: 1004.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Thursday, January 08, 2015 PM09:06:59 CST
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <queue>

int n, m, ans = 0;
bool visited[1001];
bool edges[1001][1001];

void bfs(int node) {
    std::queue<int> q;
    q.push(node);
    while (!q.empty()) {
        int temp = q.front();
        visited[temp] = true;
        for (int i = 1; i <= n; i++)
            if (edges[temp][i])
                if (!visited[i])
                    q.push(i);
        q.pop();
    }
    ans++;
}

int main() {
    int v, y;
    scanf("%d%d", &n, &m);
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < m; i++) scanf("%d%d", &v, &y), edges[v][y] = edges[y][v] = true;
    for (int i = 1; i <= n; i++)
        if (!visited[i]) bfs(i);
    printf("%d\n", ans);
    return 0;
}

