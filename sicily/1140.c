#include <cstdio>
#include <vector>

struct Node {
    int id;
    std::vector<Node*> edge;
    Node(int id) {
        this->id = id;
    }
};

struct Edge {
    int x, y;
    Edge(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int k;
int visit_count[30002];

void search(std::vector<Node> nodes, std::vector<Edge> edges) {
    if (!k--)
        return;
    int i, j, count;
    std::vector<Node*>::iterator it;
    if (edges.size() % 2) {
        for (i = 0; (size_t)i < edges.size(); i++) {
            if (dfs(edges[i].x, edges[i].y, nodes) == nodes.size() / 2) {
                for (it = nodes[edges[i].x].edge.begin(); it != nodes[edges[i].x].edge.end(); it++)
                    if ((*it)->id == edges[i].y) {
                        nodes[edges[i].x].edge.erase(it);
                        break;
                    }
                for (it = nodes[edges[i].y].edge.begin(); it != nodes[edges[i].y].edge.end(); it++)
                    if ((*it)->id == edges[i].x) {
                        nodes[edges[i].y].edge.erase(it);
                        break;
                    }
                count = 0;
                std::vector<Node> temp1;
                std::vector<Node> temp2;
                for (j = 0; (size_t)j < nodes.size(); j++) {
                    if (nodes[j].id == visit_count[count])
                        temp1.push_back(nodes[j]), count++;
                    else
                        temp2.push_back(nodes[j]);
                }
            }
        }
    } else {
    }
}

int main() {
    int n, x, y, i;
    scanf("%d %d", &n, &k);
    std::vector<Node> nodes;
    std::vector<Edge> edges;
    for (i = 0; i <= n; i++)
        nodes.push_back(Node(i));
    for (i = 0; i < n - 1; i++)
        scanf("%d %d", &x, &y), nodes[x].edge.push_back(&nodes[y]), nodes[y].edge.push_back(&nodes[x]), edges.push_back(Edge(x, y));
    search(nodes, edges);
    return 0;
}

