/*************************************************************************
	> File Name: 1003.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, January 11, 2015 PM02:45:55 CST
 ************************************************************************/

#include <cstdio>
#include <algorithm>

int n, m, i, j, q;

struct Priority {
    int id, p;
    bool operator<(const Priority &another) const {
        return p < another.p;
    }
} col[11];

struct Item {
    int id, child_items[11];
    bool operator<(const Item &another) const {
        for (int i = 1; i <= m; i++)
            if (child_items[col[i].id] < another.child_items[col[i].id]) return true;
            else if (child_items[col[i].id] > another.child_items[col[i].id]) return false;
        return id < another.id;
    }
} items[101];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++) {
            items[i].id = i;
            for (j = 1; j <= m; j++)
                scanf("%d", &items[i].child_items[j]);
        }
        scanf("%d", &q);
        while (q--) {
            for (i = 1; i <= m; i++) col[i].id = i, scanf("%d", &col[i].p);
            std::sort(col + 1, col + m + 1);
            std::sort(items + 1, items + n + 1);
            for (i = 1; i < n; i++) printf("%d ", items[i].id - 1);
            printf("%d\n", items[n].id - 1);
        }
    }
    return 0;
}

