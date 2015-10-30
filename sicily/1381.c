#include <string>
#include <iostream>

std::string plus(std::string s1, std::string s2) {
    int len1 = s1.length(), len2 = s2.length();
    int pre = 0, temp;
    std::string ans = "";
    for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || pre; i--, j--) {
        if (i >= 0 && j >= 0) {
            temp = (s1[i] - '0') + (s2[j] - '0') + pre;
            if (temp >= 10)
                temp -= 10, pre = 1;
            else
                pre = 0;
            ans = char('0' + temp) + ans;
        } else {
            if (i >= 0) {
                temp = (s1[i] - '0') + pre;
                if (temp >= 10)
                    temp -= 10, pre = 1;
                else
                    pre = 0;
                ans = char('0' + temp) + ans;
            } else if (j >= 0) {
                temp = (s2[j] - '0') + pre;
                if (temp >= 10)
                    temp -= 10, pre = 1;
                else
                    pre = 0;
                ans = char('0' + temp) + ans;
            } else {
                ans = char('0' + pre--) + ans;
            }
        }
    }
    return ans;
}

int main() {
    int t, b, times;
    std::cin >> t;
    std::string big_number, result;
    while (t--) {
        std::cin >> big_number >> b;
        while (true)
            if (big_number[0] == '0')
                big_number.erase(0, 1);
            else
                break;
        if (big_number == "" || b == 0) {
            std::cout << "0" << std::endl;
            continue;
        }
        result = "";
        while (b) {
            times = b % 10;
            b /= 10;
            while (times--)
                result = plus(result, big_number);
            big_number += "0";
        }
        std::cout << result << std::endl;
    }
}

