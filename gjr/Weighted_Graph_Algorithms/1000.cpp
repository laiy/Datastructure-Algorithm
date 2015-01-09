/*************************************************************************
	> File Name: 1000.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Friday, January 09, 2015 AM11:52:36 CST
 ************************************************************************/

#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <cstring>
#define min(a, b) (a < b ? a : b)

int how_many_roads, place_count;
std::string places[101];
int distance[205][205];

void record(std::string from, std::string to, int length) {
    int first = 0;
    for (int i = 1; i <= place_count; i++) {
        if (places[i] == from || places[i] == to) {
            first = i;
            break;
        }
    }
    if (first) {
        places[++place_count] = (places[first] == from ? to : from);
        distance[first][place_count] = distance[place_count][first] = length;
    } else {
        places[++place_count] = from;
        places[++place_count] = to;
        distance[place_count - 1][place_count] = distance[place_count][place_count - 1] = length;
    }
}

int Dijkstra(std::string from, std::string to) {
    int s, t, min, pre;
    int dis[101];
    bool visited[101];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 101; i++) dis[101] = 10000;
    for (int i = 1; i <= place_count; i++) {
        if (places[i] == from) s = i;
        if (places[i] == to) t = i;
    }
    for (int i = 1; i <= place_count; i++) {
        int min = 10000, pre = s;
        for (int j = 1; j <= place_count; j++) {
            if (!visited[j] && dis[j] < min) min = dis[j], pre = j;
        }
        visited[pre] = true;
        for (int j = 1; i <= place_count; j++) {
            dis[j] = min(dis[j], dis[pre] + distance[pre][j]);
        }
    }
    if (visited[t]) return dis[t];
    return -1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 101; i++) places[i] = "";
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                distance[i][j] = 10000;
        place_count = 0;
        int length;
        std::string from, to;
        scanf("%d", &how_many_roads);
        for (int i = 1; i <= how_many_roads; i++) std::cin >> from >> to >> length, record(from, to ,length);
        std::cin >> from >> to;
        if (from == to) printf("0\n");
        else printf("%d\n", Dijkstra(from, to));
    }
    return 0;
}

