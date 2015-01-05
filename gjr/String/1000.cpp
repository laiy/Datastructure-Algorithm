/*************************************************************************
	> File Name: 1000.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Monday, January 05, 2015 PM08:35:50 CST
 ************************************************************************/

#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>

std::string container[100];
bool visited[100];
int n;

bool is_double(char a, char b) {
    return (a == 'A' && b == 'T') || (a == 'T' && b == 'A') || (a == 'C' && b == 'G') || (a == 'G' && b == 'C');
}

bool match(std::string a, std::string b) {
    if (a.length() != b.length()) return false;
    for (int i = 0; i < a.length(); i++)
        if (!is_double(a[i], b[i])) return false;
    return true;
}

int count_how_many_matches() {
    int count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (!visited[i] && !visited[j] && match(container[i], container[j])) visited[i] = visited[j] = true, count++;
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(visited, false, sizeof(visited));
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            std::cin >> container[i];
        printf("%d\n", count_how_many_matches());
    }
    return 0;
}

