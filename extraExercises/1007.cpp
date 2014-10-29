#include <iostream>
#include <stdio.h>
#include <string>
#include <map>

int main() {
    std::map<std::string, std::string> mp;
    std::map<std::string, bool> appear;
    std::string s1, s2;
    char c;
    while (true) {
        c = getchar();
        if (c == '\n') break;
        std::cin >> s1 >> s2;
        s1 = c + s1;
        mp[s2] = s1;
        appear[s2] = true;
        getchar();
    }
    while (std::cin >> s1) {
        if (appear[s1] == true) {
            std::cout << mp[s1] << std::endl;
        } else {
            std::cout << "eh" << std::endl;
        }
    }
    return 0;
}
