/*************************************************************************
	> File Name: w10-5-5.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, December 05, 2014 PM08:36:57 CST
 ************************************************************************/

#include <cstdio>

int a, b, m, n, t;
int table[301][11][2];

void output() {
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b - 1; j++) printf("%d %d ", table[i][j][1], table[i][j][0]);
        printf("%d %d\n", table[i][b][1], table[i][b][0]);
    }
}

int main() {
    scanf("%d%d", &a, &b);
    while (scanf("%d%d%d", &m, &n, &t) != EOF) table[m][n][t]++;
    output();
    return 0;
}

