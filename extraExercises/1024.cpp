#include <stdio.h>
#include <string.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

struct Map {
    int distance[101][101];
    int number_of_city;
    int start, end;
};

int maximin_distance(Map* map) {
    for (int i = 1; i <= map->number_of_city; i++) map->distance[i][i] = 0;
    for (int k = 1; k <= map->number_of_city; k++)
        for (int i = 1; i <= map->number_of_city; i++)
            for (int j = 1; j <= map->number_of_city; j++)
                map->distance[i][j] = max(map->distance[i][j], min(map->distance[i][k], map->distance[k][j]));
    return map->distance[map->start][map->end];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, r;
        int distance, a, b, maximin, s, e, passengers;
        scanf("%d%d", &n, &r);
        Map* map = new Map;
        map->number_of_city = n;
        memset(map->distance, 10000, sizeof(map->distance[0][0]));
        for (int i = 0; i < r; i++) {
            scanf("%d%d%d", &a, &b, &distance);
            map->distance[a][b] = distance;
            map->distance[b][a] = distance;
        }
        scanf("%d%d%d", &s, &e, &passengers);
        map->start = s;
        map->end = e;
        maximin = maximin_distance(map) - 1;
        printf("%d\n", passengers / maximin + (passengers % maximin == 0 ? 0 : 1));
    }
    return 0;
}

