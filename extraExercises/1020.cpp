#include <stdio.h>

int container[10000];
int n;
int ans = 0;

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
        if (has_swapped) {
            ans += 5;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &container[i]);
        }
        Insertsort(container, n);
        printf("%d\n", ans);
    }
    return 0;
}
