#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double stringToDouble(string temp) {
    istringstream iss(temp);
    double result;
    iss >> result;
    return result;
}

int main() {
    int t;
    cin >> t;
    string c;
    getline(cin, c);
    while (t--) {
        string s, temp;
        getline(cin, s);
        double f[1000];
        int oc = 0;
        int fc = 0;
        double ans = 0;
        char op[1000];
        bool flag = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                s.erase(i--, 1);
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (isOperator(s[i]) && i == 0) {
                flag = true;
                continue;
            }
            if (isOperator(s[i])) {
                op[oc++] = s[i];
                f[fc++] = stringToDouble(temp);
                temp = "";
            } else {
                temp += s[i];
            }
        }
        f[fc++] = stringToDouble(temp);
        if (flag) {
            f[0] *= -1;
        }
        for (int i = 0, j = 0; i < oc; i++, j++) {
            if (op[i] == '*') {
                f[j + 1] = f[j] * f[j + 1];
                f[j] = 0;
            } else if (op[i] == '/') {
                f[j + 1] = f[j] / f[j + 1];
                f[j] = 0;
            } else if (op[i] == '-') {
                f[j + 1] *= -1;
            }
        }
        for (int i = 0; i < fc; i++) {
            ans += f[i];
        }
        cout << setiosflags(ios::fixed) << setprecision(3) << ans << endl;
    }
    return 0;
}

