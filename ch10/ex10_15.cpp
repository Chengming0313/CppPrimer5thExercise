//
//  ex10_15.cpp
//
//  Created by Tang Chengming on 04/28/2021
//
//  @Brief  编写一个 lambda, 捕获它所在函数的 int, 并接受一个 int 参数。 lamda 应该返回捕获的 int 和
//          int 参数的和。

#include <iostream>

int main() {
    int a = 1;

    auto sum = [a](int b) { return a + b; };
    std::cout << sum(999) << std::endl;
    return 0;
}
