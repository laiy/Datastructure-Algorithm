#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long temp = 1;
        for (int i = 0; i < n; i++) {
            temp *= 2 * n - i;
        }
        for (int i = 1; i <= n; i++) {
            temp /= i;
        }
        cout << temp / (n + 1) << endl;
    }
    return 0;
}

