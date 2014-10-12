#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;

int getNumber(char c);

int main() {
    int n;
    cin >> n;
    string s;
    while (n--) {
        int ans = 0;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            ans += getNumber(s[i]);
        }
        cout << ans << endl;
    }
    return 0;
}

int getNumber(char c) {
    if (c >= 'A' && c <= 'Z') {
        c = c - ('Z' - 'z');
    }
    switch(c) {
        case 'a':
            return 2;
        case 'b':
            return 4;
        case 'c':
            return 6;
        case 'd':
            return 3;
        case 'e':
            return 6;
        case 'f':
            return 9;
        case 'g':
            return 4;
        case 'h':
            return 8;
        case 'i':
            return 12;
        case 'j':
            return 5;
        case 'k':
            return 10;
        case 'l':
            return 15;
        case 'm':
            return 6;
        case 'n':
            return 12;
        case 'o':
            return 18;
        case 'p':
            return 7;
        case 'q':
            return 14;
        case 'r':
            return 21;
        case 's':
            return 28;
        case 't':
            return 8;
        case 'u':
            return 16;
        case 'v':
            return 24;
        case 'w':
            return 9;
        case 'x':
            return 18;
        case 'y':
            return 27;
        case 'z':
            return 36;
    }
}
