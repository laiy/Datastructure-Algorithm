#include <stdio.h>

void QuickSort(int a[], int numsize) {
    int i = 0, j = numsize - 1;
    int val = a[0];
    if (numsize > 1) {
        while (i < j) {
            for (; j > i; j--) {
                if (a[j]< val) {
                    a[i++] = a[j];
                    break;
                }
            }
            for (; i < j; i++) {
                if (a[i]> val) {
                    a[j--] = a[i];
                    break;
                }
            }
        }
        a[i] = val;
        QuickSort(a, i);
        QuickSort(a + i + 1, numsize - i - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int signal[10];
    for (int i = 0; i < n; i++) {
        scanf("%d", &signal[i]);
    }
    QuickSort(signal, n);
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", signal[i]);
    }
    printf("%d\n", signal[n - 1]);
    if (n % 2 == 0) {
        printf("%d", (signal[n / 2 - 1] + signal[n / 2]) / 2);
    } else {
        printf("%d", signal[n / 2]);
    }
    return 0;
}

