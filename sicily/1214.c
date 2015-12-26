#include <cstdio>

long long L;
long long zero_in_the_middle, one_in_the_middle;
long long result;
int bits;
bool b = false;

inline int create_palindrome_odd(long long i) {
    if (i < (1 << 15)) {
        zero_in_the_middle = i, one_in_the_middle = i;
        result = 0, bits = 0;
        while (i)
            result = (result << 1) | (i & 1), i >>= 1, bits++;
        zero_in_the_middle = (zero_in_the_middle << (bits + 1)) | result;
        one_in_the_middle = (((one_in_the_middle << 1) | 1) << bits) | result;
        return (zero_in_the_middle && zero_in_the_middle <= L ? 1 : 0) + (one_in_the_middle && one_in_the_middle <= L ? 1 : 0);
    }
    return 0;
}

inline int create_palindrome_even(long long i) {
    result = i;
    while (i)
        result = (result << 1) | (i & 1), i >>= 1;
    if (result > L)
        b = true;
    return result && result <= L ? 1 : 0;
}

int main() {
    int ans = 0;
    scanf("%lld", &L);
    for (int i = 0; !b && i < (1 << 16); i++)
        ans += create_palindrome_even(i) + create_palindrome_odd(i);
    printf("%d\n", ans);
    return 0;
}

