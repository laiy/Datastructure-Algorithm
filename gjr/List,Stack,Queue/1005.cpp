/*************************************************************************
	> File Name: 1005.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, January 04, 2015 PM03:09:06 CST
 ************************************************************************/

#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>

int n;
int origin_order[1005], post_min[1005], color[1005];
bool edge[1005][1005];
std::stack<int> s1, s2;

void no_answer() {
    printf("0\n");
    exit(0);
}

void dfs(int index, int _color) {
    color[index] = _color;
    for (int i = 1; i <= n; i++)
        if (edge[index][i]) {
            if (color[i] == _color) no_answer();
            if (!color[i]) dfs(i, 3 - _color);
        }
}

void init_data() {
    memset(color, 0, sizeof(color));
    memset(edge, false, sizeof(edge));
    while (!s1.empty()) s1.pop();
    while (!s2.empty()) s2.pop();
}

void init_post_min() {
    post_min[n + 1] = 1005;
    for (int i = n; i >= 1; i--) post_min[i] = std::min(origin_order[i], post_min[i + 1]);
}

void link_edge() {
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (origin_order[i] < origin_order[j] && post_min[j + 1] < origin_order[i])
                edge[i][j] = edge[j][i] = true;
}

void output() {
    int to_output = 1;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 1) s1.push(origin_order[i]), printf(i == 1 ? "a" : " a");
        else s2.push(origin_order[i]), printf(" c");
        while ((s1.empty() ? false : s1.top() == to_output) || (s2.empty() ? false : s2.top() == to_output)) {
            if (s1.empty() ? false : s1.top() == to_output) s1.pop(), printf(" b");
            else s2.pop(), printf(" d");
            to_output++;
        }
    }
    printf("\n");
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) scanf("%d", &origin_order[i]);
        init_data();
        init_post_min();
        link_edge();
        for (int i = 1; i <= n; i++)
            if (!color[i]) dfs(i, 1);
        output();
    }
    return 0;
}

