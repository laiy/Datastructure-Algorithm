/*************************************************************************
    > File Name: w7-5-5.cpp
    > Author: LY
    > Mail: ly.franky@gmail.com
    > Created Time: Saturday, November 15, 2014 PM02:27:43 CST
 ************************************************************************/
#include <cstdio>

int gate[1000000], code[80000];
int n, m, next[80000];

void get_next() {
    next[1] = 0;
    int j = 0;
    for (int i = 2; i <= m; i++) {
        while (j > 0 && code[j + 1] != code[i]) j = next[j];
        if (code[j + 1] == code[i]) j++;
        next[i] = j;
    }
}

void kmp() {
    int j = 0;
    for (int i = 1; i <= n; i++) {
        while (j > 0 && code[j + 1] != gate[i]) j = next[j];
        if (code[j + 1] == gate[i]) j++;
        if (j == m) {
            printf("%d\n", i - m);
            return;
        }
    }
    printf("no solution\n");
}

int main() {
    while(scanf("%d", &m) != EOF) {
        for (int i = 1; i <= m; i++) scanf("%d", &code[i]);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &gate[i]);
        get_next();
        kmp();
    }
    return 0;
}

