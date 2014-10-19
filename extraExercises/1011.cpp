#include <iostream>
#include <map>
using namespace std;

map<char, int> mp;

void initialize() {
    mp.insert(pair<char, int>('a', 2));
    mp.insert(pair<char, int>('b', 4));
    mp.insert(pair<char, int>('c', 6));
    mp.insert(pair<char, int>('d', 3));
    mp.insert(pair<char, int>('e', 6));
    mp.insert(pair<char, int>('f', 9));
    mp.insert(pair<char, int>('g', 4));
    mp.insert(pair<char, int>('h', 8));
    mp.insert(pair<char, int>('i', 12));
    mp.insert(pair<char, int>('j', 5));
    mp.insert(pair<char, int>('k', 10));
    mp.insert(pair<char, int>('l', 15));
    mp.insert(pair<char, int>('m', 6));
    mp.insert(pair<char, int>('n', 12));
    mp.insert(pair<char, int>('o', 18));
    mp.insert(pair<char, int>('p', 7));
    mp.insert(pair<char, int>('q', 14));
    mp.insert(pair<char, int>('r', 21));
    mp.insert(pair<char, int>('s', 28));
    mp.insert(pair<char, int>('t', 8));
    mp.insert(pair<char, int>('u', 16));
    mp.insert(pair<char, int>('v', 24));
    mp.insert(pair<char, int>('w', 9));
    mp.insert(pair<char, int>('x', 18));
    mp.insert(pair<char, int>('y', 27));
    mp.insert(pair<char, int>('z', 36));
}

int main() {
    int t, ans, i;
    string s;
    cin >> t;
    initialize();
    while (t--) {
        ans = 0;
        cin >> s;
        if (s[0] >= 'A' && s[0] <= 'Z') {
            s[0] = s[0] - ('Z' - 'z');
        }
        for (i = 0; i < s.length(); i++) {
            ans += mp[s[i]];
        }
        cout << ans << endl;
    }
    return 0;
}

