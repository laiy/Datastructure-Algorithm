/*************************************************************************
	> File Name: w12-5-1.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, December 19, 2014 PM07:30:30 CST
 ************************************************************************/

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

template <class Entry>
AvlNode<Entry> *AVL_search(AvlNode<Entry> *&root, const Entry entry) {
    if (root == NULL) return NULL;
    if (root->entry == entry) return root;
    AvlNode<Entry> *search_left_tree = AVL_search(root->left, entry), *search_right_tree = AVL_search(root->right, entry);
    if (search_left_tree != NULL) return search_left_tree;
    if (search_right_tree != NULL) return search_right_tree;
    return NULL;
}

template <class Entry>
void rotate_left(AvlNode<Entry> *&root) {
    AvlNode<Entry> *right_tree = root->right;
    root->right = right_tree->left;
    right_tree->left = root;
    root = right_tree;
}

template <class Entry>
void rotate_right(AvlNode<Entry> *&root) {
    AvlNode<Entry> *left_tree = root->left;
    root->left = left_tree->right;
    left_tree->right = root;
    root = left_tree;
}

template <class Entry>
void right_balance(AvlNode<Entry> *&root) {
    AvlNode<Entry> *&right_tree = root->right;
    switch (right_tree->bf) {
        case -1:
            root->bf = 0;
            right_tree->bf = 0;
            rotate_left(root);
            break;
        case 1:
            AvlNode<Entry> *sub_tree = right_tree->left;
            switch (sub_tree->bf) {
                case 0:
                    root->bf = 0;
                    right_tree->bf = 0;
                    break;
                case 1:
                    root->bf = 0;
                    right_tree->bf = -1;
                    break;
                case -1:
                    root->bf = 1;
                    right_tree->bf = 0;
                    break;
            }
            sub_tree->bf = 0;
            rotate_right(right_tree);
            rotate_left(root);
            break;
    }
}

template <class Entry>
void left_balance(AvlNode<Entry> *&root) {
    AvlNode<Entry> *&left_tree = root->left;
    switch (left_tree->bf) {
        case 1:
            root->bf = 0;
            left_tree->bf = 0;
            rotate_right(root);
            break;
        case -1:
            AvlNode<Entry> *sub_tree = left_tree->right;
            switch (sub_tree->bf) {
                case 0:
                    root->bf = 0;
                    left_tree->bf = 0;
                    break;
                case -1:
                    root->bf = 0;
                    left_tree->bf = 1;
                    break;
                case 1:
                    root->bf = -1;
                    left_tree->bf = 0;
                    break;
            }
            sub_tree->bf = 0;
            rotate_left(left_tree);
            rotate_right(root);
            break;
    }
}

template <class Entry>
void insert(AvlNode<Entry> *&root, const Entry entry, bool &taller) {
    if (root == NULL) {
        root = new AvlNode<Entry>;
        root->entry = entry;
        root->left = root->right = NULL;
        root->bf = 0;
        taller = true;
        return;
    } else if (root->entry == entry) return;
    else if (entry < root->entry) {
        insert(root->left, entry, taller);
        if (taller)
            switch (root->bf) {
                case 1:
                    left_balance(root);
                    taller = false;
                    break;
                case 0:
                    root->bf = 1;
                    break;
                case -1:
                    root->bf = 0;
                    taller = false;
                    break;
            }
    } else {
        insert(root->right, entry, taller);
        if (taller)
            switch (root->bf) {
                case 1:
                    root->bf = 0;
                    taller = false;
                    break;
                case 0:
                    root->bf = -1;
                    break;
                case -1:
                    right_balance(root);
                    taller = false;
                    break;
            }
    }
}

template <class Entry>
void AVL_insert(AvlNode<Entry> *&root, const Entry entry) {
    bool taller = false;
    insert(root, entry, taller);
}

