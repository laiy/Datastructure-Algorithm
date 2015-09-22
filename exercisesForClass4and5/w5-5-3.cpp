#include <stdio.h>
#include <vector>

int n;
std::vector<int> container;

void print() {
    if (!container.size()) {
        printf("{}\n");
        return;
    }
    printf("{");
    for (int i = 0; i < container.size() - 1; i++) {
        printf("%d,", container[i]);
    }
    printf("%d}\n", container[container.size() - 1]);
}

void dfs(int step) {
    if (step == 0) {
        print();
    } else {
        dfs(--step);
        container.push_back(++step);
        dfs(--step);
        container.pop_back();
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        dfs(n);
    }
    return 0;
}

