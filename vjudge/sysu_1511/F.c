#include <cstdio>

int main() {
    int result = 0;
    char c;
    while (scanf("%c", &c) && c != '\n')
        result += c - '0';
    if (result % 3 == 0)
        puts("2");
    else
        printf("1\n%d", result % 3);
    return 0;
}

