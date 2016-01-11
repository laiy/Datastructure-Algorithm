#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

#define max(x, y) x > y ? x : y

struct Pos {
    double pos;
    std::string name;
    char dir;
    Pos(double pos, std::string name, char dir) {
        this->pos = pos;
        this->name = name;
        this->dir = dir;
    }
};

int main() {
    int n, ind, limit, i;
    double l, v, len, maxn, pos;
    std::string name;
    char dir;
    bool zero;
    double last[32005];
    while (scanf("%d", &n), n) {
        scanf("%lf %lf", &l, &v);
        maxn = 0;
        std::vector<Pos> ve;
        for(i = 0; i < n; i++) {
            std::cin >> dir >> pos >> name;
            if (dir == 'p' || dir == 'P')
                len = l - pos;
            else
                len = pos;
            maxn = max(maxn, len);
            ve.push_back(Pos(pos, name, dir));
        }
        zero = false;
        for (i = 0; i < n; i++) {
            if (ve[i].dir == 'p' || ve[i].dir == 'P')
                last[i] = ve[i].pos + maxn;
            else
                last[i] = ve[i].pos - maxn;
            if (last[i] == 0)
                zero = true;
        }
        ind = 0, limit = l;
        if (zero)
            limit = 0;
        for (i = 0; i < n;i++)
            if (last[i] < limit)
                ind++;
        printf("%13.2lf %s\n", (int)(maxn / v * 100) / 100.0, ve[ind].name.c_str());
    }
}

