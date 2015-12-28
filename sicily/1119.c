#include <cstdio>
#include <cmath>
#include <hash_map>

int main() {
    int year, n;
    double threshold, sum, log2 = log(2);
    __gnu_cxx::hash_map<int, int> table;
    double sum_table[254019];
    sum = 0;
    for (n = 1; n <= 254018; n++)
        sum += log(n), sum_table[n] = sum;
    n = 3;
    for (year = 1960; year <= 2160; year += 10) {
        threshold = pow(2, year / 10 - 194) * log2;
        while (sum_table[n++] <= threshold)
            ;
        table[year] = n - 2;
    }
    while (scanf("%d", &year) && year)
        printf("%d\n", table[year - year % 10]);
    return 0;
}

