//
//  ex09_25.cpp
//
//  Created by aozy on 04/14/2021
//
//  @Brief

#include <iostream>
#include <vector>

int main() {
    std::vector<int> iv{ 1, 2, 3, 4, 5 };

    // elem1 与 elem2 相等
    iv.erase(iv.cbegin(), iv.cbegin());
    // elem2 等于 cend()
    iv.erase(iv.cend(), iv.cend());

    for (auto n : iv) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}
