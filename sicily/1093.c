#include <cstdio>
#define min(a, b) a < b ? a : b

int main() {
    int weight1, weight2, weight3, rate1, rate2, rate3, rate4, n, origin, best_price, add, count = 0, possibility2, possibility3, possibility4;
    while (scanf("%d %d", &weight1, &rate1) != EOF) {
        scanf("%d %d", &weight2, &rate2);
        scanf("%d %d", &weight3, &rate3);
        scanf("%d", &rate4);
        printf("Set number %d:\n", ++count);
        possibility2 = (weight1 + 1) * rate2;
        possibility3 = (weight2 + 1) * rate3;
        possibility4 = (weight3 + 1) * rate4;
        while (scanf("%d", &n) && n != 0) {
            if (n <= weight1)
                origin = rate1;
            else if (n <= weight2)
                origin = rate2;
            else if (n <= weight3)
                origin = rate3;
            else
                origin = rate4;

            if (origin == rate1) {
                best_price = min(min(min(n * rate1, possibility2), possibility3), possibility4);
                if (best_price == n * rate1)
                    add = 0;
                else if (best_price == possibility2)
                    add = weight1 + 1 - n;
                else if (best_price == possibility3)
                    add = weight2 + 1 - n;
                else
                    add = weight3 + 1 - n;
            } else if (origin == rate2) {
                best_price = min(min(n * rate2, possibility3), possibility4);
                if (best_price == n * rate2)
                    add = 0;
                else if (best_price == possibility3)
                    add = weight2 + 1 - n;
                else
                    add = weight3 + 1 - n;
            } else if (origin == rate3) {
                best_price = min(n * rate3, possibility4);
                if (best_price == n * rate3)
                    add = 0;
                else
                    add = weight3 + 1 - n;
            } else {
                best_price = n * rate4;
                add = 0;
            }

            printf("Weight (%d) has best price $%d (add %d pounds)\n", n, best_price, add);
        }
        printf("\n");
    }
    return 0;
}

