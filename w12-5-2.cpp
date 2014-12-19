/*************************************************************************
	> File Name: w12-5-2.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, December 19, 2014 PM07:30:43 CST
 ************************************************************************/

#include<cmath>
#include<algorithm>
#ifndef AVL_NODE
#define AVL_NODE

template <class Entry>
struct AvlNode {
    Entry entry;
    AvlNode<Entry> *left;
    AvlNode<Entry> *right;
    int bf;
};

#endif

template<class Entry>
int height(AvlNode<Entry> *&root) {
    return root ? 1 + max(height(root->left), height(root->right)) : 0;
}

template<class Entry>
bool is_AVL_Tree(AvlNode<Entry> *&root) {
    if (root == NULL) return true;
    return is_AVL_Tree(root->left) && is_AVL_Tree(root->right) && abs(height(root->left) - height(root->right)) <= 1;
}

