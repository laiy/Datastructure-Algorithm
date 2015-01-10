/*************************************************************************
	> File Name: 1001.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Saturday, January 10, 2015 PM03:05:48 CST
 ************************************************************************/

#include <cstdio>

int main() {
    int n, temp, ans;
    while (scanf("%d", &n) && n) {
        ans = 0;
        while (n--) scanf("%d", &temp), ans ^= temp;
        printf("%d\n", ans);
    }
    return 0;
}

