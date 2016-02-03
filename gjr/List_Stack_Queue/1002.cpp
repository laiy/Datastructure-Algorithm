/*************************************************************************
	> File Name: 1002.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, January 04, 2015 AM09:55:51 CST
 ************************************************************************/

#include <cstdio>
#include <string>
#include <iostream>
#include <stack>

bool is_character(char op) {
    return op == '+' || op == '-' || op == '/' || op == '*';
}

double calculate(double first, double second, char op) {
    if (op == '+') return first + second;
    if (op == '-') return first - second;
    if (op == '*') return first * second;
    if (op == '/') return first / second;
}

void calculate_value_and_output(std::string temp) {
    std::stack<double> container;
    for (int i = 0; i < temp.length(); i++) {
        if (is_character(temp[i])) {
            double second = container.top();
            container.pop();
            double first = container.top();
            container.pop();
            container.push(calculate(first, second, temp[i]));
        } else {
            container.push(double(temp[i] - 'a' + 1));
        }
    }
    printf("%.2f\n", container.top());
    container.pop();
}

int main() {
    int t;
    scanf("%d", &t);
    std::string temp;
    while (t--) {
        std::cin >> temp;
        calculate_value_and_output(temp);
    }
    return 0;
}

