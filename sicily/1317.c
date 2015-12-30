#include <cstdio>
#include <cstring>

int solutions;
int row_space[9], col_space[9], block_space[9];
int board[9][9], record[9][9];
int digit_table[(1 << 8) + 1];

void dfs(int i, int j) {
    while (i >= 0 && board[i][j])
        if (j)
            j--;
        else
            i--, j = 8;
    if (i == -1) {
        if (!solutions)
            memcpy(record, board, sizeof(board));
        solutions++;
        return;
    }
    int block_index = i / 3 * 3 + j / 3;
    int space = row_space[i] & col_space[j] & block_space[block_index];
    int put;
    while (space) {
        put = space & (-space);
        space ^= put;
        board[i][j] = digit_table[put];
        row_space[i] ^= put;
        col_space[j] ^= put;
        block_space[block_index] ^= put;
        dfs(i, j);
        row_space[i] ^= put;
        col_space[j] ^= put;
        block_space[block_index] ^= put;
    }
    board[i][j] = 0;
}

int main() {
    int t, count = 1, i, j, init, mask;
    scanf("%d", &t);
    char input[10];
    init = (1 << 9) - 1;
    for (int i = 0; i < 9; i++)
        digit_table[1 << i] = i + 1;
    while (t--) {
        if (count != 1)
            printf("\n");
        solutions = 0;
        for (i = 0; i < 9; i++)
            row_space[i] = col_space[i] = block_space[i] = init;
        memset(board, 0, sizeof(board));
        for (i = 0; i < 9; i++) {
            scanf("%s", input);
            for (j = 0; j < 9; j++)
                if (input[j] != '_') {
                    board[i][j] = input[j] - '0';
                    mask = ~(1 << (board[i][j] - 1));
                    row_space[i] &= mask;
                    col_space[j] &= mask;
                    block_space[i / 3 * 3 + j / 3] &= mask;
                }
        }
        dfs(8, 8);
        if (!solutions)
            printf("Puzzle %d has no solution\n", count++);
        else if (solutions > 1)
            printf("Puzzle %d has %d solutions\n", count++, solutions);
        else {
            printf("Puzzle %d solution is\n", count++);
            for (i = 0; i < 9; i++) {
                for (j = 0; j < 9; j++)
                    printf("%d", record[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}

