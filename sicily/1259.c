#include <cstdio>
#include <vector>
#include <cstring>

std::vector<int> primes;

void init_prime_table() {
    bool is_prime[10001];
    memset(is_prime, 1, sizeof(is_prime));
    for (int i = 2; i <= 10000; i++)
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= 10000; j += i)
                is_prime[j] = false;
        }
}

int numbers_of_consecutive_prime_sum_representation(int &n) {
    static int i, ans, j, temp;
    ans = 0;
    for (i = 0; (size_t)i < primes.size() && primes[i] <= n; i++) {
        temp = 0;
        for (j = i; (size_t)j <= primes.size() && temp <= n; j++) {
            temp += primes[j];
            if (temp == n) {
                ans++;
                break;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    init_prime_table();
    while (scanf("%d", &n) && n) {
        printf("%d\n", numbers_of_consecutive_prime_sum_representation(n));
    }
    return 0;
}

