/*************************************************************************
	> File Name: 1006.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Wednesday, January 21, 2015 PM08:48:29 CST
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <queue>

struct Position {
    int col, row, step;
    Position(int c, int r, int s) {
        col = c, row = r, step = s;
    }
};

int n;
int matrix[30][30];
bool visited[30][30];
int direction[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int bfs() {
    if (matrix[0][0]) return 0;
    if (n == 1 && !matrix[0][0]) return 1;
    std::queue<Position> q;
    q.push(Position(0, 0, 1));
    memset(visited, false, sizeof(visited));
    visited[0][0] = true;
    int x, y;
    while (!q.empty()) {
        Position temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            x = temp.col + direction[i][0], y = temp.row + direction[i][1];
            if (!matrix[x][y] && is_valid(x, y) && !visited[x][y]) {
                if (x == n - 1 && y == n - 1) return temp.step + 1;
                q.push(Position(x, y, temp.step + 1));
                visited[x][y] = true;
            }
        }
    }
    return 0;
}

int main() {
    while (scanf("%d", &n)) {
        if (!n) break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &matrix[i][j]);
        printf("%d\n", bfs());
    }
    return 0;
}

