#include <cstdio>
#include <cstring>
#include <queue>

struct Node {
    int location, step;
    Node(int location, int step) {
        this->location = location;
        this->step = step;
    }
};

int main() {
    int n, m, l, i, from, to, query, a, b, sum;
    scanf("%d %d %d", &n, &m, &l);
    bool road[n + 1][n + 1];
    memset(road, 0, sizeof(road));
    for (i = 0; i < m; i++)
        scanf("%d %d", &from, &to), road[from][to] = true;
    scanf("%d", &query);
    while (query--) {
        scanf("%d %d", &a, &b);
        std::queue<Node> q;
        q.push(Node(a, 0));
        sum = 0;
        while (!q.empty()) {
            Node temp = q.front();
            q.pop();
            if (temp.step > l)
                break;
            if (temp.step == l && temp.location == b)
                sum++;
            else {
                for (i = 1; i <= n; i++)
                    if (road[temp.location][i])
                        q.push(Node(i, temp.step + 1));
            }
        }
        printf("%d\n", sum);
    }
}

