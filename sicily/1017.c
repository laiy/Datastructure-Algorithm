#include <cstdio>
#include <vector>
#include <cmath>

struct Investment {
    int month;
    double money;
    Investment(int month, double money) {
        this->month = month;
        this->money = money;
    }
};

int main() {
    int n, i, month, last_month, count = 0;
    double money, last_money, lower_bound, higher_bound, temp_rate, sum;
    while (scanf("%d", &n) && n != -1) {
        std::vector<Investment> v;
        for (i = 0; i < n; i++)
            scanf("%d %lf", &month, &money), v.push_back(Investment(month, money));
        scanf("%d %lf", &last_month, &last_money);
        lower_bound = 1.0;
        higher_bound = 2.0;
        while (higher_bound - lower_bound > 1e-6) {
            sum = 0;
            temp_rate = (higher_bound + lower_bound) / 2;
            for (i = 0; i < n; i++)
                sum += v[i].money * pow(temp_rate, last_month - v[i].month + 1);
            if (sum < last_money)
                lower_bound = temp_rate;
            else
                higher_bound = temp_rate;
        }
        if (count)
            printf("\n");
        printf("Case %d: %.5lf\n", ++count, lower_bound - 1);
    }
    return 0;
}

