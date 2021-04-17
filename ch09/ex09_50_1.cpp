//
//  ex09_50_1.cpp
//  //  cpp primer 5th exercise 9.50.1
//
//  Created by aozy on 04/17/2021
//
//  @Brief  Write a program to process a vector<string>s whose elements represent integral values.
//          Produce the sum of all the elements in that vector.
//          Change the program so that it sums of strings that represent floating-point values.

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> svec{ "111", "222", "333", "444", "555" };

    int sum = 0;
    for (auto s : svec) {
        sum += std::stoi(s);
    }

    std::cout << "sum: " << sum << std::endl;

    return 0;
}
