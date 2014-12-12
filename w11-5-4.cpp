/*************************************************************************
	> File Name: w11-5-4.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, December 12, 2014 PM05:03:43 CST
 ************************************************************************/

#ifndef NODE
#define NODE

template <class Entry>
struct Node {
    Entry entry;
    Node<Entry> *left;
    Node<Entry> *right;
    Node(const Entry &en) {
        entry = en;
        left = NULL;
        right = NULL;
    }
};

#endif

template <class Entry>
Node<Entry>* BSTree_search(Node<Entry> *root, Entry &target) {
    while (root != NULL && root->entry != target)
        root = root->entry < target ? root->right : root->left;
    return root;
}

template <class Entry>
void BSTree_insert(Node<Entry> *&root, const Entry &target) {
    if (root == NULL)
        root = new Node<Entry>(target);
    else if (target < root->entry)
        BSTree_insert(root->left, target);
    else if (target > root->entry)
        BSTree_insert(root->right, target);
    else
        return;
}

template <class Entry>
void remove_root(Node<Entry> *&root) {
    if (root == NULL) return;
    Node<Entry> *to_delete = root;
    if (root->right == NULL)
        root = root->left;
    else if (root->left == NULL)
        root = root->right;
    else {
        to_delete = root->left;
        Node<Entry> *parent = root;
        while (to_delete->right != NULL) {
            parent = to_delete;
            to_delete = to_delete->right;
        }
        root->entry = to_delete->entry;
        if (parent == root) root->left = to_delete->left;
        else parent->right = to_delete->left;
    }
    delete to_delete;
}

template <class Entry>
void BSTree_remove(Node<Entry> *&root, const Entry &target) {
    //if (root == NULL) return;
    //while (root->entry != target) {
        //root = root->entry < target ? root->right : root->left;
        //if (root == NULL) return;
    //}
    //remove_root(root);
    if (root == NULL || root->entry == target)
        return remove_root(root);
    else if (target < root->entry)
        return BSTree_remove(root->left, target);
    else
        return BSTree_remove(root->right, target);
}

