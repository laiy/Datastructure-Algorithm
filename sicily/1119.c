#include <cstdio>
#include <cmath>

int main() {
    int year, bits, n;
    double threshold, sum;
    while (scanf("%d", &year) && year) {
        bits = pow(2, (year - 1960) / 10 + 2);
        threshold = bits * log(2);
        sum = 0, n = 1;
        while (sum <= threshold)
            sum += log(n++);
        printf("%d\n", n - 2);
    }
    return 0;
}

