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
    
}

template <class Entry>
void AVL_insert(AvlNode<Entry> *&root, const Entry entry);

