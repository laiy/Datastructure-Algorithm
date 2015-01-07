/*************************************************************************
	> File Name: 1002.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Wednesday, January 07, 2015 PM07:56:20 CST
 ************************************************************************/

#include <cstdio>

struct BST_Node {
    int entry;
    BST_Node *left, *right;
};

void insert(BST_Node *&node, int temp) {
    if (node->entry > temp) {
        if (node->left == NULL) {
            BST_Node *new_node = new BST_Node;
            new_node->left = new_node->right = NULL;
            new_node->entry = temp;
            node->left = new_node;
        } else {
            insert(node->left, temp);
        }
    } else {
        if (node->right == NULL) {
            BST_Node *new_node = new BST_Node;
            new_node->left = new_node->right = NULL;
            new_node->entry = temp;
            node->right = new_node;
        } else {
            insert(node->right, temp);
        }
    }
}

void in_order_search(BST_Node *node) {
    if (node == NULL) return;
    in_order_search(node->left);
    printf("%d ", node->entry);
    in_order_search(node->right);
}

void pre_order_search(BST_Node *node) {
    if (node == NULL) return;
    printf("%d ", node->entry);
    pre_order_search(node->left);
    pre_order_search(node->right);
}

int main() {
    int t, temp;
    while (scanf("%d", &t)) {
        if (!t) break;
        BST_Node *root = new BST_Node;
        scanf("%d", &temp);
        root->left = root->right = NULL;
        root->entry =  temp;
        while (--t) scanf("%d", &temp), insert(root, temp);
        in_order_search(root);
        printf("\n");
        pre_order_search(root);
        printf("\n");
    }
    return 0;
}

