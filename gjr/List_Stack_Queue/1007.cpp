/*************************************************************************
	> File Name: 1007.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Monday, January 05, 2015 AM09:54:20 CST
 ************************************************************************/

#include <cstdio>
#include <vector>
#include <algorithm>

struct single_term {
    int coefficient;
    int exponent;
    single_term(int coefficient, int exponent) {
        this->coefficient = coefficient;
        this->exponent = exponent;
    }
    bool operator<(const single_term &another) const {
        return another.exponent < this->exponent;
    }
};

std::vector<single_term> container;
std::vector<single_term> ans;

void add_and_output() {
    std::sort(container.begin(), container.end());
    std::vector<single_term>::iterator it = container.begin();
    while (it != container.end()) {
        single_term temp = *it;
        it++;
        while (it->exponent == temp.exponent && it != container.end()) {
            temp.coefficient += it->coefficient;
            it++;
        }
        if (temp.coefficient)
            ans.push_back(temp);
    }
    printf("%d\n", int(ans.size()));
    for (int i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].coefficient, ans[i].exponent);
}

int main() {
    int m, coefficient, exponent;
    scanf("%d", &m);
    while (m--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &coefficient, &exponent);
            container.push_back(single_term(coefficient, exponent));
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &coefficient, &exponent);
            container.push_back(single_term(coefficient, exponent));
        }
        add_and_output();
        container.clear();
        ans.clear();
    }
    return 0;
}

