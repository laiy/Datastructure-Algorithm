/*************************************************************************
	> File Name: 1000.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Saturday, January 10, 2015 PM04:30:10 CST
 ************************************************************************/

#include <cstdio>

int arr[100];
int n;

bool binary_searchable(int x) {
    for (int i = 0; i < x; i++)
        if (arr[i] > arr[x]) return false;
    for (int i = x + 1; i < n; i++)
        if (arr[i] < arr[x]) return false;
    return true;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        int ans = 0;
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        for (int i = 0; i < n; i++)
            if (binary_searchable(i)) ans++;
        printf("%d\n", ans);
    }
    return 0;
}

