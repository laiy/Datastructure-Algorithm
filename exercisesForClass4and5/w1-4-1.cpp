#include <cstdio>
#include <iostream>
#include <string>

int main() {
    int n;
    std::string a, b;
    scanf("%d", &n);
    while (n--) {
        std::cin >> a >> b;
        bool isTrue = false;
        for (int i = 0; i < a.length(); i++) {
            if (!a.find(b)) {
                isTrue = true;
                break;
            }
            char c = a[a.length() - 1];
            a = c + a.erase(a.length() - 1, 1);
        }
        if (isTrue) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    }
    return 0;
}

