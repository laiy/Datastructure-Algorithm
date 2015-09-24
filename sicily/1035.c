#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

std::vector<std::string> v;
bool visited[100];

bool match(char a, char b) {
    return (a == 'A' && b == 'T') || (a == 'T' && b == 'A') || (a == 'C' && b == 'G') || (a == 'G' && b == 'C');
}

int cmp(int i, int j) {
    if (visited[i] || visited[j]) return 0;
    if (v[i].length() != v[j].length()) return 0;
    for (size_t k = 0; k < v[i].length(); k++)
        if (!match(v[i][k], v[j][k]))
            return 0;
    visited[i] = visited[j] = true;
    return 1;
}

int main() {
    int t, n, i, j, ans;
    std::string s;
    scanf("%d", &t);
    while (t--) {
        v.clear();
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            std::cin >> s, v.push_back(s);
        ans = 0;
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                ans += cmp(i, j);
        printf("%d\n", ans);
    }
    return 0;
}

