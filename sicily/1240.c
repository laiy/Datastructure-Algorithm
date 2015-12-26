#include <cstdio>

#define FILTER(n) (n < 4 ? n : n - 1)

int main() {
    int n, temp, base;
    while (scanf("%d", &n) && n) {
        printf("%d: ", n);
        temp = 0;
        base = 1;
        while (n)
            temp += FILTER(n % 10) * base, base *= 9, n /= 10;
        printf("%d\n", temp);
    }
    return 0;
}

