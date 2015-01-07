/*************************************************************************
	> File Name: 1004.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Wednesday, January 07, 2015 AM10:01:33 CST
 ************************************************************************/

#include <string>
#include <iostream>

int main() {
    std::string uncompleted_ISBN;
    while (std::cin >> uncompleted_ISBN) {
        int weight = 10;
        int weighted_sum = 0;
        for (int i = 0; i < 11; i++)
            if (uncompleted_ISBN[i] != '-') weighted_sum += weight-- * (uncompleted_ISBN[i] - '0');
        int checked_digit = -1;
        for (int i = 0; i < 10; i++)
            if ((weighted_sum + i) % 11 == 0) {
                checked_digit = i;
                break;
            }
        std::cout << uncompleted_ISBN << '-' << char(checked_digit == -1 ? 'X' : checked_digit + '0') << std::endl;
    }
    return 0;
}

