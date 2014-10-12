#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main() {
    int n;
    string a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        bool isTrue = false;
        for (int i = 0; i < a.length(); i++) {
            if (!a.find(b)) {
                isTrue = true;
                break;
            }
            char c = a[a.length() - 1];
            a = c + a.erase(a.length() - 1, 1);
        }
        if (isTrue) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    return 0;
}

