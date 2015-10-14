#include <cstdio>
#include <cstring>

bool visited[5][6];
int y_direction[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int x_direction[8] = {-1, 1, 2, -2, 2, -2, -1, 1};
int record[30];
bool found;

inline bool is_valid(int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 6;
}

inline int get_number(int x, int y) {
    return x * 6 + y + 1;
}

void dfs(int x, int y, int step) {
    if (visited[x][y] || found)
        return;
    visited[x][y] = true;
    record[step] = get_number(x, y);
    if (step == 29) {
        found = true;
        return;
    }
    int temp_x, temp_y;
    for (int i = 0; i < 8; i++) {
        temp_x = x + x_direction[i], temp_y = y + y_direction[i];
        if (is_valid(temp_x, temp_y) && !visited[temp_x][temp_y])
            dfs(temp_x, temp_y, step + 1);
    }
    visited[x][y] = false;
}

int main() {
    int n;
    while (scanf("%d", &n) && n != -1) {
        found = false;
        memset(visited, 0, sizeof(visited));
        dfs((n - 1) / 6, (n - 1) % 6, 0);
        for (int i = 0; i < 29; i++)
            printf("%d ", record[i]);
        printf("%d\n", record[29]);
    }
    return 0;
}

