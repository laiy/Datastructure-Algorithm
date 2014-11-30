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
bool m_negative_visited[80000];
bool n_negative_visited[80000];

void print_intersection() {
    for (int i = 0; i < m; i++)
        m_array[i] >= 0 ? n_visited[m_array[i]] ? printf("%d ", m_array[i]) : 0 : n_negative_visited[-m_array[i]] ? printf("%d ", m_array[i]) : 0;
    printf("\n");
}

void print_union() {
    for (int i = 0; i < m; i++) printf("%d ", m_array[i]);
    for (int i = 0; i < n; i++)
        n_array[i] >= 0 ? !m_visited[n_array[i]] ? printf("%d ", n_array[i]) : 0 : !m_negative_visited[-n_array[i]] ? printf("%d ", n_array[i]) : 0;
    printf("\n");
}

void print_different_set() {
    for (int i = 0; i < m; i++)
        m_array[i] >= 0 ? !n_visited[m_array[i]] ? printf("%d ", m_array[i]) : 0 : !n_negative_visited[-m_array[i]] ? printf("%d ", m_array[i]) : 0;
    printf("\n");
}

void clear_visited() {
        for (int i = 0; i < m; i++) m_array[i] >= 0 ? m_visited[m_array[i]] = false : m_negative_visited[-m_array[i]] = false;
        for (int i = 0; i < n; i++) n_array[i] >= 0 ? n_visited[n_array[i]] = false : n_negative_visited[-n_array[i]] = false;
}

int main() {
    while (scanf("%d%d", &m, &n) != EOF) {
        for (int i = 0; i < m; i++) scanf("%d", &m_array[i]), m_array[i] >= 0 ? m_visited[m_array[i]] = true : m_negative_visited[-m_array[i]] = true;
        for (int i = 0; i < n; i++) scanf("%d", &n_array[i]), n_array[i] >= 0 ? n_visited[n_array[i]] = true : n_negative_visited[-n_array[i]] = true;
        print_intersection();
        print_union();
        print_different_set();
        clear_visited();
    }
    return 0;
}

