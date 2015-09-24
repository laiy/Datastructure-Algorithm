#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <cstdlib>

int ip_to_num(std::string str) {
    static int arr[4], count;
    std::string temp;
    count = 0;
    for (size_t i = 0; i < str.size(); i++)
        if (str[i] != '.')
            temp += str[i];
        else
            arr[count++] = atoi(temp.c_str()), temp = "";
    arr[count] = atoi(temp.c_str());
    return arr[0] << 24 | arr[1] << 16 | arr[2] << 8 | arr[3];
}

int main() {
    int n, temp;
    std::map<int, std::string> map;
    std::map<std::string, std::string> ans;
    std::string id, ip;
    while (scanf("%d", &n) && n != 0) {
        map.clear();
        ans.clear();
        while (n--) {
            std::cin >> id >> ip;
            temp = ip_to_num(ip);
            if (map.count(temp))
                ans[map[temp]] = id, map.erase(map.find(temp));
            else
                map[temp] = id;
        }
        for (std::map<std::string, std::string>::iterator it = ans.begin(); it != ans.end(); it++)
            std::cout << it->second << " is the MaJia of " << it->first << std::endl, ans.erase(it);
        printf("\n");
    }
    return 0;
}

