#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    long long m, n, record;
    long long max, temp;
    while (t--) {
        scanf("%lld", &m);
        scanf("%lld", &n);
        scanf("%lld", &max);
        for (long long i = 0; i < m - 1; i++) {
            scanf("%lld", &temp);
            max = (temp > max) ? temp : max;
        }
        for (long long i = 0; i < n; i++) {
            scanf("%lld", &temp);
            if (temp == max) {
                record = i;
            }
        }
        printf("%lld\n", record * 50);
    }
    return 0;
}

