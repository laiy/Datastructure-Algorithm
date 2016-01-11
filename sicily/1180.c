#include <cstdio>
#include <string>
#include <stack>
#include <iostream>

int main() {
    int b, e, i, j;
    std::stack<std::string> prepend, append;
    std::string text, temp;
    while (scanf("%d %d", &b, &e) && b != -1 && e != -1) {
        getchar();
        getline(std::cin, text);
        for (i = 0; i < b; i++)
            if (text[i] == '<') {
                if (text[i + 1] == '/')
                    prepend.pop(), append.pop();
                else {
                    j = text.find('>', i);
                    temp = text.substr(i, j - i + 1);
                    prepend.push(temp);
                    temp.insert(1, "/");
                    append.push(temp);
                    i = j;
                }
            }
        for (i = b; i < e; i++)
            if (text[i] == '<') {
                if (text[i + 1] == '/')
                    append.pop();
                else {
                    j = text.find('>', i);
                    temp = text.substr(i, j - i + 1);
                    temp.insert(1, "/");
                    append.push(temp);
                    i = j;
                }
            }
        temp = text.substr(b, e - b);
        while (!prepend.empty())
            temp = prepend.top() + temp, prepend.pop();
        while (!append.empty())
            temp += append.top(), append.pop();
        std::cout << temp << std::endl;
    }
    return 0;
}

