#include <stdio.h>
#include <vector>
#include <stack>
#include <iostream>
#include <string>

int main() {
    int n;
    std::string in, out;
    while (scanf("%d", &n) != EOF) {
        std::cin >> in >> out;
        std::stack<char> station;
        std::vector<std::string> state;
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == out[0]) {
                state.push_back("in");
                state.push_back("out");
                out.erase(0, 1);
                while (!station.empty()) {
                    if (station.top() == out[0]) {
                        state.push_back("out");
                        out.erase(0, 1);
                        station.pop();
                    } else {
                        break;
                    }
                }
            } else {
                station.push(in[i]);
                state.push_back("in");
            }
        }
        if (station.empty()) {
            printf("Yes.\n");
            for (int i = 0; i < state.size(); i++) {
                std::cout << state[i] << std::endl;
            }
        } else {
            printf("No.\n");
        }
        printf("FINISH\n");
    }
    return 0;
}

