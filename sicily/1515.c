#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#include <queue>

int n, destination, top, bottom, a, b, c, d;
std::string ans;
std::set<int> visited;

struct State {
    int state;
    std::string step;
    State(int state, std::string step) {
        this->state = state;
        this->step = step;
    }
};

int OP_A(int state) {
    top = state / 10000;
    bottom = state % 10000;
    top = top / 100 + top % 100 * 100;
    bottom = bottom / 100 + bottom % 100 * 100;
    return top * 10000 + bottom;
}

int OP_B(int state) {
    top = state / 10000;
    bottom = state % 10000;
    top = top % 1000 * 10 + top / 1000;
    bottom = bottom % 1000 * 10 + bottom / 1000;
    return top * 10000 + bottom;
}

int OP_C(int state) {
    a = state / 1000000 % 10;
    b = state / 100000 % 10;
    c = state / 100 % 10;
    d = state / 10 % 10;

    state -= a * 1000000;
    state -= b * 100000;
    state -= c * 100;
    state -= d * 10;

    state += b * 1000000;
    state += d * 100000;
    state += a * 100;
    state += c * 10;

    return state;
}

void bfs() {
    int state = 12345678;
    if (state == destination) {
        ans = "";
        return;
    }

    std::queue<State> q;
    q.push(State(state, ""));
    while (!q.empty()) {
        State s = q.front();
        q.pop();

        if (visited.find(s.state) != visited.end())
            continue;
        if (s.step.length() > (size_t)n)
            break;
        if (s.state == destination) {
            ans = s.step;
            break;
        }

        visited.insert(s.state);

        q.push(State(OP_A(s.state), s.step + "A"));
        q.push(State(OP_B(s.state), s.step + "B"));
        q.push(State(OP_C(s.state), s.step + "C"));
    }
}

int main() {
    while (scanf("%d", &n) && n != -1) {

        ans = "NOT FOUND";
        destination = 0;
        visited.clear();

        int temp[8], base = 1, i;
        for (i = 0; i < 8; i++)
            scanf("%d", temp + i);
        for (i = 7; i >= 0; i--)
            destination += temp[i] * base, base *= 10;

        bfs();

        if (ans == "NOT FOUND")
            printf("-1\n");
        else
            std::cout << ans.length() << " " << ans << std::endl;
    }
    return 0;
}

