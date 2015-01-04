/*************************************************************************
> File Name: 1003.cpp
> Author: LY
> Mail: ly.franky@gmail.com
> Created Time: Sunday, January 04, 2015 AM10:22:40 CST
************************************************************************/

#include <cstdio>
#include <string>
#include <stack>
#include <iostream>

bool match(char left, char right) {
    return (left == '(' && right == ')') || (left == '{' && right == '}') || (left == '[' && right == ']');
}

bool is_left_bracket(char op) {
    return op == '(' || op == '{' || op == '[';
}

bool is_right_bracket (char op) {
    return op == ')' || op == '}' || op == ']';
}

void match_and_output(std::string temp) {
    std::stack<char> container;
    for (int i = 0; i < temp.length(); i++) {
        if (is_left_bracket(temp[i])) {
            container.push(temp[i]);
            continue;
        }
        if (is_right_bracket(temp[i])) {
            if (container.empty()) {
                printf("No\n");
                return;
            }
            char nearest_bracket = container.top();
            container.pop();
            if (!match(nearest_bracket, temp[i])) {
                printf("No\n");
                return;
            }
        }
    }
    if (container.empty())
        printf("Yes\n");
    else
        printf("No\n");
}

int main() {
    int n;
    scanf("%d", &n);
    std::string temp;
    while (n--) {
        std::cin >> temp;
        match_and_output(temp);
    }
    return 0;
}


