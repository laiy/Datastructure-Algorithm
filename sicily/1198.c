#include <cstdio>
#include <iostream>
#include <algorithm>

bool cmp(std::string a, std::string b) {
    return a + b < b + a;
}

int main() {
    int t, n, i;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        std::string s[8];
        for (i = 0; i < n; i++)
            std::cin >> s[i];
        std::sort(s, s + n, cmp);
        for (i = 0; i < n; i++)
            std::cout << s[i];
        printf("\n");
    }
    return 0;
}

