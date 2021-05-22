//
//  ex10_04.cpp
//  cpp primer 5th exersie 10.4
//
//  Created by Tang Chengming on 04/19/2021
//
//  @Brief

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<double> vec{ 1.0, 1.1, 1.2 };

    double sum = std::accumulate(vec.cbegin(), vec.cend(), 0);

    std::cout << "{ 1.0, 1.1, 1.2 }\n";
    std::cout << "The sum of vector<double> is " << sum << ".\n";

    return 0;
}
