#include <iostream>
#include <stack>
using namespace std;

stack<char> st;

bool isMatch(char c) {
    if (st.empty()) return false;
    if (st.top() == '(' && c == ')') return true;
    if (st.top() == '[' && c == ']') return true;
    if (st.top() == '{' && c == '}') return true;
    return false;
}

bool isBracket(char c) {
    if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}') return true;
    return false;
}

bool push(char c) {
    if (!isBracket(c)) {
        return false;
    } else {
        if (isMatch(c)) {
            st.pop();
            return false;
        } else {
            return true;
        }
    }
}

int main() {
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    while (t--) {
        getline(cin, s);
        for (int i = 0; i < s.length(); i++) {
            if (push(s[i])) {
                st.push(s[i]);
            }
        }
        if (st.empty()) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
            while (!st.empty()) {
                st.pop();
            }
        }
    }
    return 0;
}
