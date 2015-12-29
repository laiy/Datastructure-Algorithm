#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

struct Node {
    int i, j, weight;
    Node(int i, int j, int weight) {
        this->i = i;
        this->j = j;
        this->weight = weight;
    }
    Node(const Node &n) {
        this->i = n.i;
        this->j = n.j;
        this->weight = n.weight;
    }
    bool operator<(const Node &n) const {
        return this->weight < n.weight;
    }
};

std::vector<Node> nodes;

short board[10][10];
bool col_space[10][10], row_space[10][10], block_space[3][3][10];
int solutions;
short record[10][10];
bool exist[10][10];

inline void update_weight(int i, int j) {
    if (exist[i][j])
        return;
    int weight = 9, k;
    for (k = 1; k < 10; k++)
        if (row_space[i][k] || col_space[j][k] || block_space[(i - 1) / 3][(j - 1) / 3][k])
            weight--;
    for (k = 0; (size_t)k < nodes.size(); k++)
        if (nodes[k].i == i && nodes[k].j == j)
            nodes[k].weight = weight;
}

inline void count_weight(int i, int j) {
    int k, v;
    for (k = 1; k < 10; k++)
        update_weight(i, k);
    for (k = 1; k < 10; k++)
        update_weight(k, j);
    i = ((i - 1) / 3) * 3 + 1;
    j = ((j - 1) / 3) * 3 + 1;
    for (k = 0; k < 3; k++)
        for (v = 0; v < 3; v++)
            update_weight(i + k, j + v);
}

void heuristic_dfs() {
    if (nodes.empty()) {
        if (!solutions)
            memcpy(record, board, sizeof(board));
        solutions++;
        return;
    }
    int k;
    std::sort(nodes.begin(), nodes.end());
    Node temp = Node(nodes[0]);
    nodes.erase(nodes.begin());
    std::queue<int> q;
    for (k = 1; k < 10; k++)
        if (!(row_space[temp.i][k] || col_space[temp.j][k] || block_space[(temp.i - 1) / 3][(temp.j - 1) / 3][k]))
            q.push(k);
    while (!q.empty()) {
        k = q.front();
        q.pop();

        row_space[temp.i][k] = true;
        col_space[temp.j][k] = true;
        block_space[(temp.i - 1) / 3][(temp.j - 1) / 3][k] = true;
        count_weight(temp.i, temp.j);
        board[temp.i][temp.j] = k;
        heuristic_dfs();
        board[temp.i][temp.j] = -1;
        row_space[temp.i][k] = false;
        col_space[temp.j][k] = false;
        block_space[(temp.i - 1) / 3][(temp.j - 1) / 3][k] = false;
        count_weight(temp.i, temp.j);
    }
    nodes.push_back(temp);
}

int main() {
    int t, i, j, k, weight, count = 1;
    scanf("%d", &t);
    char input[10];
    bool fuck = false;
    while (t--) {
        if (!fuck) {
            fuck = true;
        } else {
            printf("\n");
        }
        memset(board, -1, sizeof(board));
        memset(col_space, 0, sizeof(col_space));
        memset(row_space, 0, sizeof(row_space));
        memset(block_space, 0, sizeof(block_space));
        memset(exist, 0, sizeof(exist));
        solutions = 0;
        nodes.clear();
        for (i = 1; i <= 9; i++) {
            scanf("%s", input);
            for (j = 0; j < 9; j++) {
                if (input[j] != '_')
                    board[i][j + 1] = input[j] - '0', row_space[i][board[i][j + 1]] = true, col_space[j + 1][board[i][j + 1]] = true, \
                        block_space[(i - 1) / 3][(j) / 3][board[i][j + 1]] = true;
            }
        }
        for (i = 1; i <= 9; i++)
            for (j = 1; j <= 9; j++)
                if (board[i][j] == -1) {
                    weight = 9;
                    for (k = 1; k < 10; k++)
                        if (row_space[i][k] || col_space[j][k] || block_space[(i - 1) / 3][(j - 1) / 3][k])
                            weight--;
                    nodes.push_back(Node(i, j, weight));
                } else
                    exist[i][j] = true;
        heuristic_dfs();
        if (!solutions)
            printf("Puzzle %d has no solution\n", count++);
        else if (solutions > 1)
            printf("Puzzle %d has %d solutions\n", count++, solutions);
        else {
            printf("Puzzle %d solution is\n", count++);
            for (i = 1; i <= 9; i++) {
                for (j = 1; j <= 9; j++)
                    printf("%d", record[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}

