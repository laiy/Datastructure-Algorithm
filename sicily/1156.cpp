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
std::vector<Binary_Node> container;

int find_root() {
    for (int i = 1; i <= n; i++)
        if (!parent[identitys[i]]) return identitys[i];
    return 0;
}

void output(int node) {
    if (!node) return;
    int temp;
    for (int i = 0; (size_t)i < container.size(); i++)
        if (container[i].identity == node)
            temp = i;
    printf("%c", container[temp].character);
    output(container[temp].left);
    output(container[temp].right);
    if (node == root) printf("\n");
}

void clear() {
    container.clear();
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
            container.push_back(*node);
        }
        root = find_root();
        output(root);
        clear();
    }
    return 0;
}

