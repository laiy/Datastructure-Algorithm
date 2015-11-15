#include <cstdio>
#include <queue>

int main() {
    int time, t, n, front_size, i, front, temp, count[10], last[10], c = 0;
    bool unwinnable, found;
    scanf("%d", &t);
    while (t--) {
        unwinnable = false;
        found = false;
        scanf("%d", &n);
        std::queue<int> q[10];
        for (i = 0; i < 52; i++)
            scanf("%d", &temp), q[0].push(temp);
        for (i = 0; i < n; i++)
            count[i] = 1;
        front = 0;
        time = 0;
        front_size = 52;
        while (true) {
            for (i = 0; i < n; i++) {
                if (q[i].empty())
                    continue;
                temp = q[i].front();
                q[i].pop();
                if (count[i] == temp) {
                    if (i != n - 1)
                        q[i + 1].push(temp);
                    if (q[i].empty())
                        last[i] = temp;
                } else
                    q[i].push(temp);
                count[i]++;
                if (count[i] == 14)
                    count[i] = 1;
            }
            while (q[front].empty()) {
                if (front == n - 1) {
                    found = true;
                    break;
                } else
                    ++front, time = 0, front_size = q[front].size();
            }
            if (found)
                break;
            if (q[front].size() == (size_t)front_size)
                time++;
            else
                front_size = q[front].size();
            if (time == 13 * 52 + 1) {
                unwinnable = true;
                break;
            }
        }
        if (unwinnable) {
            printf("Case %d: unwinnable\n", ++c);
        } else {
            printf("Case %d:", ++c);
            for (i = 0; i < n; i++)
                printf(" %d", last[i]);
            printf("\n");

        }
    }
    return 0;
}

