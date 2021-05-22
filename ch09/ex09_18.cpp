//
//  ex09_18.cpp
//  cpp primer 5th exercise 9.18
//
//  Created by Tang Chengming on 04/14/2021
//
//  @Brief  Write a program to read a sequence of strings from the standard input into
//          a deque. Use iterators to write a loop to print the elements in the deque.

#include <deque>
#include <iostream>
#include <string>

int main() {
    std::deque<std::string> dq;
    for (std::string str; std::cin >> str; dq.push_back(str)) {
    };

    for (auto iter = dq.cbegin(); iter != dq.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << '\n';

    return 0;
}
