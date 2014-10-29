#include <string>
#include <algorithm>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    while (n--) {
        std::string temp = "", ans = "";
        std::cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '_') {
                temp += s[i];
            } else {
                if (temp != "") {
                    std::reverse(temp.begin(), temp.end());
                    ans += temp;
                }
                ans += '_';
                temp = "";
            }
        }
        if (temp != "") {
            std::reverse(temp.begin(), temp.end());
            ans += temp;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}

