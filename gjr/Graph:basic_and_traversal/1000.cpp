/*************************************************************************
	> File Name: 1000.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Thursday, January 08, 2015 PM02:33:32 CST
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <vector>

int n, m;
bool edges[101][101];
bool visited[101];
std::vector<int> roots;
bool invalid;
int depth, root, width;
int level[101];

void DFS(int node, int d) {
    level[d]++;
    if (level[d] > width) width = level[d];
    for (int i = 1; i <= n; i++) {
        if (edges[node][i]) {
            if (i == root) {
                invalid = true;
                return;
            }
            if (d + 1 > depth) depth = d + 1;
            DFS(i, d + 1);
        }
    }
}

int main() {
    int a, b;
    while (scanf("%d%d", &n, &m)) {
        if (!n) break;
        bool go_next = false;
        depth = width = 0;
        invalid = false;
        memset(level, 0, sizeof(level));
        memset(edges, false, sizeof(edges));
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            if (go_next) continue;
            if (visited[b] || a == b) {
                invalid = true;
                go_next = true;
            }
            edges[a][b] = true;
            visited[b] = true;
        }
        if (invalid) {
            printf("INVALID\n");
            roots.clear();
            continue;
        }
        for (int i = 1; i <= n; i++)
            if (!visited[i]) roots.push_back(i);
        if (roots.empty()) invalid = true;
        for (int i = 0; i < roots.size(); i++) {
            root = roots[i];
            DFS(roots[i], 0);
        }
        if (invalid)
            printf("INVALID\n");
        else
            printf("%d %d\n", depth, width);
        roots.clear();
    }
    return 0;
}

