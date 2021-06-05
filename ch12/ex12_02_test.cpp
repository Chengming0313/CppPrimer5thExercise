//
//  ex12_02_test.cpp
//
//  Created by Tang Chengming on 05/20/2021
//
//  @Brief

#include "ex12_02.h"

#include <iostream>

int main() {
    StrBlob const csb{ "111", "222" };
    StrBlob       sb{ "333", "444" };
    std::cout << csb.front() << " " << csb.back() << std::endl;
    std::cout << sb.front() << " " << sb.back() << std::endl;


    StrBlob sb2;
    for (int i = 100 ; i < 1000; i += 100) {
        sb2.pushBack(std::to_string(i));
    }
    std::cout << "sb2: " << sb2.size() << std::endl;
    while (!sb2.empty()) {
        std::cout << sb2.back() << " ";
        sb2.popBack();
    }

    return 0;
}
