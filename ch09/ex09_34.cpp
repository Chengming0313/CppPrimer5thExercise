//
//  ex09_34.cpp
//
//  Created by Tang Chengming on 04/15/2021
//
//  @Brief  分析下面程序中循环的行为
//
//  @answer  iter 会无限遍历容器中的第一个奇数

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto iter = v.begin(); iter != v.end();) {
        std::cout << *iter << "\n";
        if (*iter % 2) iter = v.insert(iter, *iter);
        ++iter;
    }

    for (auto n : v)
        std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
