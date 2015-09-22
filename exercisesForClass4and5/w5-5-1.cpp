#include <stdio.h>
#include <string.h>
#include <vector>

int map[10][10];
int n, m;
int possible[2] = {-1 ,1};
bool visited[10][10];
std::vector<std::pair<int, int> > container;
bool found = false;

struct Node {
    int x, y;
};

void print() {
    for (int i = 0; i < container.size(); i++) {
        printf("(%d,%d)", container[i].first, container[i].second);
        if (i != container.size() - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}

bool is_available(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && !map[x][y];
}

void dfs(Node* p) {
    if (found) return;
    if (p->x == m - 1 && p->y == n - 1) {
        print();
        found = true;
    } else {
        int temp_x = p->x;
        int temp_y = p->y;
        for (int i = 0; i < 2; i++) {
            if (is_available(temp_x + possible[i], temp_y)) {
                Node* temp = new Node;
                temp->x = temp_x + possible[i];
                temp->y = temp_y;
                visited[temp->x][temp->y] = true;
                container.push_back(std::make_pair<int, int>(temp->x, temp->y));
                dfs(temp);
                container.pop_back();
                visited[temp->x][temp->y] = false;
            }
        }
        for (int i = 0; i < 2; i++) {
            if (is_available(temp_x, temp_y + possible[i])) {
                Node* temp = new Node;
                temp->x = temp_x;
                temp->y = temp_y + possible[i];
                visited[temp->x][temp->y] = true;
                container.push_back(std::make_pair<int, int>(temp->x, temp->y));
                dfs(temp);
                container.pop_back();
                visited[temp->x][temp->y] = false;
            }
        }
    }
}

int main() {
    int t;
    char c[10];
    scanf("%d", &t);
    while (t--) {
        while (!container.empty()) {
            container.pop_back();
        }
        scanf("%d%d", &m, &n);
        memset(visited, false, sizeof(visited));
        found = false;
        for (int i = 0; i < m; i++) {
            scanf("%s", c);
            for (int j = 0; j < n; j++) {
                map[i][j] = c[j] - '0';
            }
        }
        if (map[0][0] == 1 || map[m - 1][n - 1] == 1) {
            printf("no\n");
            continue;
        }
        Node* p = new Node;
        container.push_back(std::make_pair<int, int>(0, 0));
        p->x = p->y = 0;
        visited[0][0] = true;
        dfs(p);
        if (!found) printf("no\n");
    }
    return 0;
}

