/*************************************************************************
	> File Name: 1002.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Thursday, January 08, 2015 PM07:48:32 CST
 ************************************************************************/

#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <cstring>

struct Postion {
    int col, row, step;
    Postion(int c, int r, int s) {
        col = c, row = r, step = s;
    }
};

int direction[8][2] = {
    -2, -1, -2, 1, -1, -2, -1, 2, 1, -2, 1, 2, 2, -1, 2, 1
};

bool is_valid(int position) {
    return position >= 0 && position < 8;
}

int bfs(int s_col, int s_row, int e_col, int e_row) {
    bool visited[8][8];
    memset(visited, false, sizeof(visited));
    std::queue<Postion> q;
    q.push(Postion(s_col, s_row, 0));
    visited[s_col][s_row] = true;
    int next_col, next_row;
    while (!q.empty()) {
        Postion temp = q.front();
        q.pop();
        if (temp.col == e_col && temp.row == e_row) return temp.step;
        for (int i = 0; i < 8; i++) {
            next_col = temp.col + direction[i][0];
            next_row = temp.row + direction[i][1];
            if (is_valid(next_col) && is_valid(next_row) && !visited[next_col][next_row])
                q.push(Postion(next_col, next_row, temp.step + 1)), visited[next_col][next_row] = true;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    std::string start, end;
    while (t--) {
        std::cin >> start >> end;
        std::cout << "To get from " << start << " to " << end << " takes " << bfs(start[0] - 'a', start[1] - '1', end[0] - 'a', end[1] - '1') << " knight moves." << std::endl;
    }
    return 0;
}

