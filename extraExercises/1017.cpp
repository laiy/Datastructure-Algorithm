#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int max1 = 0, max2 = 0, max3 = 0;
        int index, temp;
        scanf("%d", &n);
        while (n--) {
            scanf("%d%d", &index, &temp);
            if (index == 1 && temp > max1) {
                max1 = temp;
            } else if (index == 2 && temp > max2) {
                max2 = temp;
            } else if (index == 3 && temp > max3) {
                max3 = temp;
            }
        }
        if (max1) {
            printf("1 %d\n", max1);
        }
        if (max2) {
            printf("2 %d\n", max2);
        }
        if (max3) {
            printf("3 %d\n", max3);
        }
    }
    return 0;
}

