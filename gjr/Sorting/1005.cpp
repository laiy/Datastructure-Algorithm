/*************************************************************************
	> File Name: 1005.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, January 11, 2015 PM07:17:11 CST
 ************************************************************************/

#include <cstdio>
#include <algorithm>

int main() {
    int t, data[1000], n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &data[i]);
        std::sort(data, data + n);
        for (int i = 0; i < n; i++) printf("%d\n", data[i]);
    }
    return 0;
}

