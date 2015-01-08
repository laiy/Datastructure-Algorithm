/*************************************************************************
	> File Name: 1004.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Thursday, January 08, 2015 AM09:04:30 CST
 ************************************************************************/

#include <cstdio>

int main() {
    int t, first, second;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &first, &second);
        while (first != second) {
            if (first > second) first /= 2;
            else second /= 2;
        }
        printf("%d\n", first);
    }
    return 0;
}

