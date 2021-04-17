//
//  ex09_33.cpp
//  cpp primer 5th exercise 9.33
//
//  Created by aozy on 04/15/2021
//
//  @Brief  In the final example in this section what would happen
//          if we did not assign the result of insert to begin?
//          Write a program that omits this assignment to see if your expectation was correct.

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto begin = v.begin(); begin != v.end();) {
        ++begin;
        v.insert(begin, 42);
        // 程序出错，这里的 begin 已经失效
        ++begin;
    }

    for (auto n : v) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}
