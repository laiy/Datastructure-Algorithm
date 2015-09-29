#include <cstdio>
#include <cstring>

void swap (char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    short n, i, j;
    char encrypyed_str[201];
    while (scanf("%hd", &n) && n != 0) {
        scanf("%s", encrypyed_str);
        for (i = n; (size_t)i < strlen(encrypyed_str); i += 2 * n)
            for (j = 0; j < n / 2; j++)
                swap(&encrypyed_str[i + j], &encrypyed_str[i + n - 1 - j]);
        for (i = 0; i < n; i++)
            for (j = 0; (unsigned long)j < strlen(encrypyed_str); j += n)
                printf("%c", encrypyed_str[i + j]);
        printf("\n");
    }
    return 0;
}

