#include <stdio.h>
#include <queue>
#include <functional>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k, temp;
        int median_min = 0, median_max = 0;
        scanf("%d%d", &n, &k);
        std::priority_queue<int> min;
        std::priority_queue<int, std::vector<int>, std::greater<int> > max;
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            if (min.size() < k) {
                min.push(temp);
            } else {
                if (temp < min.top()) {
                    min.pop();
                    min.push(temp);
                }
            }
            if (max.size() < k) {
                max.push(temp);
            } else {
                if (temp > max.top()) {
                    max.pop();
                    max.push(temp);
                }
            }
        }
        if (k % 2 == 0) {
            for (int i = 1; i <= k; i++) {
                if (i == k / 2) {
                    median_min += min.top();
                    median_max += max.top();
                } else if (i == k / 2 + 1) {
                    median_min += min.top();
                    median_max += max.top();
                    break;
                }
                min.pop();
                max.pop();
            }
            median_min /= 2;
            median_max /= 2;
        } else {
            for (int i = 1; i <= k; i++) {
                if (i == k / 2 + 1) {
                    median_min += min.top();
                    median_max += max.top();
                    break;
                }
                min.pop();
                max.pop();
            }
        }
        printf("%d\n", median_max - median_min);
    }
}
