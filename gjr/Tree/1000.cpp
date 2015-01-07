/*************************************************************************
	> File Name: 1000.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Wednesday, January 07, 2015 AM10:36:11 CST
 ************************************************************************/

#include <cstdio>

struct AVL_Node {
    int element;
    int balance;
    AVL_Node *left, *right;
    AVL_Node(int element) {
        this->element = element;
        this->balance = 0;
        this->left = this->right = NULL;
    }
};

void rotate_left(AVL_Node *&sub_root) {
    AVL_Node *right_tree = sub_root->right;
    sub_root->right = right_tree->left;
    right_tree->left = sub_root;
    sub_root = right_tree;
}

void rotate_right(AVL_Node *&sub_root) {
    AVL_Node *left_tree = sub_root->left;
    sub_root->left = left_tree->right;
    left_tree->right = sub_root;
    sub_root = left_tree;
}

void right_balance(AVL_Node *&sub_root) {
    AVL_Node *&right_tree = sub_root->right;
    switch (right_tree->balance) {
        case 1:
            sub_root->balance = right_tree->balance = 0;
            rotate_left(sub_root);
            break;
        case -1:
            AVL_Node* sub_tree = right_tree->left;
            switch(sub_tree->balance) {
                case 0:
                    sub_root->balance = right_tree->balance = 0;
                    break;
                case -1:
                    sub_root->balance = 0;
                    right_tree->balance = 1;
                    break;
                case 1:
                    sub_root->balance = -1;
                    right_tree->balance = 0;
            }
            sub_tree->balance = 0;
            rotate_right(right_tree);
            rotate_left(sub_root);
            break;
    }
}

void left_balance(AVL_Node *&sub_root) {
    AVL_Node *&left_tree = sub_root->left;
    switch (left_tree->balance) {
        case -1:
            sub_root->balance = left_tree->balance = 0;
            rotate_right(sub_root);
            break;
        case 1:
            AVL_Node* sub_tree = left_tree->right;
            switch(sub_tree->balance) {
                case 0:
                    sub_root->balance = left_tree->balance = 0;
                    break;
                case 1:
                    sub_root->balance = 0;
                    left_tree->balance = -1;
                    break;
                case -1:
                    sub_root->balance = 1;
                    left_tree->balance = 0;
                    break;
            }
            sub_tree->balance = 0;
            rotate_left(left_tree);
            rotate_right(sub_root);
            break;
    }
}

void insert(AVL_Node *&sub_root, int &data, bool &taller) {
    if (sub_root == NULL) sub_root = new AVL_Node(data), taller = true;
    else if (data <= sub_root->element) {
        insert(sub_root->left, data, taller);
        if (taller) {
            switch (sub_root->balance) {
                case -1:
                    left_balance(sub_root), taller = false;
                    break;
                case 0:
                    sub_root->balance = -1;
                    break;
                case 1:
                    sub_root->balance = 0, taller = false;
                    break;
            }
        }
    } else {
        insert(sub_root->right, data, taller);
        if (taller) {
            switch (sub_root->balance) {
                case -1:
                    sub_root->balance = 0, taller = false;
                    break;
                case 0:
                    sub_root->balance = 1;
                    break;
                case 1:
                    right_balance(sub_root), taller = false;
                    break;
            }
        }
    }
}

void pre_order_search(AVL_Node *&root) {
    if (root == NULL) return;
    printf("%d ", root->element);
    pre_order_search(root->left);
    pre_order_search(root->right);
}

void delete_tree(AVL_Node *&root) {
    if (root == NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

int main() {
    int t, n, temp;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        bool taller = true;
        AVL_Node *root = NULL;
        while (n--) scanf("%d", &temp), insert(root, temp, taller);
        pre_order_search(root);
        printf("\n");
        delete_tree(root);
    }
    return 0;
}

