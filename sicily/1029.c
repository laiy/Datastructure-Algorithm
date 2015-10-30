#include <cstdio>
#include <iostream>
#include <string>

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
    int m, d;
    while (scanf("%d %d", &m, &d) && !(m == d && m == 0)) {
        std::string arr[101];
        arr[0] = "1";
        for (int i = 1; i <= d; i++) {
            if (i < m)
                arr[i] = plus(arr[i - 1], arr[0]);
            else
                arr[i] = plus(arr[i - 1], arr[i - m]);
        }
        std::cout << arr[d] << std::endl;
    }
}

