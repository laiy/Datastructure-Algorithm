#include <cstdio>
#include <cmath>

inline long long gcd_extend(int &a, int b, long long *x, long long *y) {
    static long long r, t;
    if (b == 0) {
        *x = 1, *y = 0;
        return a;
    } else {
        r = gcd_extend(b, a % b, x, y);
        t = *x;
        *x = *y;
        *y = t - a / b * *y;
        return r;
    }
}

int main() {
    int passengers;
    int cost_A, passenger_A, cost_B, passenger_B;
    int count = 1;
    long long lower, upper, k, gcd, x, y;
    while (scanf("%d", &passengers) && passengers) {
        scanf("%d %d", &cost_A, &passenger_A);
        scanf("%d %d", &cost_B, &passenger_B);
        gcd = gcd_extend(passenger_A, passenger_B, &x, &y);
        if (passengers % gcd == 0) {
            x *= passengers / gcd;
            y *= passengers / gcd;
            upper = floor((double)y / (passenger_A / gcd));
            lower = ceil((double)-x / (passenger_B / gcd));
            k = passenger_B * cost_A - passenger_A * cost_B <= 0 ? upper : lower;
            printf("Data set %d: %lld aircraft A, %lld aircraft B\n", count++, x + (passenger_B / gcd) * k, y - (passenger_A / gcd) * k);
        } else
            printf("Data set %d: cannot be flown\n", count++);
    }
    return 0;
}

