#include <stdio.h>
#include <string.h>
#include <queue>

#define MAX_N 200

int main() {
    int n, m, i, j, city;
    bool road[MAX_N][MAX_N];
    bool visited[MAX_N];
    bool can;
    while (scanf("%d", &n) && n != 0) {
        scanf("%d", &m);
        memset(road, 0, sizeof(road));
        memset(visited, 0, sizeof(visited));
        while (m--)
            scanf("%d %d", &i, &j), road[i][j] = true;
        std::queue<int> q;
        q.push(0);
        visited[0] = true;
        can = false;
        while (!q.empty()) {
            city = q.front();
            q.pop();
            if (city == n - 1) {
                can = true;
                break;
            }
            for (i = 0; i < n; i++)
                if (road[city][i] && !visited[i])
                    q.push(i), visited[i] = true;
        }
        printf(can ? "I can post the letter\n" : "I can't post the letter\n");
    }
    return 0;
}

