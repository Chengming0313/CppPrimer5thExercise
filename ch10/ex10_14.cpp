//
//  ex10_14.cpp
//  cpp primer 5th exercise 10.13
//
//  Created by Tang Chengming on 04/28/2021
//
//  @Brief  编写一个 lambda, 接受两个 int, 返回它们的和。

#include <iostream>

int main() {
    auto sum = [](int a, int b) -> int { return a + b; };

    int a = 1, b = 999;
    std::cout << sum(a, b);

    return 0;
}
