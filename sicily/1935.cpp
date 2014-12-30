/*************************************************************************
	> File Name: 1935.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Monday, December 29, 2014 PM03:20:35 CST
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <queue>

std::string pre_order, in_order;

struct Binary_Node {
    char character;
    Binary_Node *left, *right;
};

Binary_Node* build_tree(std::string pre_order_string, std::string in_order_string) {
    if (pre_order_string.length() == 0) return NULL;
    Binary_Node *node = new Binary_Node;
    node->character = pre_order_string[0];
    int index = in_order_string.find(node->character);
    std::string in_left = in_order_string.substr(0, index);
    std::string in_right = in_order_string.substr(index + 1, in_order_string.length());
    node->left = build_tree(pre_order_string.substr(1, in_left.length()), in_left);
    node->right = build_tree(pre_order_string.substr(1 + in_left.length(), pre_order_string.length()), in_right);
    return node;
}

void output(Binary_Node *root) {
    std::queue<Binary_Node*> container;
    container.push(root);
    while (!container.empty()) {
        Binary_Node *temp = container.front();
        printf("%c", temp->character);
        container.pop();
        if (temp->left) container.push(temp->left);
        if (temp->right) container.push(temp->right);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        std::cin >> pre_order >> in_order;
        Binary_Node *root = build_tree(pre_order, in_order);
        output(root);
    }
    return 0;
}

