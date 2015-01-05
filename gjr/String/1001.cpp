/*************************************************************************
	> File Name: 1001.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Monday, January 05, 2015 PM08:52:04 CST
 ************************************************************************/

#include <cstdio>

//kmp

int main() {
    int code_dimension, protection_dimension, temp;
    int code[80000];
    while (scanf("%d", &code_dimension) != EOF) {
        for (int i = 0; i < code_dimension; i++) scanf("%d", &code[i]);
        scanf("%d", &protection_dimension);
        int ans = 0, index = 0;
        bool go_next = false;
        for (int i = 0; i < protection_dimension; i++) {
            scanf("%d", &temp);
            if (go_next) continue;
            if (code[index] == temp) {
                if (index == 0) ans = i;
                if (index == code_dimension - 1) {
                    go_next = true;
                    continue;
                }
                index++;
            } else {
                index = 0;
                if (code[index] == temp) ans = i, index++;
            }
        }
        if (index == code_dimension - 1) printf("%d\n", ans);
        else printf("no solution\n");
    }
    return 0;
}

