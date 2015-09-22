/*************************************************************************
	> File Name: w11-5-2.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, December 12, 2014 PM05:00:23 CST
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
void inorder(Node<Entry> *root, void (*visit)(Entry &)) {
    if (root == NULL) return;
    inorder(root->left, visit);
    visit(root->entry);
    inorder(root->right, visit);
}
