/*************************************************************************
	> File Name: w9-4-2.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Wednesday, December 31, 2014 PM08:04:07 HKT
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>

int n;
int count = 0;
std::string front_end_dict[256];
int back_end_map[256];

int string_to_int(std::string temp) {
    return atof(temp.c_str());
}

void init_back_end_map(std::string s) {
    std::string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') back_end_map[count++] = string_to_int(temp), temp = "";
        else temp += s[i];
    }
    back_end_map[count++] = string_to_int(temp);
}

void output() {
    std::string temp = "";
    for (int i = 0; i < count; i++) {
        if (back_end_map[i] == 0) {
            std::cout << temp;
            if (i != count - 1) printf(" ");
            front_end_dict[++n] = temp;
            temp = "";
        } else {
            temp += front_end_dict[back_end_map[i]];
        }
    }
    printf("\n");
}

int main() {
    std::string temp;
    scanf("%d", &n);
    std::cin >> temp;
    for (int i = 0; i < n; i++) front_end_dict[i + 1] = temp[i];
    std::cin >> temp;
    init_back_end_map(temp);
    output();
    return 0;
}

