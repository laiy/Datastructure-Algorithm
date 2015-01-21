#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

struct Node {
    int index, data;
};

std::vector<Node*> container;

bool cmp(const Node *a, const Node *b) {
    if (a->data == b->data) return a->index < b->index;
    return a->data < b->data;
}

int main() {
    int n, temp;
    scanf("%d", &n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        Node* p = new Node;
        p->index = i + 1;
        p->data = temp;
        container.push_back(p);
    }
    std::sort(container.begin(), container.end(), cmp);
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", container[i]->index);
        sum += container[i]->data * (n - i - 1);
    }
    printf("%d\n", container[n - 1]->index);
    printf("%.2f\n", sum / n);
    return 0;
}

