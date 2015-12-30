#include <cstdio>
#include <cstring>

short board[10][10];
bool col_space[10][10], row_space[10][10], block_space[3][3][10];
short record[10][10];
short nodes[10][10];
int solutions, i, j, min, weight, k, m, v, c, update_value;

inline void update_weight(int &i, int &j) {
    if (nodes[i][j] == -1 || row_space[i][update_value] || col_space[j][update_value] || \
            block_space[(i - 1) / 3][(j - 1) / 3][update_value])
        return;
    nodes[i][j]--;
}

inline void count_weight(int i, int j) {
    static int count_record_i, count_record_j;
    count_record_i = i, count_record_j = j;
    for (m = 1; m < 10; m++)
        if (m != count_record_j)
            update_weight(i, m);
    for (m = 1; m < 10; m++)
        if (m != count_record_i)
            update_weight(m, j);
    i = ((i - 1) / 3) * 3 + 1;
    j = ((j - 1) / 3) * 3 + 1;
    for (m = i; m < i + 3; m++)
        for (v = j; v < j + 3; v++)
            if (m != count_record_i && v != count_record_j)
                update_weight(m, v);
}

inline void heuristic_dfs() {
    if (!c) {
        if (!solutions)
            memcpy(record, board, sizeof(board));
        solutions++;
        return;
    }
    min = 10;
    short record_i, record_j, k;
    for (i = 1; i <= 9; i++)
        for (j = 1; j <= 9; j++)
            if (nodes[i][j] != -1 && nodes[i][j] < min)
                min = nodes[i][j], record_i = i, record_j = j;
    short board_record_i = (record_i - 1) / 3, board_record_j = (record_j - 1) / 3;
    c--;
    nodes[record_i][record_j] = -1;
    short temp[10][10];
    memcpy(temp, nodes, sizeof(nodes));
    for (k = 1; k < 10; k++)
        if (!(row_space[record_i][k] || col_space[record_j][k] || block_space[board_record_i][board_record_j][k])) {
            update_value = k;
            count_weight(record_i, record_j);
            row_space[record_i][k] = true;
            col_space[record_j][k] = true;
            block_space[board_record_i][board_record_j][k] = true;
            board[record_i][record_j] = k;
            heuristic_dfs();
            row_space[record_i][k] = false;
            col_space[record_j][k] = false;
            block_space[board_record_i][board_record_j][k] = false;
            memcpy(nodes, temp, sizeof(nodes));
        }
    c++;
    nodes[record_i][record_j] = min;
}

int main() {
    int t, count = 1;
    scanf("%d", &t);
    char input[10];
    while (t--) {
        if (count != 1)
            printf("\n");
        memset(board, -1, sizeof(board));
        memset(nodes, -1, sizeof(nodes));
        memset(col_space, 0, sizeof(col_space));
        memset(row_space, 0, sizeof(row_space));
        memset(block_space, 0, sizeof(block_space));
        solutions = 0;
        for (i = 1; i <= 9; i++) {
            scanf("%s", input);
            for (j = 0; j < 9; j++) {
                if (input[j] != '_')
                    board[i][j + 1] = input[j] - '0', row_space[i][board[i][j + 1]] = true, col_space[j + 1][board[i][j + 1]] = true, \
                        block_space[(i - 1) / 3][(j) / 3][board[i][j + 1]] = true;
            }
        }
        c = 0;
        for (i = 1; i <= 9; i++)
            for (j = 1; j <= 9; j++)
                if (board[i][j] == -1) {
                    weight = 9;
                    for (k = 1; k < 10; k++)
                        if (row_space[i][k] || col_space[j][k] || block_space[(i - 1) / 3][(j - 1) / 3][k])
                            weight--;
                    nodes[i][j] = weight;
                    c++;
                }
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

