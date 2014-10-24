#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        int a;
        scanf("%d%d", &n, &m);
        bool b[80000];
        memset(b, false, sizeof(b));
        for (int i = 0; i < n * n; i++) {
            scanf("%d", &a);
            b[a] = true;
        }
        while (m--) {
            int temp;
            scanf("%d", &temp);
            if (b[temp]) {
                printf("true\n");
            } else {
                printf("false\n");
            }
        }
    }
    return 0;
}

