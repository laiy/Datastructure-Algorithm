#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

struct period {
    int start;
    int end;
} arr[168];

stack<struct period> st;

int cmp(const void* a, const void* b) {
    struct period* first = (struct period*)a;
    struct period* second = (struct period*)b;
    if (first->start == second->start) {
        return first->end - second->end;
    } else {
        return first->start - second->start;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, count = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i].start >> arr[i].end;
        }
        qsort(arr, n, sizeof(arr[0]), cmp);
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(arr[i]);
            } else if (st.top().end < arr[i].start) {
                st.push(arr[i]);
            } else if (st.top().end > arr[i].end) {
                st.pop();
                st.push(arr[i]);
            }
        }
        while (!st.empty()) {
            st.pop();
            count++;
        }
        cout << count << endl;
    }
    return 0;
}

