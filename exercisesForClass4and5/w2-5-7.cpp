#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int ly[10];
        stack<int> st;
        int count = 0, step = 2;
        for (int i = 0 ; i < 10; i++) {
            cin >> ly[i];
        }
        st.push(1);
        while (true) {
            if (st.empty()) {
                st.push(step++);
                if (step == 12) {
                    cout << "No" << endl;
                    break;
                }
            }
            if (st.top() != ly[count]) {
                st.push(step++);
                if (step == 12) {
                    cout << "No" << endl;
                    break;
                }
            } else {
                st.pop();
                count++;
                if (count == 10) {
                    cout << "Yes" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
