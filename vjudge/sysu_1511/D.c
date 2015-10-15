#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

struct Node {
    int x, y, id;
    Node(int a, int b, int i) {
        x = a;
        y = b;
        id = i;
    }
};

struct Distance {
    int from, to, distance;
    Distance(int f, int t, int d) {
        from = f;
        to = t;
        distance = d;
    }
    bool operator<(const Distance &d) const {
        return distance < d.distance;
    }
};

int main() {
    int n, x, y, i, j;
    scanf("%d", &n);
    std::vector<Node> nodes;
    std::vector<Distance> d;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        nodes.push_back(Node(x, y, i + 1));
    }
    for (i = 0; (size_t)i + 1 < nodes.size(); i++) {
        for (j = i + 1; (size_t)j < nodes.size(); j++) {
            d.push_back(Distance(i + 1, j + 1, abs(nodes[i].x - nodes[j].x) + abs(nodes[i].y - nodes[j].y)));
        }
    }
    std::sort(d.begin(), d.end());
    std::vector<Distance> visited;
    for (i = 0; (size_t)i < d.size(); i++) {
        bool c = false;
        for (j = 0; (size_t)j < visited.size(); j++) {
            if (d[i].from == visited[j].from || d[i].from == visited[j].to || d[i].to == visited[j].from || d[i].to == visited[j].to) {
                c = true;
                break;
            }
        }
        if (c)
            continue;
    }
}

