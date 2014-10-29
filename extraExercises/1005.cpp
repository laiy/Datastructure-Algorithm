#include <stdio.h>
#include <iostream>
#include <iomanip>

struct Node {
    int index, data;
} container[1000];

void QuickSort(Node a[], int numsize) {
    int i = 0, j = numsize - 1;
    Node val = a[0];
    if (numsize > 1) {
        while (i < j) {
            for (; j > i; j--) {
                if (a[j].data == val.data) {
                    if (a[j].index < val.index) {
                        a[i++] = a[j];
                        break;
                    }
                }
                if (a[j].data < val.data) {
                    a[i++] = a[j];
                    break;
                }
            }
            for (; i < j; i++) {
                if (a[i].data == val.data) {
                    if (a[i].index > val.index) {
                        a[j--] = a[i];
                        break;
                    }
                }
                if (a[i].data > val.data) {
                    a[j--] = a[i];
                    break;
                }
            }
        }
        a[i] = val;
        QuickSort(a, i);
        QuickSort(a + i + 1, numsize - i - 1);
    }
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
    QuickSort(container, n);
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", container[i].index);
        sum += container[i].data * (n - i - 1);
    }
    printf("%d\n", container[n - 1].index);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << sum / n << std::endl;
    return 0;
}

