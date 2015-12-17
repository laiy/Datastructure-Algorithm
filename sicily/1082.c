#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
    int maximum_cost, removal_list_size, to_remove, policy, cost, remove_count, p;
    char op;
    bool fuck = false;
    while (scanf("%d", &maximum_cost) != EOF) {
        if (fuck)
            printf("\n");
        else
            fuck = true;
        std::vector<int> v;
        std::priority_queue<int, std::vector<int>, std::greater<int> > removal_list;
        scanf("%d", &removal_list_size);
        while (removal_list_size--)
            scanf("%d", &to_remove), removal_list.push(to_remove);
        policy = 1;
        remove_count = 0;
        while (scanf("%c", &op) && op != 'e') {
            switch(op) {
                case 'a':
                    scanf("%d", &cost), v.push_back(cost);
                    break;
                case 'p':
                    scanf("%d", &policy);
                    break;
                case 'r':
                    if (v.size()) {
                        std::sort(v.begin(), v.end());
                        if (policy == 1)
                            p = *v.begin(), v.erase(v.begin());
                        else {
                            std::vector<int>::iterator it = v.end();
                            it--;
                            p = *it, v.erase(it);
                        }
                        if (++remove_count == removal_list.top())
                            printf("%d\n", p), removal_list.pop();
                    } else
                        printf("-1\n");
                    break;
            }
        }
    }
    return 0;
}

