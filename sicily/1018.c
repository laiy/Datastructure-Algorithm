#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

#define NOT_FOUND -1

std::string order[52];
std::string value[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
std::string suit[4] = {"C", "D", "H", "S"};

inline void init_order() {
    for (int i = 0; i < 13; i++)
        for (int j = 0; j < 4; j++)
            order[i * 4 + j] = value[i] + suit[j];
}

inline int nth_position(std::string s) {
    for (int i = 0; i < 52; i++)
        if (order[i] == s)
            return i;
    return NOT_FOUND;
}

inline bool smaller(std::string a, std::string b) {
    return nth_position(a) < nth_position(b);
}

inline std::string mini(std::string a, std::string b) {
    return smaller(a, b) ? a : b;
}

bool test(std::string a, std::string b, std::string c, std::string d, std::string e) {
    static int sum;
    static std::string temp;
    temp = mini(c, mini(d, e));
    sum = 0;
    sum += (temp == c) ? 1 + (smaller(d, e) ? 0 : 3) : (temp == d) ? 2 + (smaller(c, e) ? 0 : 3) : 3 + (smaller(c, d) ? 0 : 3);
    return a == order[(nth_position(b) + 4 * sum) % 52];
}

int main() {
    int t, count = 0;
    scanf("%d", &t);
    std::string card[5];
    init_order();
    while (t--) {
        std::cin >> card[0] >> card[1] >> card[2] >> card[3] >> card[4];
        std::sort(card, card + 5);
        do {
            if (test(card[0], card[1], card[2], card[3], card[4])) {
                std::cout << "Problem " << ++count << ": " << card[0] << " " << card[1] << " " << card[2] << " " << card[3] << " " << card[4] << std::endl;
                break;
            }
        } while (next_permutation(card, card + 5));
    }
    return 0;
}

