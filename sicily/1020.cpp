#include <cstring>
#include <cstdio>

int num_pieces, j;
long long pieces[23], result, base;

long long str_to_longlong(char *str, int length) {
    result = 0, base = 1;
    for (j = length - 1; j >= 0; j--)
        result += (str[j] - '0') * base, base *= 10;
    return result;
}

long long calculate_result(int b) {
    static long long remember_that;
    result = 0;
    remember_that = 1000000000000000000 % b;
    for (j = 0; j < num_pieces; j++) {
        result = (result * remember_that + pieces[j] % b) % b;
    }
    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        static int n, b[100], i, length;
        static char x[401];
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", b + i);
        scanf("%s", x);
        length = strlen(x);
        if (length < 19) {
            long long num = str_to_longlong(x, length);
            printf("(%lld", num % b[0]);
            for (i = 1; i < n; i++)
                printf(",%lld", num % b[i]);
        } else {
            char *p = x;
            num_pieces = length / 18 + 1;
            pieces[0] = str_to_longlong(p, length % 18);
            p += length % 18;
            for (i = 1; i < num_pieces; i++) {
                pieces[i] = str_to_longlong(p, 18);
                p += 18;
            }
            printf("(%lld", calculate_result(b[0]));
            for (i = 1; i < n; i++)
                printf(",%lld", calculate_result(b[i]));
        }
        printf(")\n");
    }
    return 0;
}

