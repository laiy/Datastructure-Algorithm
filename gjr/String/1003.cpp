/*************************************************************************
	> File Name: 1003.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Wednesday, January 07, 2015 AM09:28:36 CST
 ************************************************************************/

#include <cstdio>

int len = 0;
char container[1000];
char left[100];
char right[100];

bool is_valid(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '-' || c == '_';
}

int left_len(int index) {
    int count = 0;
    for (int i = index; i >= 0; i--)
        if (is_valid(container[i]) || (container[i] == '.' && is_valid(container[i - 1]))) count++;
        else break;
    return count;
}

int right_len(int index) {
    int count = 0;
    for (int i = index; i < len; i++)
        if (is_valid(container[i]) || (container[i] == '.' && is_valid(container[i + 1]))) count++;
        else break;
    return count;
}

int main() {
    char temp;
    while (scanf("%c", &temp) != EOF) container[len++] = temp;
    container[len] = '\0';
    for (int i = 0; i < len; i++) {
        if (container[i] == '@') {
            int len_left = left_len(i - 1);
            int len_right = right_len(i + 1);
            if (len_left && len_right) {
                for (int j = i - len_left; j <= i + len_right; j++) printf("%c", container[j]);
                printf("\n");
            }
        }
    }
    return 0;
}

