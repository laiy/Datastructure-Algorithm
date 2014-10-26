#include <stdio.h>

int list[100];

void print(int index, int m) {
    if (index > m) return;
    int i;
    for (i = 0; i <= index - 1; i++) {
        printf("%d", list[i]);
    }
    for (i = index; i < m; i++) {
        printf("0");
    }
    printf("\n");
}

void split(int n, int index, int m) {
    int i;
    if (n == 0) {
        print(index, m);
    } else {
        for (i = n; i >= 1; i--) {
            if (index == 0 || i <= list[index - 1]) {
                list[index] = i;
                split(n - i, index + 1, m);
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        split(n, 0, m);
    }
    return 0;
}

