/*************************************************************************
	> File Name: 1006.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Monday, January 05, 2015 AM09:19:03 CST
 ************************************************************************/

#include <cstdio>
#include <list>

int n, m;
std::list<int> container;

int manage_the_queue_and_return_how_much_time_taken() {
    int minutes = 0;
    int temp;
    while (true) {
        bool push_back = false;
        temp = container.front();
        std::list<int>::iterator it = container.begin();
        while (it != container.end()) {
            if (*it > temp) {
                push_back = true;
                break;
            }
            it++;
        }
        if (push_back) container.push_back(temp), container.pop_front();
        else {
            container.pop_front(), minutes++, n--;
            if (m == 0) return minutes;
        }
        m = !m ? n - 1 : m - 1;
    }
}

int main() {
    int t, temp;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            container.push_back(temp);
        }
        printf("%d\n", manage_the_queue_and_return_how_much_time_taken());
        container.clear();
    }
    return 0;
}

