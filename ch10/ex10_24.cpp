//
//  ex10_24.cpp
//
//  Created by Tang Chengming on 05/03/2021
//
//  @Brief  编写程序, 给定一个 string, 使用 bind 以及 check_size 在一个 int 的 vector
//          中查找第一个大于 string 长度的值.

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std::placeholders;

bool check_size(std::string const &str, int size) {
    return static_cast<int>(str.size()) < size;
}

int main() {

    std::string str("12345");

    std::vector<int> vec{ 1, 3, 4, 5, 7, 9 };

    auto item = std::find_if(vec.cbegin(), vec.cend(), std::bind(check_size, str, _1));

    if (item != vec.cend()) {
        std::cout << *item << std::endl;
    }
    else {
        std::cerr << "no value that is larger than str.size()." << std::endl;
    }

    return 0;
}
