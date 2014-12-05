/*************************************************************************
	> File Name: w10-5-1.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, December 05, 2014 PM05:26:39 CST
 ************************************************************************/

#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>

int m, n;
std::string table[10000];

void hash(std::string name, int index) {
    while (table[index] != "") index++;
    if (index > m - 1) {
        index = 0;
        while (table[index] != "") index++;
    }
    table[index] = name;
}

void get_value_and_hash(std::string name) {
    int weight = 0;
    for (int i = 0; i < name.length(); i++) weight += name[i] - 'a' + 1;
    hash(name, weight % m);
}

void output() {
    for (int i = 0; i < m; i++) {
        if (table[i] != "") {
            std::cout << i << ":" << table[i] << std::endl;
        } else {
            printf("NULL\n");
        }
    }
        //table[i] != "" ? std::cout << i << ":" << table[i] << std::endl : printf("NULL\n");
        //if (table[i] != "") {
            //std::cout << i << ":" << table[i] << std::endl;
        //} else {
            //printf("NULL\n");
        //}
}

void clear_table() {
    for (int i = 0; i < m; i++) {
        if (table[i] != "") table[i] = "";
    }
}

int main() {
    std::string name;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) std::cin >> name, get_value_and_hash(name);
        output();
        clear_table();
    }
    return 0;
}

