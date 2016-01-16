#include <cstdio>
#include <queue>
#include <cstring>

struct state {
    int i, j, step, d;
    state(int i, int j, int step, int d) {
        this->i = i;
        this->j = j;
        this->step = step;
        this->d = d;
    }
};

int m, n;
int move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline bool is_valid(int i, int j) {
    return i >= 1 && i <= m && j >= 1 && j <= n;
}

int main() {
    int d, i, x, temp_i, temp_j;
    scanf("%d %d %d", &m, &n, &d);
    char input[m + 1][n + 1];
    bool visited[m + 1][n + 1][d + 1];
    memset(visited, 0, sizeof(visited));
    for (i = 1; i <= m; i++)
        scanf("%s", input[i] + 1);
    std::queue<state> q;
    q.push(state(1, 1, 0, 0));
    visited[1][1][0] = true;
    while (!q.empty()) {
        state s = q.front();
        q.pop();
        if (s.i == m && s.j == n) {
            printf("%d\n", s.step);
            return 0;
        }
        for (i = 0; i < 4; i++) {
            temp_i = s.i + move[i][0];
            temp_j = s.j + move[i][1];
            if (is_valid(temp_i, temp_j)) {
                if (input[temp_i][temp_j] == 'P' && !visited[temp_i][temp_j][s.d])
                    q.push(state(temp_i, temp_j, s.step + 1, s.d)), visited[temp_i][temp_j][s.d] = true;
                x = 1;
                while (is_valid(temp_i, temp_j)) {
                    temp_i += move[i][0], temp_j += move[i][1], x++;
                    if (is_valid(temp_i, temp_j) && input[temp_i][temp_j] == 'P' && x + s.d <= d && !visited[temp_i][temp_j][s.d + x])
                        q.push(state(temp_i, temp_j, s.step + 1, s.d + x)), visited[temp_i][temp_j][s.d + x] = true;
                }
            }
        }
    }
    printf("impossible\n");
    return 0;
}

