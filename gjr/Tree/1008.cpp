/*************************************************************************
	> File Name: 1008.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Thursday, January 08, 2015 PM12:46:35 CST
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
#include <string>
#include <iostream>

struct Huffman_Tree_Node {
    char character;
    int weight;
    std::string HUFFMAN_CODE;
    Huffman_Tree_Node *left, *right;
    Huffman_Tree_Node() {}
    Huffman_Tree_Node(char c, int w) {
        character = c;
        weight = w;
        left = right = NULL;
    }
    bool operator<(const Huffman_Tree_Node &another) const {
        return weight < another.weight;
    }
    bool is_leaf() {
        return !left && !right;
    }
};

int appear_times[26];
std::deque<Huffman_Tree_Node> container;
int ans;

void build_tree() {
    for (int i = 0; i < 26; i++)
        if (appear_times[i]) container.push_back(Huffman_Tree_Node(char('A' + i), appear_times[i]));
    int temp = container.size();
    for (int i = 0; i < temp - 1; i++) {
        std::sort(container.begin(), container.end());
        Huffman_Tree_Node *new_node = new Huffman_Tree_Node;
        new_node->left = &container[0];
        new_node->right = &container[1];
        new_node->weight = container[0].weight + container[1].weight;
        container.pop_front();
        container.pop_front();
        container.push_back(*new_node);
    }
}

void DFS(Huffman_Tree_Node *node, std::string current_huffman_code) {
    if (node->is_leaf()) node->HUFFMAN_CODE = current_huffman_code;
    else {
        DFS(node->right, current_huffman_code + "1");
        DFS(node->left, current_huffman_code + "0");
    }
}

void BFS() {
    std::deque<Huffman_Tree_Node*> queue;
    queue.push_back(&container[0]);
    while (!queue.empty()) {
        Huffman_Tree_Node *temp = queue.front();
        queue.pop_front();
        if (temp->is_leaf()) ans += temp->weight * temp->HUFFMAN_CODE.length();
        if (temp->right) queue.push_back(temp->right);
        if (temp->left) queue.push_back(temp->left);
    }
}

int main() {
    int n;
    char temp;
    scanf("%d", &n);
    memset(appear_times, 0, sizeof(appear_times));
    while (n--) getchar(), scanf("%c", &temp), appear_times[temp - 'A']++;
    build_tree();
    DFS(&container[0], "");
    ans = 0;
    BFS();
    printf("%d\n", ans);
    container.clear();
    return 0;
}
