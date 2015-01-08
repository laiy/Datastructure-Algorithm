/*************************************************************************
	> File Name: 1005.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Thursday, January 08, 2015 AM09:13:55 CST
 ************************************************************************/

#include <queue>

template <typename T>
void levelTraversal(BinaryNode<T>* root, void (*visit)(T &x)) {
    if (root == NULL) return;
    std::queue< BinaryNode<T>* > container;
    container.push(root);
    while (!container.empty()) {
        BinaryNode<T> *temp = container.front();
        container.pop();
        visit(temp->elem);
        if (temp->left) container.push(temp->left);
        if (temp->right) container.push(temp->right);
    }
}

