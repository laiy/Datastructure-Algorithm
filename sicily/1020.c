#include <string.h>
#include <stdio.h>

int num_pieces, j, length, pieces[45], result, t;

int str_to_int(char *str, int l) {
    result = 0, j = 0;
    while (j < l)
        result = result * 10 + str[j++] - '0';
    return result;
}

int calculate_result(int b) {
    t = 1000000000 % b;
    result = 0;
    for (j = 0; j < num_pieces; j++)
        result = (result * t + pieces[j] % b) % b;
    return result;
}

int main() {
    int n, b[100], i, t, num, r[100];
    char x[401], *p;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", b + i);
        scanf("%s", x);
        length = strlen(x);
        if (length < 10) {
            num = str_to_int(x, length);
            for (i = 0; i < n; i++)
                r[i] = num % b[i];
        } else {
            p = x;
            num_pieces = length / 9 + 1;
            pieces[0] = str_to_int(p, length % 9);
            p += length % 9;
            for (i = 1; i < num_pieces; i++)
                pieces[i] = str_to_int(p, 9), p += 9;
            for (i = 0; i < n; i++)
                r[i] = calculate_result(b[i]);
        }
        printf("(%d", r[0]);
        for (i = 1; i < n; i++)
            printf(",%d", r[i]);
        printf(")\n");
    }
    return 0;
}

