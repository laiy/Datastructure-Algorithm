#include <stdio.h>
#include <iostream>
#include <string>

long long hash_table[1000];
int m;

int hash(long long key) {
    return key % m;
}

void add(long long a) {
    int index = hash(a);
    if (!hash_table[index]) {
        hash_table[index] = a;
    } else {
        int i = 1;
        while (true) {
            index += i * i;
            index = (index >= m) ? index % m : index;
            if (!hash_table[index]) {
                hash_table[index] = a;
                break;
            }
            i++;
        }
    }
}

void query(long long a) {
    int index = hash(a);
    int origin = index;
    int i = 1;
    while (true) {
        if (hash_table[index] == a) {
            printf("yes\n");
            return;
        } else {
            index += i * i;
            index = (index >= m) ? index % m : index;
            if (index == origin) {
                printf("no\n");
                return;
            }
            i++;
        }
    }
}

void print() {
    for (int i = 0; i < m; i++) {
        if (!hash_table[i]) {
            printf("%d#NULL\n", i);
        } else {
            printf("%d#%lld\n", i, hash_table[i]);
        }
    }
}

int main() {
    scanf("%d", &m);
    std::string op;
    long long temp;
    for (int i = 0; i < m; i++) {
        hash_table[i] = 0;
    }
    while (true) {
        std::cin >> op;
        if (op == "End") {
            break;
        } else if (op == "Print") {
            print();
        } else {
            std::cin >> temp;
            if (op == "Add") {
                add(temp);
            } else {
                query(temp);
            }
        }
    }
    return 0;
}

