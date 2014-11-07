#include <iostream>
#include <vector>

template <typename T>
int binarySearch(const std::vector<T> table, int bot, int top, const T &x) {
    int temp;
    while (bot <= top) {
        temp = (bot + top) / 2;
        if (table[temp] == x) {
            ++temp;
            while (table[temp] == x) {
                ++temp;
            }
            return temp - 1;
        }
        if (table[temp] < x) {
            bot = temp + 1;
        } else {
            top = temp - 1;
        }
    }
    return -1;
}

int main() {
    int a[] = {0, 1, 1, 3, 3, 3, 6};
    std::vector<int> v(a, a + 7);
    std::cout << binarySearch(v, 0, v.size() - 1, 3);
    std::cout << binarySearch(v, 0, v.size() - 1, 7);
    return 0;
}

