/*************************************************************************
	> File Name: w11-5-3.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, December 12, 2014 PM05:01:35 CST
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
void postorder(Node<Entry> *root, void (*visit)(Entry &)) {
    if (root == NULL) return;
    postorder(root->left, visit);
    postorder(root->right, visit);
    visit(root->entry);
}

