/*************************************************************************
	> File Name: w9-5-2.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, November 30, 2014 AM09:02:56 CST
 ************************************************************************/

#include <cstdio>
#include <cstring>

int m, n;
int m_array[101];
int n_array[101];
bool m_visited[80000];
bool n_visited[80000];

void print_intersection() {
    for (int i = 0; i < m; i++)
        if (n_visited[m_array[i]]) printf("%d ", m_array[i]);
    printf("\n");
}

void print_union() {
    for (int i = 0; i < m; i++) printf("%d ", m_array[i]);
    for (int i = 0; i < n; i++)
        if (!m_visited[n_array[i]]) printf("%d ", n_array[i]);
    printf("\n");
}

void print_different_set() {
    for (int i = 0; i < m; i++)
        if (!n_visited[m_array[i]]) printf("%d ", m_array[i]);
    printf("\n");
}

int main() {
    while (scanf("%d%d", &m, &n) != EOF) {
        memset(m_visited, false, sizeof(bool));
        memset(n_visited, false, sizeof(bool));
        for (int i = 0; i < m; i++) scanf("%d", &m_array[i]), m_visited[m_array[i]] = true;
        for (int i = 0; i < n; i++) scanf("%d", &n_array[i]), n_visited[n_array[i]] = true;
        print_intersection();
        print_union();
        print_different_set();
    }
    return 0;
}

