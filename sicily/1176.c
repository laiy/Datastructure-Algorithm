#include <cstdio>
#include <cstring>
#define max(a, b) (a > b) ? a : b

int arr[1000];
int remember_arr[1000][1000];

int dp(int left, int right) {
    int ans;
    if (right - left == 1)
        ans = max(arr[left], arr[right]);
    else if (remember_arr[left][right] >= 0)
        ans = remember_arr[left][right];
    else
        ans = max(arr[left] + (arr[left + 1] >= arr[right] ? dp(left + 2, right) : dp(left + 1, right - 1)),
                arr[right] + (arr[left] >= arr[right - 1] ? dp(left + 1, right - 1) : dp(left, right - 2)));
    return remember_arr[left][right] = ans;
}

int main() {
    short n, count = 1;
    int i, sum;
    while (scanf("%hd", &n) && n != 0) {
        sum  = 0;
        memset(remember_arr, -1, sizeof(remember_arr));
        for (i = 0; i < n; i++)
            scanf("%d", arr + i), sum += arr[i];
        printf("In game %hd, the greedy strategy might lose by as many as %d points.\n", count++, 2 * dp(0, n - 1) - sum);
    }
    return 0;
}

