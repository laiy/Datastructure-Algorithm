#include <cstdio>
#include <queue>
#include <cstring>

struct edge {
    int i, j, dis;
    edge(int i, int j, int dis) {
        this->i = i;
        this->j = j;
        this->dis = dis;
    }
    bool operator<(const edge &e) const {
        return this->dis > e.dis;
    }
};

int main() {
    int t, i, j, n, d, node_count, max, to_insert;
    bool print = false;
    scanf("%d", &t);
    while (t--) {
        if (print)
            printf("\n");
        print = true;
        scanf("%d", &n);
        int dis[n + 1][n + 1];
        bool s[n + 1];
        memset(dis, 0, sizeof(dis));
        memset(s, 0, sizeof(s));
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++) {
                scanf("%d", &d);
                dis[i][j] = d;
            }
        std::priority_queue<edge> q;
        s[1] = true;
        for (i = 2; i <= n; i++)
            if (dis[1][i])
                q.push(edge(1, i, dis[1][i]));
        node_count = 1;
        max = 0;
        while (node_count++ != n) {
            while (true) {
                edge shortest = q.top();
                q.pop();
                if (s[shortest.i] && s[shortest.j])
                    continue;
                else {
                    to_insert = !s[shortest.i] ? shortest.i : shortest.j;
                    if (shortest.dis > max)
                        max = shortest.dis;
                    break;
                }
            }
            s[to_insert] = true;
            for (i = 1; i <= n; i++)
                if (!s[i] && dis[to_insert][i])
                    q.push(edge(to_insert, i, dis[to_insert][i]));
        }
        printf("%d\n", max);
    }
    return 0;
}

