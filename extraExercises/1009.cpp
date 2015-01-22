#include <cstdio>

int a[10];

int partition(int left, int right) {
    int key = a[left];
    while (left < right) {
        while (a[right] >= key && left < right) right--;
        a[left] = a[right];
        while (a[left] <= key && left < right) left++;
        a[right] = a[left];
    }
    a[left] = key;
    return left;
}

void QuickSort(int left, int right) {
    if (left < right) {
        int pivot = partition(left, right);
        QuickSort(left, pivot - 1);
        QuickSort(pivot + 1, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    QuickSort(0, n - 1);
    for (int i = 0; i < n - 1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[n - 1]);
    if (n % 2 == 0)
        printf("%d", (a[n / 2 - 1] + a[n / 2]) / 2);
    else
        printf("%d", a[n / 2]);
    return 0;
}

