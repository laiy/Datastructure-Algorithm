#include <iostream>

int main() {
    std::string keyword, s;
    while (std::cin >> keyword && keyword != "THEEND") {
        std::cin >> s;
        int length = keyword.length();
        std::string ordered_str = s;
        int order[10], record, count = 0;
        bool visited[10];
        char min;
        for (int i = 0; i < length; i++)
            visited[i] = false;
        for (int i = 0; i < length; i++) {
            for (int k = 0; k < length; k++)
                if (!visited[k]) {
                    min = keyword[k], record = k;
                    break;
                }
            for (int j = 0; j < length; j++) {
                if (visited[j])
                    continue;
                if (keyword[j] < min)
                    min = keyword[j], record = j;
            }
            visited[record] = true;
            order[count++] = record;
        }
        int l = s.length() / length;
        for (int i = 0; i < length; i++)
            ordered_str.replace(order[i] * l, l, s.substr(i * l, l));
        for (int i = 0; i < l; i++)
            for (int j = 0; (size_t)j < s.length(); j += l)
                std::cout << ordered_str[i + j];
        std::cout << std::endl;
    }
    return 0;
}

