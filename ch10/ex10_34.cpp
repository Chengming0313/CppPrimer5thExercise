//
//  ex10_34.cpp
//
//  Created by Tang Chengming on 05/04/2021
//
//  @Brief  使用 reverse_iterator 逆序打印一个 vector.

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{ 1, 2, 3, 4, 5 };
    // reverse_iterator 同样是使用 <, 而不是 >
    for (auto rit = vec.crbegin(); rit < vec.crend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    return 0;
}
