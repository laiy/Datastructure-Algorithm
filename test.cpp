/*************************************************************************
	> File Name: test.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Monday, December 29, 2014 AM09:51:21 CST
 ************************************************************************/

#include <iostream>
#include <list>

void output(std::list<int> list) {
    std::list<int>::iterator plist;
    for (plist = list.begin(); plist != list.end(); plist++)
        std::cout << *plist;
    std::cout << std::endl;
}

int main() {
    std::list<int> list2(10, 6);
    std::list<int> list3(list2.begin(), --list2.end());
    output(list2);
    output(list3);
}

