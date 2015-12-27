#include <cstdio>
#include <cstring>

/*
 * calculate ans ^ 3 % mod
 */
inline long long cube_end(long long ans, long long mod) {
    return (((ans % mod) * (ans % mod) % mod) * (ans % mod)) % mod;
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
            ans += base;
            while (cube_end(ans, base * 10) != match)
                ans += base;
            base *= 10;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

