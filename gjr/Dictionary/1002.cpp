/*************************************************************************
	> File Name: 1002.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Saturday, January 10, 2015 PM03:56:31 CST
 ************************************************************************/

#include <cstdio>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n, m;
    std::string temp;
    while (scanf("%d", &n)) {
        if (!n) break;
        int ans = n;
        scanf("%d", &m);
        std::map<std::string, bool> map;
        while (n--) std::cin >> temp, std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower), map[temp] = true;
        while (m--) {
            std::cin >> temp, std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            if (map[temp]) ans--, map[temp] = false;
        }
        printf("%d\n", ans);
    }
    return 0;
}

