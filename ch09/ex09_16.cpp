#include <iostream>
//
//  ex09_16.cpp
//
//  Created by Tang Chengming on 04/17/2021
//
//  @Brief  Repeat the previous program, but compare elements in a
//          list<int> to a vector<int>.

#include <list>
#include <vector>

int main() {
    std::list<int>   lst1{ 1, 2, 3, 4 };
    std::vector<int> v1{ 1, 2, 3, 4 };

    // error，相等运算符必须是同类型的容器
    // if (lst1 == v1)

    if (std::vector<int>(lst1.cbegin(), lst1.cend()) == v1)
        std::cout << "equal\n";
    else
        std::cout << "not equal\n";

    return 0;
}