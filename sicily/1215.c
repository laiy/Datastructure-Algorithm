#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

struct State {
    short px, py, hx, hy, step;
} temp, new_state;

int main() {
    short n, m, i, j;
    short px, py, hx, hy;
    char map[20][20];
    bool visited[20][20][20][20], flag = true;
    char location_map[4];
    short move_x[4], move_y[4], direction_x[4] = {-1, 1, 0, 0}, direction_y[4] = {0, 0, -1, 1};
    memset(visited, 0, sizeof(visited));
    scanf("%hd %hd", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == 'P')
                temp.px = i, temp.py = j;
            if (map[i][j] == 'H')
                temp.hx = i, temp.hy = j;
        }
    scanf("%s", location_map);
    for (i = 0; i < 4; i++)
        if (location_map[i] == 'N')
            move_x[i] = -1, move_y[i] = 0;
        else if (location_map[i] == 'S')
            move_x[i] = 1, move_y[i] = 0;
        else if (location_map[i] == 'W')
            move_x[i] = 0, move_y[i] = -1;
        else if (location_map[i] == 'E')
            move_x[i] = 0, move_y[i] = 1;
    temp.step = 0;
    std::queue<State> q;
    q.push(temp);
    visited[temp.px][temp.py][temp.hx][temp.hy] = true;
    while (flag && !q.empty() && q.front().step < 255) {
        temp = q.front();
        q.pop();
        for (i = 0; i < 4; i++) {
            px = temp.px + direction_x[i];
            py = temp.py + direction_y[i];
            hx = temp.hx + move_x[i];
            hy = temp.hy + move_y[i];
            if (map[px][py] == '#' || map[px][py] == '!' || map[hx][hy] == '!')
                continue;
            if (map[hx][hy] == '#')
                hx = temp.hx, hy = temp.hy;
            if (visited[px][py][hx][hy])
                continue;
            visited[px][py][hx][hy] = true;
            new_state.step = temp.step + 1;
            new_state.px = px, new_state.py = py, new_state.hx = hx, new_state.hy = hy;
            if ((px == hx && py == hy) || (px == temp.hx && py == temp.hy && hx == temp.px && hy == temp.py)) {
                printf("%d\n", new_state.step);
                flag = false;
                break;
            }
            q.push(new_state);
        }
    }
    if (flag)
        printf("Impossible\n");
    return 0;
}

