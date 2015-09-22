#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    long long ans[40];
    ans[0] = 1;
    ans[1] = 2;
    for (int i = 2; i < 40; i++) {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    while (t--) {
        int n;
        cin >> n;
        cout << ans[n - 1] << endl; 
    }
    return 0;
}

