#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iomanip>

struct Node {
    int index, data;
} container[1000];

int cmp(const void *a, const void *b) {
    return ((Node*)a)->data - ((Node*)b)->data;
}

int main() {
    int n, temp, count = 0;
    scanf("%d", &n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        Node* p = new Node;
        p->index = i + 1;
        p->data = temp;
        container[count++] = *p;
    }
    std::qsort(container, n, sizeof(Node), cmp);
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", container[i].index);
        sum += container[i].data * (n - i - 1);
    }
    printf("%d\n", container[n - 1].index);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << sum / n << std::endl;
    return 0;
}

