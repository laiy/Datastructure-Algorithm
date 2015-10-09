#include <cstdio>
#include <string>
#include <iostream>

int n, temp;
int magic[2][4];
int destination[2][4];
std::string ans;
bool found;

void swap(int *a, int *b) {
    *a ^= *b ^= *a ^= *b;
}

bool fix() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            if (magic[i][j] != destination[i][j])
                return false;
    return true;
}

void dfs(std::string s) {
    if (found)
        return;
    if (fix() && s.length() <= (size_t)n) {
        ans = s, found = true;
        return;
    } else if (s.length() > (size_t)n) {
        return;
    } else if (s.length() >= 2 && s[s.length() - 1] == 'A' && s[s.length() - 2] == 'A') {
        return;
    } else if (s.length() >= 2 && s[s.length() - 1] == s[s.length() - 2] == s[s.length() - 3] == s[s.length() - 4]) {
        return;
    }

    s += "A";
    for (int i = 0; i < 4; i++)
        swap(&magic[0][i], &magic[1][i]);
    dfs(s);
    for (int i = 0; i < 4; i++)
        swap(&magic[0][i], &magic[1][i]);
    s.erase(s.end() - 1);

    s += "B";
    for (int i = 0; i < 2; i++) {
        temp = magic[i][3];
        for (int j = 3; j > 0; j--)
            magic[i][j] = magic[i][j - 1];
        magic[i][0] = temp;
    }
    dfs(s);
    for (int i = 0; i < 2; i++) {
        temp = magic[i][0];
        for (int j = 0; j < 3; j++)
            magic[i][j] = magic[i][j + 1];
        magic[i][3] = temp;
    }
    s.erase(s.end() - 1);

    s += "C";
    temp = magic[0][1];
    magic[0][1] = magic[1][1];
    magic[1][1] = magic[1][2];
    magic[1][2] = magic[0][2];
    magic[0][2] = temp;
    dfs(s);
    temp = magic[0][1];
    magic[0][1] = magic[0][2];
    magic[0][2] = magic[1][2];
    magic[1][2] = magic[1][1];
    magic[1][1] = temp;
}

int main() {
    while (scanf("%d", &n) && n != -1) {
        ans = "NOT FOUND";
        found = false;
        int count = 0;
        for (int i = 0; i < 2; i++)
            if (i == 0) {
                for (int j = 0; j < 4; j++)
                    magic[i][j] = ++count;
            } else {
                for (int j = 3; j >= 0; j--)
                    magic[i][j] = ++count;
            }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 4; j++)
                scanf("%d", &destination[i][j]);
        dfs("");
        if (ans == "NOT FOUND")
            printf("-1\n");
        else
            std::cout << ans.length() << " " << ans << std::endl;
    }
    return 0;
}

