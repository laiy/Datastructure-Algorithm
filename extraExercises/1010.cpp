#include <stdio.h>

int container[100];
int n;

void print() {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", container[i]);
    }
    printf("%d \n", container[n - 1]);
}

void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

void Insertsort(int a[], int n) {  
    int i, j;
    for (i = 1; i < n; i++) {
        bool has_swapped = false;
        for (j = i - 1; j >= 0 && a[j] > a[j + 1]; j--) {
            swap(a[j], a[j + 1]);
            has_swapped = true;
        }
        if (has_swapped) print();
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &container[i]);
    }
    scanf("%d", &container[n - 1]);
    print();
    Insertsort(container, n);
    return 0;
}

