#include <cstdio>
#include <vector>
#include <algorithm>

struct Node {
    int own, need;
    Node(const int &o, const int &n) {
        own = o;
        need = n;
    }
    inline bool operator<(const Node &other) const {
        return need < other.need;
    }
};

int main() {
    int n, s, a, b, i, temp;
    bool yes;
    std::vector<Node> v;
    while (scanf("%d %d", &n, &s) && n != 0) {
        while (n--)
            scanf("%d %d", &a, &b), v.push_back(Node(a, b));
        std::sort(v.begin(), v.end());
        temp = (int)v.size();
        yes = true;
        for (i = 0; i < temp; i++) {
            if (s >= v[i].need)
                s += v[i].own;
            else {
                yes = false;
                break;
            }
        }
        if (yes)
            printf("YES\n");
        else
            printf("NO\n");
        v.clear();
    }
    return 0;
}

