#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int count = 0;
        int container[1000];
        for (int i = 0; i < n; i++) {
            scanf("%d", &container[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            int min = container[i];
            int index = i;
            for (int j = i + 1; j < n; j++) {
                if (container[j] < min) {
                    index = j;
                    min = container[j];
                }
            }
            if (index != i) {
                container[i] ^= container[index];
                container[index] ^= container[i];
                container[i] ^= container[index];
            }
            for (int k = 0; k < n - 1; k++) {
                printf("%d ", container[k]);
            }
            printf("%d\n", container[n - 1]);
        }
    }
}

