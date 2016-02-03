#include <iostream>
#include <stdio.h>

struct trie_node {
    bool is_end;
    trie_node* next[10];
    trie_node() {
        for (int i = 0; i < 10; i++)
            next[i] = NULL;
        is_end = false;
    }
} *temp;

int main() {
    int t, n, i;
    std::string input;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        trie_node *root = new trie_node();
        bool yes = true;
        while (n--) {
            std::cin >> input;
            if (yes) {
                temp = root;
                for (i = 0; i < input.length() && yes; i++) {
                    if (temp->next[input[i] - '0'] == NULL) {
                        trie_node *new_node = new trie_node();
                        temp->next[input[i] - '0'] = new_node;
                        temp = new_node;
                        if (i == input.length() - 1)
                            temp->is_end = true;
                    } else {
                        temp = temp->next[input[i] - '0'];
                        if (temp->is_end || i == input.length() - 1)
                            yes = false;
                    }
                }
            }
        }
        if (yes)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
