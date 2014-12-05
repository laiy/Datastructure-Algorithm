/*************************************************************************
	> File Name: w10-5-2.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, December 05, 2014 PM07:36:57 CST
 ************************************************************************/

#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>

int m, n;
double average_find_length = 0;
std::string table[10000];

void hash(std::string name, int index) {
    int origin = index, count = 1;
    average_find_length++;
    while (table[index] != "") {
        index = origin + pow(count++, 2), average_find_length++;
        while (index > m - 1) index -= m;
    }
    table[index] = name;
}

void get_value_and_hash(std::string name) {
    int weight = 0;
    for (int i = 0; i < name.length(); i++) weight += name[i] - 'a' + 1;
    hash(name, weight % m);
}

void print(int index) {
    if (index == -1) printf("NULL\n");
    else
        std::cout << table[index] << std::endl;
}

void output() {
    for (int i = 0; i < m; i++)
        printf("%d:", i), table[i] != "" ? print(i) : print(-1);
    printf("%.3f\n", average_find_length / n);
}

void clear_table() {
    for (int i = 0; i < m; i++)
        if (table[i] != "") table[i] = "";
}

int main() {
    std::string name;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) std::cin >> name, get_value_and_hash(name);
        output();
        clear_table();
        average_find_length = 0;
    }
    return 0;
}
