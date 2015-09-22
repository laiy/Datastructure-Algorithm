#include <stdio.h>

int list[100];

void print(int index) {
    int i;
    for (i = 0; i <= index - 2; i++) {
        printf("%d+", list[i]);
    }
    printf("%d\n", list[index - 1]);
}

void split(int n, int index = 0) {
    int i;
    if (!n) {
        print(index);
    } else {
        for (i = n; i >= 1; i--) {
            if (index == 0 || i <= list[index - 1]) {
                list[index] = i;
                split(n - i, index + 1);
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        split(n);
    }
    return 0;
}

