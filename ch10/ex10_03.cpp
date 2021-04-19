//
//  ex10_03.cpp
//  cpp primer 5th exercise 10.3
//
//  Created by Tang Chengming on 04/19/2021
//
//  @Brief

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> vec{ 1, 2, 3, 4, 5 };

    int sum = std::accumulate(vec.cbegin(), vec.cend(), 0);

    std::cout << "{ 1, 2, 3, 4, 5 }\n";
    std::cout << "The sum of vector<int> is " << sum << std::endl;

    return 0;
}
