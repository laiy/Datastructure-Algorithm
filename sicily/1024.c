#include <cstdio>
#include <vector>
#include <cstring>

struct road {
    short to, distance;
    road(short t, short d) {
        to  = t;
        distance = d;
    }
};

int n, k, x, y, d, longest_distance;
std::vector<road> v[10001];
bool visited[10001];

void dfs(int p, int distance) {
    if (distance > longest_distance) longest_distance = distance;
    visited[p] = true;
    for (int i = 0; (size_t)i < v[p].size(); i++)
        if (!visited[v[p][i].to])
            dfs(v[p][i].to, distance + v[p][i].distance);
    visited[p] = false;
}

int main() {
    int j;
    while (scanf("%d %d", &n, &k) != EOF) {
        memset(visited, 0, sizeof(visited));
        longest_distance = 0;
        for (j = 1; j < n; j++)
            scanf("%d %d %d", &x, &y, &d), v[x].push_back(road(y, d)), v[y].push_back(road(x, d));
        visited[k] = true;
        dfs(k, 0);
        printf("%d\n", longest_distance);
        for (int i = 1; i <= n; i++)
            v[i].clear();
    }
    return 0;
}

