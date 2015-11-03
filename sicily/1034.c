#include <cstdio>
#include <cstring>
#include <queue>

struct Node {
    int num, level;
    Node(int n, int l) {
        num = n;
        level = l;
    }
};

bool invalid;
int level_count[101];
int depth, n;
bool edge[101][101];
bool v[101];

void bfs(int root) {
    memset(v, 0, sizeof(v));
    std::queue<Node> q;
    q.push(Node(root, 0));
    while (!q.empty()) {
        Node temp = q.front();
        q.pop();
        level_count[temp.level]++;
        v[temp.num] = true;
        if (temp.level > depth)
            depth = temp.level;
        for (int i = 1; i <= n; i++)
            if (edge[temp.num][i]) {
                if (v[i]) {
                    invalid = true;
                    return;
                }
                q.push(Node(i, temp.level + 1));
            }
    }
}

int main() {
    int m, i, a, b, width;
    bool visited[101];
    bool invalid;
    while (scanf("%d %d", &n, &m) && n != 0) {
        invalid = false;
        memset(edge, 0, sizeof(edge));
        memset(visited, 0, sizeof(visited));
        for (i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            if (visited[b] || a == b)
                invalid = true;
            visited[b] = true, edge[a][b] = true;
        }
        if (invalid) {
            printf("INVALID\n");
            continue;
        }
        depth = 0;
        memset(level_count, 0, sizeof(level_count));
        for (i = 1; i <= n; i++)
            if (!visited[i] && !invalid)
                bfs(i);
        if (level_count[0] == 0 || invalid) {
            printf("INVALID\n");
            continue;
        }
        width = level_count[0];
        for (i = 1; i <= depth; i++)
            if (level_count[i] > width)
                width = level_count[i];
        printf("%d %d\n", depth, width);
    }
    return 0;
}

