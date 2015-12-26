#include <cstdio>
#include <vector>
#include <cstring>

#define PRIME_TABLE_SIZE 1000001

std::vector<int> primes;

inline void init_prime_table() {
    bool is_prime[PRIME_TABLE_SIZE + 1];
    memset(is_prime, 1, sizeof(is_prime));
    for (int i = 2; i <= PRIME_TABLE_SIZE; i++)
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= PRIME_TABLE_SIZE; j += i)
                is_prime[j] = false;
        }
}

char k[102];
int length, j, t;
int pieces[12], num_pieces;
long long result;

inline int str_to_int(char *str, int l) {
    result = 0, j = 0;
    while (j < l)
        result = result * 10 + str[j++] - '0';
    return result;
}

inline bool mod_equal_zero(int b) {
    t = 1000000000 % b;
    result = 0;
    for (j = 0; j < num_pieces; j++)
        result = (result * t + pieces[j] % b) % b;
    return result == 0;
}

int main() {
    int l, i;
    bool bad;
    char *p;
    init_prime_table();
    while (scanf("%s %d", k, &l) && !(l == 0 && k[0] == '0')) {
        bad = false;
        length = strlen(k);
        num_pieces = length / 9 + 1;
        p = k;
        pieces[0] = str_to_int(p, length % 9);
        p += length % 9;
        for (i = 1; i < num_pieces; i++)
            pieces[i] = str_to_int(p, 9), p += 9;
        for (i = 0; (size_t)i < primes.size() && primes[i] < l; i++) {
            if (mod_equal_zero(primes[i])) {
                printf("BAD %d\n", primes[i]);
                bad = true;
                break;
            }
        }
        if (!bad)
            printf("GOOD\n");
    }
    return 0;
}

