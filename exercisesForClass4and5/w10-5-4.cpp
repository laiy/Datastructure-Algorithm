/*************************************************************************
	> File Name: w10-5-4.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, December 05, 2014 PM08:19:28 CST
 ************************************************************************/

#include <cstdio>

int a, b, m, n;
int table[301][11];

void output() {
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b - 1; j++) printf("%d ", table[i][j]);
        printf("%d\n", table[i][b]);
    }
}

int main() {
    scanf("%d%d", &a, &b);
    while (scanf("%d%d", &m, &n) != EOF) table[m][n]++;
    output();
    return 0;
}

