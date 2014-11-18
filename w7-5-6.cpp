/*************************************************************************
	> File Name: w7-5-6.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Saturday, November 15, 2014 PM02:29:40 CST
 ************************************************************************/

#include <cstdio>
#include <iostream>

int lcs_length(std::string &x, std::string &y) {
    int m = x.length();
    int n = y.length();
    int c[1000][1000];
    size_t i, j;
    for (i = 0; i < m; i++) c[i][0] = 0; 
    for (i = 0; i < n; i++) c[0][i] = 0; 
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                if (x[i] == y[j]) {
                    c[i][j] = 1;
                } else {
                    if (i > 0) {
                        c[i][j] = c[i - 1][j];
                    }
                    if (j > 0) {
                        c[i][j] = c[i][j - 1];
                    }
                }
                continue;
            }
            if (x[i] == y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
            } else {
                c[i][j] = c[i][j - 1];
            }
        }
    }
    return c[m - 1][n - 1];
}

int main() {
    std::string x, y;
    while (std::cin >> x >> y) {
        printf("%d\n", lcs_length(x, y));
    }
    return 0;
}

