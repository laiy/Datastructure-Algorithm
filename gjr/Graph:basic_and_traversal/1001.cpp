/*************************************************************************
	> File Name: 1001.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Thursday, January 08, 2015 PM04:40:46 CST
 ************************************************************************/

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

struct Edge {
    int from, to;
    std::string type;
    Edge(int f, int t) {
        from = f;
        to = t;
        type = "Cross";
    }
};

int n, m, k, u, v, times = 0;
bool edges[101][101];
int visited[101];
int times_when_found[101];
std::vector<Edge> container;

void note(int u, int v, std::string type) {
    for (int i = 0; i < m; i++)
        if (container[i].from == u && container[i].to == v) {
            container[i].type = type;
            break;
        }
}

void dfs(int node) {
    times++;
    for (int i = 1; i <= n; i++)
        if (edges[node][i]) {
            if (!visited[i]) {
                times_when_found[i] = times;
                visited[i] = 1;
                note(node, i, "Tree");
                dfs(i);
            } else if (visited[i] == 1)
                note(node, i, "Back");
            else if (times_when_found[node] < times_when_found[i])
                note(node, i, "Down");
        }
    visited[node] = 2;
    times++;
}

void query_edge(int u, int v) {
    for (int i = 0; i < m; i++)
        if (container[i].from == u && container[i].to == v) {
            printf("edge (%d,%d) is ", u, v), std::cout << container[i].type << " Edge" << std::endl;
            break;
        }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d%d", &u, &v), edges[u][v] = true, container.push_back(Edge(u, v));
    for (int i = 1; i <= n; i++)
        if (!visited[i]) times_when_found[i] = times, visited[i] = 1, dfs(i);
    scanf("%d", &k);
    while (k--) scanf("%d%d", &u, &v), query_edge(u, v);
    return 0;
}

