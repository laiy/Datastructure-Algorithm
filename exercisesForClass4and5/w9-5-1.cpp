/*************************************************************************
	> File Name: w9-5-1.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, November 30, 2014 AM08:42:57 CST
 ************************************************************************/

#include <cstdio>

int n;
int entry[10000];

void print_entry() {
    for (int i = 0; i < n - 1; i++) printf("%d ", entry[i]);
    printf("%d\n", entry[n - 1]);
}

void insert_heap(int current, int low, int high) {
    int large = 2 * low + 1;
    while (large <= high) {
        if (large < high && entry[large] < entry[large + 1]) large++;
        if (current >= entry[large]) break;
        else {
            entry[low] = entry[large];
            low = large;
            large = 2 * low + 1;
        }
    }
    entry[low] = current;
}

void build_heap() {
    int low;
    for (low = n / 2 - 1; low >= 0; low--) {
        int current = entry[low];
        insert_heap(current, low, n - 1);
    }
    print_entry();
}

void heap_sort() {
    int current, last_sorted;
    build_heap();
    for (last_sorted = n - 1; last_sorted > 0; last_sorted--) {
        current = entry[last_sorted];
        entry[last_sorted] = entry[0];
        insert_heap(current, 0, last_sorted - 1);
        print_entry();
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &entry[i]);
        }
        heap_sort();
    }
    return 0;
}

