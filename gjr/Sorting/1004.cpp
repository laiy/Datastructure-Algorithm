/*************************************************************************
> File Name: 1004.cpp
> Author: LY
> Mail: ly.franky@gmail.com
> Created Time: Sunday, January 11, 2015 PM04:10:51 CST
************************************************************************/
#include <cstdio>
#include <algorithm>

int main() {
    int n, m, i, a[100001];
    while (scanf("%d%d", &n, &m) && !(!n && !m)) {
        for (i = 0; i < n; i++) scanf("%d", &a[i]);
        std::sort(a, a + n);
        printf("%d", a[0]);
        for (i = m; i < n; i += m) printf(" %d", a[i]);
        printf("\n");
    }
    return 0;
}

