#include <cstdio>
#include <vector>
#include <algorithm>

struct piece {
    int xl, yl, xh, yh;
    piece(int xl, int yl, int xh, int yh) {
        this->xl = xl;
        this->yl = yl;
        this->xh = xh;
        this->yh = yh;
    }
};

typedef struct floor {
    std::vector<piece> pieces;
    int from_x, from_y, to_x, to_y;
    floor(int from_x, int from_y, int to_x, int to_y) {
        this->from_x = from_x;
        this->from_y = from_y;
        this->to_x = to_x;
        this->to_y = to_y;
    }
} Floor;

struct line {
    int from_x, from_y, to_x, to_y;
    line(int from_x, int from_y, int to_x, int to_y) {
        this->from_x = from_x;
        this->from_y = from_y;
        this->to_x = to_x;
        this->to_y = to_y;
    }
};

bool horizontal_lines_cmp(const line &l1, const line &l2) {
    return (l1.from_x != l2.from_x) ? l1.from_x < l2.from_x : (l1.from_y == l2.from_y) ? l1.to_y < l2.to_y : l1.from_y < l2.from_y;
}

bool vertical_lines_cmp(const line &l1, const line &l2) {
    return (l1.from_y != l2.from_y) ? l1.from_y < l2.from_y : (l1.from_x == l2.from_x) ? l1.to_x < l2.to_x : l1.from_x < l2.from_x;
}

int ans;

void dfs(Floor f) {
    std::vector<line> horizontal_lines;
    std::vector<line> vertical_lines;
    int floor_height = f.to_x - f.from_x;
    int floor_width = f.to_y - f.from_y;
    for (int i = 0; (size_t)i < f.pieces.size(); i++) {
        horizontal_lines.push_back(line(f.pieces[i].xl, f.pieces[i].yl, f.pieces[i].xl, f.pieces[i].yh));
        horizontal_lines.push_back(line(f.pieces[i].xh, f.pieces[i].yl, f.pieces[i].xh, f.pieces[i].yh));
        vertical_lines.push_back(line(f.pieces[i].xl, f.pieces[i].yl, f.pieces[i].xh, f.pieces[i].yl));
        vertical_lines.push_back(line(f.pieces[i].xl, f.pieces[i].yh, f.pieces[i].xh, f.pieces[i].yh));
    }
    std::sort(horizontal_lines.begin(), horizontal_lines.end(), horizontal_lines_cmp);
    int temp_x = -1, start_y, end_y;
    for (int i = 0; (size_t)i < horizontal_lines.size(); i++) {
        if (horizontal_lines[i].from_x != temp_x) {
            if (i) {
                if (end_y - start_y == floor_width && temp_x != f.from_x && temp_x != f.to_x) {
                    Floor up = Floor(f.from_x, f.from_y, temp_x, f.to_y);
                    Floor down = Floor(temp_x, f.from_y, f.to_x, f.to_y);
                    for (int j = 0; (size_t)j < f.pieces.size(); j++) {
                        if (f.pieces[j].xh <= temp_x)
                            up.pieces.push_back(f.pieces[j]);
                        else
                            down.pieces.push_back(f.pieces[j]);
                    }
                    dfs(up);
                    dfs(down);
                    return;
                }
            }
            temp_x = horizontal_lines[i].from_x;
            start_y = horizontal_lines[i].from_y;
            end_y = horizontal_lines[i].to_y;
        } else {
            if (horizontal_lines[i].from_y == end_y)
                end_y = horizontal_lines[i].to_y;
        }
    }
    std::sort(vertical_lines.begin(), vertical_lines.end(), vertical_lines_cmp);
    int temp_y = -1, start_x, end_x;
    for (int i = 0; (size_t)i < vertical_lines.size(); i++) {
        if (vertical_lines[i].from_y != temp_y) {
            if (i) {
                if (end_x - start_x == floor_height && temp_y != f.from_y && temp_y != f.to_y) {
                    Floor left = Floor(f.from_x, f.from_y, f.to_x, temp_y);
                    Floor right = Floor(f.from_x, temp_y, f.to_x, f.to_y);
                    for (int j = 0; (size_t)j < f.pieces.size(); j++) {
                        if (f.pieces[j].yh <= temp_y)
                            left.pieces.push_back(f.pieces[j]);
                        else
                            right.pieces.push_back(f.pieces[j]);
                    }
                    dfs(left);
                    dfs(right);
                    return;
                }
            }
            temp_y = vertical_lines[i].from_y;
            start_x = vertical_lines[i].from_x;
            end_x = vertical_lines[i].to_x;
        } else {
            if (vertical_lines[i].from_x == end_x)
                end_x = vertical_lines[i].to_x;
        }
    }
    if (floor_width * floor_height > ans)
        ans = floor_width * floor_height;
}

int main() {
    int t, length, width, n, xl, yl, xh, yh;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &length, &width);
        scanf("%d", &n);
        std::vector<piece> piece_v;
        for (int i = 0; i < n; i++)
            scanf("%d %d %d %d", &xl, &yl, &xh, &yh), piece_v.push_back(piece(xl, yl, xh, yh));
        Floor f = Floor(0, 0, length, width);
        f.pieces = piece_v;
        ans = 0;
        dfs(f);
        printf("%d\n", (ans) ? ans : width * length);
    }
    return 0;
}

