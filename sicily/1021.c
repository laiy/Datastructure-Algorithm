#include <cstdio>
#include <stack>

int main() {
    int n, i, x, y, temp;
    while (scanf("%d", &n)) {
        if (n == 0) break;
        temp = 2 * n + 1;
        int circle[temp];
        for (i = 0; i < n; i++)
            scanf("%d%d", &x, &y), circle[x] = circle[y] = i;
        std::stack<int> st;
        for (i = 1; i < temp; i++) {
            if (st.empty()) {
                st.push(circle[i]);
            } else {
                if (st.top() == circle[i])
                    st.pop();
                else
                    st.push(circle[i]);
            }
        }
        if (st.empty())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

