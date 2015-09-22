#include <cstdio>

int generator(int n) {
    int temp = n, count = 0;
    while (temp) {
        temp /= 10;
        count++;
    }
    int number = n - count * 10;
    while (number < n) {
        int sum = number;
        int tmp = number;
        while(tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == n) return number;
        number++;
    }
    return 0;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", generator(n));
    }
}

