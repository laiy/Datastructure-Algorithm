#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

int possible_x[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int possible_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool visited[8][8];
int ans[64];

bool is_available(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8 && !visited[x][y];
}

int next_position_has_steps(int x, int y) {
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        if (is_available(x + possible_x[i], y + possible_y[i])) counter++;
    }
    return counter;
}

struct map_node {
    int x, y, degree;
    map_node() {
        x = y = degree = -1;
    }
    map_node(int a, int b) {
        x = a;
        y = b;
        degree = next_position_has_steps(a, b);
    }
};

void output() {
    for (int i = 0; i < 63; i++) {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[63]);
}

bool cmp(map_node a, map_node b) {
    return a.degree < b.degree;
}

bool dfs(map_node p, int count) {
    map_node temp;
    std::vector<map_node> container;
    visited[p.x][p.y] = true;
    ans[count] = 8 * p.x + p.y + 1;
    if (count == 63) return true;
    for (int i = 0; i < 8; i++) {
        map_node temp = map_node(p.x + possible_x[i], p.y + possible_y[i]);
        if (is_available(temp.x, temp.y)) container.push_back(temp);
    }
    sort(container.begin(), container.end(), cmp);
    for (int i = 0; i < container.size(); i++) {
        if (dfs(container[i], count + 1)) return true;
    }
    visited[temp.x][temp.y] = false;
    return false;
}

int main() {
    int start;
    while (scanf("%d", &start)) {
        if (start == -1) break;
        memset(visited, false, sizeof(visited));
        map_node p = map_node((start - 1) / 8, (start - 1) % 8);
        dfs(p, 0);
        output();
    }
    return 0;
}

