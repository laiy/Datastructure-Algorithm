#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        for (int i = 0; i < n; i++) {
            s += (char)(((int)'0') + (i + 1));
        }
        std::cout << s << std::endl;
        while (next_permutation(s.begin(), s.end())) {
            std::cout << s << std::endl;
        }
    }
    return 0;
}


