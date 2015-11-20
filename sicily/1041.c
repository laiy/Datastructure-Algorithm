#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
#include <cstring>

struct Map {
    int map[21][21];
    Map(int map[21][21]) {
        for (int i = 0; i < 21; i++)
            for (int j = 0; j < 21; j++)
                this->map[i][j] = map[i][j];
    }
};

int main() {
    int height, width, n, i, x, y, distance, temp, other;
    int map[21][21], up, right, left, down, to_push, j, k, count = 0;
    bool b;
    std::string direction;
    while (scanf("%d %d", &height, &width) && !(height == 0 && width == 0)) {
        memset(map, -1, sizeof(map));
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%d %d", &x, &y), map[x][y] = i;
        std::stack<Map> protected_state;
        while (std::cin >> direction) {
            if (direction == "done")
                break;
            scanf("%d", &distance);
            b = false;
            if (direction == "down") {
                down = 0;
                while (distance--) {
                    protected_state.push(Map(map));
                    for (i = 0; i < width; i++)
                        if (map[down][i] != -1) {
                            temp = down + 1;
                            to_push = map[down][i];
                            map[down][i] = -1;
                            while (true) {
                                if (temp == height) {
                                    for (j = 0; j < height; j++)
                                        for (k = 0; k < width; k++)
                                            map[j][k] = protected_state.top().map[j][k];
                                    protected_state.pop();
                                    break;
                                }
                                if (map[temp][i] == -1) {
                                    map[temp][i] = to_push;
                                    break;
                                } else {
                                    other = map[temp][i];
                                    map[temp][i] = to_push;
                                    to_push = other;
                                }
                                temp++;
                            }
                            if (protected_state.empty()) {
                                b = true;
                                break;
                            }
                        }
                    if (b)
                        break;
                    protected_state.pop();
                    down++;
                }
            } else if (direction == "right") {
                right = 0;
                while (distance--) {
                    protected_state.push(Map(map));
                    for (i = 0; i < height; i++)
                        if (map[i][right] != -1) {
                            temp = right + 1;
                            to_push = map[i][right];
                            map[i][right] = -1;
                            while (true) {
                                if (temp == width) {
                                    for (j = 0; j < height; j++)
                                        for (k = 0; k < width; k++)
                                            map[j][k] = protected_state.top().map[j][k];
                                    protected_state.pop();
                                    break;
                                }
                                if (map[i][temp] == -1) {
                                    map[i][temp] = to_push;
                                    break;
                                } else {
                                    other = map[i][temp];
                                    map[i][temp] = to_push;
                                    to_push = other;
                                }
                                temp++;
                            }
                            if (protected_state.empty()) {
                                b = true;
                                break;
                            }
                        }
                    if (b)
                        break;
                    protected_state.pop();
                    right++;
                }
            } else if (direction == "left") {
                left = width - 1;
                while (distance--) {
                    protected_state.push(Map(map));
                    for (i = 0; i < height; i++)
                        if (map[i][left] != -1) {
                            temp = left - 1;
                            to_push = map[i][left];
                            map[i][left] = -1;
                            while (true) {
                                if (temp == -1) {
                                    for (j = 0; j < height; j++)
                                        for (k = 0; k < width; k++)
                                            map[j][k] = protected_state.top().map[j][k];
                                    protected_state.pop();
                                    break;
                                }
                                if (map[i][temp] == -1) {
                                    map[i][temp] = to_push;
                                    break;
                                } else {
                                    other = map[i][temp];
                                    map[i][temp] = to_push;
                                    to_push = other;
                                }
                                temp--;
                            }
                            if (protected_state.empty()) {
                                b = true;
                                break;
                            }
                        }
                    if (b)
                        break;
                    protected_state.pop();
                    left--;
                }
            } else {
                up = height - 1;
                while (distance--) {
                    protected_state.push(Map(map));
                    for (i = 0; i < width; i++)
                        if (map[up][i] != -1) {
                            temp = up - 1;
                            to_push = map[up][i];
                            map[up][i] = -1;
                            while (true) {
                                if (temp == -1) {
                                    for (j = 0; j < height; j++)
                                        for (k = 0; k < width; k++)
                                            map[j][k] = protected_state.top().map[j][k];
                                    protected_state.pop();
                                    break;
                                }
                                if (map[temp][i] == -1) {
                                    map[temp][i] = to_push;
                                    break;
                                } else {
                                    other = map[temp][i];
                                    map[temp][i] = to_push;
                                    to_push = other;
                                }
                                temp--;
                            }
                            if (protected_state.empty()) {
                                b = true;
                                break;
                            }
                        }
                    if (b)
                        break;
                    protected_state.pop();
                    up--;
                }
            }
        }
        printf("Data set %d ends with boxes at locations", ++count);
        for (k = 0; k < height; k++)
            for (j = 0; j < width; j++)
                if (map[k][j] != -1)
                    printf(" (%d,%d)", k, j);
        printf(".\n");
    }
    return 0;
}

