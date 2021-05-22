//
//  ex10_35.cpp
//
//  Created by Tang Chengming on 05/04/2021
//
//  @Brief  使用普通迭代器逆序打印一个 vector

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{ 1, 2, 3, 4, 5 };

    for (auto cur = vec.cend(); cur > vec.cbegin(); --cur) {
        std::cout << *(cur - 1) << " ";
    }
    std::cout << std::endl;

    return 0;
}
