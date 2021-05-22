//
//  ex09_41.cpp
// cpp primer 5th exercise 9.41
//
//  Created by Tang Chengming on 04/16/2021
//
//  @Brief  Write a program that initializes a string from a vector<char>.

#include <iostream>
#include <string>
#include <vector>

int main() {
    // 通过一对迭代器从一个　std::vector<char> 初始化一个 std::string
    std::vector<char> cvec{ 'a', 'b', 'c', 'd' };
    std::string       str(cvec.cbegin(), cvec.cend());

    std::cout << str << std::endl;

    return 0;
}
