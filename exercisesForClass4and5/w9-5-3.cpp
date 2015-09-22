/*************************************************************************
	> File Name: w9-5-3.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, November 30, 2014 AM11:04:13 CST
 ************************************************************************/

#include <cstdio>

int n, k;
int entry[10000];

void insert_heap(int current, int low, int high) {
    int small = 2 * low + 1;
    while (small <= high) {
        if (small < high && entry[small] > entry[small + 1]) small++;
        if (current <= entry[small]) break;
        else {
            entry[low] = entry[small];
            low = small;
            small = 2 * low + 1;
        }
    }
    entry[low] = current;
}

void build_heap() {
    int low;
    for (low = k / 2 - 1; low >= 0; low--) {
        int current = entry[low];
        insert_heap(current, low, k - 1);
    }
}

void heap_sort() {
    int current, last_sorted;
    build_heap();
    for (last_sorted = k - 1; last_sorted > 0; last_sorted--) {
        current = entry[last_sorted];
        entry[last_sorted] = entry[0];
        insert_heap(current, 0, last_sorted - 1);
    }
}

void print_entry() {
    for (int i = 0; i < k - 1; i++) printf("%d ", entry[i]);
    printf("%d\n", entry[k - 1]);
}

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 0; i < k; i++) scanf("%d", &entry[i]);
        build_heap();
        for (int i = k; i < n; i++) {
            scanf("%d", &entry[i]);
            if (entry[i] > entry[0]) insert_heap(entry[i], 0, k - 1);
        }
        heap_sort();
        print_entry();
    }
    return 0;
}

