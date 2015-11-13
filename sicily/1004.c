#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

#define INF 1e9
#define ESP 1e-6
#define max(a, b) a > b ? a : b

inline bool equal(double a, double b) {
    return fabs(a - b) <= ESP;
}

struct Line {
    double x1, y1, x2, y2;
    double k, b;
    Line(double &x1, double &y1, double &x2, double &y2, double &k, double &b) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->k = k;
        this->b = b;
    }
    bool operator<(const Line &l) const {
        if (!equal(k, l.k))
            return k < l.k;
        if (!equal(b, l.b))
            return b < l.b;
        if (!equal(x1, l.x1))
            return x1 < l.x1;
        if (!equal(y1, l.y1))
            return y1 < l.y1;
        if (!equal(x2, l.x2))
            return x2 < l.x2;
        return y2 < l.y2;
    }
};


inline void swap(double &a, double &b) {
    double t = a;
    a = b;
    b = t;
}

inline bool judge(Line a, Line b) {
    if (equal(a.k, b.k) && equal(a.b, b.b)) {
        if (equal(a.k, INF))
            return equal(b.y1, a.y2) || b.y1 < a.y2;
        else
            return equal(a.x2, b.x1) || a.x2 > b.x1;
    }
    return false;
}

int main(){
    int n, ans, i;
    double x1, y1, x2, y2, k, b;
    bool flag;
    while (scanf("%d", &n) && n != 0) {
        std::vector<Line> v;
        ans = n;
        for (i = 0; i < n ;i++) {
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            flag = equal(x1, x2);
            if(flag && y1 > y2)
                swap(y1, y2);
            else if(!flag && x1 > x2) {
                swap(x1, x2);
                swap(y1, y2);
            }
            k = flag ? INF : (y2 - y1) / (x2 - x1);
            b = flag ? x1 : y1 - k * x1;
            v.push_back(Line(x1, y1, x2, y2, k, b));
        }
        std::sort(v.begin(), v.end());
        for (i = 0; i < n - 1; i++) {
            if (judge(v[i], v[i + 1])) {
                ans--;
                if (equal(v[i].k, INF))
                    v[i + 1].y2 = max(v[i].y2, v[i + 1].y2);
                else
                    v[i + 1].x2 = max(v[i].x2, v[i + 1].x2);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

