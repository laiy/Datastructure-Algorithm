/*************************************************************************
	> File Name: 1007.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Thursday, January 08, 2015 AM10:18:12 CST
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <string>

int main() {
    std::string pre_order_search, post_order_search;
    std::cin >> pre_order_search >> post_order_search;
    int ans = 1, len = pre_order_search.length();
    for (int i = 0; i < len - 1; i++)
        if (pre_order_search[i + 1] == post_order_search[post_order_search.find(pre_order_search[i]) - 1]) ans *= 2;
    printf("%d", ans);
    return 0;
}

