#include <cstdio>

inline bool match(int num) {
    int temp = num;
    int sum_10 = 0, sum_12 = 0, sum_16 = 0;
    while (temp)
        sum_10 += temp % 10, temp /= 10;
    temp = num;
    while (temp)
        sum_12 += temp % 12, temp /= 12;
    temp = num;
    while (temp)
        sum_16 += temp % 16, temp /= 16;
    return sum_10 == sum_12 && sum_10 == sum_16;
}

int main() {
    for (int i = 1000; i < 10000; i++)
        if (match(i))
            printf("%d\n", i);
    return 0;
}

