#include <iostream>

int findNumberOfWays(int m, int n) {
    if (m == 1 || n == 1) {
        return 1;
    } else if (n >= m) {
        return 1 + findNumberOfWays(m, m - 1);
    } else {
        return findNumberOfWays(m - n, n) + findNumberOfWays(m, n - 1);
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int m, n;
        std::cin >> m >> n;
        std::cout << findNumberOfWays(m, n) << std::endl;
    }
    return 0;
}

