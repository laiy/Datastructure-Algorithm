#include <cstdio>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
#include <cstring>

struct state {
    int board;
    std::string record;
    state(int board, std::string record) {
        this->board = board;
        this->record = record;
    }
};

int invert[9] = {27, 63, 54, 219, 511, 438, 216, 504, 432};
bool visited[512];

inline std::string int_to_string(int i) {
    std::stringstream ss;
    ss << i;
    return ss.str();
}

int main() {
    int n, i, j, count, board, temp;
    char input[9];
    std::string ans;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", input);
        memset(visited, 0, sizeof(visited));
        count = 0;
        board = 0;
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                if (input[count++] == 'w')
                    board |= 1 << (count - 1);
        std::queue<state> q;
        q.push(state(board, ""));
        std::string ans;
        while (!q.empty()) {
            state s = q.front();
            visited[s.board] = true;
            q.pop();
            if (s.board == 511) {
                ans = s.record;
                break;
            }
            for (i = 0; i < 9; i++) {
                temp = invert[i] ^ s.board;
                if (!visited[temp])
                    q.push(state(temp, s.record + int_to_string(i + 1)));
            }
        }
        if (board == 511)
            printf("11\n");
        else
            std::cout << ans << std::endl;
    }
    return 0;
}

