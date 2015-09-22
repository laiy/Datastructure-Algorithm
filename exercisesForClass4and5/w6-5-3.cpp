#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

bool cmp(std::string a, std::string b) {
    return a + b < b + a;
}

int main() {
    int t, n, i;
    std::string container[8];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            std::cin >> container[i];
        }
        sort(container, container + n, cmp);
        for (i = 0; i < n; i++) {
            std::cout << container[i];
        } 
        printf("\n");
    }
    return 0;
}

