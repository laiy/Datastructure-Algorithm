#include <cstdio>
#include <cstring>
#include <cstdlib>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int t, n, i, b, f, temp_f, temp_b, ans;
    int cost_time[1001];
    scanf("%d", &t);
    while (t--) {
        memset(cost_time, 0, sizeof(cost_time));
        scanf("%d%d%d", &n, &f, &b);
        for (i = 0; i < n; i++) {
            scanf("%d%d", &temp_f, &temp_b);
            if (temp_b) cost_time[i] = 3 * f - temp_f;
            else cost_time[i] = f + temp_f;
        }
        qsort(cost_time, n, sizeof(int), cmp);
        if (b % n == 0) ans = (b / n - 1) * 2 * f + cost_time[n - 1];
        else ans = b / n * 2 * f + cost_time[b % n - 1];
        printf("%d\n", ans);
    }
    return 0;
}

