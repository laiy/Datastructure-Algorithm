#include <cstdio>
#include <cstring>

int len;

bool minus(char *p) {
    if (p[len - 1] % 2 == 0) {
        int t = 0;
        for (int i = 0; i < len; i++) {
            t = (t * 10 + (p[i] - '0'));
            p[i] = (t / 2) + '0';
            t %= 2;
        }
        if (p[0] == '0') {
            len--;
            for (int i = 0; i < len; i++)
                p[i] = p[i + 1];
            p[len] = '\0';
        }
        return true;
    }
    return false;
}

int main() {
    int t, times, c = 0;
    char p[102];
    scanf("%d", &t);
    bool fuck = false;
    while (t--) {
        if (fuck)
            printf("\n");
        else
            fuck = true;
        scanf("%s", p);
        len = strlen(p);
        times = 1;
        while (true) {
            if (minus(p))
                times++;
            else
                break;
        }
        printf("Case %d: %d\n", ++c, times);
    }
    return 0;
}

