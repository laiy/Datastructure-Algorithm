#include <iostream>
#include <sstream>
#include <iomanip>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '#';
}

int pre(char a) {
    if (a == '#')
        return 3;
    else if (a == '+' || a == '-')
        return 1;
    else if (a == '*' || a == '/')
        return 2;
    return 0;
}
 
double stringToDouble(string temp) {
    istringstream iss(temp);
    double result;
    iss >> result;
    return result;
}

double caculate(string s) {
    stack<float> st;
    stack<char> sc;
    string temp = "";
    double db;
    double d1, d2;
    for (int i = 0; i < s.length(); i++) {
        if (isOperator(s[i])) {
            if (temp != "") {
                st.push(stringToDouble(temp));
                temp = "";
            }
            if (sc.empty()) {
                sc.push(s[i]);
            } else {
                if (s[i] == '(') {
                    sc.push(s[i]);
                    continue;
                }
                if (pre(s[i]) > pre(sc.top())) {
                    sc.push(s[i]);
                } else {
                    if (s[i] == ')') {
                        while (true) {
                            if (sc.top() == '(') {
                                sc.pop();
                                break;
                            }
                            if (sc.top() == '#') {
                                d2 = st.top();
                                st.pop();
                                st.push(-1 * d2);
                            } else {
                                d2 = st.top();
                                st.pop();
                                d1 = st.top();
                                st.pop();
                                if (sc.top() == '+') {
                                    st.push(d1 + d2);
                                } else if (sc.top() == '-') {
                                    st.push(d1 - d2);
                                } else if (sc.top() == '*') {
                                    st.push(d1 * d2);
                                } else if (sc.top() == '/') {
                                    st.push(d1 / d2);
                                }
                            }
                            sc.pop();
                        }
                    } else {
                        while (true) {
                            if (sc.top() == '#') {
                                d2 = st.top();
                                st.pop();
                                st.push(-1 * d2);
                            } else {
                                d2 = st.top();
                                st.pop();
                                d1 = st.top();
                                st.pop();
                                if (sc.top() == '+') {
                                    st.push(d1 + d2);
                                } else if (sc.top() == '-') {
                                    st.push(d1 - d2);
                                } else if (sc.top() == '*') {
                                    st.push(d1 * d2);
                                } else if (sc.top() == '/') {
                                    st.push(d1 / d2);
                                }
                            }
                            sc.pop();
                            if (sc.empty()) {
                                sc.push(s[i]);
                                break;
                            } else if (pre(s[i]) > pre(sc.top())) {
                                sc.push(s[i]);
                                break;
                            }
                        }
                    }
                }
            }
        } else {
            temp += s[i];
        }
    }
    if (temp != "") {
        st.push(stringToDouble(temp));
    }
    while (!sc.empty()) {
        if (sc.top() == '#') {
            d2 = st.top();
            st.pop();
            st.push(-1 * d2);
        } else {
            d2 = st.top();
            st.pop();
            d1 = st.top();
            st.pop();
            if (sc.top() == '+') {
                st.push(d1 + d2);
            } else if (sc.top() == '-') {
                st.push(d1 - d2);
            } else if (sc.top() == '*') {
                st.push(d1 * d2);
            } else if (sc.top() == '/') {
                st.push(d1 / d2);
            }
        }
        sc.pop();
    }
    db = st.top();
    st.pop();
    return db;
}

int main() {
    int t;
    cin >> t;
    string c;
    getline(cin, c);
    while (t--) {
        string s, temp;
        getline(cin, s);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                s.erase(i--, 1);
                continue;
            }
            if (s[i] == '-') {
                if (i == 0) {
                    s[i] = '#';
                } else if (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/' || s[i - 1] == '#') {
                    s[i] = '#';
                    if (s[i - 1] == '#') {
                        s.erase(--i, 1);
                        s.erase(i--, 1);
                    }
                }
            }
            if (s[i] == '+') {
                if (i == 0) {
                    s.erase(i--, 1);
                } else if (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/' || s[i - 1] == '#') {
                    s.erase(i--, 1);
                }
            }
        }
        cout << setiosflags(ios::fixed) << setprecision(3) << caculate(s) << endl;
    }
    return 0;
}

