/*************************************************************************
	> File Name: w10-5-3.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, December 05, 2014 PM08:00:58 CST
 ************************************************************************/

#include <cstdio>
#include <deque>

int n, t;
double average_find_length = 0;
std::deque<int> table[10];

void hash(int lucky_number) {
    table[lucky_number % t].push_front(lucky_number);
}

void output() {
    for (int i = 0; i < t; i++) {
        int count = 1;
        while (table[i].front()) {
            printf("%d ", table[i].front());
            average_find_length += count++;
            table[i].pop_front();
        }
        printf("\n");
    }
    printf("%.3f\n", average_find_length / n);
}

void clear_table() {
    for (int i = 0; i < t; i++) table[i].clear();
}

int main() {
    int lucky_number;
    while (scanf("%d%d", &n, &t) != EOF) {
        for (int i = 0; i < n; i++) scanf("%d", &lucky_number), hash(lucky_number);
        output();
        clear_table();
        average_find_length = 0;
    }
    return 0;
}

