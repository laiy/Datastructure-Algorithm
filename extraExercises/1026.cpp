#include <stdio.h>

int m;

struct Binary_Search_Tree_Node {
    int data;
    Binary_Search_Tree_Node *parent, *left, *right;
};

void pre_order_search(Binary_Search_Tree_Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    pre_order_search(node->left);
    pre_order_search(node->right);
}

void in_order_search(Binary_Search_Tree_Node* node) {
    if (node == NULL) return;
    in_order_search(node->left);
    printf("%d ", node->data);
    in_order_search(node->right);
}

void insert(Binary_Search_Tree_Node* root, Binary_Search_Tree_Node* new_node) {
    Binary_Search_Tree_Node *temp_parent = NULL, *temp_location = root;
    while (temp_location != NULL) {
        temp_parent = temp_location;
        if (new_node->data < temp_location->data) {
            temp_location = temp_location->left;
        } else {
            temp_location = temp_location->right;
        }
    }
    new_node->parent = temp_parent;
    if (new_node->data < temp_parent->data) {
        temp_parent->left = new_node;
    } else {
        temp_parent->right = new_node;
    }
}

int main() {
    while (scanf("%d", &m)) {
        if (!m) break;
        int temp;
        scanf("%d", &temp);
        Binary_Search_Tree_Node* root = new Binary_Search_Tree_Node;
        root->data = temp;
        root->left = root->right = root->parent = NULL;
        for (int i = 0; i < m - 1; i++) {
            scanf("%d", &temp);
            Binary_Search_Tree_Node* new_node = new Binary_Search_Tree_Node;
            new_node->data = temp;
            new_node->left = new_node->right = new_node->parent = NULL;
            insert(root, new_node);
        }
        in_order_search(root);
        printf("\n");
        pre_order_search(root);
        printf("\n");
    }
    return 0;
}

