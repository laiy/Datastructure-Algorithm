#include <cstdio>
#include <algorithm>
#include <deque>

struct HUFFMAN_TREE_NODE {
    int weight, code_length;
    HUFFMAN_TREE_NODE *left, *right;
};

int n;

std::deque<HUFFMAN_TREE_NODE*> forest;

int cmp(HUFFMAN_TREE_NODE *a, HUFFMAN_TREE_NODE *b) {
    return a->weight < b->weight;
}

void create_huffman_tree() {
    for (int i = 0; i < n - 1; i++) {
        std::sort(forest.begin(), forest.end(), cmp);
        HUFFMAN_TREE_NODE *new_node = new HUFFMAN_TREE_NODE;
        new_node->weight = forest[0]->weight + forest[1]->weight;
        new_node->left = forest[0];
        new_node->right = forest[1];
        forest.pop_front();
        forest.pop_front();
        forest.push_back(new_node);
    }
}

void search_tree(HUFFMAN_TREE_NODE* node) {
    int counter = 0;
    std::deque<HUFFMAN_TREE_NODE*> q;
    node->code_length = 0;
    q.push_back(node);
    while (!q.empty()) {
        HUFFMAN_TREE_NODE *temp = q.front();
        q.pop_front();
        if (temp->left == NULL && temp->right == NULL) {
            counter += temp->code_length * temp->weight;
        } else {
            if (temp->left != NULL) {
                temp->left->code_length = temp->code_length + 1;
                q.push_back(temp->left);
            }
            if (temp->right != NULL) {
                temp->right->code_length = temp->code_length + 1;
                q.push_back(temp->right);
            }
        }
    }
    printf("%d\n", counter);
}

int main() {
    int weight;
    char c[2];
    scanf("%d", &n);
    if (!n) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%s%d", c, &weight);
        HUFFMAN_TREE_NODE *new_node = new HUFFMAN_TREE_NODE;
        new_node->weight = weight;
        new_node->left = new_node->right = NULL;
        forest.push_back(new_node);
    }
    create_huffman_tree();
    search_tree(forest.front());
    return 0;
}

