#include <stdio.h>
#include <iostream>
#include <string>

int hash_table[1000];
bool empty[1000];
int m;

void add(int a) {
    int index = a % m;
    int i = 0;
    while (i < m) {
        if (empty[index]) {
            hash_table[index] = a;
            empty[index] = false;
            return;
        }
        i++;
        index = (a + i * i) % m;
    }
}

void query(int a) {
    int index = a % m;
    int i = 0;
    while (i < m) {
        if (hash_table[index] == a && empty[index] == false) {
            printf("yes\n");
            return;
        }
        i++;
        index = (a + i * i) % m;
    }
    printf("no\n");
}

void print() {
    for (int i = 0; i < m; i++) {
        if (empty[i]) {
            printf("%d#NULL\n", i);
        } else {
            printf("%d#%d\n", i, hash_table[i]);
        }
    }
}

int main() {
    scanf("%d", &m);
    std::string op;
    int temp;
    for (int i = 0; i < m; i++) {
        empty[i] = true;
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
            } else if (op == "Query"){
                query(temp);
            }
        }
    }
    return 0;
}

