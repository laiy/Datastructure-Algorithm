#include <stdio.h>

int hash_table[10000];
int n, m;

int hash(int key) {
    return key % m;
}

int main() {
    int temp;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        hash_table[i] = 0;
    }
    while (n--) {
        scanf("%d", &temp);
        int index = hash(temp);
        if (!hash_table[index]) {
            hash_table[index] = temp;
        } else {
            while (true) {
                if (index == m - 1) {
                    index = 0;
                } else {
                    index++;
                }
                if (!hash_table[index]) {
                    hash_table[index] = temp;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (hash_table[i]) {
            printf("%d#%d\n", i, hash_table[i]);
        } else {
            printf("%d#NULL\n", i);
        }
    }
    return 0;
}
