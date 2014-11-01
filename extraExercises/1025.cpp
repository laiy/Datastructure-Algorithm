#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

std::vector<int> v[101];
int n, m;
bool visited[101];
int color[101];
std::queue<int> q;

bool bfs() {
    memset(color, 0, sizeof(color));
    memset(visited, false, sizeof(visited));
    color[1] = 1;
}

int main() {
    int a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if (bfs()) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}

