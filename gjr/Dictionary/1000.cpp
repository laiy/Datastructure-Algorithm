/*************************************************************************
	> File Name: 1000.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Saturday, January 10, 2015 AM11:13:01 CST
 ************************************************************************/

#include <cstdio>
#include <map>

int main() {
    int n, temp;
    bool orz = false;
    while (scanf("%d", &n) != EOF) {
        if (orz) printf("\n");
        else orz = true;
        std::map<int, int> container;
        while (n--)
            scanf("%d", &temp), container[temp]++;
        std::map<int, int>::iterator it = container.begin();
        while (it != container.end())
            printf("%d %d\n", (*it).first, (*it).second), it++;
    }
    return 0;
}

