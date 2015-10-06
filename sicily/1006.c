#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
#include <set>

std::string ranking[100], median;
int n, median_value;

int difference(std::string a, std::string b) {
    std::set<std::string> s;
    std::string temp1, temp2;
    std::set<std::string>::iterator it;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 5; j++)
            temp1 = a[i], temp2 = a[j], s.insert(temp1 + temp2);
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 5; j++) {
            temp1 = b[i], temp2 = b[j];
            if ((it = s.find(temp1 + temp2)) != s.end())
                s.erase(it);
        }
    return s.size();
}

void try_this_one(std::string s) {
    int value = 0;
    for (int i = 0; i < n; i++)
        value += difference(ranking[i], s);
    if (value < median_value)
        median_value = value, median = s;
}

void search_all_possibilities() {
    char a[5] = {'A', 'B', 'C', 'D', 'E'};
    do {
        try_this_one(std::string(a));
    } while (std::next_permutation(a, a + 5));
}

int main() {
    while (scanf("%d", &n) && n != 0) {
        median_value = INT_MAX;
        for (int i = 0; i < n; i++)
            std::cin >> ranking[i];
        search_all_possibilities();
        std::cout << median << " is the median ranking with value " << median_value << "." << std::endl;
    }
    return 0;
}

