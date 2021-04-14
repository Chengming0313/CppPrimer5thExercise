//
//  ex09_24.cpp
//
//  Created by aozy on 04/14/2021
//
//  @Brief  Write a program that fetches the first element in a vector using at,
//          the subscript operator, front, and begin. Test your program on an empty vector.

#include <iostream>
#include <vector>

int main() {
    std::vector<int> iv{ 1, 2, 3 };
    if (!iv.empty()) {
        std::cout << "at(0)   : " << iv.at(0) << '\n';
        std::cout << "[0]     : " << iv[0] << '\n';
        std::cout << "front() : " << iv.front() << '\n';
        std::cout << "*begin(): " << *iv.begin() << '\n';
    }

    std::vector<int> iv2;
    std::cout << "at(0)   : " << iv2.at(0) << '\n';
    std::cout << "[0]     : " << iv2[0] << '\n';
    std::cout << "front() : " << iv2.front() << '\n';
    std::cout << "*begin(): " << *iv2.begin() << '\n';

    return 0;
}
