#include <cstdio>
#include <vector>
#include <algorithm>

struct Plan {
    short end, length;
    float avg_planes;
    Plan(short end, short length, float avg_planes) {
        this->end = end;
        this->length = length;
        this->avg_planes = avg_planes;
    }
    bool operator<(const Plan &p) const {
        if (this->avg_planes != p.avg_planes)
            return this->avg_planes > p.avg_planes;
        else
            return (this->length != p.length) ? this->length > p.length : this->end < p.end;
    }
};

int main() {
    short n, k, numbers_of_quarters, numbers_of_output, minimum_numbers_of_quarters, i, j, t;
    scanf("%hd", &n);
    std::vector<Plan> v;
    float avg_planes;
    for (k = 1; k <= n; k++) {
        scanf("%hd %hd %hd", &numbers_of_quarters, &numbers_of_output, &minimum_numbers_of_quarters);
        short numbers_of_planes[numbers_of_quarters];
        short record[numbers_of_quarters+ 1][numbers_of_quarters + 1];
        for (i = 0; i < numbers_of_quarters; i++)
            scanf("%hd", numbers_of_planes + i);
        v.clear();
        for (j = minimum_numbers_of_quarters; j <= numbers_of_quarters; j++)
            for (i = 0; i <= numbers_of_quarters - j; i++) {
                avg_planes = 0;
                if (j == minimum_numbers_of_quarters) {
                    for (t = 0; t < j; t++)
                        avg_planes += numbers_of_planes[i + t];
                    record[i + 1][i + j] = avg_planes;
                } else {
                    avg_planes = record[i + 2][i + j] + numbers_of_planes[i];
                    record[i + 1][i + j] = avg_planes;
                }
                avg_planes /= j;
                v.push_back(Plan(i + j, j, avg_planes));
            }
        std::sort(v.begin(), v.end());
        printf("Result for run %hd:\n", k);
        for (i = 0; i < numbers_of_output && i < (short)v.size(); i++)
            printf("%hd-%hd\n", (short)(v[i].end - v[i].length + 1), v[i].end);
    }
    return 0;
}

