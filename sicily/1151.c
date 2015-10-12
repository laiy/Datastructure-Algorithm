#include <cstdio>
#include <queue>
#include <hash_map>

int a[] = {1, 2, 3, 4, 8, 7, 6, 5};

__gnu_cxx::hash_map<int, char> record;

inline int OP_A(int n) {
    return (n & 4095) << 12 | n >> 12;
}

inline int OP_B(int n) {
    return (( 7 << 9 | 7 << 21 ) & n) >> 9 | (~(7 << 9 | 7 << 21) & n) << 3;
}

inline int OP_C(int n) {
    return ((7 | 7 << 9 | 7 << 12 | 7 << 21) & n) | ((7 << 3) & n) << 3 | ((7 << 6) & n) << 12 | ((7 << 15) & n) >> 12 | ((7 << 18) & n) >> 3;
}

inline int resume_B(int n) {
    return ((7 | 7 << 12) & n) << 9 | (~(7 | 7 << 12) & n) >> 3;
}

inline int resume_C(int n) {
    return ((7 | 7 << 9 | 7 << 12 | 7 << 21) & n) | ((7 << 3) & n) << 12 | ((7 << 6) & n) >> 3 | ((7 << 15) & n) << 3 | ((7 << 18) & n) >> 12;
}

inline int zip(int *a) {
    int code = 0;
    for (int i = 0; i < 8; ++i)
        code |= (a[i] - 1) << (3 * i);
    return  code;
}

void bfs() {
    int temp, code;
    std::queue<int> q;
    q.push(zip(a));
    while (!q.empty()) {
        code = q.front();
        q.pop();
        temp = OP_A(code);
        if (!record[temp])
            record[temp] = 'A', q.push(temp);
        temp = OP_B(code);
        if (!record[temp])
            record[temp] = 'B', q.push(temp);
        temp = OP_C(code);
        if (!record[temp])
            record[temp] = 'C', q.push(temp);
    }
}

int main() {
    bfs();
    int n, arr[8], i, j, origin = zip(a);
    char s[100];
    while (scanf("%d", &n) && n != -1) {
        for (i = 0; i < 8; i++)
            scanf("%d", arr + i);
        for (i = zip(arr), j = 0; i != origin && j < n; j++) {
            s[j] = record[i];
            switch (s[j]) {
                case 'A':
                    i = OP_A(i);
                    break;
                case 'B':
                    i = resume_B(i);
                    break;
                case 'C':
                    i = resume_C(i);
                    break;
            }
        }
        if (i != origin)
            printf("-1\n");
        else {
            printf("%d ", j);
            while (j--)
                putchar(s[j]);
            putchar('\n');
        }
    }
    return 0;
}

