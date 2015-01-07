/*************************************************************************
	> File Name: 1003.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Wednesday, January 07, 2015 PM08:23:42 CST
 ************************************************************************/

#include <cstdio>
#include <vector>
#include <cstring>

struct Node {
    char character;
    int left, right;
    Node(char c, int l, int r) {
        character = c;
        left = l;
        right = r;
    }
};

bool visited[1001];
std::vector<Node> nodes[1001];

int find_root() {
    for (int i = 0; i < 1001; i++)
        if (!nodes[i].empty())
            if (!visited[i]) return i;
}

void pre_order_search(int node) {
    if (node == 0) return;
    printf("%c", nodes[node][0].character);
    pre_order_search(nodes[node][0].left);
    pre_order_search(nodes[node][0].right);
}


int main() {
    int n, index, left, right;
    char c;
    while (scanf("%d", &n) != EOF) {
        memset(visited, false, sizeof(visited));
        while (n--) {
            scanf("%d %c %d %d", &index, &c, &left, &right);
            nodes[index].push_back(Node(c, left, right));
            visited[left] = visited[right] = true;
        }
        pre_order_search(find_root());
        printf("\n");
        for (int i = 0; i < 1001; i++)
            if (!nodes[i].empty())
                nodes[i].clear();
    }
    return 0;
}

