//
//  ex09_19.cpp
//  cpp primer 5th exercise 9.19
//
//  Created by Tang Chengming on 04/14/2021
//
//  @Brief  Rewrite the program from the previous exercise to use a list.
//          List the changes you needed to make.

#include <iostream>
#include <list>
#include <string>

int main() {
    // 只需要将容器类型换成 std::list 即可。
    std::list<std::string> lst;
    for (std::string str; std::cin >> str;) {
        lst.push_back(str);
    }

    for (auto iter = lst.cbegin(); iter != lst.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << '\n';

    return 0;
}
