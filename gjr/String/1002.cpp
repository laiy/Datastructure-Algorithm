/*************************************************************************
	> File Name: 1002.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Wednesday, January 07, 2015 AM08:51:35 CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s1, s2, temp1, temp2;
    bool ok = false;
    int len1, len2;
    while (std::getline(std::cin, s1)) {
        std::getline(std::cin, s2);
        std::reverse(s1.begin(), s1.end());
        std::reverse(s2.begin(), s2.end());
        len1 = s1.length();
        len2 = s2.length();
        ok = false;
        temp1 = temp2 = "";
        for (int i = 0; i < len2; i++) {
            if (i < len2 / 2) temp1 += s2[i];
            else temp2 += s2[i];
            if (s2[i] != ' ') ok = true;
        }
        s2 = temp2 + temp1;
        if (ok)
            std::cout << s2 << std::endl;
        ok = false;
        temp1 = temp2 = "";
        for (int i = 0; i < len1; i++) {
            if (i < len1 / 2) temp1 += s1[i];
            else temp2 += s1[i];
            if (s1[i] != ' ') ok = true;
        }
        s1 = temp2 + temp1;
        if (ok)
            std::cout << s1 << std::endl;
    }
    return 0;
}

