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
    return 0;
}
