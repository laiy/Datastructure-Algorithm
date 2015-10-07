#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

struct Person {
    int id, salary, tall, subordinates, boss;
    Person(int id, int salary, int tall) {
        this->id = id;
        this->salary = salary;
        this->tall = tall;
        this->subordinates = 0;
        this->boss = 0;
    }
    bool operator<(const Person &a) const {
        return this->salary > a.salary;
    }
};

int main() {
    int n, m, q, id, salary, tall;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &m, &q);
        std::vector<Person> v;
        std::map<int, Person*> ma;
        for (int i = 0; i < m; i++)
            scanf("%d %d %d", &id, &salary, &tall), v.push_back(Person(id, salary, tall));
        std::sort(v.begin(), v.end());
        for (int i = m - 1; i > 0; i--) {
            for (int j = i - 1; j >= 0; j--)
                if (v[j].tall >= v[i].tall) {
                    v[i].boss = v[j].id;
                    v[j].subordinates += v[i].subordinates + 1;
                    break;
                }
        }
        for (int i = 0; i < m; i++)
            ma[v[i].id] = &v[i];
        for (int i = 0; i < q; i++)
            scanf("%d", &id), printf("%d %d\n", ma[id]->boss, ma[id]->subordinates);
    }
    return 0;
}

