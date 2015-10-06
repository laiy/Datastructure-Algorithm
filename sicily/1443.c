#include <cstdio>
#include <queue>

int main() {
    int t, n, m, temp;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        std::queue<int> q;
        for (int i = 0; i < n; i++)
            scanf("%d", &temp), q.push(temp);
        int count = 0;
        while (true) {
            int top = q.front();
            q.pop();
            bool print = true;
            int size = q.size();
            while (size--) {
                temp = q.front();
                q.pop();
                if (temp > top)
                    print = false;
                q.push(temp);
            }
            if (print) {
                count++;
                if (m == 0) {
                    printf("%d\n", count);
                    break;
                }
            } else {
                q.push(top);
            }
            m = (m == 0) ? q.size() - 1 : --m;
        }
    }
    return 0;
}
