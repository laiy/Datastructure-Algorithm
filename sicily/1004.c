#include <cstdio>
#include <vector>
#include <cmath>

#define DEVIATION 0.00001
#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

struct Line {
    double x1, x2, y1, y2;
    Line(double x1, double x2, double y1, double y2) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
};

inline bool equal(double a, double b) {
    return fabs(a - b) < DEVIATION;
}

inline bool coincide(Line a, Line b) {
    if (equal(a.x1, a.x2) && equal(b.x1, b.x2) && equal(b.x1, a.x1)) {
        if ((a.y1 <= b.y2 && a.y1 >= b.y1) || (a.y2 <= b.y2 && a.y2 >= b.y1) || (a.y1 <= b.y1 && a.y1 >= b.y2) || (a.y2 <= b.y1 && a.y2 >= b.y2)) {
            a.y1 = min(b.y2, min(b.y1, min(a.y1, a.y2))), a.y2 = max(b.y2, max(b.y1, max(a.y1, a.y2)));
            return true;
        }
        return false;
    }
    static double temp;
    temp = (a.x1 - a.x2) / (a.y1 - a.y2);
    if (equal(temp, (b.x1 - b.x2) / (b.y1 - b.y2)) && equal((a.x1 - b.x1) / (a.y1 - b.y1), temp))
        if ((a.x1 <= b.x2 && a.x1 >= b.x1) || (a.x2 <= b.x2 && a.x2 >= b.x1) || (a.x1 <= b.x1 && a.x1 >= b.x2) || (a.x2 <= b.x1 && a.x2 >= b.x2)) {
            if (temp > 0)
                a.y1 = min(b.y2, min(b.y1, min(a.y1, a.y2))), a.y2 = max(b.y2, max(b.y1, max(a.y1, a.y2))), a.x1 = min(a.x1, min(a.x2, min(b.x1, b.x2))), a.x2 = max(a.x1, max(a.x2, max(b.x1, b.x2)));
            else
                a.y1 = min(b.y2, min(b.y1, min(a.y1, a.y2))), a.y2 = max(b.y2, max(b.y1, max(a.y1, a.y2))), a.x2 = min(a.x1, min(a.x2, min(b.x1, b.x2))), a.x1 = max(a.x1, max(a.x2, max(b.x1, b.x2)));
            return true;
        }
    return false;
}

int main() {
    int n, i, count, total;
    double x1, y1, x2, y2;
    bool found;
    while (scanf("%d", &n) && n != 0) {
        count = 0;
        std::vector<Line> v;
        total = n;
        while (n--) {
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            Line l = Line(x1, x2, y1, y2);
            found = false;
            for (i = 0; (size_t)i < v.size(); i++)
                if (coincide(v[i], l)) {
                    found = true;
                    count++;
                    break;
                }
            if (!found)
                v.push_back(l);

        }
        printf("%d\n", total - count);
    }
}

