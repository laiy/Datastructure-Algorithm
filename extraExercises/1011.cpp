#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;

map<char, int> mp;

int main() {
    map<char, int> mp;
    char alp[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w','x',
    'y', 'z'};
    int num[26] = {2, 4, 6, 3,6, 9, 4, 8, 12, 5, 10, 15, 6, 12, 18,
    7, 14, 21, 28, 8, 16, 24, 9, 18, 27, 36};
    for (int i = 0; i < 26; i++) {
        mp[alp[i]] = num[i];
    }
    int t, ans, i;
    scanf("%d", &t);
    while (t--) {
        char word[101];
        ans = 0;
        scanf("%s", word);
        for (i = 0; i < strlen(word); i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                word[i] = word[i] + 32;
            }
            ans += mp[word[i]];
        }
        printf("%d\n", ans);
    }
    return 0;
}

