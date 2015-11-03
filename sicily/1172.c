#include <vector>
#include <cstdio>
#include <cstring>

int n, m;

inline bool is_valid(int r, int c) {
    return r >= 1 && r <= n && c >= 1 && c <= m;
}

int direction_x[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int direction_y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int queen_x[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
int queen_y[8] = {0, 0, 1, -1, 1, -1, -1, 1};

struct queen {
    int x, y;
    queen(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    int k, r, c, i, j, temp_r, temp_c, ans, count = 0;
    while (scanf("%d %d", &n, &m) && !(n == 0 && m == 0)) {
        ans = 0;
        bool unsafe[n + 1][m + 1];
        bool visited[n + 1][m + 1];
        memset(unsafe, 0, sizeof(unsafe));
        memset(visited, 0, sizeof(visited));
        std::vector<queen> v;
        scanf("%d", &k);
        for (i = 0; i < k; i++)
            scanf("%d %d", &r, &c), v.push_back(queen(r, c)), visited[r][c] = true;;
        scanf("%d", &k);
        for (i = 0; i < k; i++) {
            scanf("%d %d", &r, &c);
            visited[r][c] = true;
            if (!unsafe[r][c])
                unsafe[r][c] = true, ans++;
            for (j = 0; j < 8; j++) {
                temp_r =  r + direction_x[j];
                temp_c =  c + direction_y[j];
                if (is_valid(temp_r, temp_c) && !unsafe[temp_r][temp_c])
                    unsafe[temp_r][temp_c] = true, ans++;
            }
        }
        scanf("%d", &k);
        for (i = 0; i < k; i++) {
            scanf("%d %d", &r, &c);
            visited[r][c] = true;
            if (!unsafe[r][c])
                unsafe[r][c] = true, ans++;
        }
        for (i = 0; (size_t)i < v.size(); i++) {
            r = v[i].x;
            c = v[i].y;
            if (!unsafe[r][c])
                unsafe[r][c] = true, ans++;
            for (j = 0; j < 8; j++) {
                temp_r = r + queen_x[j];
                temp_c = c + queen_y[j];
                while (is_valid(temp_r, temp_c) && !visited[temp_r][temp_c]) {
                    if (!unsafe[temp_r][temp_c])
                        unsafe[temp_r][temp_c] = true, ans++;
                    temp_r += queen_x[j];
                    temp_c += queen_y[j];
                }
            }
        }
        printf("Board %d has %d safe squares.\n", ++count, n * m - ans);
    }
}

