/*************************************************************************
	> File Name: w7-5-6.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Saturday, November 15, 2014 PM02:29:40 CST
 ************************************************************************/

#include <cstdio>
#include <cstring>

int lcs_length(char* x, char *y) {
    int m = strlen(x); 
    int n = strlen(y); 
    int c[1000][1000];
    size_t i, j;
    for (i = 0; i < m; i++) c[i][0] = 0; 
    for (i = 0; i < n; i++) c[0][i] = 0; 
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = x[i] == y[j] ? 1 : (i > 0) ? c[i - 1][j] : (j > 0) ? c[i][j - 1] : c[i][j];
                continue;
            }
            c[i][j] = x[i] == y[j] ? c[i - 1][j - 1] + 1 : (c[i - 1][j] >= c[i][j - 1]) ? c[i - 1][j] : c[i][j - 1];
        }
    }
    return c[m - 1][n - 1];
}

int main() {
    char x[1000], y[1000];
    while (scanf("%s%s", x, y) != EOF) {
        printf("%d\n", lcs_length(x, y));
    }
    return 0;
}

