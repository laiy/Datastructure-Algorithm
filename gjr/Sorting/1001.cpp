/*************************************************************************
	> File Name: 1001.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, January 11, 2015 AM09:51:15 CST
 ************************************************************************/

#include <cstdio>
#include <cctype>
#include <cstring>

static char first[200], second[200];
static short i, j;

bool is_sign(char *s, short i) {
    return (i == 0 || !isdigit(s[i - 1])) && (s[i] == '+' || s[i] == '-') && isdigit(s[i + 1]);
}

void init(char *s) {
    static char temp[200];
    for (i = 0, j = 0; i < strlen(s); i++, j++) {
        if (isdigit(s[i])) {
            if (i == 0 || s[i - 1] != '+' && s[i - 1] != '-')
                temp[j++] = '+';
            while (s[i] == '0') i++;
            while (isdigit(s[i])) temp[j++] = s[i++];
            if (temp[j - 1] == '+' || temp[j - 1] == '-') j--;
        }
        temp[j] = s[i] >= 'a' && s[i] <= 'z' ? s[i] - 32 : s[i];
    }
    temp[j] = '\0';
    strcpy(s, temp);
}

int cmp() {
    init(first), init(second);
    static short len1, len2, k;
    for (i = 1, j = 1; i < strlen(first) && j < strlen(second); i++, j++) {
        if (isdigit(first[i]) && isdigit(second[j])) {
            k = i;
            while (isdigit(first[k])) k++;
            len1 = k - i;
            k = j;
            while (isdigit(second[k])) k++;
            len2 = k - j;
            if (len1 != len2) return len1 < len2 ? -1 : 1;
            else
                while (i < k && j < k)
                    if (first[i++] != second[j++])
                        return first[i] < second[j] ? -1 : 1;
        }
        if (first[i] != second[j]) {
            if (is_sign(first, i) && is_sign(second, j)) return first[i] == '-' ? -1 : 1;
            return first[i] < second[j] ? -1 : 1;
        }
    }
    return 0;
}

int main() {
    short n;
    scanf("%hd", &n);
    for (short l = 1; l <= n; l++) {
        scanf("%s%s", first, second);
        printf("%hd %hd\n", l, cmp());
    }
    return 0;
}

