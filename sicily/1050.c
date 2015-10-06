#include <cstdio>
#include <limits.h>

int m[5], target, result;

void dfs(int n) {
    for (int i = 0; i < n; i++)
        if (m[i] <= target && m[i] > result)
            result = m[i];
    if (result == target || n == 1) return;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            int temp1 = m[i], temp2 = m[j];
            m[j] = m[n - 1];
            m[i] = temp1 * temp2, dfs(n - 1);
            m[i] = temp1 + temp2, dfs(n - 1);
            m[i] = temp2 - temp1, dfs(n - 1);
            m[i] = temp1 - temp2, dfs(n - 1);
            if (temp1 != 0 && temp2 % temp1 == 0)
                m[i] = temp2 / temp1, dfs(n - 1);
            if (temp2 != 0 && temp1 % temp2 == 0)
                m[i] = temp1 / temp2, dfs(n - 1);
            m[i] = temp1, m[j] = temp2;
        }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d %d %d %d", m, m + 1, m + 2, m + 3, m + 4, &target);
        result = INT_MIN;
        dfs(5);
        printf("%d\n", result);
    }
    return 0;
}

