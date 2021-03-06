#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int ly[30];
        for (int i = 0; i < 30; i++) {
            ly[i] = 0;
        }
        ly[1] = 1;
        int step = 1;
        int count = 0;
        for (int i = 1; i < n; i++) {
            count = 0;
            while (count != i + 1) {
                if (step == n) {
                    step = 0;
                }
                if (!ly[step + 1]) {
                    count++;
                }
                step++;
            }
            ly[step] = i + 1;
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", ly[i]);
        }
        printf("\n");
    }
    return 0;
}

