#include <cstdio>
#include <string>
#include <iostream>
#include <hash_set>
#include <queue>

using namespace __gnu_cxx;

int n, destination, top, bottom, a, b, c, d;
std::string ans;
__gnu_cxx::hash_set<int> visited;

struct State {
    int state;
    std::string step;
    State(int state, std::string step) {
        this->state = state;
        this->step = step;
    }
};

int OP_A(int state) {
    return state / 10000 + state % 10000 * 10000;
}

int OP_B(int state) {
    top = state / 10000;
    bottom = state % 10000;
    top = top % 10 * 1000 + top / 10;
    bottom = bottom % 10 * 1000 + bottom / 10;
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

    state += c * 1000000;
    state += a * 100000;
    state += d * 100;
    state += b * 10;

    return state;
}

void bfs() {
    int state = 12348765;
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


