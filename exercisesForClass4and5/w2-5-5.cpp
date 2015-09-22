#include <queue>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        queue<int> q;
        for (int i = 1; i <= t; i++) {
            q.push(i);
        }
        while (q.size() != 1) {
            cout << q.front() << " ";
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << " " << endl;
    }
    return 0;
}

