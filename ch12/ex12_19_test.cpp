//
//  ex12_19_test.cpp
//
//  Created by Tang Chengming on 05/20/2021
//
//  @Brief

#include "ex12_19.h"

#include <iostream>

int main() {
    StrBlob sb{ "111", "222", "333" };

    for (auto begin = sb.begin(); begin != sb.end(); begin.incr()) {
        std::cout << begin.deref() << std::endl;
    }

    for (auto begin = sb.begin(); begin != sb.end(); begin.incr()) {
        // StrBlob 返回的 std::string 可以进行赋值
        begin.deref() = "xxx";
        std::cout << begin.deref() << std::endl;
    }

    return 0;
}
