//
//  ex10_05.cpp
//  cpp primer 5th exercise 10.5
//
//  Created by Tang Chengming on 04/19/2021
//
//  @Brief

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<char const *> roster1{ "111", "222", "333" };
    std::vector<char const *> roster2{ "111", "222", "333" };
    char                      cstr1[4]{ '1', '1', '1' };
    char                      cstr2[4]{ '2', '2', '2' };
    char                      cstr3[4]{ '3', '3', '3' };
    std::vector<char const *> roster3{ cstr1, cstr2, cstr3 };

    std::cout << std::boolalpha
              << std::equal(std::begin(roster1), std::end(roster1), std::begin(roster2))
              << std::endl;

    std::cout << std::boolalpha
              << std::equal(std::begin(roster1), std::end(roster1), std::begin(roster3))
              << std::endl;

    return 0;
}
