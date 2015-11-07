#include <cstdio>
#include <vector>
#include <algorithm>

struct state {
    int f, b;
    state(int f, int b) {
        this->f = f;
        this->b = b;
    }
    bool operator<(const state& s) const {
        if (b == s.b) {
            if (b == 0)
                return f < s.f;
            else
                return f > s.f;
        }
        return b < s.b;
    }
};

int main() {
    int t, n, b, f, fi, bi, i, ans, index, times;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &f, &b);
        std::vector<state> v;
        for (i = 0; i < n; i++)
            scanf("%d %d", &fi, &bi), v.push_back(state(fi, bi));
        std::sort(v.begin(), v.end());
        index = b - 1;
        times = 0;
        while (index >= n)
            index -= n, times++;
        fi = v[index].f;
        bi = v[index].b;
        if (bi)
            ans = 3 * f - fi + times * 2 * f;
        else
            ans = fi + f + times * 2 * f;
        printf("%d\n", ans);
    }
    return 0;
}

