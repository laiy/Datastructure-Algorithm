#include <cstdio>
#include <cstring>

bool is_prime[1299710];

void init() {
    int i, j;
    memset(is_prime, 1, sizeof(is_prime));
    for (i = 2; i <= 1141; i++)
        if (is_prime[i])
            for (j = i + i; j <= 1299709; j += i)
                is_prime[j] = false;
}

int main() {
    init();
    int n, gap_count, i;
    while (scanf("%d", &n) && n) {
        if (is_prime[n])
            printf("0\n");
        else {
            gap_count = 2;
            for (i = n - 1; !is_prime[i]; i--)
                gap_count++;
            for (i = n + 1; !is_prime[i]; i++)
                gap_count++;
            printf("%d\n", gap_count);
        }
    }
    return 0;
}

