/*************************************************************************
	> File Name: 1006.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Thursday, January 08, 2015 AM09:25:19 CST
 ************************************************************************/

#include <stack>

// root is a pointer to the root of the binary tree.
template <typename T>
void inorder_recursive(BinaryNode<T>* root, void (*visit)(T &x)) {
    if (root == NULL) return;
    inorder_recursive(root->left, visit);
    visit(root->elem);
    inorder_recursive(root->right, visit);
}
 
// root is a pointer to the root of the binary tree.
template <typename T>
void inorder(BinaryNode<T>* root, void (*visit)(T &x)) {
    std::stack< BinaryNode<T>* > container;
    while (!container.empty() || root != NULL) {
        if (root == NULL) {
            root = container.top();
            visit(root->elem);
            container.pop();
            root = root->right;
        } else {
            container.push(root);
            root = root->left;
        }
    }
}
