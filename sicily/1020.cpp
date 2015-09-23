#include <cstring>
#include <cstdio>

int big_number[401];
int length, result, j;

int getResult(int b) {
    result = 0;
    for (j = 0; j < length; j++) {
        result = (result * 10 + big_number[j]) % b;
    }
    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        static int n, b[100], i;
        static char x[401];
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", b + i);
        scanf("%s", x);
        length = strlen(x);
        for (i = 0; i < length; i++)
            big_number[i] = x[i] - '0';
        printf("(%d", getResult(b[0]));
        for (i = 1; i < n; i++) {
            printf(",%d", getResult(b[i]));
        }
        printf(")\n");
    }
    return 0;
}

