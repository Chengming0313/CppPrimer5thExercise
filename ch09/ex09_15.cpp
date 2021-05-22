//
//  ex09_15.cpp
//
//  Created by Tang Chengming on 04/17/2021
//
//  @Brief  Write a program to determine whether two vector<int>s are equal.

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1{ 1, 2, 3, 4 };
    std::vector<int> v2{ 1, 2, 3, 4 };

    std::vector<int> v3{ 1, 2, 3, 4 };
    std::vector<int> v4{ 2, 3, 4 };

    if (v1 == v2)
        std::cout << "v1 equal to v2\n";
    else
        std::cout << "v1 not equal to v2\n";

    if (v3 == v4)
        std::cout << "v3 equal to v4\n";
    else
        std::cout << "v3 not equal to v4\n";

    return 0;
}