/*************************************************************************
	> File Name: w7-5-5.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Saturday, November 15, 2014 PM02:27:43 CST
 ************************************************************************/

#include <cstdio>
#include <cstring>

struct bad_char_table {
    int record[256][256];
    int index_record[256];
} b_table;

int code[60000];
int gate_protection[60000];
int length_of_the_code, number_of_intergers_in_gate_protection;

int last_appear_position(int target, int temp_position) {
    for (int i = 0; i < b_table.index_record[target] - 1; i++) {
        if (b_table.record[target][i + 1] == temp_position) return b_table.record[target][i];
    }
    return -1;
}

void BM_search() {
    int index = 0, bad_char_step;
    while (index + length_of_the_code < number_of_intergers_in_gate_protection) {
        for (int i = length_of_the_code - 1; i >= 0; i--) {
            if (code[i] != gate_protection[index + i]) {
                bad_char_step = i - last_appear_position(gate_protection[index + i], i);
                index += bad_char_step;
                break;
            }
            if (!i) {
                printf("%d\n", index);
                return;
            }
        }
    }
    printf("no solution.\n");
}

int main() {
    while (scanf("%d", &length_of_the_code) != EOF) {
        memset(bad_char_table.record, 0, sizeof(int));
        memset(b_table.index_record, 0, sizeof(int));
        for (int i = 0; i < length_of_the_code; i++) {
            scanf("%d", &code[i]);
            b_table.record[code[i]][b_table.index_record[code[i]]++] = i;
        }
        scanf("%d", &number_of_intergers_in_gate_protection);
        for (int i = 0; i < number_of_intergers_in_gate_protection; i++) scanf("%d", &gate_protection[i]);
        BM_search();
    }
    return 0;
}

