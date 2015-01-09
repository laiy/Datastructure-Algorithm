/*************************************************************************
	> File Name: 1001.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, January 09, 2015 PM07:12:53 CST
 ************************************************************************/

#include <cstdio>
#include <cstring>
#define max(a, b) (a > b ? a : b)

int distance[501][501];
int n;

int prim_and_get_max_length() {
    int longest = 0;
    bool visited[501];
    int closest_dis[501];
    memset(visited, false, sizeof(visited));
    for (int i = 2; i <= n; i++) closest_dis[i] = distance[1][i];
    visited[1] = true;
    for (int i = 1; i < n; i++) {
        int index, min = 65537;
        for (int j = 2; j <= n; j++)
            if (!visited[j] && closest_dis[j] < min) min = closest_dis[j], index = j;
        longest = max(longest, min);
        visited[index] = true;
        for (int j = 2; j <= n; j++)
            if (!visited[j] && distance[index][j] < closest_dis[j]) closest_dis[j] = distance[index][j];
    }
    return longest;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &distance[i][j]);
        printf("%d\n", prim_and_get_max_length());
        if (t) printf("\n");
    }
    return 0;
}

