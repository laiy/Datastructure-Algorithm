/*************************************************************************
	> File Name: 1003.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Saturday, January 10, 2015 AM09:27:16 CST
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <vector>

int color[1000000];
std::vector<int> container[1000000];

int main() {
    memset(color, 0, sizeof(color));
    for (int i = 0; i < 280; i++) container[i].clear();
    int from, to;
    int c = 0;
    bool print = false;
    while (scanf("%d%d", &from, &to) != EOF) {
        if (!color[from] && !color[to])
            c++, color[from] = color[to] = c, print = true, container[c].push_back(from), container[c].push_back(to);
        else if (color[from] == color[to]) print = false;
        else {
            if (!color[from] || !color[to]) {
                bool temp = color[from];
                color[from] = color[to] = !temp ? color[to] : color[from];
                print = true;
                container[color[from]].push_back((!temp ? from : to));
            } else {
                int f = color[from];
                int temp = container[color[from]].size();
                for (int i = 0; i < temp; i++)
                    color[container[f][i]] = color[to], container[color[to]].push_back(container[f][i]);
                container[f].clear();
                print = true;
            }
        }
        if (print) printf("%d %d\n", from, to);
    }
    return 0;
}

