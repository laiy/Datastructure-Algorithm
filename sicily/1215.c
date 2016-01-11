#include <cstdio>
#include <cstring>
#include <queue>

char location_map[5];
int move_x[4];
int move_y[4];
int direction_x[4] = {-1, 1, 0, 0};
int direction_y[4] = {0, 0, -1, 1};
int n, m, steps;
bool impossible = false;
bool pre_meet = false;
char map[21][21];
int threshold = 256;

struct State {
    int h_position_x, h_position_y, p_position_x, p_position_y, steps;
    State(int h_position_x, int h_position_y, int p_position_x, int p_position_y, int steps) {
        this->h_position_x = h_position_x;
        this->h_position_y = h_position_y;
        this->p_position_x = p_position_x;
        this->p_position_y = p_position_y;
        this->steps = steps;
    }
};

inline bool meet(int p_position_x, int p_position_y, int h_position_x, int h_position_y, int possible_step) {
    if (p_position_x == h_position_x && p_position_y == h_position_y)
        return true;
    if (p_position_x + 1 == h_position_x && p_position_y == h_position_y && location_map[1] == 'N')
        threshold = possible_step;
    if (p_position_x - 1 == h_position_x && p_position_y == h_position_y && location_map[0] == 'S')
        threshold = possible_step;
    if (p_position_x == h_position_x && p_position_y + 1 == h_position_y && location_map[3] == 'W')
        threshold = possible_step;
    if (p_position_x == h_position_x && p_position_y - 1 == h_position_y && location_map[2] == 'E')
        threshold = possible_step;
    return false;
}

inline bool valid_pos(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(State original_state) {
    std::queue<State> q;
    q.push(original_state);
    int px, py, hx, hy;
    while (!q.empty()) {
        State temp = q.front();
        q.pop();
        if (temp.steps > 255) {
            impossible = true;
            return;
        }
        if (temp.steps == threshold) {
            steps = threshold;
            return;
        }
        if (meet(temp.p_position_x, temp.p_position_y, temp.h_position_x, temp.h_position_y, temp.steps + 1)) {
            steps = temp.steps;
            return;
        }
        for (int i = 0; i < 4; i++) {
            px = temp.p_position_x + direction_x[i];
            py = temp.p_position_y + direction_y[i];
            hx = temp.h_position_x + move_x[i];
            hy = temp.h_position_y + move_y[i];
            if (valid_pos(px, py) && map[px][py] == '.') {
                if (map[hx][hy] == '#')
                    q.push(State(temp.h_position_x, temp.h_position_y, px, py, temp.steps + 1));
                else if (map[hx][hy] == '.')
                    q.push(State(hx, hy, px, py, temp.steps + 1));
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int i, j, h_position_x, h_position_y, p_position_x, p_position_y;
    char row[21];
    for (i = 0; i < n; i++)
        scanf("%s", row), memcpy(&map[i], &row[0], sizeof(strlen(row)));
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
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (map[i][j] == 'H')
                h_position_x = i, h_position_y = j, map[i][j] = '.';
            else if (map[i][j] == 'P')
                p_position_x = i, p_position_y = j, map[i][j] = '.';
    bfs(State(h_position_x, h_position_y, p_position_x, p_position_y, 0));
    if (impossible)
        printf("Impossible\n");
    else
        printf("%d\n", steps);
    return 0;
}

