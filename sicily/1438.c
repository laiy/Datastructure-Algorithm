#include <cstdio>
#include <algorithm>

int main() {
    short t, n, i, arr[20000];
    int ans;
    scanf("%hd", &t);
    while (t--) {
        scanf("%hd", &n);
        for (i = 0; i < n; i++)
            scanf("%hd", arr + i);
        std::sort(arr, arr + n);
        ans = 0;
        for (i = n - 3; i >= 0; i -= 3)
            ans += arr[i];
        printf("%d\n", ans);
    }
    return 0;
}

