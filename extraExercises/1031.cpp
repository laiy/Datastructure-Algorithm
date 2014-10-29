#include <stdio.h>

int hash(int key) {
    return key % 13;
}

struct Node {
    int data;
    Node* next;
};

Node* hash_table[13];

int main() {
    int n;
    int temp;
    int index;
    while (true) {
        for (int i = 0; i < 13; i++) {
            hash_table[i] = 0;
        }
        scanf("%d", &n);
        if (!n) break;
        while (n--) {
            scanf("%d", &temp);
            index = hash(temp);
            Node* p = new Node;
            p->data = temp;
            p->next = 0;
            if (hash_table[index] == 0) {
                hash_table[index] = p;
            } else {
                Node* tmp = hash_table[index];
                while (tmp->next != 0) {
                    tmp = tmp->next;
                }
                tmp->next = p;
            }
        }
        for (int i = 0; i < 13; i++) {
            if (hash_table[i]) {
                printf("%d#", i);
                Node* tmp = hash_table[i];
                while (tmp->next != 0) {
                    printf("%d ", tmp->data);
                    tmp = tmp->next;
                }
                printf("%d\n", tmp->data);
            } else {
                printf("%d#NULL\n", i);
            }
        }
    }
    return 0;
}
