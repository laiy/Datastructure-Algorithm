#include <cstdio>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

struct Node {
    double x, y;
    Node(double x, double y) {
        this->x = x;
        this->y = y;
    }
    Node(const Node &n1, const Node &n2) {
        double x1 = n1.x, y1 = n1.y, x2 = n2.x, y2 = n2.y, theta = atan((y2 - y1) / (x2 - x1)), arfa = acos(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) / 4.0);
        this->x = x1 + 2 * cos(theta + arfa);
        this->y = y1 + 2 * sin(theta + arfa);
    }
    bool operator<(const Node &n) const {
        return this->x < n.x;
    }
};

int main() {
    int t, n, count = 0, i, c;
    double x;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        std::queue<Node> q;
        std::vector<Node> v;
        for (i = 0; i < n; i++)
            scanf("%lf", &x), v.push_back(Node(x, 1.0));
        std::sort(v.begin(), v.end());
        for (i = 0; (size_t)i < v.size(); i++)
            q.push(v[i]);
        c = 0;
        while (q.size() != 1) {
            c++;
            Node n1 = q.front();
            q.pop();
            Node n2 = q.front();
            if (c == n - 1)
                n--, c = 0, q.pop();
            q.push(Node(n1, n2));
        }
        printf("%d: %.4lf %.4lf\n", ++count, q.front().x, q.front().y);
    }
    return 0;
}

