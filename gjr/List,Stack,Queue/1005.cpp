/*************************************************************************
	> File Name: 1005.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, January 04, 2015 PM03:09:06 CST
 ************************************************************************/

#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int n;
int origin_order[1005];
std::vector<std::string> container;

void dfs(std::string output, std::stack<int> s1, std::stack<int> s2, int index, int output_index) {
    if (s1.empty() && s2.empty() && index >= n) {
        container.push_back(output);
        return;
    }
    if (s1.empty() ? true : origin_order[index] < s1.top() && index < n) {
        s1.push(origin_order[index]);
        dfs(output + " a", s1, s2, index + 1, output_index);
        s1.pop();
        if (s1.empty() ? false : s1.top() - 1 == origin_order[index]) return;
    }
    if (s1.empty() ? false : s1.top() == output_index) {
        int temp = s1.top();
        s1.pop();
        dfs(output + " b", s1, s2, index, output_index + 1);
        s1.push(temp);
        return;
    }
    if (s2.empty() ? true : origin_order[index] < s2.top() && index < n) {
        s2.push(origin_order[index]);
        dfs(output + " c", s1, s2, index + 1, output_index);
        s2.pop();
    }
    if (s2.empty() ? false : s2.top() == output_index) {
        s2.pop();
        dfs(output + " d", s1, s2, index, output_index + 1);
    }
}

void dfs_and_output() {
    std::string output = "a";
    std::stack<int> s1, s2;
    s1.push(origin_order[0]);
    dfs(output, s1, s2, 1, 1);
    std::sort(container.begin(), container.end());
    if (container.empty())
        printf("0\n");
    else
        std::cout << container[0] << std::endl;
    container.clear();
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) scanf("%d", &origin_order[i]);
        dfs_and_output();
    }
    return 0;
}

