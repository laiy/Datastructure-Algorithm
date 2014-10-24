#include <stdio.h>

void cope(int *sum, int times);

int arr[105][105];
int brr[105];
int n;

int main() {
    int t, sum;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            brr[i] = 1;
        }
        sum = 0;
        cope(&sum, 0);
        printf("%d\n", sum);
    }
}

void cope(int *sum, int times) {
    if (times >= n - 1) {
        return;
    }
    int a, b, min = 100005;
    for (int i = 0; i < n; i++) {
        if (brr[i]) {
            for (int j = 0; j < n; j++) {
                if (brr[j]) {
                    if (arr[i][j] < min && i != j) {
                        min = arr[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
    }
    *sum += min;
    brr[b] = 0;
    for (int i = 0; i < n; i++) {
        if (arr[a][i] > arr[b][i]) {
            arr[a][i] = arr[b][i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i][a] > arr[i][b]) {
            arr[i][a] = arr[i][b];
        }
    }
    cope(sum, times + 1);
}
