#include <cstdio>
#include <cstdlib>

int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int main() {
    int t, n;
    int temp[20];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp[i]);
        }
        qsort(temp, n, sizeof(int), cmp);
        printf("%d\n", (temp[0] - temp[n - 1]) * 2);
    }
    return 0;
}

