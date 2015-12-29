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
};

std::vector<Node*> nodes;

short board[10][10];
Node *map[10][10];
bool col_space[10][10], row_space[10][10], block_space[3][3][10];
int solutions;
short record[10][10];
bool exist[10][10];

bool cmp(const Node* a, const Node* b) {
    return a->weight < b->weight;
}

inline void update_weight(int i, int j) {
    if (exist[i][j])
        return;
    int weight = 9, k;
    for (k = 1; k < 10; k++)
        if (row_space[i][k] || col_space[j][k] || block_space[(i - 1) / 3][(j - 1) / 3][k])
            weight--;
    map[i][j]->weight = weight;
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
    /* printf("%d\n", (int)nodes.size()); */
    if (nodes.empty()) {
        if (!solutions)
            memcpy(record, board, sizeof(board));
        solutions++;
        return;
    }
    int k;
    std::sort(nodes.begin(), nodes.end(), cmp);
    printf("%d\n", nodes[0]->weight);
    std::queue<int> q;
    for (k = 1; k < 10; k++)
        if (!row_space[nodes[0]->i][k] && !col_space[nodes[0]->j][k] && !block_space[(nodes[0]->i - 1) / 3][(nodes[0]->j - 1) / 3][k])
            q.push(k);
    while (!q.empty()) {
        k = q.front();
        q.pop();

        row_space[nodes[0]->i][k] = true;
        col_space[nodes[0]->j][k] = true;
        block_space[(nodes[0]->i - 1) / 3][(nodes[0]->j - 1) / 3][k] = true;

        count_weight(nodes[0]->i, nodes[0]->j);

        /* printf("i: %d j: %d k: %d\n", nodes[0]->i, nodes[0]->j, k); */

        board[nodes[0]->i][nodes[0]->j] = k;
        Node* temp = nodes[0];
        nodes.erase(nodes.begin());

        heuristic_dfs();

        nodes.insert(nodes.begin(), temp);
        board[nodes[0]->i][nodes[0]->j] = -1;

        row_space[nodes[0]->i][k] = false;
        col_space[nodes[0]->j][k] = false;
        block_space[(nodes[0]->i - 1) / 3][(nodes[0]->j - 1) / 3][k] = false;

        count_weight(nodes[0]->i, nodes[0]->j);
    }
}

int main() {
    int t, i, j, k, weight, count = 1;
    scanf("%d", &t);
    char input;
    while (t--) {
        memset(board, -1, sizeof(board));
        memset(col_space, 0, sizeof(col_space));
        memset(row_space, 0, sizeof(row_space));
        memset(block_space, 0, sizeof(block_space));
        memset(exist, 0, sizeof(exist));
        memset(map, 0, sizeof(map));
        solutions = 0;
        nodes.clear();
        for (i = 1; i <= 9; i++)
            for (j = 1; j <= 9; j++) {
                scanf("%c", &input);
                if (input != '_')
                    board[i][j] = input - '0', row_space[i][board[i][j]] = true, col_space[j][board[i][j]] = true, \
                        block_space[(i - 1) / 3][(j - 1) / 3][board[i][j]] = true;
            }
        for (i = 1; i <= 9; i++)
            for (j = 1; j <= 9; j++)
                if (board[i][j] == -1) {
                    weight = 9;
                    for (k = 1; k < 10; k++)
                        if (row_space[i][k] || col_space[j][k] || block_space[(i - 1) / 3][(j - 1) / 3][k])
                            weight--;
                    Node node = Node(i, j, weight);
                    map[i][j] = &node;
                    nodes.push_back(&node);
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
        printf("\n");
    }
    return 0;
}

