#include <iostream>
#include <queue>
using namespace std;


bool print(queue<int> temp) {
    int toPrint = temp.front();
    temp.pop();
    while (!temp.empty()) {
        if (temp.front() > toPrint) return false;
        temp.pop();
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, min = 0;
        queue<int> q;
        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            int temp;
            cin >> temp;
            q.push(temp);
        }
        while (true) {
            if (q.empty()) {
                cout << min << endl;
                break;
            }
            if (print(q)) {
                min++;
                if (n == 1) {
                    cout << min << endl;
                    break;
                }
            } else {
                q.push(q.front());
            }
            q.pop();
            n--;
            if (!n) n = q.size();
        }
    }
    return 0;
}

