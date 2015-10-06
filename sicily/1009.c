#include <cstdio>
#include <math.h>

bool is_prime(long long a) {
    for (long long i = 2; i * i <= a; i++)
        if (a % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 11; i <= n && i <= 59; i++) {
        if (is_prime(i)) {
            long long x = (long long)pow(2, i) - 1;
            long long number = x;
            bool first_print = true, found = false;
            for (long long j = 2; j * j <= x; j++) {
                if (x % j == 0) {
                    x = x / j;
                    if (first_print) {
                        found = true;
                        first_print = false;
                        printf("%lld ", j);
                    } else {
                        printf("* %lld ", j);
                    }
                }
            }
            if (found)
                printf("* %lld = %lld = ( 2 ^ %d ) - 1\n", x, number, i);
        }
    }
    return 0;
}

