#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>
using namespace std;

struct Position {
    Position(int x, int y, int step) {
        this->x = x;
        this->y = y;
        this->step = step;
    }
    int x, y, step;
};

bool isValid(int x, int max) {
    if (x >= 0 && x < max) return true;
    return false;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (!n) break;
        char ly[30][30];
        bool footPrint[30][30];
        bool found = false;
        memset(footPrint, false, sizeof(footPrint));
        queue<Position> q;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == n || j == n) {
                    ly[i][j] = '1';
                } else {
                    cin >> ly[i][j];
                }
            }
        }
        q.push(Position(0, 0, 0));
        footPrint[0][0] = true;
        while (!q.empty()) {
            int tempX = q.front().x, tempY = q.front().y;
            int frontStep = q.front().step;
            if (tempX == n - 1 && tempY == n - 1) {
                cout << frontStep + 1 << endl;
                found = true;
                break;
            }
            q.pop();
            if (isValid(tempX + 1, n) && isValid(tempY, n)) {
                if (ly[tempX + 1][tempY] == '0' && !footPrint[tempX + 1][tempY]) {
                    footPrint[tempX + 1][tempY] = true;
                    q.push(Position(tempX + 1, tempY, frontStep + 1));
                }
            }
            if (isValid(tempX - 1, n) && isValid(tempY, n)) {
                if (ly[tempX - 1][tempY] == '0' && !footPrint[tempX - 1][tempY]) {
                    footPrint[tempX - 1][tempY] = true;
                    q.push(Position(tempX - 1, tempY, frontStep + 1));
                }
            }
            if (isValid(tempX, n) && isValid(tempY + 1, n)) {
                if (ly[tempX][tempY + 1] == '0' && !footPrint[tempX][tempY + 1]) {
                    q.push(Position(tempX, tempY + 1, frontStep + 1));
                    footPrint[tempX][tempY + 1] = true;
                }
            }
            if (isValid(tempX, n) && isValid(tempY - 1, n)) {
                if (ly[tempX][tempY - 1] == '0' && !footPrint[tempX][tempY - 1]) {
                    q.push(Position(tempX, tempY - 1, frontStep + 1));
                    footPrint[tempX][tempY - 1] = true;
                }
            }
        }
        if (!found) {
            cout << '0' << endl;
        }
    }
    return 0;
}
