#include <cstdio>
#include <cstring>

int n, m, count;
bool aim[16][16];
bool temp[16][16];
int direction[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

inline void test() {
    int t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            t = 0;
            for (int k = 0; k < 8; k++)
                if (temp[(i + direction[k][0] + n) % n][(j + direction[k][1] + m) % m])
                    t++;
            if (t == 3 || (temp[i][j] && t == 2)) {
                if (!aim[i][j])
                    return;
            } else
                if (aim[i][j])
                    return;
        }
    count++;
}

void dfs(int i, int j) {
    if (i == n) {
        test();
        return;
    }
    temp[i][j] = 0;
    if (j == m - 1)
        dfs(i + 1, 0);
    else
        dfs(i, j + 1);
    temp[i][j] = 1;
    if (j == m - 1)
        dfs(i + 1, 0);
    else
        dfs(i, j + 1);
}

int main() {
    int k, i, j, c = 1;
    while (scanf("%d %d", &n, &m) && n && m) {
        memset(aim, 0, sizeof(aim));
        scanf("%d", &k);
        while (k--)
            scanf("%d %d", &i, &j), aim[i][j] = true;
        count = 0;
        dfs(0, 0);
        if (count)
            printf("Case %d: %d possible ancestors.\n", c++, count);
        else
            printf("Case %d: Garden of Eden.\n", c++);
    }
    return 0;
}

