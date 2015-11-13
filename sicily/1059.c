#include <cstdio>
#include <cmath>

#define EPS 1e-8

int main() {
    int t;
    double x1, y1, x2, y2, x3, y3, x, y;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
        x = (x3 * (x2 - x1) * (y3 - y1) - (y2 - y1) * ((x3 - x1) * x2 + (y2 - y3) * (y3 - y1)))
            / ((x2 - x1) * (y3 - y1) + (y2 - y1) * (x1 - x3));
        y = (fabs(x - x3) < EPS) ? y2 + (x3 - x1) * (x - x2) / (y1 - y3) : y3 + (x2 - x1) * (x - x3) / (y1 - y2);
        printf("%.4f %.4f\n", x + EPS, y + EPS);
    }
    return 0;
}

