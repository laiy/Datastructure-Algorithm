/*************************************************************************
	> File Name: 1001.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Monday, January 05, 2015 PM08:52:04 CST
 ************************************************************************/

#include <cstdio>

int code_dimension, protection_dimension;
int code[80000], protection[1000000], next[80000];

void get_next() {
    next[1] = 0;
    int j = 0;
    for (int i = 2; i <= code_dimension; i++) {
        if (code[j + 1] == code[i]) j++;
        else 
            while (code[j + 1] != code[i] && j > 0) j = next[j];
        next[i] = j;
    }
}

void kmp_and_output() {
    int j = 0;
    for (int i = 1; i <= protection_dimension; i++) {
        if (code[j + 1] == protection[i]) j++;
        else 
            while (code[j + 1] != protection[i] && j > 0) j = next[j];
        if (j == code_dimension) {
            printf("%d\n", i - code_dimension);
            return;
        }
    }
    printf("no solution\n");
}

int main() {
    while (scanf("%d", &code_dimension) != EOF) {
        for (int i = 1; i <= code_dimension; i++) scanf("%d", &code[i]);
        scanf("%d", &protection_dimension);
        for (int i = 1; i <= protection_dimension; i++) scanf("%d", &protection[i]);
        get_next();
        kmp_and_output();
    }
    return 0;
}

