#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

struct HUFFMAN_TREE_NODE {
    int weight, code_length;
    HUFFMAN_TREE_NODE *left, *right;
};

std::vector<HUFFMAN_TREE_NODE> container;

int cmp(HUFFMAN_TREE_NODE a, HUFFMAN_TREE_NODE b) {
    return a.weight < b.weight;
}

void create_huffman_tree() {
    while (container.size() != 1) {
        HUFFMAN_TREE_NODE *new_node = new HUFFMAN_TREE_NODE;
        std::vector<HUFFMAN_TREE_NODE>::iterator it = container.begin();
        new_node->weight = container[0].weight + container[1].weight;
        new_node->left = &container[0];
        new_node->right = &container[1];
        container.erase(it + 1);
        container.erase(it);
        container.insert(container.begin(), *new_node);
    }
}

void search_tree(HUFFMAN_TREE_NODE* node) {
    int counter = 0;
    std::queue<HUFFMAN_TREE_NODE*> q;
    node->code_length = 0;
    q.push(node);
    while (!q.empty()) {
        HUFFMAN_TREE_NODE *temp = q.front();
        q.pop();
        if (temp->left == NULL && temp->right == NULL) {
            counter += temp->code_length * temp->weight;
        } else {
            if (temp->left != NULL) {
                temp->left->code_length = temp->code_length + 1;
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                temp->right->code_length = temp->code_length + 1;
                q.push(temp->right);
            }
        }
    }
    printf("%d\n", counter);
}

int main() {
    int n, weight;
    char c[2];
    scanf("%d", &n);
    if (!n) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%s%d", c, &weight);
        HUFFMAN_TREE_NODE *new_node = new HUFFMAN_TREE_NODE;
        new_node->weight = weight;
        new_node->left = new_node->right = NULL;
        container.push_back(*new_node);
    }
    std::sort(container.begin(), container.end(), cmp);
    create_huffman_tree();
    search_tree(&container[0]);
    return 0;
}

