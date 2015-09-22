#include <iostream>

void move(int count, int from, int to, int bridge) {
    if (count > 0) {
        move(count - 1, from, bridge, to);
        std::cout << "move disk " << count << " from peg " << from << " to peg " << to << std::endl;
        move(count - 1, bridge, to, from);
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        move(n, 1, 3, 2);
    }
    return 0;
}
