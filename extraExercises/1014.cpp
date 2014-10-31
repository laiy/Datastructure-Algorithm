/*
 *method1: spfa
 *#include<cstdio>
 *#include<cstring>
 *#include<queue>
 *#define MAXN 2010
 *#define MAXNF 210
 *#define INF 0x3f3f3f3f
 *
 *int n, m, e, a, b, c, s, t;
 *std::queue<int> q;
 *int v[MAXN], d[MAXN], next[MAXN], w[MAXN], first[MAXNF];
 *bool inq[MAXNF];
 *
 *void init() {
 *    e = 0;
 *    memset(first, -1, sizeof(first));
 *}
 *
 *void add_edge(int a, int b, int c) {
 *    v[e] = b;
 *    w[e] = c;
 *    next[e] = first[a];
 *    first[a] = e++;
 *}
 *
 *void spfa(int st) {
 *    memset(d, 0x3f, sizeof(d));
 *    d[st] = 0; 
 *    inq[st] = true;
 *    q.push(st);
 *    while(!q.empty()) {
 *        int u = q.front();
 *        q.pop();
 *        inq[u] = 0;
 *        for(int i = first[u]; i != -1; i = next[i]) {
 *            if(d[v[i]] > d[u]+w[i]) {
 *                d[v[i]] = d[u]+w[i];
 *                if(!inq[v[i]]) q.push(v[i]), inq[v[i]] = true;
 *            }
 *        }
 *    }
 *}
 *
 *int main() {
 *    while(~scanf("%d%d",&n,&m)) {
 *       init();
 *       for(int i=0;i<m;i++) {
 *           scanf("%d%d%d", &a, &b, &c);
 *           add_edge(a, b, c);
 *           add_edge(b, a, c);
 *       }
 *       scanf("%d%d", &s, &t);
 *       spfa(s);
 *       printf("%d\n", d[t] == INF ? -1 : d[t]);
 *    }
 *    return 0;
 *}
 */

/*
 *method2: Dijkstra
 */

#include <stdio.h>
#define N 10000000

int dis[200], map[200][200];
bool visited[200];
int n;

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = N;
        }
        dis[i] = N;
        visited[i] = false;
    }
}

int Dijkstra(int s, int t) {
    int min, pre = s;
    dis[s] = 0;
    while (true) {
        visited[pre] = true;
        if (pre == t) break;
        for (int i = 0; i < n; i++) {
            if (map[pre][i] != N && !visited[i]) {
                dis[i] = (dis[i] <= dis[pre] + map[pre][i]) ? dis[i] : dis[pre] + map[pre][i];
            }
        }
        min = N;
        pre = -1;
        for (int i= 0; i < n; i++) {
            if (dis[i] < min && !visited[i]) {
                min = dis[i];
                pre = i;
            }
        }
        if (pre == -1) break;
    }
    return ((pre== -1) ? -1 : dis[pre]);
}

int main() {
    int s, t, x, m, a, b;
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        while (m--) {
            scanf("%d%d%d", &a, &b, &x);
            if (x < map[a][b]) {
                map[a][b] = map[b][a] = x;
            }
        }
        scanf("%d%d", &s, &t);
        printf("%d\n", Dijkstra(s, t));
    }
    return 0;
}

