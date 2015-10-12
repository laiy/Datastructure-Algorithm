#include <cstdio>
#include <iostream>
#include <hash_map>
#include <hash_set>
#include <string>
#include <queue>

using namespace __gnu_cxx;

int a[] = {1, 2, 3, 4, 8, 7, 6, 5};
__gnu_cxx::hash_map<int, std::string> record;

struct Node {
    int code;
    std::string step;
    Node(int c, std::string s) {
        this->code = c;
        this->step = s;
    }
};

inline  int OP_A(int n) {
    return (n & 4095) << 12 | n >> 12;
}

inline int OP_B(int n) {
    return (( 7 << 9 | 7 << 21 ) & n) >> 9 | (~( 7 << 9 | 7 << 21 ) & n) << 3;
}

inline int OP_C(int n) {
    return ((7 | 7 << 9 | 7 << 12 | 7 << 21) & n) | ((7 << 3) & n) << 3 | ((7 << 6) & n) << 12 | ((7 << 15) & n) >> 12 | ((7 << 18) & n) >> 3;
}

inline int zip(int *a) {
    int code = 0;
    for (int i = 0; i < 8; ++i)
        code |= (a[i] - 1) << (3 * i);
    return  code;
}

void bfs() {
    std::queue<Node> q;
    q.push(Node(zip(a), ""));
    __gnu_cxx::hash_set<int> visited;
    while (!q.empty()) {
        Node temp = q.front();
        q.pop();
        if (visited.find(temp.code) != visited.end())
            continue;
        visited.insert(temp.code);
        record[temp.code] = temp.step;
        q.push(Node(OP_A(temp.code), temp.step + "A"));
        q.push(Node(OP_B(temp.code), temp.step + "B"));
        q.push(Node(OP_C(temp.code), temp.step + "C"));
    }
}

int main() {
    bfs();
    int n, arr[8], i, code;
    while (scanf("%d", &n) && n != -1) {
        for (i = 0; i < 8; i++)
            scanf("%d", arr + i);
        code = zip(arr);
        if (record[code].length() <= (size_t)n)
            std::cout << record[code].length() << " " << record[code] << std::endl;
        else
            printf("-1\n");
    }
    return 0;
}

