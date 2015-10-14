#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

bool visited[8][8];
int y_direction[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int x_direction[8] = {-1, 1, 2, -2, 2, -2, -1, 1};
int record[64];
bool found;

struct Node {
    int x, y, weight;
    Node(int x, int y, int weight) {
        this->x = x;
        this->y = y;
        this->weight = weight;
    }
    bool operator<(const Node &node) const {
        return weight < node.weight;
    }
};

inline bool is_valid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

inline int get_number(int x, int y) {
    return x * 8 + y + 1;
}

inline int get_weight(int x, int y) {
    int temp_x, temp_y, weight = 0;
    for (int i = 0; i < 8; i++) {
        temp_x = x + x_direction[i], temp_y = y + y_direction[i];
        if (is_valid(temp_x, temp_y) && !visited[temp_x][temp_y])
            weight++;
    }
    return weight;
}

void dfs(int x, int y, int step) {
    if (visited[x][y] || found)
        return;
    visited[x][y] = true;
    record[step] = get_number(x, y);
    if (step == 63) {
        found = true;
        return;
    }
    int temp_x, temp_y;
    std::vector<Node> v;
    for (int i = 0; i < 8; i++) {
        temp_x = x + x_direction[i], temp_y = y + y_direction[i];
        if (is_valid(temp_x, temp_y) && !visited[temp_x][temp_y])
            v.push_back(Node(temp_x, temp_y, get_weight(temp_x, temp_y)));
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; (size_t)i < v.size(); i++)
        dfs(v[i].x, v[i].y, step + 1);
    visited[x][y] = false;
}

int main() {
    int n;
    while (scanf("%d", &n) && n != -1) {
        found = false;
        memset(visited, 0, sizeof(visited));
        dfs((n - 1) / 8, (n - 1) % 8, 0);
        for (int i = 0; i < 63; i++)
            printf("%d ", record[i]);
        printf("%d\n", record[63]);
    }
    return 0;
}

