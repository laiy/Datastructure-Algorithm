/*************************************************************************
	> File Name: 1013.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Saturday, December 27, 2014 AM10:45:37 CST
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <vector>

int n, m;
int node_weight[16];
int edge_weight[16][16];
bool visited[16];
int ans[16];

struct circumstance {
    int road[16];
};

std::vector<circumstance> container;
std::vector<double> ratio;

void init_data() {
    container.clear();
    memset(node_weight, 0, sizeof(node_weight));
    memset(edge_weight, 0, sizeof(edge_weight));
    memset(visited, false, sizeof(visited));
    memset(ans, 0, sizeof(ans));
}

void init_weight() {
    for (int i = 1; i <= n; i++)
        scanf("%d", &node_weight[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &edge_weight[i][j]);
}

void find_posible_circumstance(int count) {
    if (count == m) {
        circumstance temp;
        for (int i = 0; i < m; i++) temp.road[i] = ans[i];
        container.push_back(temp);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (i < ans[count - 1]) continue;
        if (!visited[i]) {
            ans[count] = i;
            visited[i] = true;
            find_posible_circumstance(count + 1);
            visited[i] = false;
        }
    }
}

void find_all_posible_circumstances() {
    for (int i = 1; i <= n; i++) {
        visited[i] = true;
        ans[0] = i;
        find_posible_circumstance(1);
    }
}

int prim(int road[]) {
    int v = road[0], min, index;
    int edge_weight_sum = 0;
    int low[16], closest[16];
    for (int i = 0; i < m; i++)
        low[road[i]] = edge_weight[v][road[i]], closest[road[i]] = v;
    for (int i = 1; i < m; i++) {
        min = 1500;
        for (int j = 0; j < m; j++)
            if (low[road[j]] != 0 && low[road[j]] < min)
                min = low[road[j]], index = road[j];
        edge_weight_sum += min;
        low[index] = 0;
        for (int j = 0; j < m; j++)
            if (edge_weight[index][road[j]] != 0 && edge_weight[index][road[j]] < low[road[j]])
                low[road[j]] = edge_weight[index][road[j]], closest[road[j]] = road[index];
    }
    return edge_weight_sum;
}

void count_ratio_for_all_circumstances() {
    for (int i = 0; i < container.size(); i++) {
        int node_weight_sum = 0;
        for (int j = 0; j < m; j++) node_weight_sum += node_weight[container[i].road[j]];
        ratio.push_back((double)prim(container[i].road) / (double)node_weight_sum);
    }
}

void find_min_ratio_and_output() {
    double min = 1500;
    int index;
    for (int i = 0; i < ratio.size(); i++)
        if (ratio[i] < min) min = ratio[i], index = i;
    for (int i = 0; i < m; i++)
        printf("%d ", container[index].road[i]);
    printf("\n");
}

int main() {
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) break;
        init_data();
        init_weight();
        find_all_posible_circumstances();
        count_ratio_for_all_circumstances();
        find_min_ratio_and_output();
    }
    return 0;
}

