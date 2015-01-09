/*************************************************************************
	> File Name: 1002.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, January 09, 2015 PM07:42:09 CST
 ************************************************************************/

#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

int n, m;
int indegree[100100];
std::vector<int> edge[100100];

void topo_and_output() {
    std::priority_queue<int, std::vector<int>, std::greater<int> > q;
    for (int i = 1; i <= n; i++)
        if (!indegree[i]) q.push(i);
    while (!q.empty()) {
        int temp = q.top();
        printf("%d ", temp);
        q.pop();
        for (int i = 0; i < edge[temp].size(); i++) {
            indegree[edge[temp][i]]--;
            if (!indegree[edge[temp][i]]) q.push(edge[temp][i]);
        }
    }
    printf("\n");
}

int main() {
    int t, before, after;
    scanf("%d", &t);
    while (t--) {
        memset(indegree, 0, sizeof(indegree));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) edge[i].clear();
        for (int i = 0; i < m; i++) scanf("%d%d", &before, &after), edge[before].push_back(after), indegree[after]++;
        topo_and_output();
    }
    return 0;
}

