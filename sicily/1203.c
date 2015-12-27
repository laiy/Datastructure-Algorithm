#include <cstdio>
#include <cstring>

/*
 * a * b % mod
 */
inline long long mul_and_mod(long long a, long long b, long long mod) {
    long long c;
    const int base = 10;
    for (c = 0; b != 0; b /= base)
        c += (b % base) * a, c %= mod, a = (a * base) % mod;
    return c;
}

/*
 * ans ^ 3 % mod
 */
inline long long cube_end(long long ans, long long mod) {
    return mul_and_mod(mul_and_mod(ans, ans, mod), ans, mod);
}

int main() {
    int nProb, length, i;
    long long base, match, ans;
    char input[100];
    scanf("%d", &nProb);
    while (nProb--) {
        scanf("%s", input);
        length = strlen(input);
        ans = match = input[length - 1] - '0';
        if (input[length - 1] == '3')
            ans = 7;
        if (input[length - 1] == '7')
            ans = 3;
        base = 10;
        for (i = length - 2; i >= 0; i--) {
            match += (input[i] - '0') * base;
            while (cube_end(ans, base * 10) != match)
                ans += base;
            base *= 10;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

