/*************************************************************************
	> File Name: w11-5-1.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, December 12, 2014 PM04:52:42 CST
 ************************************************************************/

#ifndef NODE
#define NODE

template <class Entry>

struct Node {
    Entry entry;
    Node<Entry> *left;
    Node<Entry> *right;
};

#endif

template <class Entry>
void preorder(Node<Entry> *root, void (*visit)(Entry &)) {
    if (root == NULL) return;
    visit(root->entry);
    preorder(root->left, visit);
    preorder(root->right, visit);
}

