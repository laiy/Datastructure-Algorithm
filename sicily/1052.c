#include <cstdio>

int main() {
    int n, arr[1000], i, count, temp;
    bool print;
    while (scanf("%d", &n) && n != 0) {
        for (i = 0; i < n; i++)
            scanf("%d", arr+ i);
        count = 0;
        while (true) {
            count++;

            temp = arr[n - 1] / 2;
            for (i = n - 1; i >= 1; i--)
                arr[i] /= 2, arr[i] += arr[i - 1] / 2;
            arr[0] /= 2, arr[0] += temp;

            for (i = 0; i < n; i++)
                if (arr[i] % 2 != 0)
                    arr[i]++;
            print = true;
            temp = arr[0];
            for (i = 1; i < n; i++)
                if (arr[i] != temp) {
                    print = false;
                    break;
                }
            if (print) {
                printf("%d %d\n", count, temp);
                break;
            }
        }
    }
    return 0;
}

