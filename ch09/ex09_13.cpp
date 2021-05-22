//
//  ex09_13.cpp
//
//  Created by Tang Chengming on 04/17/2021
//
//  @Brief  How would you initialize a vector<double> from a list<int>?
//          From a vector<int>?
//          Write code to check your answers.

#include <iostream>
#include <list>
#include <vector>

int main() {
    // 使用迭代器初始化容器, 元素类型必须要相容
    std::list<int>      lst{ 1, 2, 3, 4 };
    std::vector<double> v1(lst.cbegin(), lst.cend());

    for (double d : v1)
        std::cout << d << " ";
    std::cout << '\n';

    std::vector<int>    v2{ 6, 7, 8, 9 };
    std::vector<double> v3(v2.cbegin(), v2.cend());
    for (double d : v3)
        std::cout << d << " ";
    std::cout << '\n';

    return 0;
}