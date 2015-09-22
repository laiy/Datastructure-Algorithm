#include <cstring>
#include <cstdio>

int remember_arr[401], length, z, result[100];
char x[401];

/*
 * remember 10 ^ y % z in the remember_arr for n belong to [0..length-1]
 */
int awesome_remember(int y) {
    if (y == 0)
        return 1;
    else {
        return remember_arr[y] = ((10 % z) * (awesome_remember(y - 1))) % z;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, b[100], i, j, count;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &b[i]);
        scanf("%s", x);
        length = strlen(x);
        printf("(");
        for (i = 0; i < n; i++) {
            z = b[i];
            remember_arr[0] = 1;
            awesome_remember(length - 1);
            result[i] = 0;
            count = length - 1;
            for (j = 0; j < length; j++) {
                result[i] += (((x[j] - 48) % z) * remember_arr[count--]) % z;
            }
            result[i] %= z;
        }
        for (i = 0; i < n - 1; i++) {
            printf("%d,", result[i]);
        }
        printf("%d)\n", result[i]);
    }
    return 0;
}

