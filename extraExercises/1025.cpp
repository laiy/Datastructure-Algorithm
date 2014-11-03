#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

std::vector<int> v[101];
int n, m, count = 0;
bool visited[101];
bool searched[101];
std::queue<int> q;

void search() {
    memset(searched, false, sizeof(searched));
    q.push(1);
    while (!q.empty()) {
        memset(visited, false, sizeof(visited));
        int temp = q.front();
        q.pop();
        visited[temp] = true;
        searched[temp] = true;
        std::queue<int> temp_queue;
        temp_queue.push(temp);
        while (!temp_queue.empty()) {
            int x = temp_queue.front();
            temp_queue.pop();
            for (int i = 0; i < v[x].size(); i++) {
                if (visited[v[x][i]]) continue;
                visited[v[x][i]] = true;
                searched[v[x][i]] = true;
                temp_queue.push(v[x][i]);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!searched[i]) {
                q.push(i);
                break;
            }
        }
        count++;
    }
}

int main() {
    int a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    search();
    printf("%d\n", count);
    return 0;
}

