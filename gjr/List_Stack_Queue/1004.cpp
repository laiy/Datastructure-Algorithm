/*************************************************************************
	> File Name: 1004.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, January 04, 2015 PM02:40:18 CST
 ************************************************************************/

#include <iostream>
#include <stack>

int rank(char op) {
    if (op == '*' || op == '/' || op == '%') return 1;
    return 0;
}

bool is_operator(char c) {
    return c == '*' || c == '/' || c == '%' || c == '+' || c == '-';
}

std::string translate_to_postfix_expression(std::string infix_expression) {
    std::string postfix_expression = "";
    std::stack<char> container;
    for (int i = 0; i < infix_expression.length(); i++) {
        if (is_operator(infix_expression[i])) {
            while (!container.empty()) {
                char op = container.top();
                if (rank(op) >= rank(infix_expression[i])) {
                    postfix_expression += op;
                    container.pop();
                } else {
                    break;
                }
            }
            container.push(infix_expression[i]);
        } else {
            postfix_expression += infix_expression[i];
        }
    }
    while (!container.empty()) {
        postfix_expression += container.top();
        container.pop();
    }
    return postfix_expression;
}

int main() {
    std::string infix_expression;
    std::cin >> infix_expression;
    std::cout << translate_to_postfix_expression(infix_expression);
    return 0;
}

