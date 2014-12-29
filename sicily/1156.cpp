/*************************************************************************
	> File Name: 1156.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Monday, December 29, 2014 PM03:20:19 CST
 ************************************************************************/

#include <cstdio>
#include <vector>
#include <cstring>

struct Binary_Node {
    int identity;
    char character;
    int left;
    int right;
};

int n;
int root;
int parent[1001];
int identitys[1001];
std::vector<Binary_Node> container[1001];

int find_root() {
    for (int i = 1; i <= n; i++)
        if (!parent[identitys[i]]) return identitys[i];
}

void output(int node) {
    if (!node) return;
    printf("%c", container[node][0].character);
    output(container[node][0].left);
    output(container[node][0].right);
    if (node == root) printf("\n");
}

void clear() {
    for (int i = 1; i <= n; i++) {
        container[identitys[i]].clear();
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        if (!n) continue;
        memset(parent, 0, sizeof(parent));
        for (int i = 1; i <= n; i++) {
            Binary_Node *node = new Binary_Node;
            scanf("%d %c %d %d", &node->identity, &node->character, &node->left, &node->right);
            identitys[i] = node->identity;
            if (node->left) parent[node->left] = node->identity;
            if (node->right) parent[node->right] = node->identity;
            container[node->identity].push_back(*node);
        }
        root= find_root();
        output(root);
        clear();
    }
    return 0;
}

